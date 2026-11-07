r"""Write docs/api/sdk from the Windows CE SDK reference's help pages.

Reads the HTML pages of the SDK reference (wcesdkr.chm, unpacked with 7zz or
7z, or a folder already unpacked) and writes an entry in the docs/api format
for each function, macro, message or structure the headers declare that has no
entry in docs/api yet. mkdocs.py then writes them into the headers with the
hand-written ones, which take precedence.

    python3 tools/mksdkdocs.py wcesdkr.chm

Entries go in docs/api/sdk/<header>.txt, named after the header that declares
them. Structures list their members as @member lines, which mkdocs.py writes
above each member."""
import argparse
import glob
import html
import os
import re
import shutil
import subprocess
import sys
import tempfile
import textwrap
import unicodedata

import mkdocs
import mkheaders

ROOT = mkheaders.ROOT
WIDTH = 72
CONTINUATION = "       "
SECTION_PARAMETERS = ("Parameters",)
SECTION_MEMBERS = ("Members",)
SECTION_RETURNS = ("Return Values", "Return Value")
SECTION_REMARKS = ("Remarks",)
ASCII_REPLACEMENTS = {
    "‘": "'", "’": "'", "“": '"', "”": '"', "–": "-", "—": "-",
    "…": "...", " ": " ", "®": "(R)", "©": "(c)", "™": "(TM)", "°": " degrees",
    "×": "x", "•": "-",
}


def ascii_text(text):
    for original, replacement in ASCII_REPLACEMENTS.items():
        text = text.replace(original, replacement)
    text = unicodedata.normalize("NFKD", text).encode("ascii", "ignore").decode("ascii")
    return text.replace("/*", "/ *").replace("*/", "* /")


def plain(fragment):
    fragment = re.sub(r"<br\s*/?>", " ", fragment, flags=re.I)
    fragment = re.sub(r"<[^>]+>", "", fragment)
    return re.sub(r"\s+", " ", ascii_text(html.unescape(fragment))).strip()


def definition_list(fragment):
    tokens = re.split(r"(<dl[^>]*>|</dl>|<dt[^>]*>|<dd[^>]*>)", fragment, flags=re.I)
    pairs = []
    depth = 0
    current = None
    for token in tokens:
        lower = token.lower()
        if lower.startswith("<dl"):
            depth += 1
            if depth > 1 and current is not None:
                current.append(token)
            continue
        if lower == "</dl>":
            depth -= 1
            if depth >= 1 and current is not None:
                current.append(token)
            continue
        if depth == 1 and lower.startswith("<dt"):
            current = []
            pairs.append([current, []])
            continue
        if depth == 1 and lower.startswith("<dd"):
            if pairs:
                current = pairs[-1][1]
            continue
        if current is not None:
            current.append(token)
    return [(plain("".join(name)), "".join(description)) for name, description in pairs]


def preformatted(fragment):
    fragment = re.sub(r"<br\s*/?>", "\n", fragment, flags=re.I)
    fragment = re.sub(r"<[^>]+>", "", fragment)
    lines = [line.rstrip() for line in ascii_text(html.unescape(fragment)).replace("\t", "    ").splitlines()]
    while lines and not lines[0]:
        lines.pop(0)
    while lines and not lines[-1]:
        lines.pop()
    return lines


def paragraphs(fragment):
    parts = []
    for piece in re.split(r"(<pre[^>]*>.*?</pre>|<dl[^>]*>.*</dl>)", fragment, flags=re.I | re.S):
        lower = piece[:4].lower()
        if lower.startswith("<pre"):
            code = preformatted(piece)
            if code:
                parts.append(code)
            continue
        if lower.startswith("<dl"):
            for term, description in definition_list(piece):
                text = " ".join(item for item in paragraphs(description) if isinstance(item, str))
                parts.append(f"{term}: {text}" if text else term)
        else:
            for paragraph in re.split(r"<p[^>]*>|</p>|<li[^>]*>", piece, flags=re.I):
                text = plain(paragraph)
                if text:
                    parts.append(text)
    return parts


def parse_page(path):
    source = open(path, encoding="cp1252", errors="replace").read()
    heading = re.search(r"<h2[^>]*>(.*?)</h2>", source, re.I | re.S)
    if not heading:
        return None
    body = re.split(r"</body>", source[heading.end():], flags=re.I)[0]
    sections = re.split(r"<h4[^>]*>(.*?)</h4>", body, flags=re.I | re.S)
    page = {"title": plain(heading.group(1)), "summary": [item for item in paragraphs(sections[0]) if isinstance(item, str)][:1], "parameters": [], "members": [], "returns": [], "remarks": []}
    for index in range(1, len(sections) - 1, 2):
        name = plain(sections[index])
        content = sections[index + 1]
        if name in SECTION_PARAMETERS or name in SECTION_MEMBERS:
            dl = re.search(r"<dl[^>]*>.*</dl>", content, re.I | re.S)
            entries = [(term, " ".join(item for item in paragraphs(description) if isinstance(item, str))) for term, description in (definition_list(dl.group(0)) if dl else [])]
            page["parameters" if name in SECTION_PARAMETERS else "members"] = entries
        elif name in SECTION_RETURNS:
            page["returns"] = paragraphs(content)
        elif name in SECTION_REMARKS:
            page["remarks"] = paragraphs(content)
    return page


def unpack(path, scratch):
    if os.path.isdir(path):
        return path
    tool = shutil.which("7zz") or shutil.which("7z")
    if not tool:
        sys.exit("mksdkdocs: unpacking a .chm needs 7zz or 7z")
    folder = os.path.join(scratch, "help")
    subprocess.run([tool, "x", "-y", f"-o{folder}", path], check=True, stdout=subprocess.DEVNULL)
    return folder


def load_pages(folder):
    pages = {}
    for root, _, files in os.walk(folder):
        for name in sorted(files):
            if name.lower().endswith((".htm", ".html")):
                page = parse_page(os.path.join(root, name))
                if page and page["summary"] and re.fullmatch(r"\w+", page["title"]):
                    pages.setdefault(page["title"], page)
    return pages


def wrapped(text, first="", rest=""):
    return textwrap.wrap(first + text, WIDTH, subsequent_indent=rest, break_long_words=False, break_on_hyphens=False)


def hand_written():
    names = set()
    for path in glob.glob(os.path.join(ROOT, "docs", "api", "*.txt")):
        names |= set(re.findall(r"^## (\w+)", open(path, encoding="utf-8").read(), re.M))
    return names


def struct_declared(text, name):
    return re.search(r"\}\s*(?:[*\w]+\s*,\s*)*%s\s*[,;]" % re.escape(name), text) is not None


def define_declared(text, name):
    return re.search(r"^[ \t]*#[ \t]*define[ \t]+%s\b" % re.escape(name), text, re.M) is not None


def function_declared(text, name):
    return mkdocs.declaration(text, name) is not None


def declaring_header(texts, page):
    name = page["title"]
    for path, text in texts.items():
        if page["members"] and struct_declared(text, name):
            return path, "struct"
    for path, text in texts.items():
        if function_declared(text, name):
            return path, "function"
    for path, text in texts.items():
        if define_declared(text, name):
            return path, "define"
    return None, None


def entry(page, kind):
    name = page["title"]
    parameters = [term for term, _ in page["parameters"] if re.fullmatch(r"\w+", term)]
    function_like = kind == "function" or (kind == "define" and parameters and not name.isupper())
    heading = f"## {name}({', '.join(parameters)})" if function_like and len(parameters) == len(page["parameters"]) else f"## {name}"
    lines = [heading] + wrapped(page["summary"][0])
    if page["remarks"]:
        for paragraph in page["remarks"]:
            lines += [""] + (["    " + line if line else "" for line in paragraph] if isinstance(paragraph, list) else wrapped(paragraph))
    tags = []
    if kind == "struct":
        for term, description in page["members"]:
            if re.fullmatch(r"\w+", term):
                tags += wrapped(description, f"@member {term} ", CONTINUATION)
    else:
        for term, description in page["parameters"]:
            tags += wrapped(description, f"@param {term} ", CONTINUATION)
        if page["returns"]:
            tags += wrapped(" ".join(item for item in page["returns"] if isinstance(item, str)), "@return ", CONTINUATION)
    if tags:
        lines += [""] + tags
    return lines


def main():
    parser = argparse.ArgumentParser(description="Write docs/api/sdk from the Windows CE SDK reference's help pages")
    parser.add_argument("help", help="wcesdkr.chm, or a folder of its unpacked pages")
    arguments = parser.parse_args()

    with tempfile.TemporaryDirectory() as scratch:
        pages = load_pages(unpack(arguments.help, scratch))
    texts = {path: open(path, errors="replace").read() for path in mkheaders.header_paths()}
    written = set(hand_written())
    files = {}
    for name in sorted(pages):
        if name in written or name + "W" in written or name in mkheaders.ENTRY_POINTS:
            continue
        page = pages[name]
        if not (page["parameters"] or page["members"] or page["returns"]):
            continue
        path, kind = declaring_header(texts, page)
        if not path:
            continue
        header = os.path.splitext(os.path.basename(path))[0]
        files.setdefault(header, []).append(entry(page, kind))
    folder = os.path.join(ROOT, "docs", "api", "sdk")
    os.makedirs(folder, exist_ok=True)
    for old in glob.glob(os.path.join(folder, "*.txt")):
        os.remove(old)
    for header, entries in sorted(files.items()):
        with open(os.path.join(folder, header + ".txt"), "w", encoding="utf-8") as output:
            output.write("\n\n".join("\n".join(lines) for lines in entries) + "\n")
    print("mksdkdocs: %d entries in %d files" % (sum(len(entries) for entries in files.values()), len(files)))


if __name__ == "__main__":
    main()
