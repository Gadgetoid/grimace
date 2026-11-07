const fs = require('fs');
const path = require('path');

function tokenize(command) {
    const tokens = [];
    let current = '';
    let quote = null;
    let started = false;
    for (let index = 0; index < command.length; index++) {
        const character = command[index];
        if (quote) {
            if (character === quote) {
                quote = null;
            } else if (character === '\\' && quote === '"' && index + 1 < command.length) {
                current += command[++index];
            } else {
                current += character;
            }
        } else if (character === '"' || character === "'") {
            quote = character;
            started = true;
        } else if (character === '\\' && index + 1 < command.length) {
            current += command[++index];
            started = true;
        } else if (/\s/.test(character)) {
            if (started) {
                tokens.push(current);
            }
            current = '';
            started = false;
        } else {
            current += character;
            started = true;
        }
    }
    if (started) {
        tokens.push(current);
    }
    return tokens;
}

function parseCommand(command) {
    const tokens = tokenize(command);
    const compilerIndex = tokens.findIndex((token) => /(^|[\\/])llvm-rc(\.exe)?$/.test(token));
    if (compilerIndex < 0) {
        return null;
    }
    const result = { llvmRc: tokens[compilerIndex], includes: [], defines: [], script: null };
    for (let index = compilerIndex + 1; index < tokens.length; index++) {
        const token = tokens[index];
        if (token === '--') {
            result.script = tokens[index + 1] || null;
            break;
        }
        const option = /^[-/]([IiDd])(.*)$/.exec(token);
        if (!option) {
            continue;
        }
        const value = option[2] || tokens[++index];
        if (value === undefined) {
            continue;
        }
        (option[1].toUpperCase() === 'I' ? result.includes : result.defines).push(value);
    }
    return result.script ? result : null;
}

function buildFiles(root) {
    const files = [];
    const buildFolders = (folder) => {
        try {
            return fs.readdirSync(folder, { withFileTypes: true }).filter((entry) => entry.isDirectory()).map((entry) => path.join(folder, entry.name));
        } catch {
            return [];
        }
    };
    const addFrom = (folder) => {
        files.push(path.join(folder, 'build.ninja'));
        for (const target of buildFolders(path.join(folder, 'CMakeFiles'))) {
            files.push(path.join(target, 'build.make'));
        }
    };
    for (const folder of buildFolders(root).filter((folder) => /^build/i.test(path.basename(folder)))) {
        addFrom(folder);
        for (const nested of buildFolders(folder)) {
            if (!['CMakeFiles', 'Testing', '.cmake'].includes(path.basename(nested))) {
                addFrom(nested);
            }
        }
    }
    return files;
}

function sameFile(first, second) {
    return path.resolve(first).toLowerCase() === path.resolve(second).toLowerCase();
}

function findCommand(root, scriptPath) {
    let best = null;
    for (const file of buildFiles(root)) {
        let text;
        let modified;
        try {
            text = fs.readFileSync(file, 'utf8');
            modified = fs.statSync(file).mtimeMs;
        } catch {
            continue;
        }
        if (!text.includes('llvm-rc')) {
            continue;
        }
        for (const line of text.split(/\r?\n/)) {
            if (!line.includes('llvm-rc')) {
                continue;
            }
            const command = parseCommand(line.replace(/^\s*COMMAND\s*=\s*/, '').replace(/^.*?&&\s*/, ''));
            if (command && sameFile(command.script, scriptPath) && (!best || modified > best.modified)) {
                best = { ...command, source: file, modified };
            }
        }
    }
    return best;
}

module.exports = { tokenize, parseCommand, buildFiles, findCommand };
