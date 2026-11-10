import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools"))
import manifests

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CORE_HEADERS = ["windows.h", "commctrl.h", "commdlg.h", "winsock.h", "notify.h", "tlhelp32.h", "mmreg.h", "msacm.h", "imm.h", "ras.h", "af_irda.h",
                "windowsx.h", "winnetwk.h", "mmsystem.h", "lmcons.h", "tchar.h"]
HEADERS = CORE_HEADERS + ["wincrypt.h", "sipapi.h", "tapi.h", "shlobj.h", "wininet.h", "sspi.h", "objbase.h", "ole2.h", "oleauto.h", "olectl.h",
                          "msgstore.h", "addrstor.h", "imgdecmp.h", "inkx.h", "richink.h", "mlang.h", "htmlctrl.h", "tnefapi.h", "urlmon.h",
                          "winscard.h", "mshtml.h", "cpl.h"]
WIN32_WCE = {1: 100, 101: 101, 2: 200, 3: 300}
VERSION_NAMES = {1: "1.0", 101: "1.01", 2: "2.0", 3: "3.0"}
COMMON_FLAGS = ["-fshort-wchar", "-ffreestanding", "-nostdlibinc", "-w", "-ferror-limit=0"]
ARCHITECTURES = {
    "mips": {"target": ["--target=mipsel-unknown-none-elf", "-march=mips1", "-msoft-float", "-Wno-unknown-warning-option", "-Wno-experimental-option"],
             "sdk_defines": ["-DMIPS", "-D_MIPS_=1", "-D_M_MRX000=4000"], "defines": []},
    "sh3": {"target": ["--target=sh3el-unknown-none-wince"],
            "sdk_defines": ["-DSHx", "-DSH3", "-D_SH3_", "-D_M_SH=3"], "defines": ["-DSHx", "-DSH3", "-D_SH3_"]},
    "x86": {"target": ["--target=i486-unknown-none-elf", "-malign-double"],
            "sdk_defines": ["-D_X86_", "-Dx86", "-D_M_IX86=400", "-D_INTEGRAL_MAX_BITS=64", "-U__asm", "-fasm-blocks"], "defines": ["-D_X86_", "-Dx86"]},
    "arm": {"target": ["--target=armv4-unknown-none-wince", "-mcpu=strongarm", "-marm", "-mfloat-abi=soft"],
            "sdk_defines": ["-DARM", "-D_ARM_", "-DARMV4", "-D_M_ARM=4", "-D_INTEGRAL_MAX_BITS=64"], "defines": ["-DARM", "-D_ARM_", "-DARMV4"]},
}
DEFAULT_VERSIONS = {"mips": ["1", "2"], "sh3": ["1", "101", "2"], "x86": ["2"], "arm": ["3"]}
UNDECLARED_EXPORTS = {"x86": re.compile(r"^(_?[a-z]\w*|GetErrorInfo|GetHGlobalFromStream)$")}
KNOWN_DIFFERENCES = re.compile(r"^((size|offset)_(struct_)?_?(WIN32_FIND_DATAA|tagREBARBANDINFOA|REBARBANDINFOA|IMAGE_\w+64|REPARSE_DATA_BUFFER)(_|$)|WINVER$|OLEMISC_WANTSTOMENUMERGE$)")
KNOWN_SIGNATURES = re.compile(r"^(ImageList_EndDrag|waveOutGetVolume|waveOutSetVolume|Random|DebugBreak)$")
CORE_EXCLUDED_FUNCTIONS = re.compile(r"^(Co[A-Z]\w*|Ole\w+|Stg\w+|Var[A-Z]\w*|Variant\w+|SafeArray\w+|Sys[A-Z]\w*|Disp\w+|CLSIDFromString|"
                                r"StringFrom\w+|ReadClass\w+|WriteClass\w+|\w*TypeLib\w*|CreateErrorInfo|SetErrorInfo|CreateOleAdviseHolder|BstrFromVector|"
                                r"VectorFromBstr|SystemTimeToVariantTime|VariantTimeToSystemTime|line[A-Z]\w*|Dll[A-Z]\w*|ThisIsGwes|__C_specific_handler|"
                                r"acmFilter\w+|acmFormatChoose)$")
CORE_EXCLUDED_HEADERS = {"tapi.h", "mmreg.h", "mmddk.h", "oleauto.h", "oaidl.h", "objidl.h", "objbase.h", "oleidl.h", "ole2.h", "wtypes.h", "kfuncs.h",
                    "unknwn.h", "rpc.h", "rpcdce.h", "rpcndr.h", "rpcnsip.h", "rpcnterr.h", "olectl.h", "ocidl.h", "cguid.h", "coguid.h"}
CORE_EXCLUDED_TYPES = re.compile(r"^(P?U?INT128|RNAAPP_INFO|PRNAAPP_INFO|RASPPPADDR|RasCntlEnum_t|RUNQ_t|PRUNQ_t|PTHREAD|P?EXCEPTION_ROUTINE|"
                            r"_onexit_t|l?div_t|P?SOCKHAND|LPHICON)$|^(LP)?(LINE|PHONE|HLINE|HPHONE|HCALL|P?ACMFILTER|P?ACMFORMATCHOOSE|ACMDRIVERPROC|LPACMDRIVERPROC|I[A-Z]\w*Vtbl$|I[A-Z][a-z]\w*$|LP[A-Z]*VTBL$|PFN(CANUNLOADNOW|GETCLASSOBJECT)$)")
EXCLUDED_MACROS = re.compile(r"^(\w+[a-z0-9]A|\w+API|DEBUGMSG|ERRORMSG|RETAILMSG|DBGCHK|WSAStartup|WSACleanup|BASETYPES|cdecl|NETCONS_INCLUDED|"
                             r"SOCKHAND_DEFINED|BACKUP_MSG_FILENAME|IS_DISPATCHING|IS_UNWINDING|IS_TARGET_UNWIND|isleadbyte|iswascii|MB_CUR_MAX|"
                             r"ACMHELPMSG\w+|DEFINE_GUID|DIALOGEX|LPTBSAVEPARAMS|ALGIDDEF|ASSERTMSG|ASSERT_IMPLIES|VERIFY|DEBUGLED|DEBUGZONE|RETAILLED|"
                             r"BEGIN_INTERFACE|END_INTERFACE|DECLARE_INTERFACE_?|INTERFACE|interface|CONST_VTBL|PURE|THIS_?|STDMETHOD\w*|DECLSPEC_UUID|"
                             r"DEFINE_OLEGUID|DEFINE_SHLGUID|EXTERN_C|FARSTRUCT|HUGEP|SEC_FAR|SECURITY_|POINTER_32|POINTER_64|RESTRICTED_POINTER|WX86|"
                             r"\w+_H|\w+_DEFINED)$")
EXCLUDED_CONSTANTS = re.compile(r"^(CERT_E_|CRYPT_E_|TRUST_E_|DIGSIG_E_|SPAPI_E_|WIN32$)")
EXCLUDED_FUNCTIONS = re.compile(r"^(Dll[A-Z]\w*|ThisIsGwes|__C_specific_handler)$")
EXCLUDED_HEADERS = {"mmddk.h", "kfuncs.h", "rpc.h", "rpcdce.h", "rpcndr.h", "rpcnsip.h", "rpcnterr.h", "cguid.h", "coguid.h"}
EXCLUDED_TYPES = re.compile(r"^(P?U?INT128|RNAAPP_INFO|PRNAAPP_INFO|RASPPPADDR|RasCntlEnum_t|RUNQ_t|PRUNQ_t|PTHREAD|P?EXCEPTION_ROUTINE|"
                            r"_onexit_t|l?div_t|P?SOCKHAND|LPHICON)$")
UNDERSCORE_MACRO_HEADERS = {"tchar.h"}
CORE_EXCLUSIONS = (CORE_EXCLUDED_FUNCTIONS, CORE_EXCLUDED_HEADERS, CORE_EXCLUDED_TYPES)
EXCLUSIONS = (EXCLUDED_FUNCTIONS, EXCLUDED_HEADERS, EXCLUDED_TYPES)
SDK_DEFINES = ["-fms-extensions", "-Wno-implicit-int", "-D_WIN32", "-DUNDER_CE", "-DUNICODE", "-D_UNICODE", "-DWIN32_LEAN_AND_MEAN", "-D__asm=grimace_sdk_asm", "-D__export=",
               "-DHUGEP="]


class Side:
    def __init__(self, clang, target, version, include, defines, headers):
        self.clang = clang
        self.flags = target + COMMON_FLAGS + ["-D_WIN32_WCE=%d" % version] + defines + ["-I%s" % folder for folder in include]
        self.prelude = "".join("#include <%s>\n" % header for header in headers)

    def run(self, extra, body, check=False):
        return subprocess.run([self.clang] + self.flags + extra + ["-x", "c", "-"], input=self.prelude + body, capture_output=True, text=True,
                              check=check)

    def macros(self):
        found = {}
        for line in self.run(["-E", "-dM"], "", check=True).stdout.splitlines():
            match = re.match(r"#define (\w+) (.+)$", line)
            if match:
                found[match.group(1)] = match.group(2)
        return found

    def tree(self, body=""):
        return json.loads(self.run(["-fsyntax-only", "-Xclang", "-ast-dump=json"], body).stdout)

    def evaluate(self, expressions):
        lines = list(expressions.items())
        while True:
            body = "".join("long long grimace_value_%s = (long long)(%s);\n" % (name, expression) for name, expression in lines)
            result = self.run(["-S", "-emit-llvm", "-o", "-"], body)
            bad = set()
            first = self.prelude.count("\n") + 1
            for match in re.finditer(r"<stdin>:(\d+):\d+: error", result.stderr):
                index = int(match.group(1)) - first
                if 0 <= index < len(lines):
                    bad.add(index)
            if not bad:
                break
            lines = [line for index, line in enumerate(lines) if index not in bad]
        values = {}
        for match in re.finditer(r"@grimace_value_(\w+) = (?:dso_local )?global i64 (-?\d+)", result.stdout):
            values[match.group(1)] = int(match.group(2))
        return values


    def signatures(self, names):
        names = sorted(names)
        unusable = set()
        while True:
            body = "".join("void *grimace_address_%s = (void *)&%s;\n" % (name, name) for name in names)
            result = self.run(["-S", "-emit-llvm", "-o", "-"], body)
            first = self.prelude.count("\n") + 1
            bad = set()
            for match in re.finditer(r"<stdin>:(\d+):\d+: error", result.stderr):
                index = int(match.group(1)) - first
                if 0 <= index < len(names):
                    bad.add(names[index])
            if not bad:
                break
            unusable |= bad
            names = [name for name in names if name not in bad]
        found = {}
        for match in re.finditer(r"^declare (?:dso_local )?(.*?) @(\w+)\((.*?)\)", result.stdout, re.M):
            signature = "%s (%s)" % (match.group(1), match.group(3))
            found[match.group(2)] = re.sub(r"\b(noundef|dso_local)\s*", "", signature).strip()
        return found, unusable


def exports(version, arch):
    return manifests.exported_at(arch, WIN32_WCE[version])


def sdk_folder(reference, version, work):
    source = os.path.join(reference, "include", "ce%d" % WIN32_WCE[version])
    folder = os.path.join(work, "ce%d" % version)
    os.makedirs(folder)
    for name in os.listdir(source):
        shutil.copyfile(os.path.join(source, name), os.path.join(folder, name.lower()))
    return folder


def macro_names(side):
    return set(re.findall(r"^#define (\w+)", side.run(["-E", "-dM"], "", check=True).stdout, re.M))


def declared_names(tree):
    found = set()
    for node in tree["inner"]:
        if node.get("name"):
            found.add(node["name"])
        if node.get("kind") == "EnumDecl":
            found.update(child["name"] for child in node.get("inner", []) if child.get("kind") == "EnumConstantDecl")
    return found


def records(tree):
    found = {}
    for node in tree["inner"]:
        if node.get("kind") == "TypedefDecl" and not node.get("isImplicit"):
            found.setdefault(node["name"], node["name"])
        if node.get("kind") == "RecordDecl" and node.get("name") and node.get("completeDefinition"):
            fields = [child["name"] for child in node.get("inner", []) if child.get("kind") == "FieldDecl" and child.get("name")]
            found["%s %s" % (node.get("tagUsed", "struct"), node["name"])] = fields
    return found


def defining_headers(folder):
    where = {}
    for name in sorted(os.listdir(folder)):
        text = open(os.path.join(folder, name), encoding="latin-1").read()
        for macro in re.findall(r"^\s*#\s*define\s+(\w+)", text, re.M):
            where.setdefault(macro, name)
    return where


def type_headers(tree):
    where = {}
    current = None
    for node in tree["inner"]:
        location = node.get("loc", {})
        for candidate in (location.get("file"), location.get("expansionLoc", {}).get("file"), location.get("spellingLoc", {}).get("file")):
            if candidate:
                current = os.path.basename(candidate)
        if node.get("kind") in ("TypedefDecl", "RecordDecl") and node.get("name"):
            key = node["name"] if node["kind"] == "TypedefDecl" else "%s %s" % (node.get("tagUsed", "struct"), node["name"])
            where.setdefault(key, current)
    return where


def typedef_types(tree):
    found = {}
    for node in tree["inner"]:
        if node.get("kind") == "TypedefDecl" and not node.get("isImplicit"):
            found[node["name"]] = node["type"].get("desugaredQualType", node["type"]["qualType"])
    return found


def checked_macro_name(name, header):
    if header in UNDERSCORE_MACRO_HEADERS:
        return not name.startswith("__") and not name.startswith("_INC_") and not name.endswith("_H_")
    return not name.startswith("_")


def checked_headers(version):
    return HEADERS if WIN32_WCE[version] >= 300 else CORE_HEADERS


def exclusions(version):
    return EXCLUSIONS if WIN32_WCE[version] >= 300 else CORE_EXCLUSIONS


def excluded_constant(name, header, excluded_headers):
    return header is None or header in excluded_headers or bool(EXCLUDED_CONSTANTS.match(name))


def compare_values(label, sdk_values, our_values, sdk_names, report, excluded=frozenset()):
    missing = sorted(name for name in sdk_names if name not in our_values and name in sdk_values and name not in excluded)
    different = sorted(name for name in sdk_values if name in our_values and sdk_values[name] % 2 ** 32 != our_values[name] % 2 ** 32
                       and not KNOWN_DIFFERENCES.match(name))
    report.append("%s: %d compared, %d excluded, %d missing, %d different" % (label, len(sdk_values) - len(excluded), len(excluded), len(missing),
                                                                             len(different)))
    for name in different:
        report.append("  different %s: SDK %d, ours %d" % (name, sdk_values[name], our_values[name]))
    for name in missing:
        report.append("  missing %s" % name)
    return len(missing) + len(different)


def check(clang, reference, version, work, arch, target_arch):
    sdk_include = sdk_folder(reference, version, work)
    target = ARCHITECTURES[target_arch]["target"]
    headers = [header for header in checked_headers(version) if os.path.exists(os.path.join(sdk_include, header))]
    our_headers = [header for header in headers if os.path.exists(os.path.join(ROOT, "include", header))]
    sdk = Side(clang, target, WIN32_WCE[version], [sdk_include], SDK_DEFINES + ARCHITECTURES[arch]["sdk_defines"], headers)
    ours = Side(clang, target, WIN32_WCE[version], [os.path.join(ROOT, "include"), os.path.join(ROOT, "include", "w32api")], ARCHITECTURES[arch]["defines"],
                our_headers)
    label = "" if arch == "mips" else " %s" % arch.upper()
    if target_arch != arch:
        label += " (%s target)" % target_arch
    report = ["CE %s%s, headers: %s" % (VERSION_NAMES[version], label, " ".join(headers))]
    function_exclusions, header_exclusions, type_exclusions = exclusions(version)

    sdk_macros = sdk.macros()
    our_macros = ours.macros()
    candidates = {name: name for name, value in sdk_macros.items() if not name.startswith("_") and "(" not in name}
    sdk_values = sdk.evaluate(candidates)
    our_values = ours.evaluate({name: name for name in sdk_values if name in our_macros or name in candidates})
    where = defining_headers(sdk_include)
    excluded = {name for name in sdk_values if name not in our_values and excluded_constant(name, where.get(name), header_exclusions)}
    problems = compare_values("constants", sdk_values, our_values, sdk_values, report, excluded)

    sdk_tree = sdk.tree()
    sdk_records = records(sdk_tree)
    our_records = records(ours.tree())
    type_where = type_headers(sdk_tree)
    sizes = {}
    excluded_types = set()
    for name, fields in sdk_records.items():
        if name.startswith(("struct ", "union ")) or type_where.get(name) in header_exclusions or type_exclusions.match(name):
            excluded_types.add(name)
            continue
        sizes["size_" + re.sub(r"\W", "_", name)] = "sizeof(%s)" % name
        if isinstance(fields, list):
            for field in fields:
                sizes["offset_%s_%s" % (re.sub(r"\W", "_", name), field)] = "__builtin_offsetof(%s, %s)" % (name, field)
    sdk_sizes = sdk.evaluate(sizes)
    our_sizes = ours.evaluate({key: expression for key, expression in sizes.items() if key in sdk_sizes})
    report.append("types: %d checked by name, %d excluded (tags and excluded areas)" % (len(sdk_records) - len(excluded_types), len(excluded_types)))
    problems += compare_values("layouts", sdk_sizes, our_sizes, sdk_sizes, report)

    exported = exports(version, arch)
    sdk_functions = sorted(node["name"] for node in sdk.tree()["inner"] if node.get("kind") == "FunctionDecl" and node["name"] in exported)
    sdk_signatures, _ = sdk.signatures(sdk_functions)
    excluded = sorted(name for name in sdk_signatures if function_exclusions.match(name))
    our_signatures, unusable = ours.signatures(name for name in sdk_signatures if name not in excluded)
    different = sorted(name for name in our_signatures if name in sdk_signatures and our_signatures[name] != sdk_signatures[name]
                       and our_signatures[name] != sdk_signatures[name].replace("(...)", "()") and not KNOWN_SIGNATURES.match(name))
    undeclared = UNDECLARED_EXPORTS.get(arch)
    known = sorted(name for name in unusable if undeclared and undeclared.match(name))
    unusable = [name for name in unusable if name not in known]
    report.append("functions: %d compared, %d excluded, %d missing or unavailable, %d different" %
                  (len(sdk_signatures) - len(excluded), len(excluded), len(unusable), len(different)))
    for name in different:
        report.append("  different %s: SDK %s, ours %s" % (name, sdk_signatures[name], our_signatures[name]))
    if known:
        report.append("functions exported but not declared by grimace (C runtime, OLE): %d" % len(known))
        report.extend("  undeclared %s" % name for name in known)
    for name in sorted(unusable):
        report.append("  missing %s" % name)
    problems += len(different) + len(unusable)

    sdk_typedefs = typedef_types(sdk_tree)
    loose = Side(clang, target, WIN32_WCE[version], [os.path.join(ROOT, "include"), os.path.join(ROOT, "include", "w32api")],
                 ARCHITECTURES[arch]["defines"] + ["-DNO_STRICT"], our_headers)
    loose_typedefs = typedef_types(loose.tree())
    handles = sorted(name for name, kind in sdk_typedefs.items() if kind == "void *" and name.startswith("H") and name in loose_typedefs and not type_exclusions.match(name))
    different = [name for name in handles if loose_typedefs[name] != "void *"]
    report.append("handles with NO_STRICT: %d compared, %d different" % (len(handles), len(different)))
    for name in different:
        report.append("  different %s: SDK void *, ours %s" % (name, loose_typedefs[name]))
    problems += len(different)

    our_names = macro_names(ours) | declared_names(ours.tree())
    unchecked = sorted(name for name in macro_names(sdk) - set(sdk_values) - our_names
                       if checked_macro_name(name, where.get(name)) and where.get(name) not in header_exclusions and where.get(name) is not None
                       and not EXCLUDED_MACROS.match(name))
    report.append("other macros: %d missing" % len(unchecked))
    for name in unchecked:
        report.append("  missing %s" % name)
    problems += len(unchecked)
    return problems, report


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compare grimace's headers with the Windows CE 1.0, 2.0 and 3.0 SDK headers")
    parser.add_argument("--reference", default=os.environ.get("GRIMACE_REFERENCE"), help="folder with include/ce100, ce101, ce200 and ce300 (the SDKs' headers), default $GRIMACE_REFERENCE")
    parser.add_argument("--clang", default=os.environ.get("CLANG", "clang"))
    parser.add_argument("--ce", choices=["1", "101", "2", "3"], action="append", help="CE versions to check, default those --arch has export lists for")
    parser.add_argument("--arch", choices=sorted(ARCHITECTURES), default="mips", help="SDK defines and export lists to check against")
    parser.add_argument("--target-arch", choices=sorted(ARCHITECTURES), help="compile for this architecture's clang target instead, "
                        "to check the headers with a clang that lacks --arch's backend")
    parser.add_argument("--report", help="write the full report here")
    arguments = parser.parse_args()
    if not arguments.reference:
        sys.exit("check-headers: set GRIMACE_REFERENCE or pass --reference (see tools/fetch-reference)")
    total = 0
    lines = []
    with tempfile.TemporaryDirectory() as work:
        default_versions = DEFAULT_VERSIONS[arguments.arch]
        for version in sorted((int(ce) for ce in (arguments.ce or default_versions)), key=WIN32_WCE.get):
            problems, report = check(arguments.clang, os.path.expanduser(arguments.reference), version, work, arguments.arch,
                                     arguments.target_arch or arguments.arch)
            total += problems
            lines += report
    if arguments.report:
        open(arguments.report, "w").write("\n".join(lines) + "\n")
    print("\n".join(line for line in lines if not line.startswith("  ")))
    sys.exit(1 if total else 0)
