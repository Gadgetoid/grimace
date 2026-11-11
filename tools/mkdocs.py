import argparse
import glob
import os
import re
import sys

import mkheaders

ROOT = mkheaders.ROOT
QUALIFIERS = {"const", "CONST", "volatile", "struct", "union", "enum", "IN", "OUT", "OPTIONAL"}
BASIC_TYPES = {"void", "char", "short", "int", "long", "unsigned", "signed", "float", "double", "_Bool"}
ENTRY = re.compile(r"^## (\w+)(?:\((.*)\))?\s*$")


def read_entries():
    entries = {}
    paths = sorted(glob.glob(os.path.join(ROOT, "docs", "api", "*.txt"))) + sorted(glob.glob(os.path.join(ROOT, "docs", "api", "sdk", "*.txt")))
    for path in paths:
        current = None
        for line in open(path, encoding="utf-8"):
            match = ENTRY.match(line)
            if match:
                name, parameters = match.groups()
                names = [word.strip() for word in parameters.split(",")] if parameters else []
                current = None if name in entries else entries.setdefault(name, {"parameters": [word for word in names if word], "body": [], "source": path})
            elif current is not None:
                current["body"].append(line.rstrip())
    for entry in entries.values():
        while entry["body"] and not entry["body"][-1]:
            entry["body"].pop()
        while entry["body"] and not entry["body"][0]:
            entry["body"].pop(0)
    return entries


EXPORTS = {version: set().union(*(manifest.names() for manifest in mkheaders.manifests.manifests() if manifest.version == wce))
           for version, wce in ((1, 100), (2, 200), (3, 300))}
EXPORT_VERSIONS = {1: 100, 2: 200, 3: 300}


def same_function(name):
    names = {name}
    if name.endswith("W"):
        names.add(name[:-1])
    for first, second in (("Ce", "Peg"), ("Peg", "Ce")):
        if name.startswith(first):
            names.add(second + name[len(first):])
    return names


def availability(name):
    if name in mkheaders.ENTRY_POINTS:
        return None
    versions = [version for version in sorted(EXPORTS) if same_function(name) & EXPORTS[version]]
    if not versions or versions == sorted(EXPORTS):
        return None
    names = [mkheaders.manifests.VERSION_NAMES[EXPORT_VERSIONS[version]] for version in versions]
    if versions == sorted(EXPORTS)[-len(versions):]:
        return "Windows CE %s and later." % names[0]
    return "Windows CE %s only." % " and ".join(names)


def split_members(body):
    kept = []
    members = {}
    current = None
    for line in body:
        match = re.match(r"@member (\w+) ?(.*)", line)
        if match:
            current = members[match.group(1)] = [match.group(2)]
        elif current is not None and line.startswith(" "):
            current.append(line.strip())
        else:
            current = None
            kept.append(line)
    while kept and not kept[-1]:
        kept.pop()
    return kept, members


def indented_docstring(lines, indent):
    return indent + "/**\n" + "".join((indent + " * %s\n" % line) if line else indent + " *\n" for line in lines) + indent + " */\n"


def strip_indented_docstring(text, start):
    before = text[:start]
    match = re.search(r"[ \t]*/\*\*(?:(?!\*/).)*\*/\n$", before, re.S)
    if match:
        return before[:match.start()], text[start:]
    return before, text[start:]


def struct_braces(text, name):
    for match in re.finditer(r"\}\s*(?:[*\w]+\s*,\s*)*%s\s*[,;]" % re.escape(name), text):
        close = match.start()
        depth = 0
        for index in range(close, -1, -1):
            if text[index] == "}":
                depth += 1
            elif text[index] == "{":
                depth -= 1
                if depth == 0:
                    return index, close
    return None


def document_struct(text, entry, name):
    braces = struct_braces(text, name)
    if not braces:
        return text, "not declared"
    open_brace, close_brace = braces
    body, members = split_members(entry["body"])
    placements = []
    code_lines = []
    position = text.rfind("\n", 0, open_brace) + 1
    while position < close_brace:
        end = text.find("\n", position)
        line = text[position:end]
        code = re.sub(r"//.*|/\*.*?\*/", "", line).strip()
        if code and not code.startswith(("*", "/*")):
            code_lines.append((position, code))
        position = end + 1
    for member, lines in members.items():
        for line_start, code in code_lines:
            if line_start > open_brace and (re.search(r"\b%s\s*(\[[^\]]*\])?\s*(:\s*\w+\s*)?[;,]" % re.escape(member), code)
                                            or re.search(r"\(\s*\*\s*%s\s*\)\s*\(" % re.escape(member), code)):
                placements.append((line_start, lines))
                break
    seen = set()
    for line_start, lines in sorted(placements, key=lambda placement: -placement[0]):
        if line_start in seen:
            continue
        seen.add(line_start)
        line = text[line_start:text.find("\n", line_start)]
        indent = line[:len(line) - len(line.lstrip())]
        before, after = strip_indented_docstring(text, line_start)
        text = before + indented_docstring(lines, indent) + after
    start = statement_start(text, open_brace)
    before, after = strip_docstring(text, start)
    return before + docstring({"body": body}, None) + after, None


def document_define(text, entry, name):
    match = re.search(r"^[ \t]*#[ \t]*define[ \t]+%s\b" % re.escape(name), text, re.M)
    if not match:
        return text, "not declared"
    before, after = strip_docstring(text, match.start())
    return before + docstring(entry, None) + after, None


def docstring(entry, note):
    body = [line.replace("*/", "* /") for line in entry["body"]]
    if note:
        body += ["", "@note %s" % note]
    return "/**\n" + "".join((" * %s\n" % line) if line else " *\n" for line in body) + " */\n"


def statement_start(text, position):
    start = text.rfind("\n", 0, position) + 1
    while start > 0:
        previous_start = text.rfind("\n", 0, start - 1) + 1
        previous = text[previous_start:start - 1].strip()
        if not previous or previous.startswith("#") or previous.endswith((";", "}", "{", "*/", "\\")) or in_macro(text, previous_start):
            break
        start = previous_start
    return start


def strip_docstring(text, start):
    before = text[:start]
    match = re.search(r"/\*\*(?:(?!\*/).)*\*/\n$", before, re.S)
    if match:
        return before[:match.start()], text[start:]
    return before, text[start:]


def split_parameters(text):
    parts = []
    depth = 0
    current = ""
    for character in text:
        if character == "," and depth == 0:
            parts.append(current)
            current = ""
            continue
        depth += character in "(["
        depth -= character in ")]"
        current += character
    parts.append(current)
    return parts


def is_named(parameter):
    tokens = []
    for word in re.findall(r"[A-Za-z_]\w*", re.sub(r"\[[^\]]*\]", "", parameter)):
        if word in QUALIFIERS:
            continue
        if word in BASIC_TYPES and tokens and tokens[-1] in BASIC_TYPES:
            continue
        tokens.append(word)
    return len(tokens) >= 2


def name_parameters(text, open_paren, names):
    depth = 0
    for index in range(open_paren, len(text)):
        if text[index] == "(":
            depth += 1
        elif text[index] == ")":
            depth -= 1
            if depth == 0:
                close_paren = index
                break
    else:
        return text, "no closing parenthesis"
    parameters = split_parameters(text[open_paren + 1:close_paren])
    stripped = [parameter.strip() for parameter in parameters]
    if stripped in (["void"], [""]):
        return text, None if not names else "declared without parameters"
    if stripped and stripped[-1] == "...":
        parameters = parameters[:-1]
        stripped = stripped[:-1]
    if len(parameters) != len(names):
        return text, "declares %d parameters, docs name %d" % (len(parameters), len(names))
    rewritten = []
    for parameter, name in zip(parameters, names):
        if "(" in parameter or is_named(parameter):
            rewritten.append(parameter)
            continue
        array = re.search(r"(\s*\[[^\]]*\])\s*$", parameter)
        if array:
            rewritten.append(parameter[:array.start()].rstrip() + " " + name + array.group(1))
        else:
            spacing = "" if parameter.rstrip().endswith("*") else " "
            rewritten.append(parameter.rstrip() + spacing + name)
    remainder = text[open_paren + 1 + len(",".join(parameters)):close_paren]
    return text[:open_paren + 1] + ",".join(rewritten) + remainder + text[close_paren:], None


def in_macro(text, line_start):
    while line_start > 0:
        previous_start = text.rfind("\n", 0, line_start - 1) + 1
        if not text[previous_start:line_start - 1].rstrip().endswith("\\"):
            return False
        if text[previous_start:line_start].lstrip().startswith("#"):
            return True
        line_start = previous_start
    return False


def declaration(text, name):
    pattern = r"\b_WNAME\(%s\)\s*\(|\b%s\s*\(" % (re.escape(name), re.escape(name))
    for match in re.finditer(pattern, text):
        line_start = text.rfind("\n", 0, match.start()) + 1
        if in_macro(text, line_start):
            continue
        line = text[line_start:match.start()]
        if line.lstrip().startswith(("#", "/", "*")) or re.search(r"[=;]", line) or "__typeof__" in line:
            continue
        end = text.find(";", match.end())
        if end < 0 or "{" in text[match.end():end]:
            continue
        return match.start(), match.end() - 1
    return None


def find_declaration(texts, name):
    for path, text in texts.items():
        found = declaration(text, name)
        if found:
            return path, found
    return None, None


def apply(entries):
    paths = mkheaders.header_paths() + sorted(glob.glob(os.path.join(ROOT, "include", "grimace", "sdk", "*.h")))
    texts = {path: open(path, errors="replace").read() for path in paths}
    changed = set()
    problems = []
    for name in sorted(entries):
        entry = entries[name]
        if any(line.startswith("@member ") for line in entry["body"]):
            path = next((path for path, text in texts.items() if struct_braces(text, name)), None)
            if not path:
                problems.append("%s: not declared" % name)
                continue
            texts[path], problem = document_struct(texts[path], entry, name)
            changed.add(path)
            continue
        path, found = find_declaration(texts, name)
        if not found:
            path = next((path for path, text in texts.items() if re.search(r"^[ \t]*#[ \t]*define[ \t]+%s\b" % re.escape(name), text, re.M)), None)
            if not path:
                problems.append("%s: not declared" % name)
                continue
            texts[path], problem = document_define(texts[path], entry, name)
            changed.add(path)
            continue
        text = texts[path]
        name_start, open_paren = found
        if entry["parameters"]:
            text, problem = name_parameters(text, open_paren, entry["parameters"])
            if problem:
                problems.append("%s: %s" % (name, problem))
        comment = docstring(entry, availability(name))
        before, after = strip_docstring(text, statement_start(text, name_start))
        text = before + comment + after
        if name.endswith("W"):
            macro = re.search(r"^[ \t]*#[ \t]*define[ \t]+%s[ \t]+%s[ \t]*$" % (re.escape(name[:-1]), re.escape(name)), text, re.M)
            if macro:
                before, after = strip_docstring(text, macro.start())
                text = before + comment + after
        texts[path] = text
        changed.add(path)
    for path in changed:
        with open(path, "w") as output:
            output.write(texts[path])
    return problems


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Write docstrings from docs/api into the headers, and name the documented functions' parameters")
    parser.parse_args()
    entries = read_entries()
    problems = apply(entries)
    for problem in problems:
        print("mkdocs: %s" % problem, file=sys.stderr)
    print("mkdocs: %d functions documented, %d problems" % (len(entries), len(problems)))
