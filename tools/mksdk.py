"""
Write include/grimace/sdk/*.h: declarations for the functions the ROM exports and the Windows CE 3.0
SDK declares, but our headers don't, with the types they need.

Everything comes from clang's AST of the SDK headers. Declarations from headers that the SDK's
windows.h includes go in sdk/windows.h, which our windows.h includes last. The rest go in
sdk/<header>.h, included by our <header>.h, which is written here if we have no such header.
"""
import argparse
import glob
import os
import re
import subprocess
import sys
import tempfile
from importlib.machinery import SourceFileLoader

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
check = SourceFileLoader("check_headers", os.path.join(ROOT, "tests", "check-headers.py")).load_module()
ARM = check.ARCHITECTURES["arm"]
SDK_HEADERS = ["windows.h", "commctrl.h", "commdlg.h", "winsock.h", "notify.h", "tlhelp32.h", "mmreg.h", "msacm.h", "ras.h", "raserror.h",
               "af_irda.h", "winnetwk.h", "mmsystem.h", "lmcons.h", "wincrypt.h", "sipapi.h", "tapi.h", "shellapi.h", "shlobj.h", "wininet.h",
               "sspi.h", "security.h", "schnlsp.h", "sslsock.h", "objbase.h", "ole2.h", "oleauto.h", "olectl.h", "msgstore.h", "addrstor.h",
               "asform.h", "imgdecmp.h", "inkx.h", "richink.h", "mlang.h", "htmlctrl.h", "tnefapi.h", "dbgapi.h", "kfuncs.h", "wceshell.h",
               "ipexport.h", "icmpapi.h", "cpl.h", "dbt.h", "keybd.h", "nled.h", "winioctl.h", "urlmon.h", "winscard.h", "mshtml.h"]
WINDOWS_GROUP = "windows.h"
C_WORDS = {"const", "volatile", "struct", "union", "enum", "unsigned", "signed", "char", "short", "int", "long", "float", "double", "void",
           "_Bool", "__attribute__", "__int64", "restrict", "__restrict"}
ANONYMOUS = re.compile(r"\((?:unnamed|anonymous)(?: struct| union| enum)? at [^)]*\)")
ATTRIBUTE = re.compile(r"\s*__attribute__\(\((?:[^()]|\([^()]*\))*\)\)")
TAG = re.compile(r"\b(struct|union|enum) ([A-Za-z_]\w*)")


def walk(node, visit):
    visit(node)
    for child in node.get("inner", []):
        walk(child, visit)


TYPEDEF_TAGS = set()


def clean(spelled):
    spelled = ATTRIBUTE.sub("", spelled)
    return TAG.sub(lambda match: match.group(2) if match.group(2) in TYPEDEF_TAGS else match.group(0), spelled)


class Sdk:
    def __init__(self, tree):
        self.typedefs = {}
        candidates = {}
        self.records = {}
        self.enums = {}
        self.functions = {}
        self.by_id = {}
        for node in tree["inner"]:
            kind = node.get("kind")
            if node.get("isImplicit"):
                continue
            walk(node, self.index)
            if kind == "TypedefDecl":
                candidates.setdefault(node["name"], []).append(node)
            elif kind == "RecordDecl" and node.get("name") and node.get("completeDefinition"):
                self.records[node["name"]] = node
            elif kind == "EnumDecl" and node.get("name") and node.get("inner"):
                self.enums[node["name"]] = node
            elif kind == "FunctionDecl" and node.get("storageClass") != "static":
                if not any(child.get("kind") == "CompoundStmt" for child in node.get("inner", [])):
                    self.functions.setdefault(node["name"], node)
        for name, nodes in candidates.items():
            complete = [node for node in nodes if self.complete(node["type"]["qualType"])]
            self.typedefs[name] = (complete or nodes)[0]

    def index(self, node):
        self.by_id.setdefault(node.get("id"), node)
        if node.get("kind") == "RecordDecl" and node.get("name") and node.get("completeDefinition"):
            self.records.setdefault(node["name"], node)

    def complete(self, spelled):
        if ANONYMOUS.search(spelled):
            return True
        tags = TAG.findall(spelled)
        return not tags or all(name in (self.enums if kind == "enum" else self.records) for kind, name in tags)


def file_of(node, current):
    location = node.get("loc", {})
    for candidate in (location.get("file"), location.get("expansionLoc", {}).get("file"), location.get("spellingLoc", {}).get("file")):
        if candidate:
            return os.path.basename(candidate).lower()
    return current


def files_by_id(tree):
    found = {}
    current = None

    def visit(node):
        nonlocal current
        current = file_of(node, current)
        if node.get("id"):
            found[node["id"]] = current
    for node in tree["inner"]:
        walk(node, visit)
    return found


def our_names(clang, headers):
    side = check.Side(clang, ARM["target"], 300, [os.path.join(ROOT, "include"), os.path.join(ROOT, "include", "w32api")],
                      ARM["defines"] + ["-DGRIMACE_NO_SDK", "-DGRIMACE_NO_CONSTANTS"], headers)
    tree = side.tree()
    names = {name: None for name in side.macros()}
    tags = {}
    current = None
    for node in tree["inner"]:
        current = file_of(node, current)
        home = current[len("extras-"):] if current and current.startswith("extras-") else current
        home = home if home and os.path.exists(os.path.join(ROOT, "include", home)) else None
        kind = node.get("kind")
        if kind in ("TypedefDecl", "FunctionDecl", "VarDecl") and node.get("name"):
            names.setdefault(node["name"], home)
        elif kind in ("RecordDecl", "EnumDecl") and node.get("name") and (node.get("completeDefinition") or node.get("inner")):
            tags.setdefault(node["name"], home)
        if kind == "EnumDecl":
            for child in node.get("inner", []):
                if child.get("kind") == "EnumConstantDecl":
                    names.setdefault(child["name"], home)
    return names, tags


def windows_includes(clang):
    command = [clang] + ARM["target"] + check.COMMON_FLAGS + ["-D_WIN32_WCE=300"] + ARM["defines"] + \
              ["-I" + os.path.join(ROOT, "include"), "-I" + os.path.join(ROOT, "include", "w32api"), "-DGRIMACE_NO_SDK", "-M", "-x", "c", "-"]
    result = subprocess.run(command, input="#include <windows.h>\n", capture_output=True, text=True, check=True)
    return {os.path.basename(path).lower() for path in re.findall(r"(\S+\.h)\b", result.stdout)}


def declarator(spelled, name):
    spelled = spelled.strip()
    if "(*)" in spelled:
        return spelled.replace("(*)", "(*%s)" % name, 1)
    if "(**)" in spelled:
        return spelled.replace("(**)", "(**%s)" % name, 1)
    if spelled.endswith(")") and "(" in spelled:
        split = parameter_list_start(spelled)
        if split:
            return "%s %s%s" % (spelled[:split].strip(), name, spelled[split:])
    array = re.match(r"^(.*?)\s*((?:\[\d*\])+)$", spelled)
    if array:
        return "%s %s%s" % (array.group(1), name, array.group(2))
    if spelled.endswith("*"):
        return spelled + name
    return "%s %s" % (spelled, name)


def type_names(spelled):
    spelled = ANONYMOUS.sub("", spelled)
    tags = {(kind, name) for kind, name in TAG.findall(spelled)}
    stripped = TAG.sub("", spelled)
    names = set(re.findall(r"[A-Za-z_]\w*", stripped)) - C_WORDS
    return names, tags


class Writer:
    def __init__(self, sdk, files, ours, our_tags, packs, group_of):
        self.sdk = sdk
        self.files = files
        self.ours = ours
        self.our_tags = our_tags
        self.packs = packs
        self.group_of = group_of
        self.done = set()
        self.chunks = []
        self.dependencies = {}
        self.unresolved = set()
        self.declared = []
        self.forwarded = []
        self.windows_headers = set()

    def group(self, node):
        return self.group_of(self.files.get(node["id"]))

    def emit(self, group, lines):
        self.chunks.append((group, lines))

    def note_dependency(self, group, node):
        other = self.group(node)
        if other != group:
            self.dependencies.setdefault(group, set()).add(other)

    def declare_names(self, group, spelled):
        names, tags = type_names(clean(spelled))
        for name in sorted(names):
            self.declare_typedef(group, name)
        for kind, name in sorted(tags):
            if kind == "enum":
                self.define_tag(group, kind, name)
            else:
                self.forward(group, kind, name)

    def complete_type(self, group, spelled):
        spelled = clean(spelled)
        if "*" in spelled or "(" in ANONYMOUS.sub("", spelled):
            self.declare_names(group, spelled)
            return
        names, tags = type_names(spelled)
        for name in sorted(names):
            self.declare_typedef(group, name)
            self.complete_typedef(group, name)
        for kind, name in sorted(tags):
            self.define_tag(group, kind, name)

    def forward(self, group, kind, name):
        if name in self.our_tags or name in self.ours:
            self.ours_from(group, self.our_tags.get(name) or self.ours.get(name))
            return
        node = self.sdk.records.get(name)
        if node is not None:
            self.note_dependency(group, node)
            kind = node.get("tagUsed", kind)
            group = self.group(node)
        if ("forward", name) in self.done:
            return
        self.done.add(("forward", name))
        self.forwarded.append((group, kind, name))
        self.emit(group, ["%s %s;" % (kind, name)])

    def anonymous_tag(self, node, spelled):
        if ANONYMOUS.search(spelled):
            return self.owned_record(node)
        tags = TAG.findall(spelled)
        if len(tags) == 1 and TAG.sub("", spelled).strip() == "":
            kind, tag = tags[0]
            if tag not in (self.sdk.enums if kind == "enum" else self.sdk.records):
                return self.owned_record(node)
        return None

    def ours_from(self, group, home):
        if home and home not in self.windows_headers and home != group:
            self.dependencies.setdefault(group, set()).add(home)

    def declare_typedef(self, group, name):
        if name in self.ours:
            self.ours_from(group, self.ours[name])
            return
        node = self.sdk.typedefs.get(name)
        if node is None:
            self.unresolved.add(name)
            return
        self.note_dependency(group, node)
        if ("typedef", name) in self.done:
            return
        self.done.add(("typedef", name))
        home = self.group(node)
        spelled = clean(node["type"]["qualType"])
        record = self.anonymous_tag(node, ATTRIBUTE.sub("", node["type"]["qualType"]))
        if record is not None:
            if record.get("kind") == "EnumDecl":
                self.emit(home, ["typedef %s %s;" % (self.enum_body(record), name), ""])
                return
            self.complete_fields(home, record)
            suffix = TAG.sub("", ANONYMOUS.sub("", ATTRIBUTE.sub("", node["type"]["qualType"]))).strip()
            self.emit(home, ["typedef %s %s;" % (self.record_body(record, ""), declarator(suffix, name).strip() if suffix else name), ""])
            return
        self.declare_names(home, spelled)
        self.declared.append(name)
        self.emit(home, ["typedef %s;" % declarator(spelled, name)])

    def complete_typedef(self, group, name):
        node = self.sdk.typedefs.get(name)
        if node is None or name in self.ours or ("complete", name) in self.done:
            return
        self.done.add(("complete", name))
        spelled = clean(node["type"]["qualType"])
        if self.anonymous_tag(node, ATTRIBUTE.sub("", node["type"]["qualType"])) is None:
            self.complete_type(self.group(node), spelled)

    def owned_record(self, typedef):
        found = []

        def visit(node):
            if node.get("ownedTagDecl"):
                found.append(node["ownedTagDecl"]["id"])
            elif node.get("decl", {}).get("kind") in ("RecordDecl", "EnumDecl"):
                found.append(node["decl"]["id"])
        walk(typedef, visit)
        for identifier in found:
            if identifier in self.sdk.by_id:
                return self.sdk.by_id[identifier]
        return None

    def define_tag(self, group, kind, name):
        if name in self.our_tags or name in self.ours:
            self.ours_from(group, self.our_tags.get(name) or self.ours.get(name))
            return
        key = ("enum" if kind == "enum" else "record", name)
        node = (self.sdk.enums if kind == "enum" else self.sdk.records).get(name)
        if node is not None:
            self.note_dependency(group, node)
        if key in self.done:
            return
        self.done.add(key)
        if node is None:
            if kind != "enum":
                self.forward(group, kind, name)
            return
        home = self.group(node)
        if kind == "enum":
            body = self.enum_body(node)
            if "=" in body or re.search(r"\{\n\s+\w", body):
                self.emit(home, [body + ";", ""])
            return
        self.forward(home, kind, name)
        self.complete_fields(home, node)
        self.emit(home, [self.record_body(node, name) + ";", ""])

    def complete_fields(self, group, record):
        for child in record.get("inner", []):
            if child.get("kind") == "FieldDecl":
                if not ANONYMOUS.search(child["type"]["qualType"]):
                    self.complete_type(group, child["type"]["qualType"])
            elif child.get("kind") == "RecordDecl" and child.get("completeDefinition"):
                self.complete_fields(group, child)

    def finish(self):
        position = (0, 0)
        while position != (len(self.declared), len(self.forwarded)):
            declared, forwarded = len(self.declared), len(self.forwarded)
            for name in self.declared[position[0]:]:
                node = self.sdk.typedefs[name]
                self.complete_typedef(self.group(node), name)
                spelled = clean(node["type"]["qualType"])
                for kind, tag in TAG.findall(spelled):
                    self.define_tag(self.group(node), kind, tag)
            for group, kind, name in self.forwarded[position[1]:]:
                self.define_tag(group, kind, name)
            position = (declared, forwarded)

    def enum_body(self, node):
        constants = []
        for child in node.get("inner", []):
            if child.get("kind") != "EnumConstantDecl" or child["name"] in self.ours:
                continue
            values = [grandchild["value"] for grandchild in child.get("inner", []) if "value" in grandchild]
            constants.append("    %s = %s" % (child["name"], values[0]) if values else "    %s" % child["name"])
        name = (" " + node["name"]) if node.get("name") else ""
        return "enum%s {\n%s\n}" % (name, ",\n".join(constants))

    def record_body(self, node, name, indent=""):
        lines = []
        children = node.get("inner", [])
        pending = [child for child in children if child.get("kind") == "RecordDecl" and not child.get("name") and child.get("completeDefinition")]
        for child in children:
            if child.get("kind") != "FieldDecl":
                continue
            spelled = clean(child["type"]["qualType"])
            field_name = child.get("name", "")
            if ANONYMOUS.search(spelled):
                record = pending.pop(0)
                inner = self.record_body(record, "", indent + "    ")
                lines.append("%s    %s%s;" % (indent, inner, (" " + field_name) if field_name else ""))
                continue
            tag = TAG.fullmatch(spelled.strip())
            if not field_name and tag and tag.group(2) in self.sdk.records:
                inner = self.record_body(self.sdk.records[tag.group(2)], "", indent + "    ")
                lines.append("%s    %s;" % (indent, inner))
                continue
            if child.get("isBitfield"):
                width = [grandchild["value"] for grandchild in child.get("inner", []) if "value" in grandchild][0]
                lines.append("%s    %s : %s;" % (indent, declarator(spelled, field_name), width))
            else:
                lines.append("%s    %s;" % (indent, declarator(spelled, field_name)))
        kind = node.get("tagUsed", "struct")
        header = "%s%s" % (kind, (" " + name) if name else "")
        pack = self.packs.get(node["id"])
        attribute = " __attribute__((packed, aligned(%d)))" % pack if pack else ""
        return "%s {\n%s\n%s}%s" % (header, "\n".join(lines), indent, attribute)

    def function(self, node):
        group = self.group(node)
        spelled = clean(node["type"]["qualType"])
        split = parameter_list_start(spelled)
        if split is None:
            spelled = clean(node["type"].get("desugaredQualType", spelled))
            split = parameter_list_start(spelled)
        result = spelled[:split].strip()
        self.declare_names(group, result)
        parameters = []
        for child in node.get("inner", []):
            if child.get("kind") == "ParmVarDecl":
                parameter_type = clean(child["type"]["qualType"])
                self.declare_names(group, parameter_type)
                parameters.append(declarator(parameter_type, child.get("name", "")).strip())
        if node.get("variadic"):
            parameters.append("...")
        if not parameters:
            parameters = ["void"]
        self.emit(group, ["%s %s(%s);" % (result, node["name"], ", ".join(parameters))])


def parameter_list_start(spelled):
    depth = 0
    for index in range(len(spelled) - 1, -1, -1):
        if spelled[index] == ")":
            depth += 1
        elif spelled[index] == "(":
            depth -= 1
            if depth == 0:
                return index
    return None


def packed_records(sdk, side):
    candidates = {}
    for name, node in sdk.records.items():
        if any(child.get("kind") == "MaxFieldAlignmentAttr" for child in node.get("inner", [])):
            candidates[node["id"]] = "%s %s" % (node.get("tagUsed", "struct"), name)
    values = side.evaluate({identifier.replace("0x", "id"): "_Alignof(%s)" % spelled for identifier, spelled in candidates.items()})
    return {identifier: values[identifier.replace("0x", "id")] for identifier in candidates if identifier.replace("0x", "id") in values}


def strongly_connected(nodes, edges):
    index = {}
    low = {}
    stack = []
    on_stack = set()
    components = []
    counter = [0]

    def visit(node):
        index[node] = low[node] = counter[0]
        counter[0] += 1
        stack.append(node)
        on_stack.add(node)
        for other in sorted(edges.get(node, ())):
            if other not in index:
                visit(other)
                low[node] = min(low[node], low[other])
            elif other in on_stack:
                low[node] = min(low[node], index[other])
        if low[node] == index[node]:
            component = set()
            while True:
                member = stack.pop()
                on_stack.discard(member)
                component.add(member)
                if member == node:
                    break
            components.append(component)
    for node in nodes:
        if node not in index:
            visit(node)
    return components


def windows_family(clang, sdk_include):
    command = [clang] + ARM["target"] + check.COMMON_FLAGS + ["-D_WIN32_WCE=300", "-DWINCEMACRO"] + check.SDK_DEFINES + ARM["sdk_defines"] + \
              ["-I" + sdk_include, "-M", "-x", "c", "-"]
    result = subprocess.run(command, input="#include <windows.h>\n", capture_output=True, text=True, check=True)
    return {os.path.basename(path).lower() for path in re.findall(r"(\S+\.h)\b", result.stdout)}


def sdk_includes(sdk_include, header):
    path = os.path.join(sdk_include, header)
    if not os.path.exists(path):
        return []
    text = open(path, encoding="latin-1").read()
    return [name.lower() for name in re.findall(r'^\s*#\s*include\s*[<"]([\w.]+)[>"]', text, re.M)]


def wrapper(header, group_file, includes=()):
    guard = "GRIMACE_%s" % re.sub(r"\W", "_", header).upper()
    lines = ["#include <windows.h>", "", "#ifndef %s" % guard, "#define %s" % guard, ""]
    if group_file:
        lines += ["#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)", "#include <grimace/sdk/%s>" % group_file, "#endif"]
    lines += ["#include <%s>" % name for name in includes]
    lines += ["#define %s_CONTENT" % guard, "#ifndef GRIMACE_NO_CONSTANTS", "#include <grimace/constants.h>", "#endif", "", "#endif", ""]
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Write include/grimace/sdk/*.h from the Windows CE 3.0 SDK headers and the ROM export lists")
    parser.add_argument("--reference", default=os.environ.get("GRIMACE_REFERENCE"))
    parser.add_argument("--clang", default=os.environ.get("CLANG", "clang"))
    parser.add_argument("--report", help="write exports the SDK doesn't declare to this file")
    arguments = parser.parse_args()
    if not arguments.reference:
        sys.exit("mksdk: set GRIMACE_REFERENCE or pass --reference")
    sdk_folder = os.path.join(ROOT, "include", "grimace", "sdk")
    for path in glob.glob(os.path.join(sdk_folder, "*")):
        os.remove(path)
    for path in glob.glob(os.path.join(ROOT, "include", "*.h")):
        text = open(path).read()
        if re.search(r"#define GRIMACE_\w+_CONTENT", text) and "GRIMACE_INSIDE" not in text:
            os.remove(path)
    os.makedirs(sdk_folder, exist_ok=True)
    with tempfile.TemporaryDirectory() as work:
        sdk_include = check.sdk_folder(os.path.expanduser(arguments.reference), 3, work)
        headers = [header for header in SDK_HEADERS if os.path.exists(os.path.join(sdk_include, header))]
        sdk_side = check.Side(arguments.clang, ARM["target"], 300, [sdk_include], check.SDK_DEFINES + ARM["sdk_defines"], headers)
        tree = sdk_side.tree()
        sdk = Sdk(tree)
        for name, node in sdk.typedefs.items():
            spelled = ATTRIBUTE.sub("", node["type"]["qualType"])
            tags = TAG.findall(spelled)
            if len(tags) == 1 and tags[0][1] == name and TAG.sub("", spelled).strip() == "" and \
                    name not in (sdk.enums if tags[0][0] == "enum" else sdk.records):
                TYPEDEF_TAGS.add(name)
        files = files_by_id(tree)
        family = windows_family(arguments.clang, sdk_include)
        packs = packed_records(sdk, sdk_side)
        include_map = {header: sdk_includes(sdk_include, header) for header in os.listdir(sdk_include)}
    own = sorted(os.path.basename(path) for path in glob.glob(os.path.join(ROOT, "include", "*.h")))
    ours, our_tags = our_names(arguments.clang, ["windows.h"] + [header for header in own if header != "windows.h"])

    windows_headers = windows_includes(arguments.clang)

    def group_of(sdk_file):
        if sdk_file is None or (sdk_file in family and (sdk_file not in own or sdk_file in windows_headers)):
            return WINDOWS_GROUP
        return sdk_file

    exported = check.exports(3, "arm")
    wanted = sorted(name for name in sdk.functions if name in exported and name not in ours and not name.startswith("__"))
    writer = Writer(sdk, files, ours, our_tags, packs, group_of)
    writer.windows_headers = windows_headers
    for name in wanted:
        writer.function(sdk.functions[name])
    for name, node in sorted(sdk.typedefs.items()):
        if files.get(node["id"]) not in check.EXCLUDED_HEADERS and not check.EXCLUDED_TYPES.match(name):
            writer.declare_typedef(group_of(files.get(node["id"])), name)
    for name, node in sorted(sdk.records.items()):
        if node in tree["inner"] and files.get(node["id"]) not in check.EXCLUDED_HEADERS:
            writer.define_tag(group_of(files.get(node["id"])), node.get("tagUsed", "struct"), name)
    for name, node in sorted(sdk.enums.items()):
        if files.get(node["id"]) not in check.EXCLUDED_HEADERS:
            writer.define_tag(group_of(files.get(node["id"])), "enum", name)
    writer.finish()
    groups = sorted({group for group, _ in writer.chunks})
    edges = {group: {other for other in others if other in groups} for group, others in writer.dependencies.items() if group in groups}
    components = strongly_connected(groups, edges)
    file_of_group = {}
    for component in components:
        name = WINDOWS_GROUP if WINDOWS_GROUP in component else sorted(component)[0]
        for group in component:
            file_of_group[group] = name
    for name in sorted(set(file_of_group.values())):
        members = {group for group, file_name in file_of_group.items() if file_name == name}
        needed = set()
        for group in members:
            needed |= {other for other in writer.dependencies.get(group, set()) if file_of_group.get(other, other) != name}
        includes = []
        for other in sorted(needed - {WINDOWS_GROUP}):
            if other in file_of_group and other not in own:
                includes.append("#include <grimace/sdk/%s>" % file_of_group[other])
            else:
                includes.append("#include <%s>" % other)
        includes = sorted(set(includes), key=includes.index)
        lines = [line for group, chunk in writer.chunks if group in members for line in chunk]
        guard = "GRIMACE_SDK_%s" % re.sub(r"\W", "_", name).upper()
        text = ["#ifndef %s" % guard, "#define %s" % guard, ""] + includes + ["", "#ifdef __cplusplus", "extern \"C\" {", "#endif", ""] + lines + \
               ["", "#ifdef __cplusplus", "}", "#endif", "", "#endif", ""]
        with open(os.path.join(sdk_folder, name), "w") as output:
            output.write("\n".join(text))
    contentless = {header for header in (set(files.values()) | set(headers)) - {None}
                   if header not in family and header not in check.EXCLUDED_HEADERS and header not in file_of_group and header not in own}
    wrapped = {group for group in file_of_group if group != WINDOWS_GROUP} | set(own) | contentless
    for group, name in sorted(file_of_group.items()):
        if group != WINDOWS_GROUP and not os.path.exists(os.path.join(ROOT, "include", group)):
            includes = [header for header in include_map.get(group, []) if header in wrapped and header not in family and header != group]
            with open(os.path.join(ROOT, "include", group), "w") as output:
                output.write(wrapper(group, name, includes))
    for header in sorted(contentless):
        if not os.path.exists(os.path.join(ROOT, "include", header)):
            includes = [name for name in include_map.get(header, []) if name in wrapped and name not in family and name != header]
            with open(os.path.join(ROOT, "include", header), "w") as output:
                output.write(wrapper(header, None, includes))
    with open(os.path.join(sdk_folder, "groups.txt"), "w") as output:
        output.write("".join("%s %s\n" % item for item in sorted(file_of_group.items())))
    undeclared = sorted(exported - set(sdk.functions) - set(ours))
    print("mksdk: %d functions declared in %d files, %d types unresolved: %s" % (
        len(wanted), len(set(file_of_group.values())), len(writer.unresolved), " ".join(sorted(writer.unresolved))))
    print("mksdk: %d exports the SDK doesn't declare" % len(undeclared))
    if arguments.report:
        with open(arguments.report, "w") as output:
            output.write("\n".join(undeclared) + "\n")


if __name__ == "__main__":
    main()
