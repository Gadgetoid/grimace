const fs = require('fs');
const path = require('path');

const MAX_FILES = 2000;
const parsedFiles = new Map();
const folderListings = new Map();

function decode(bytes) {
    if (bytes[0] === 0xff && bytes[1] === 0xfe) {
        return bytes.subarray(2).toString('utf16le');
    }
    if (bytes[0] === 0xef && bytes[1] === 0xbb && bytes[2] === 0xbf) {
        return bytes.subarray(3).toString('utf8');
    }
    return bytes.toString('latin1');
}

function docBefore(lines, index) {
    let end = index - 1;
    while (end >= 0 && !lines[end].trim()) {
        end--;
    }
    if (end < 0 || !lines[end].trim().endsWith('*/')) {
        return null;
    }
    let start = end;
    while (start >= 0 && !lines[start].includes('/*')) {
        start--;
    }
    if (start < 0 || !lines[start].trim().startsWith('/**')) {
        return null;
    }
    const text = lines.slice(start, end + 1)
        .map((line) => line.trim().replace(/^\/\*\*\s?/, '').replace(/\*\/$/, '').replace(/^\*\s?/, '').trimEnd())
        .join('\n')
        .trim();
    return text || null;
}

function parseText(text) {
    const lines = text.split(/\r?\n/);
    const defines = [];
    const includes = [];
    let inComment = false;
    for (let index = 0; index < lines.length; index++) {
        const line = lines[index];
        if (inComment) {
            if (line.includes('*/')) {
                inComment = false;
            }
            continue;
        }
        const trimmed = line.trim();
        if (trimmed.startsWith('/*') && !trimmed.includes('*/')) {
            inComment = true;
            continue;
        }
        const include = /^(\s*#\s*include(_next)?\s*)([<"])([^>"]+)[>"]/.exec(line);
        if (include) {
            const start = include[1].length + 1;
            includes.push({ name: include[4], quoted: include[3] === '"', next: Boolean(include[2]), line: index, start, end: start + include[4].length });
            continue;
        }
        const define = /^\s*#\s*define\s+([A-Za-z_]\w*)(\([^)]*\))?(.*)$/.exec(line);
        if (!define) {
            continue;
        }
        let value = define[3];
        let last = index;
        while (value.trimEnd().endsWith('\\') && last + 1 < lines.length) {
            value = value.trimEnd().slice(0, -1) + ' ' + lines[++last].trim();
        }
        const comment = /\/\/\s*(.*)$/.exec(value);
        value = value.replace(/\/\/.*$/, '').replace(/\/\*.*?\*\//g, '').replace(/\s+/g, ' ').trim();
        const nameStart = line.indexOf(define[1], line.indexOf('define') + 6);
        defines.push({
            name: define[1],
            parameters: define[2] || '',
            value,
            line: index,
            start: nameStart,
            end: nameStart + define[1].length,
            doc: docBefore(lines, index) || (comment ? comment[1].trim() : null),
        });
        index = last;
    }
    return { defines, includes };
}

function parseFile(filePath) {
    let stat;
    try {
        stat = fs.statSync(filePath);
    } catch {
        return null;
    }
    const cached = parsedFiles.get(filePath);
    if (cached && cached.modified === stat.mtimeMs) {
        return cached.parsed;
    }
    const parsed = parseText(decode(fs.readFileSync(filePath)));
    parsedFiles.set(filePath, { modified: stat.mtimeMs, parsed });
    return parsed;
}

function listing(folder) {
    if (!folderListings.has(folder)) {
        try {
            folderListings.set(folder, fs.readdirSync(folder));
        } catch {
            folderListings.set(folder, []);
        }
    }
    return folderListings.get(folder);
}

function findIn(folder, name) {
    const direct = path.join(folder, name);
    if (fs.existsSync(direct)) {
        return direct;
    }
    if (name.includes('/') || name.includes('\\')) {
        return null;
    }
    const match = listing(folder).find((entry) => entry.toLowerCase() === name.toLowerCase());
    return match ? path.join(folder, match) : null;
}

function resolveInclude(name, quoted, fromFolder, includePaths, next = false) {
    let folders = quoted ? [fromFolder, ...includePaths] : includePaths;
    if (next) {
        const position = includePaths.findIndex((folder) => path.resolve(folder) === path.resolve(fromFolder));
        folders = includePaths.slice(position + 1);
    }
    for (const folder of folders) {
        const found = findIn(folder, name);
        if (found) {
            return found;
        }
    }
    return null;
}

function index(scriptPath, text, includePaths) {
    const symbols = new Map();
    const own = parseText(text);
    const folder = path.dirname(scriptPath);
    const add = (defines, file) => {
        for (const define of defines) {
            if (!symbols.has(define.name)) {
                symbols.set(define.name, { ...define, file });
            }
        }
    };
    add(own.defines, scriptPath);
    const links = own.includes.map((include) => ({ ...include, target: resolveInclude(include.name, include.quoted, folder, includePaths) }));
    const queue = links.map((link) => link.target).filter(Boolean);
    const seen = new Set(queue);
    while (queue.length && seen.size <= MAX_FILES) {
        const file = queue.shift();
        const parsed = parseFile(file);
        if (!parsed) {
            continue;
        }
        add(parsed.defines, file);
        for (const include of parsed.includes) {
            const target = resolveInclude(include.name, include.quoted, path.dirname(file), includePaths, include.next);
            if (target && !seen.has(target)) {
                seen.add(target);
                queue.push(target);
            }
        }
    }
    return { symbols, includes: links, files: seen.size };
}

function evaluate(name, symbols, depth = 0) {
    if (/^\d+$/.test(name)) {
        return Number(name);
    }
    if (/^0x[0-9a-f]+$/i.test(name)) {
        return parseInt(name, 16);
    }
    const symbol = symbols.get(name);
    if (!symbol || symbol.parameters || depth > 8) {
        return null;
    }
    const value = symbol.value.replace(/^\((.*)\)$/, '$1').replace(/^\((?:WORD|DWORD|UINT|int)\)\s*/i, '').replace(/[uUlL]+$/, '').trim();
    return evaluate(value, symbols, depth + 1);
}

function clearCaches() {
    parsedFiles.clear();
    folderListings.clear();
}

module.exports = { decode, parseText, resolveInclude, index, evaluate, clearCaches };
