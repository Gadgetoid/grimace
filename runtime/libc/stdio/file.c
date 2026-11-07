#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "../internal.h"

void *CreateFileW(const grimace_wchar *path, unsigned long access, unsigned long share, void *security, unsigned long disposition, unsigned long attributes,
                  void *template_file);
int ReadFile(void *handle, void *buffer, unsigned long size, unsigned long *read, void *overlapped);
int WriteFile(void *handle, const void *buffer, unsigned long size, unsigned long *written, void *overlapped);
int CloseHandle(void *handle);
unsigned long SetFilePointer(void *handle, long distance, long *high, unsigned long method);
int FlushFileBuffers(void *handle);
void OutputDebugStringW(const grimace_wchar *text);

#define INVALID_HANDLE ((void *)-1)
#define GENERIC_READ 0x80000000ul
#define GENERIC_WRITE 0x40000000ul
#define FILE_SHARE_READ 1
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define OPEN_ALWAYS 4
#define FILE_ATTRIBUTE_NORMAL 0x80
#define FILE_BEGIN 0
#define FILE_CURRENT 1
#define FILE_END 2
#define BUFFER_SIZE 512
#define DEBUG_SIZE 128
#define TEXT_MODE 0x4000
#define BINARY_MODE 0x8000

enum { IDLE, READING, WRITING };

struct stream {
    void *handle;
    int readable;
    int writable;
    int append;
    int debug;
    int text;
    int error;
    int eof;
    int state;
    int unget_count;
    unsigned char unget[2];
    size_t position;
    size_t length;
    unsigned char buffer[BUFFER_SIZE];
    grimace_wchar debug_text[DEBUG_SIZE];
    size_t debug_length;
    struct stream *next;
};

static struct stream standard[3] = {
    {INVALID_HANDLE, 1, 0, 0, 0, 0, 0, 1, IDLE, 0, {0}, 0, 0, {0}, {0}, 0, 0},
    {INVALID_HANDLE, 0, 1, 0, 1, 0, 0, 0, IDLE, 0, {0}, 0, 0, {0}, {0}, 0, 0},
    {INVALID_HANDLE, 0, 1, 0, 1, 0, 0, 0, IDLE, 0, {0}, 0, 0, {0}, {0}, 0, 0},
};
static struct stream *opened;

FILE *_getstdfilex(int index) {
    return index >= 0 && index < 3 ? (FILE *)&standard[index] : NULL;
}

static void flush_debug(struct stream *stream) {
    if (stream->debug_length) {
        stream->debug_text[stream->debug_length] = 0;
        OutputDebugStringW(stream->debug_text);
        stream->debug_length = 0;
    }
}

static int flush_writes(struct stream *stream) {
    if (stream->debug) {
        flush_debug(stream);
        return 0;
    }
    if (stream->state == WRITING && stream->length) {
        unsigned long written = 0;
        if (stream->append) {
            SetFilePointer(stream->handle, 0, NULL, FILE_END);
        }
        if (!WriteFile(stream->handle, stream->buffer, (unsigned long)stream->length, &written, NULL) || written != stream->length) {
            stream->error = 1;
            stream->length = 0;
            return EOF;
        }
    }
    if (stream->state == READING && stream->position < stream->length) {
        SetFilePointer(stream->handle, -(long)(stream->length - stream->position), NULL, FILE_CURRENT);
    }
    stream->position = 0;
    stream->length = 0;
    stream->unget_count = 0;
    stream->state = IDLE;
    return 0;
}

static int put_byte(struct stream *stream, unsigned char value) {
    if (!stream->writable) {
        stream->error = 1;
        return EOF;
    }
    if (stream->state == READING) {
        flush_writes(stream);
    }
    stream->state = WRITING;
    stream->buffer[stream->length++] = value;
    if (stream->length == BUFFER_SIZE && flush_writes(stream)) {
        return EOF;
    }
    return value;
}

static int put_raw(struct stream *stream, unsigned unit, int wide) {
    if (!wide) {
        return put_byte(stream, (unsigned char)(unit < 256 ? unit : '?'));
    }
    if (put_byte(stream, (unsigned char)unit) == EOF || put_byte(stream, (unsigned char)(unit >> 8)) == EOF) {
        return EOF;
    }
    return (int)unit;
}

static int put_unit(struct stream *stream, unsigned unit, int wide) {
    if (stream->debug) {
        stream->debug_text[stream->debug_length++] = (grimace_wchar)(wide ? unit : unit & 0xFF);
        if (unit == '\n' || stream->debug_length == DEBUG_SIZE - 1) {
            flush_debug(stream);
        }
        return (int)unit;
    }
    if (stream->text && unit == '\n' && put_raw(stream, '\r', wide) == EOF) {
        return EOF;
    }
    return put_raw(stream, unit, wide);
}

static int get_byte(struct stream *stream) {
    if (stream->unget_count) {
        return stream->unget[--stream->unget_count];
    }
    if (!stream->readable || stream->debug || stream->handle == INVALID_HANDLE) {
        stream->eof = 1;
        return EOF;
    }
    if (stream->state == WRITING) {
        flush_writes(stream);
    }
    if (stream->state != READING || stream->position == stream->length) {
        unsigned long read = 0;
        if (!ReadFile(stream->handle, stream->buffer, BUFFER_SIZE, &read, NULL)) {
            stream->error = 1;
            return EOF;
        }
        stream->state = READING;
        stream->position = 0;
        stream->length = read;
        if (!read) {
            stream->eof = 1;
            return EOF;
        }
    }
    return stream->buffer[stream->position++];
}

static int get_raw(struct stream *stream, int wide) {
    int low = get_byte(stream);
    if (!wide || low == EOF) {
        return low;
    }
    int high = get_byte(stream);
    return high == EOF ? EOF : low | high << 8;
}

static int unget_unit(struct stream *stream, int unit, int wide);

static int get_unit(struct stream *stream, int wide) {
    int unit = get_raw(stream, wide);
    if (stream->text && unit == '\r') {
        int next = get_raw(stream, wide);
        if (next == '\n') {
            return next;
        }
        if (next != EOF) {
            unget_unit(stream, next, wide);
        }
    }
    return unit;
}

static int unget_unit(struct stream *stream, int unit, int wide) {
    if (unit == EOF || stream->unget_count + (wide ? 2 : 1) > 2) {
        return EOF;
    }
    if (wide) {
        stream->unget[stream->unget_count++] = (unsigned char)(unit >> 8);
    }
    stream->unget[stream->unget_count++] = (unsigned char)unit;
    stream->eof = 0;
    return unit;
}

static FILE *open_handle(void *handle, int readable, int writable, int append, int text) {
    struct stream *stream = calloc(1, sizeof *stream);
    if (!stream) {
        CloseHandle(handle);
        return NULL;
    }
    stream->handle = handle;
    stream->readable = readable;
    stream->writable = writable;
    stream->append = append;
    stream->text = text;
    stream->next = opened;
    opened = stream;
    return (FILE *)stream;
}

static int parse_mode(const grimace_wchar *mode, int *readable, int *writable, int *append, int *text, unsigned long *disposition) {
    int plus = 0;
    *text = 1;
    for (const grimace_wchar *at = mode + 1; *at; at++) {
        plus |= *at == '+';
        if (*at == 'b') {
            *text = 0;
        }
    }
    *append = mode[0] == 'a';
    if (mode[0] == 'r') {
        *readable = 1;
        *writable = plus;
        *disposition = OPEN_EXISTING;
    } else if (mode[0] == 'w') {
        *readable = plus;
        *writable = 1;
        *disposition = CREATE_ALWAYS;
    } else if (mode[0] == 'a') {
        *readable = plus;
        *writable = 1;
        *disposition = OPEN_ALWAYS;
    } else {
        return 0;
    }
    return 1;
}

FILE *_wfopen(const wchar_t *path, const wchar_t *mode) {
    int readable;
    int writable;
    int append;
    int text;
    unsigned long disposition;
    if (!parse_mode(mode, &readable, &writable, &append, &text, &disposition)) {
        return NULL;
    }
    void *handle = CreateFileW(path, (readable ? GENERIC_READ : 0) | (writable ? GENERIC_WRITE : 0), FILE_SHARE_READ, NULL, disposition,
                               FILE_ATTRIBUTE_NORMAL, NULL);
    if (handle == INVALID_HANDLE) {
        return NULL;
    }
    return open_handle(handle, readable, writable, append, text);
}

static void widen(const char *text, grimace_wchar *output, size_t capacity) {
    size_t length = 0;
    while (text[length] && length + 1 < capacity) {
        output[length] = (unsigned char)text[length];
        length++;
    }
    output[length] = 0;
}

FILE *fopen(const char *path, const char *mode) {
    grimace_wchar wide_path[260];
    grimace_wchar wide_mode[8];
    widen(path, wide_path, 260);
    widen(mode, wide_mode, 8);
    return _wfopen(wide_path, wide_mode);
}

FILE *_wfdopen(void *handle, const wchar_t *mode) {
    int readable;
    int writable;
    int append;
    int text;
    unsigned long disposition;
    if (!parse_mode(mode, &readable, &writable, &append, &text, &disposition)) {
        return NULL;
    }
    return open_handle(handle, readable, writable, append, text);
}

int fclose(FILE *file) {
    struct stream *stream = (struct stream *)file;
    int result = fflush(file);
    if (stream >= standard && stream < standard + 3) {
        return result;
    }
    for (struct stream **link = &opened; *link; link = &(*link)->next) {
        if (*link == stream) {
            *link = stream->next;
            break;
        }
    }
    if (!CloseHandle(stream->handle)) {
        result = EOF;
    }
    free(stream);
    return result;
}

FILE *_wfreopen(const wchar_t *path, const wchar_t *mode, FILE *file) {
    fclose(file);
    return _wfopen(path, mode);
}

int _fcloseall(void) {
    int count = 0;
    while (opened) {
        fclose((FILE *)opened);
        count++;
    }
    return count;
}

int fflush(FILE *file) {
    if (!file) {
        return _flushall() < 0 ? EOF : 0;
    }
    struct stream *stream = (struct stream *)file;
    int result = flush_writes(stream);
    if (!result && stream->handle != INVALID_HANDLE && stream->writable) {
        FlushFileBuffers(stream->handle);
    }
    return result;
}

int _flushall(void) {
    int count = 0;
    for (int index = 1; index < 3; index++) {
        flush_writes(&standard[index]);
    }
    for (struct stream *stream = opened; stream; stream = stream->next) {
        flush_writes(stream);
        count++;
    }
    return count;
}

size_t fread(void *buffer, size_t size, size_t count, FILE *file) {
    struct stream *stream = (struct stream *)file;
    unsigned char *output = buffer;
    size_t total = size * count;
    size_t done = 0;
    while (done < total) {
        int value = get_unit(stream, 0);
        if (value == EOF) {
            break;
        }
        output[done++] = (unsigned char)value;
    }
    return size ? done / size : 0;
}

size_t fwrite(const void *buffer, size_t size, size_t count, FILE *file) {
    struct stream *stream = (struct stream *)file;
    const unsigned char *input = buffer;
    size_t total = size * count;
    size_t done = 0;
    while (done < total && put_unit(stream, input[done], 0) != EOF) {
        done++;
    }
    return size ? done / size : 0;
}

int fgetc(FILE *file) {
    return get_unit((struct stream *)file, 0);
}

wint_t fgetwc(FILE *file) {
    int unit = get_unit((struct stream *)file, 1);
    return unit == EOF ? WEOF : (wint_t)unit;
}

int fputc(int character, FILE *file) {
    return put_unit((struct stream *)file, (unsigned char)character, 0);
}

wint_t fputwc(wint_t character, FILE *file) {
    return put_unit((struct stream *)file, character, 1) == EOF ? WEOF : character;
}

int ungetc(int character, FILE *file) {
    return unget_unit((struct stream *)file, character, 0);
}

wint_t ungetwc(wint_t character, FILE *file) {
    return character == WEOF || unget_unit((struct stream *)file, character, 1) == EOF ? WEOF : character;
}

char *fgets(char *buffer, int size, FILE *file) {
    int length = 0;
    while (length + 1 < size) {
        int character = fgetc(file);
        if (character == EOF) {
            break;
        }
        buffer[length++] = (char)character;
        if (character == '\n') {
            break;
        }
    }
    if (!length) {
        return NULL;
    }
    buffer[length] = 0;
    return buffer;
}

wchar_t *fgetws(wchar_t *buffer, int size, FILE *file) {
    int length = 0;
    while (length + 1 < size) {
        wint_t character = fgetwc(file);
        if (character == WEOF) {
            break;
        }
        buffer[length++] = (wchar_t)character;
        if (character == '\n') {
            break;
        }
    }
    if (!length) {
        return NULL;
    }
    buffer[length] = 0;
    return buffer;
}

int fputs(const char *string, FILE *file) {
    while (*string) {
        if (fputc((unsigned char)*string++, file) == EOF) {
            return EOF;
        }
    }
    return 0;
}

int fputws(const wchar_t *string, FILE *file) {
    while (*string) {
        if (fputwc(*string++, file) == WEOF) {
            return EOF;
        }
    }
    return 0;
}

int getchar(void) {
    return fgetc(stdin);
}

wint_t getwchar(void) {
    return fgetwc(stdin);
}

int putchar(int character) {
    return fputc(character, stdout);
}

wint_t putwchar(wint_t character) {
    return fputwc(character, stdout);
}

char *gets(char *buffer) {
    int length = 0;
    int character;
    while ((character = getchar()) != EOF && character != '\n') {
        buffer[length++] = (char)character;
    }
    if (character == EOF && !length) {
        return NULL;
    }
    buffer[length] = 0;
    return buffer;
}

wchar_t *_getws(wchar_t *buffer) {
    int length = 0;
    wint_t character;
    while ((character = getwchar()) != WEOF && character != '\n') {
        buffer[length++] = (wchar_t)character;
    }
    if (character == WEOF && !length) {
        return NULL;
    }
    buffer[length] = 0;
    return buffer;
}

int puts(const char *string) {
    return fputs(string, stdout) == EOF || fputc('\n', stdout) == EOF ? EOF : 0;
}

int _putws(const wchar_t *string) {
    return fputws(string, stdout) == EOF || fputwc('\n', stdout) == WEOF ? EOF : 0;
}

long ftell(FILE *file) {
    struct stream *stream = (struct stream *)file;
    if (stream->handle == INVALID_HANDLE) {
        return -1;
    }
    long position = (long)SetFilePointer(stream->handle, 0, NULL, FILE_CURRENT);
    if (stream->state == READING) {
        position -= (long)(stream->length - stream->position);
    } else if (stream->state == WRITING) {
        position += (long)stream->length;
    }
    return position - stream->unget_count;
}

int fseek(FILE *file, long offset, int origin) {
    struct stream *stream = (struct stream *)file;
    if (stream->handle == INVALID_HANDLE) {
        return -1;
    }
    if (origin == SEEK_CUR) {
        offset += ftell(file);
        origin = SEEK_SET;
    }
    if (flush_writes(stream)) {
        return -1;
    }
    if (SetFilePointer(stream->handle, offset, NULL, origin == SEEK_END ? FILE_END : FILE_BEGIN) == 0xFFFFFFFFul) {
        return -1;
    }
    stream->eof = 0;
    return 0;
}

int fgetpos(FILE *file, fpos_t *position) {
    long current = ftell(file);
    if (current < 0) {
        return -1;
    }
    *position = current;
    return 0;
}

int fsetpos(FILE *file, const fpos_t *position) {
    return fseek(file, (long)*position, SEEK_SET);
}

int feof(FILE *file) {
    return ((struct stream *)file)->eof;
}

int ferror(FILE *file) {
    return ((struct stream *)file)->error;
}

void clearerr(FILE *file) {
    ((struct stream *)file)->error = 0;
    ((struct stream *)file)->eof = 0;
}

void *_fileno(FILE *file) {
    return ((struct stream *)file)->handle;
}

int _setmode(FILE *file, int mode) {
    struct stream *stream = (struct stream *)file;
    int previous = stream->text ? TEXT_MODE : BINARY_MODE;
    if (mode == TEXT_MODE || mode == BINARY_MODE) {
        stream->text = mode == TEXT_MODE;
    }
    return previous;
}

struct file_output {
    struct grimace_output output;
    struct stream *stream;
    int wide;
};

static void put_file(struct grimace_output *output, unsigned character) {
    struct file_output *target = (struct file_output *)output;
    if (put_unit(target->stream, character, target->wide) != EOF) {
        output->written++;
    }
}

static int format_file(FILE *file, int wide, const void *format, va_list arguments) {
    struct file_output target = {{put_file, 0}, (struct stream *)file, wide};
    int length = __grimace_format(&target.output, format, wide, arguments);
    return ((struct stream *)file)->error ? -1 : length;
}

int vfprintf(FILE *file, const char *format, va_list arguments) {
    return format_file(file, 0, format, arguments);
}

int vfwprintf(FILE *file, const wchar_t *format, va_list arguments) {
    return format_file(file, 1, format, arguments);
}

int vprintf(const char *format, va_list arguments) {
    return format_file(stdout, 0, format, arguments);
}

int vwprintf(const wchar_t *format, va_list arguments) {
    return format_file(stdout, 1, format, arguments);
}

int fprintf(FILE *file, const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = format_file(file, 0, format, arguments);
    va_end(arguments);
    return length;
}

int fwprintf(FILE *file, const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = format_file(file, 1, format, arguments);
    va_end(arguments);
    return length;
}

int printf(const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = format_file(stdout, 0, format, arguments);
    va_end(arguments);
    return length;
}

int wprintf(const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = format_file(stdout, 1, format, arguments);
    va_end(arguments);
    return length;
}

struct file_reader {
    struct grimace_reader reader;
    int wide;
};

static int next_file(struct grimace_reader *reader) {
    int unit = get_unit(reader->state, ((struct file_reader *)reader)->wide);
    if (unit != EOF) {
        reader->consumed++;
    }
    return unit;
}

static void back_file(struct grimace_reader *reader, int unit) {
    if (unit != EOF && unget_unit(reader->state, unit, ((struct file_reader *)reader)->wide) != EOF) {
        reader->consumed--;
    }
}

static int scan_file(FILE *file, int wide, const void *format, va_list arguments) {
    struct file_reader reader = {{next_file, back_file, file, 0}, wide};
    return __grimace_scan(&reader.reader, format, wide, arguments);
}

int fscanf(FILE *file, const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int result = scan_file(file, 0, format, arguments);
    va_end(arguments);
    return result;
}

int fwscanf(FILE *file, const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int result = scan_file(file, 1, format, arguments);
    va_end(arguments);
    return result;
}

int scanf(const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int result = scan_file(stdin, 0, format, arguments);
    va_end(arguments);
    return result;
}

int wscanf(const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int result = scan_file(stdin, 1, format, arguments);
    va_end(arguments);
    return result;
}
