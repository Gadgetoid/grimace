"""
Prepare docstring work from the Windows CE 3.0 reference (eMbedded Visual Tools 3.0 help files).

index    parse the extracted help pages into <reference>/index.json
batches  write <reference>/batches/*.md: each function the ROM exports and our headers declare, with
         our declaration, its docs/api entry if any, and its reference page as text
status   count functions with docstrings, reference pages, both or neither
merge    fold docs/api/<file>.<batch>.txt into docs/api/<file>.txt, sorted, replacing entries of the same name
"""
import argparse
import glob
import html
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_REFERENCE = os.path.join(ROOT, "reference")
SKIPPED_SECTIONS = {"example", "libraries", "generic-text routine mappings", "see also"}
BATCH_SIZE = 40
ENTRY = re.compile(r"^## (\w+)(?:\((.*)\))?\s*$")
STALE = re.compile(r"Windows CE (1\.0|1\.01|2\.0)|CE (1\.0|2\.0)|Velo|grimace::runtime|static C library")


def text_of(fragment):
    fragment = re.sub(r"<(script|style)\b.*?</\1>", "", fragment, flags=re.S | re.I)
    fragment = re.sub(r"<br\s*/?>", "\n", fragment, flags=re.I)
    fragment = re.sub(r"<[^>]+>", "", fragment)
    return re.sub(r"[ \t\r\f\v]+", " ", html.unescape(fragment).replace("\xa0", " ")).strip()


def blocks(fragment):
    output = []
    position = 0
    pattern = re.compile(r"<(pre|dl|table|p|ul|ol)\b[^>]*>(.*?)</\1>", re.S | re.I)
    for match in pattern.finditer(fragment):
        kind, body = match.group(1).lower(), match.group(2)
        loose = text_of(fragment[position:match.start()])
        if loose:
            output.append(loose)
        position = match.end()
        if kind == "pre":
            code = html.unescape(re.sub(r"<[^>]+>", "", body)).replace("\xa0", " ").strip("\n")
            output.append("```\n%s\n```" % code.rstrip())
        elif kind == "dl":
            for term, definition in re.findall(r"<dt>(.*?)</dt>\s*<dd>(.*?)(?=<dt>|$)", body, re.S | re.I):
                output.append("- %s: %s" % (text_of(term), text_of(re.sub(r"</dd>", "", definition, flags=re.I))))
        elif kind == "table":
            rows = []
            for row in re.findall(r"<tr\b[^>]*>(.*?)</tr>", body, re.S | re.I):
                cells = [text_of(cell) for cell in re.findall(r"<t[hd]\b[^>]*>(.*?)</t[hd]>", row, re.S | re.I)]
                if any(cells):
                    rows.append("| " + " | ".join(cells) + " |")
            output.append("\n".join(rows))
        elif kind in ("ul", "ol"):
            output.append("\n".join("- " + text_of(item) for item in re.findall(r"<li\b[^>]*>(.*?)(?=<li\b|$)", body, re.S | re.I)))
        else:
            paragraph = text_of(body)
            if paragraph:
                output.append(paragraph)
    loose = text_of(fragment[position:])
    if loose:
        output.append(loose)
    return [block for block in output if block.strip()]


def parse_page(path):
    raw = open(path, encoding="cp1252", errors="replace").read()
    body = re.search(r"<body\b[^>]*>(.*)</body>", raw, re.S | re.I)
    body = body.group(1) if body else raw
    heading = re.search(r"<h1\b[^>]*>(.*?)</h1>", body, re.S | re.I)
    if not heading:
        return None
    title = text_of(heading.group(1))
    after = body[heading.end():]
    after = re.sub(r'<div class="footer">.*', "", after, flags=re.S | re.I)
    parts = re.split(r"<h4\b[^>]*>(.*?)</h4>", after, flags=re.S | re.I)
    sections = [("Summary", blocks(parts[0]))]
    for index in range(1, len(parts), 2):
        sections.append((text_of(parts[index]), blocks(parts[index + 1])))
    names = set(name for name in re.split(r"[,\s]+", title) if re.match(r"^_?[A-Za-z]\w*$", name))
    for row in re.findall(r"<tr\b[^>]*>\s*<td\b[^>]*>\s*<b>(\w+)</b>", body, re.S | re.I):
        names.add(row)
    see_also = []
    for index in range(1, len(parts), 2):
        if text_of(parts[index]).lower() == "see also":
            see_also = [text_of(link) for link in re.findall(r"<a\b[^>]*>(.*?)</a>", parts[index + 1], re.S | re.I)]
    return {"title": title, "names": sorted(names), "sections": sections, "see_also": see_also,
            "page": os.path.relpath(path, DEFAULT_REFERENCE)}


def page_rank(name, page):
    base = os.path.basename(page["page"]).lower()
    penalty = 0
    if re.search(r"fsd|_drv|ddk|oem|pb_", base):
        penalty += 10
    if page["title"] != name:
        penalty += 1
    return penalty


def index(reference):
    pages = []
    for path in sorted(glob.glob(os.path.join(reference, "help", "evt3", "*", "htm", "*.htm"))):
        page = parse_page(path)
        if page:
            pages.append(page)
    by_name = {}
    for number, page in enumerate(pages):
        for name in page["names"]:
            by_name.setdefault(name, []).append(number)
    for name in by_name:
        by_name[name].sort(key=lambda number: page_rank(name, pages[number]))
    output = os.path.join(reference, "index.json")
    with open(output, "w") as handle:
        json.dump({"pages": pages, "names": by_name}, handle)
    print("docref: %d pages, %d names, written to %s" % (len(pages), len(by_name), output))


def load_index(reference):
    path = os.path.join(reference, "index.json")
    if not os.path.exists(path):
        sys.exit("docref: run `python3 tools/docref.py index` first")
    return json.load(open(path))


def lookup(data, name):
    for candidate in (name, name[:-1] if name.endswith("W") else None, name[1:] if name.startswith("_") else None):
        if candidate and candidate in data["names"]:
            return [data["pages"][number] for number in data["names"][candidate]]
    return []


def declarations(clang):
    headers = [os.path.basename(path) for path in sorted(glob.glob(os.path.join(ROOT, "include", "*.h"))) if os.path.basename(path) != "mswsock.h"]
    source = "#include <windows.h>\n#include <winsock.h>\n" + "".join("#include <%s>\n" % header for header in headers)
    command = [clang, "--target=armv4-unknown-none-wince", "-fshort-wchar", "-ffreestanding", "-nostdlibinc", "-fsyntax-only", "-w", "-D_WIN32_WCE=300",
               "-I", os.path.join(ROOT, "include"), "-I", os.path.join(ROOT, "include", "w32api"), "-Xclang", "-ast-dump=json", "-x", "c", "-"]
    tree = json.loads(subprocess.run(command, input=source, capture_output=True, text=True, check=True).stdout)
    found = {}
    current = None
    for node in tree["inner"]:
        location = node.get("loc", {})
        for candidate in (location.get("expansionLoc", {}).get("file"), location.get("file"), location.get("spellingLoc", {}).get("file")):
            if candidate and not candidate.startswith("<"):
                current = candidate
                break
        if node.get("kind") != "FunctionDecl" or node.get("isImplicit") or node["name"] in found:
            continue
        spelled = node["type"]["qualType"]
        result = spelled[:spelled.index("(")].strip() if "(" in spelled else spelled
        parameters = ["%s %s" % (child["type"]["qualType"], child.get("name", "")) for child in node.get("inner", []) if child.get("kind") == "ParmVarDecl"]
        if node.get("variadic"):
            parameters.append("...")
        found[node["name"]] = {"declaration": "%s %s(%s);" % (result, node["name"], ", ".join(parameter.strip() for parameter in parameters) or "void"),
                               "file": os.path.relpath(current, ROOT) if current else "?"}
    return found


def exported_names():
    names = set()
    for path in glob.glob(os.path.join(ROOT, "exports", "jornada720-ce3", "*.txt")):
        names.update(line.strip() for line in open(path) if line.strip())
    return names


def docs_entries():
    entries = {}
    for path in sorted(glob.glob(os.path.join(ROOT, "docs", "api", "*.txt"))):
        current = None
        for line in open(path, encoding="utf-8"):
            match = ENTRY.match(line)
            if match:
                current = match.group(1)
                entries[current] = {"file": os.path.relpath(path, ROOT), "text": line}
            elif current:
                entries[current]["text"] += line
    for entry in entries.values():
        entry["text"] = entry["text"].rstrip() + "\n"
    return entries


def target_file(name, declared, pages, entries):
    if name in entries:
        return entries[name]["file"]
    for page in pages:
        for section, content in page["sections"]:
            if section.lower().startswith("requirements"):
                match = re.search(r"\|\s*([A-Za-z0-9_]+)\.h\s*\|", "\n".join(content))
                if match:
                    return "docs/api/%s.txt" % match.group(1).lower()
    base = os.path.basename(declared["file"])
    return "docs/api/%s.txt" % os.path.splitext(base)[0]


def page_text(page):
    lines = ["Source: `%s` (%s)" % (page["page"], page["title"])]
    for section, content in page["sections"]:
        if section.lower() in SKIPPED_SECTIONS or not content:
            continue
        lines += ["", "#### %s" % section, "", "\n\n".join(content)]
    if page["see_also"]:
        lines += ["", "See also: " + ", ".join(page["see_also"])]
    return "\n".join(lines)


def work(clang, reference):
    data = load_index(reference)
    declared = declarations(clang)
    exported = exported_names()
    entries = docs_entries()
    items = []
    for exported_name in sorted(set(declared) & exported):
        name = exported_name
        if declared[name]["file"].endswith("aliases.h") and name + "W" in declared:
            name += "W"
        pages = lookup(data, name)
        status = "review" if name in entries else ("new" if pages else "new-without-reference")
        if status == "review" and STALE.search(entries[name]["text"]):
            status = "review-stale"
        items.append({"name": name, "exported_as": exported_name, "status": status, "declared": declared[name], "pages": pages[:2],
                      "target": target_file(name, declared[name], pages, entries), "entry": entries.get(name)})
    return items, entries, data


def batches(clang, reference):
    items, _, _ = work(clang, reference)
    folder = os.path.join(reference, "batches")
    os.makedirs(folder, exist_ok=True)
    for path in glob.glob(os.path.join(folder, "*.md")):
        os.remove(path)
    by_target = {}
    for item in items:
        by_target.setdefault(item["target"], []).append(item)
    listing = ["# Docstring batches", "", "| Batch | Target | New | New without reference | Review | Review, stale |", "| --- | --- | --- | --- | --- | --- |"]
    number = 0
    for target in sorted(by_target):
        group = by_target[target]
        for start in range(0, len(group), BATCH_SIZE):
            number += 1
            chunk = group[start:start + BATCH_SIZE]
            name = "%03d-%s.md" % (number, os.path.splitext(os.path.basename(target))[0])
            lines = ["# Batch %03d: %s" % (number, target), "", "Write or revise the entries below in `%s`. See `reference/DOCSTRINGS.md`." % target, ""]
            for item in chunk:
                exported_as = "" if item["exported_as"] == item["name"] else " Exported by the ROM as `%s`, which the headers map to this name." % item["exported_as"]
                lines += ["---", "", "## %s (%s)" % (item["name"], item["status"]), "", "Declared in `%s`:%s" % (item["declared"]["file"], exported_as), "",
                          "```c", item["declared"]["declaration"], "```", ""]
                if item["entry"]:
                    lines += ["Current entry in `%s`:" % item["entry"]["file"], "", "```", item["entry"]["text"].rstrip(), "```", ""]
                for page in item["pages"]:
                    lines += ["### Reference", "", page_text(page), ""]
                if not item["pages"]:
                    lines += ["No reference page. Describe it from the declaration and the SDK header only if its purpose is clear; otherwise leave it out.", ""]
            with open(os.path.join(folder, name), "w") as handle:
                handle.write("\n".join(lines))
            counts = [sum(1 for item in chunk if item["status"] == status) for status in ("new", "new-without-reference", "review", "review-stale")]
            listing.append("| [%s](%s) | `%s` | %d | %d | %d | %d |" % (name[:-3], name, target, *counts))
    with open(os.path.join(folder, "INDEX.md"), "w") as handle:
        handle.write("\n".join(listing) + "\n")
    print("docref: %d functions in %d batches, written to %s" % (len(items), number, folder))


def status(clang, reference):
    items, entries, _ = work(clang, reference)
    counts = {}
    for item in items:
        counts[item["status"]] = counts.get(item["status"], 0) + 1
    with_page = sum(1 for item in items if item["pages"])
    print("docref: %d functions declared and exported" % len(items))
    print("  documented: %d (%d with a reference page, %d mentioning CE 1.0, 2.0 or the Velo)" % (
        counts.get("review", 0) + counts.get("review-stale", 0), sum(1 for item in items if item["status"].startswith("review") and item["pages"]),
        counts.get("review-stale", 0)))
    print("  undocumented with a reference page: %d" % counts.get("new", 0))
    print("  undocumented without a reference page: %d" % counts.get("new-without-reference", 0))
    print("  with a reference page: %d" % with_page)


def read_file_entries(path):
    entries = {}
    current = None
    for line in open(path, encoding="utf-8"):
        match = ENTRY.match(line)
        if match:
            current = match.group(1)
            entries[current] = line
        elif current:
            entries[current] += line
    return {name: text.rstrip() + "\n" for name, text in entries.items()}


def merge():
    pending = sorted(glob.glob(os.path.join(ROOT, "docs", "api", "*.*.txt")))
    for path in pending:
        target = re.sub(r"\.[^.]+\.txt$", ".txt", path)
        entries = read_file_entries(target) if os.path.exists(target) else {}
        incoming = read_file_entries(path)
        entries.update(incoming)
        with open(target, "w", encoding="utf-8") as handle:
            handle.write("\n".join(entries[name] for name in sorted(entries, key=str.lower)))
        os.remove(path)
        print("docref: merged %d entries from %s into %s" % (len(incoming), os.path.relpath(path, ROOT), os.path.relpath(target, ROOT)))
    if not pending:
        print("docref: nothing to merge")


def main():
    parser = argparse.ArgumentParser(description="Prepare docstring work from the Windows CE 3.0 reference help files")
    parser.add_argument("command", choices=["index", "batches", "status", "merge"])
    parser.add_argument("--reference", default=os.environ.get("GRIMACE_DOCS_REFERENCE", DEFAULT_REFERENCE))
    parser.add_argument("--clang", default=os.path.join(os.environ.get("GRIMACE_LLVM_ROOT", os.path.join(ROOT, "llvm")), "bin", "clang"))
    arguments = parser.parse_args()
    if arguments.command == "index":
        index(arguments.reference)
    elif arguments.command == "merge":
        merge()
    elif arguments.command == "batches":
        batches(arguments.clang, arguments.reference)
    else:
        status(arguments.clang, arguments.reference)


if __name__ == "__main__":
    main()
