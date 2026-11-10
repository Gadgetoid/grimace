"""
Export lists in exports/<name>/: one <dll>.txt per DLL, a name per line, and a MANIFEST saying what they came from.

A target is an architecture and a minimum Windows CE version, optionally narrowed to a platform or pinned to a device.
Pinned to a device, it imports exactly what that device's list at that version exports. Otherwise it may run on any
device of a platform with a list at that version, whose list is at that version or later, so it imports directly only
what all of those export, and gets lazy imports, bound when first called, for what only some of them export.
"""
import argparse
import functools
import glob
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXPORTS = os.path.join(ROOT, "exports")
WIN32_WCE = {"1": 100, "1.01": 101, "2": 200, "3": 300, "6": 600}
VERSION_NAMES = {100: "1.0", 101: "1.01", 200: "2.0", 300: "3.0", 600: "6.0"}


class Manifest:
    def __init__(self, folder):
        self.folder = folder
        self.name = os.path.basename(folder)
        fields = {}
        for line in open(os.path.join(folder, "MANIFEST")):
            key, _, value = line.partition(":")
            fields[key.strip()] = value.strip()
        self.arch = fields["arch"]
        self.version = WIN32_WCE[fields["version"]]
        self.platform = fields["platform"]
        self.devices = fields.get("device", "").split()
        self.source = fields.get("source", "")
        self._dlls = None

    def dlls(self):
        if self._dlls is None:
            self._dlls = {}
            for path in sorted(glob.glob(os.path.join(self.folder, "*.txt"))):
                dll = os.path.splitext(os.path.basename(path))[0]
                self._dlls[dll] = {line.strip() for line in open(path) if line.strip()}
        return self._dlls

    def names(self):
        return set().union(*self.dlls().values()) if self.dlls() else set()


class Target:
    def __init__(self, arch, version, platform=None, device=None):
        self.arch = arch
        self.version = version
        self.platform = platform
        self.device = device

    def label(self):
        text = "%s CE %s" % (self.arch, VERSION_NAMES[self.version])
        if self.device:
            text += " on %s" % self.device
        elif self.platform:
            text += " %s" % self.platform
        return text

    def condition(self):
        terms = ["GRIMACE_WCE == %d" % self.version, "GRIMACE_%s" % self.arch.upper()]
        if self.device:
            terms.append("defined(GRIMACE_DEVICE_%s)" % self.device.upper())
        else:
            terms.append("!defined(GRIMACE_DEVICE)")
            if self.platform:
                terms.append("defined(GRIMACE_PLATFORM_%s)" % self.platform.upper())
            elif len(platforms(self.arch)) > 1:
                terms.append("!defined(GRIMACE_PLATFORM)")
        return " && ".join(terms)


@functools.cache
def manifests():
    return tuple(Manifest(os.path.dirname(path)) for path in sorted(glob.glob(os.path.join(EXPORTS, "*", "MANIFEST"))))


def platforms(arch):
    return sorted({manifest.platform for manifest in manifests() if manifest.arch == arch})


def reachable(target):
    """The lists a program built for target may meet: those at its version or later, of the platforms with a list at its
    version (or the one chosen), or the pinned device's at its version."""
    found = [manifest for manifest in manifests() if manifest.arch == target.arch]
    if target.device:
        found = [manifest for manifest in found if target.device in manifest.devices and manifest.version == target.version]
        if not found:
            raise LookupError("no export list for %s" % target.label())
        return found
    if target.platform:
        found = [manifest for manifest in found if manifest.platform == target.platform]
    platforms_at_version = {manifest.platform for manifest in found if manifest.version == target.version}
    if not platforms_at_version:
        raise LookupError("no export list for %s" % target.label())
    return [manifest for manifest in found if manifest.version >= target.version and manifest.platform in platforms_at_version]


def imports(target):
    """{dll: (direct, lazy)} for target: direct names every reachable list exports, lazy ones only some do."""
    lists = reachable(target)
    dlls = sorted(set().union(*(manifest.dlls().keys() for manifest in lists)))
    result = {}
    for dll in dlls:
        exported = [manifest.dlls().get(dll, set()) for manifest in lists]
        direct = set.intersection(*exported)
        lazy = set.union(*exported) - direct
        result[dll] = (direct, lazy)
    return result


def targets():
    """Every target the headers distinguish: each architecture and version with a list, plus each platform and device."""
    found = []
    for manifest in sorted(manifests(), key=lambda manifest: (manifest.arch, manifest.version)):
        generic = Target(manifest.arch, manifest.version)
        if not any(target.condition() == generic.condition() for target in found):
            found.append(generic)
            if len(platforms(manifest.arch)) > 1:
                for platform in sorted({other.platform for other in manifests() if other.arch == manifest.arch and other.version == manifest.version}):
                    found.append(Target(manifest.arch, manifest.version, platform=platform))
    for manifest in manifests():
        for device in manifest.devices:
            found.append(Target(manifest.arch, manifest.version, device=device))
    return found


def exported_at(arch, version):
    """Every name any list for arch at exactly version exports."""
    names = set()
    for manifest in manifests():
        if manifest.arch == arch and manifest.version == version:
            names |= manifest.names()
    return names


def write_imports(target, output):
    os.makedirs(output, exist_ok=True)
    for path in glob.glob(os.path.join(output, "*.txt")):
        os.remove(path)
    for dll, (direct, lazy) in imports(target).items():
        with open(os.path.join(output, dll + ".txt"), "w") as listing:
            listing.writelines(name + "\n" for name in sorted(direct))
        with open(os.path.join(output, dll + ".lazy"), "w") as listing:
            listing.writelines(name + "\n" for name in sorted(lazy))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="List the export lists, or write a target's direct and lazy imports per DLL")
    parser.add_argument("--arch")
    parser.add_argument("--version", choices=sorted(WIN32_WCE))
    parser.add_argument("--platform")
    parser.add_argument("--device")
    parser.add_argument("--output", help="write <dll>.txt (direct imports) and <dll>.lazy (lazy imports) here")
    arguments = parser.parse_args()
    if not arguments.arch:
        for manifest in manifests():
            print("%-16s %-5s CE %-5s %-8s %-11s %5d names  %s" % (manifest.name, manifest.arch, VERSION_NAMES[manifest.version], manifest.platform,
                                                                   " ".join(manifest.devices) or "-", len(manifest.names()), manifest.source))
        sys.exit(0)
    target = Target(arguments.arch, WIN32_WCE[arguments.version], arguments.platform or None, arguments.device or None)
    try:
        found = imports(target)
    except LookupError as error:
        sys.exit("manifests: %s" % error)
    if arguments.output:
        write_imports(target, arguments.output)
    direct = sum(len(names[0]) for names in found.values())
    lazy = sum(len(names[1]) for names in found.values())
    print("%s: %d direct and %d lazy imports from %s" % (target.label(), direct, lazy, ", ".join(manifest.name for manifest in reachable(target))))
