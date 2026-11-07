const path = require('path');
const { evaluate } = require('./symbols');

function codeLines(lines) {
    const result = [];
    let inComment = false;
    lines.forEach((line, index) => {
        let code = line;
        if (inComment) {
            if (!code.includes('*/')) {
                return;
            }
            code = code.slice(code.indexOf('*/') + 2);
            inComment = false;
        }
        code = code.replace(/\/\*.*?\*\//g, '').replace(/\/\/.*$/, '');
        if (code.includes('/*')) {
            code = code.slice(0, code.indexOf('/*'));
            inComment = true;
        }
        if (code.trim() && !code.trim().startsWith('#')) {
            result.push({ index, code });
        }
    });
    return result;
}

function wholeLine(lines, index) {
    const line = lines[index] || '';
    const start = line.length - line.trimStart().length;
    return { line: index, start, end: Math.max(line.trimEnd().length, start + 1) };
}

function findQuoted(lines, text) {
    const needle = `"${text}"`;
    for (const { index, code } of codeLines(lines)) {
        const column = code.toLowerCase().indexOf(needle.toLowerCase());
        if (column >= 0) {
            return { line: index, start: column + 1, end: column + 1 + text.length };
        }
    }
    return null;
}

function findWord(lines, word) {
    const pattern = new RegExp(`(^|[^\\w])(${word.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')})(?![\\w])`);
    for (const { index, code } of codeLines(lines)) {
        const match = pattern.exec(code);
        if (match) {
            const start = match.index + match[1].length;
            return { line: index, start, end: start + word.length };
        }
    }
    return null;
}

function findStatement(lines, type, id, symbols) {
    const pattern = new RegExp(`^\\s*("[^"]*"|\\S+)\\s+${type}\\b`, 'i');
    let first = null;
    for (const { index, code } of codeLines(lines)) {
        const match = pattern.exec(code);
        if (!match) {
            continue;
        }
        const name = match[1].replace(/^"|"$/g, '');
        const location = { line: index, start: code.indexOf(match[1]), end: code.indexOf(match[1]) + match[1].length };
        first = first || location;
        if (id === undefined || name.toUpperCase() === String(id).toUpperCase() || (symbols && evaluate(name, symbols) === Number(id))) {
            return location;
        }
    }
    if (first) {
        return first;
    }
    const keyword = codeLines(lines).find(({ code }) => new RegExp(`\\b${type}\\b`, 'i').test(code));
    return keyword ? wholeLine(lines, keyword.index) : null;
}

function parse(output, scriptPath, lines, symbols) {
    const diagnostics = [];
    const outputLines = output.split(/\r?\n/);
    const script = path.resolve(scriptPath).toLowerCase();
    const firstLine = () => wholeLine(lines, 0);
    for (let index = 0; index < outputLines.length; index++) {
        const text = outputLines[index];
        const located = /^(.*?):(\d+):(\d+): (fatal error|error|warning): (.*)$/.exec(text);
        if (located) {
            const severity = located[4] === 'warning' ? 'warning' : 'error';
            if (path.resolve(located[1]).toLowerCase() === script) {
                const line = Number(located[2]) - 1;
                const column = Number(located[3]) - 1;
                const word = /^(<[^>]*>|"[^"]*"|\w+)/.exec((lines[line] || '').slice(column));
                diagnostics.push({ line, start: column, end: column + (word ? word[0].length : 1), severity, message: located[5] });
            } else {
                diagnostics.push({ ...firstLine(), severity, message: `${located[1]}:${located[2]}: ${located[5]}` });
            }
            continue;
        }
        const statement = /^llvm-rc: Error in (\w+) statement(?: \(ID ([^)]+)\))?:\s*(.*)$/.exec(text);
        if (statement) {
            const details = [statement[3]].filter(Boolean);
            while (index + 1 < outputLines.length && /^\s*error\s*:/i.test(outputLines[index + 1])) {
                details.push(outputLines[++index].replace(/^\s*error\s*:\s*/i, '').trim());
            }
            const message = `${statement[1]}${statement[2] ? ` ${statement[2]}` : ''}: ${details.join(' ').replace(/\s+:\s+/g, ': ')}`;
            const missing = /file not found\s*:\s*(.+)$/i.exec(details.join(' '));
            const location = (missing && findQuoted(lines, missing[1].trim())) || findStatement(lines, statement[1], statement[2], symbols) || firstLine();
            diagnostics.push({ ...location, severity: 'error', message });
            continue;
        }
        const parsing = /^llvm-rc: Error parsing file: (.*)$/.exec(text);
        if (parsing) {
            const token = /got (\S+)\s*$/.exec(parsing[1]);
            const location = (token && findWord(lines, token[1].replace(/^"|"$/g, ''))) || firstLine();
            diagnostics.push({ ...location, severity: 'error', message: parsing[1] });
            continue;
        }
        const other = /^llvm-rc: (.*)$/.exec(text);
        if (other && !/^Preprocessing failed/i.test(other[1])) {
            diagnostics.push({ ...firstLine(), severity: 'error', message: other[1] });
        }
    }
    return diagnostics;
}

module.exports = { parse, findStatement, findWord, findQuoted };
