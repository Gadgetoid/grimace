#ifndef GRIMACE_STRING_H
#define GRIMACE_STRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Copies bytes between blocks of memory that don't overlap.
 *
 * Use memmove if the blocks may overlap.
 *
 * @param destination Block to copy to.
 * @param source Block to copy from.
 * @param count Number of bytes to copy.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
void *memcpy(void *destination, const void *source, size_t count);
/**
 * Copies bytes between blocks of memory, which may overlap.
 *
 * @param destination Block to copy to.
 * @param source Block to copy from.
 * @param count Number of bytes to copy.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
void *memmove(void *destination, const void *source, size_t count);
/**
 * Fills a block of memory with a byte value.
 *
 * @param destination The block to fill.
 * @param value The byte value, converted to unsigned char.
 * @param count Number of bytes to fill.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
void *memset(void *destination, int value, size_t count);
/**
 * Compares two blocks of memory byte by byte.
 *
 * @param first First block.
 * @param second Second block.
 * @param count Number of bytes to compare.
 * @return Less than, equal to or greater than zero as first is less than,
 *         equal to or greater than second.
 *
 * @note Windows CE 2.0 and later.
 */
int memcmp(const void *first, const void *second, size_t count);
/**
 * Finds the first occurrence of a byte in a block of memory.
 *
 * @param memory Block to search.
 * @param value Byte to find, converted to unsigned char.
 * @param count Number of bytes to search.
 * @return Pointer to the first match, or NULL if there is none.
 */
void *memchr(const void *memory, int value, size_t count);
/**
 * Copies bytes until value is copied or count bytes have been copied.
 *
 * If value is found, copying includes it and the return points just past
 * it in destination.
 *
 * @param destination Receives the copied bytes.
 * @param source Bytes to copy.
 * @param value Byte that stops the copy, converted to char.
 * @param count Maximum number of bytes to copy.
 * @return Pointer just past value in destination, or NULL if value was
 *         not copied.
 *
 * @note Windows CE 2.0 and later.
 */
void *_memccpy(void *destination, const void *source, int value, unsigned int count);
/**
 * Compares count bytes in two buffers without regard to case.
 *
 * @param first First buffer.
 * @param second Second buffer.
 * @param count Number of bytes to compare.
 * @return Less than, equal to or greater than zero according to the
 *         comparison.
 *
 * @note Windows CE 2.0 and later.
 */
int _memicmp(const void *first, const void *second, unsigned int count);
/**
 * Returns the number of characters before the terminating null character.
 *
 * @param string Null-terminated string.
 * @return String length.
 *
 * @note Windows CE 2.0 and later.
 */
size_t strlen(const char *string);
/**
 * Copies source to destination, including its terminating null character.
 *
 * The destination must have enough space. Overlapping strings have
 * undefined behavior.
 *
 * @param destination Receives the copy.
 * @param source Null-terminated string to copy.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
char *strcpy(char *destination, const char *source);
/**
 * Copies up to count characters from source to destination.
 *
 * If source is shorter than count, destination is padded with null bytes.
 * Otherwise no null terminator is appended. Overlapping strings have
 * undefined behavior.
 *
 * @param destination Receives the copy.
 * @param source String to copy.
 * @param count Maximum number of characters to copy.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
char *strncpy(char *destination, const char *source, size_t count);
/**
 * Appends source to destination, including a terminating null character.
 *
 * The destination must have enough space. Overlapping strings have
 * undefined behavior.
 *
 * @param destination Null-terminated string to extend.
 * @param source Null-terminated string to append.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
char *strcat(char *destination, const char *source);
/**
 * Appends at most count characters from source and terminates destination.
 *
 * The destination must have enough space for the result and terminator.
 * Overlapping strings have undefined behavior.
 *
 * @param destination Null-terminated string to extend.
 * @param source Null-terminated string to append.
 * @param count Maximum number of source characters to append.
 * @return destination.
 *
 * @note Windows CE 2.0 and later.
 */
char *strncat(char *destination, const char *source, size_t count);
/**
 * Compares two null-terminated strings lexicographically.
 *
 * The comparison is case-sensitive and is not affected by locale.
 *
 * @param first First string.
 * @param second Second string.
 * @return Less than, equal to or greater than zero according to the
 *         comparison.
 *
 * @note Windows CE 2.0 and later.
 */
int strcmp(const char *first, const char *second);
/**
 * Compares at most count characters of two strings lexicographically.
 *
 * The comparison is case-sensitive and not affected by locale. It stops
 * when either string ends.
 *
 * @param first First string.
 * @param second Second string.
 * @param count Maximum number of characters to compare.
 * @return Less than, equal to or greater than zero according to the
 *         comparison.
 *
 * @note Windows CE 2.0 and later.
 */
int strncmp(const char *first, const char *second, size_t count);
/**
 * Compares strings lexicographically without regard to case.
 *
 * The case conversion follows the LC_CTYPE locale setting.
 *
 * @param first First null-terminated string.
 * @param second Second null-terminated string.
 * @return Less than, equal to or greater than zero according to the
 *         comparison.
 *
 * @note Windows CE 3.0 and later.
 */
int _stricmp(const char *first, const char *second);
/**
 * Compares up to count characters without regard to case.
 *
 * Comparison stops earlier if either string ends and is not affected by
 * the current locale.
 *
 * @param first First null-terminated string.
 * @param second Second null-terminated string.
 * @param count Maximum number of characters to compare.
 * @return Less than, equal to or greater than zero according to the
 *         comparison.
 *
 * @note Windows CE 3.0 and later.
 */
int _strnicmp(const char *first, const char *second, size_t count);
/**
 * Finds the first occurrence of character in string.
 *
 * The terminating null character is included in the search.
 *
 * @param string Null-terminated string to search.
 * @param character Character to find, converted to char.
 * @return Pointer to the match, or NULL if none is found.
 *
 * @note Windows CE 2.0 and later.
 */
char *strchr(const char *string, int character);
/**
 * Finds the last occurrence of character in string.
 *
 * The terminating null character is included in the search.
 *
 * @param string Null-terminated string to search.
 * @param character Character to find, converted to char.
 * @return Pointer to the match, or NULL if none is found.
 *
 * @note Windows CE 3.0 and later.
 */
char *strrchr(const char *string, int character);
/**
 * Finds the first occurrence of substring in string.
 *
 * The terminating null characters are not searched. An empty substring
 * returns string.
 *
 * @param string Null-terminated string to search.
 * @param substring Null-terminated string to find.
 * @return Pointer to the match, or NULL if none is found.
 *
 * @note Windows CE 2.0 and later.
 */
char *strstr(const char *string, const char *substring);
/**
 * Finds the first character in string that occurs in characters.
 *
 * The terminating null character is not searched.
 *
 * @param string Null-terminated string to search.
 * @param characters Null-terminated set of characters.
 * @return Pointer to the matching character, or NULL if none is found.
 *
 * @note Windows CE 3.0 and later.
 */
char *strpbrk(const char *string, const char *characters);
/**
 * Returns the length of the initial segment containing only characters
 * from characters.
 *
 * The terminating null character is not searched.
 *
 * @param string String to scan.
 * @param characters Null-terminated set of accepted characters.
 * @return Length of the initial segment.
 *
 * @note Windows CE 3.0 and later.
 */
size_t strspn(const char *string, const char *characters);
/**
 * Returns the length of the initial string segment containing no characters
 * from characters.
 *
 * The terminating null character is included in the search.
 *
 * @param string String to scan.
 * @param characters Null-terminated set of excluded characters.
 * @return Length of the initial segment.
 *
 * @note Windows CE 2.0 and later.
 */
size_t strcspn(const char *string, const char *characters);
/**
 * Returns the next token separated by characters in delimiters.
 *
 * The function replaces delimiters with null characters. Pass NULL as
 * string to continue tokenizing the previous string. It uses static state
 * and is unsafe for simultaneous tokenization of multiple strings.
 *
 * @param string String to tokenize, or NULL to continue.
 * @param delimiters Null-terminated set of delimiter characters.
 * @return Pointer to the next token, or NULL when no tokens remain.
 *
 * @note Windows CE 2.0 and later.
 */
char *strtok(char *string, const char *delimiters);
/**
 * Allocates and returns a copy of a null-terminated string.
 *
 * Free the returned string with free.
 *
 * @param string String to duplicate.
 * @return Copy of string, or NULL if allocation fails.
 *
 * @note Windows CE 3.0 and later.
 */
char *_strdup(const char *string);
/**
 * Converts uppercase letters in string to lowercase in place.
 *
 * Conversion follows the LC_CTYPE locale setting.
 *
 * @param string String to convert.
 * @return string.
 *
 * @note Windows CE 3.0 and later.
 */
char *_strlwr(char *string);
/**
 * Converts lowercase letters in string to uppercase in place.
 *
 * Conversion follows the LC_CTYPE locale setting.
 *
 * @param string String to convert.
 * @return string.
 *
 * @note Windows CE 3.0 and later.
 */
char *_strupr(char *string);
/**
 * Reverses the characters in string in place.
 *
 * The terminating null character remains at the end.
 *
 * @param string String to reverse.
 * @return string.
 *
 * @note Windows CE 3.0 and later.
 */
char *_strrev(char *string);
/**
 * Sets every character in string to character, except the terminator.
 *
 * @param string String to modify.
 * @param character Replacement character, converted to char.
 * @return string.
 *
 * @note Windows CE 3.0 and later.
 */
char *_strset(char *string, int character);
/**
 * Sets up to count characters in string to character.
 *
 * If count exceeds the string length, only the string's characters are
 * changed.
 *
 * @param string String to modify.
 * @param character Replacement character, converted to char.
 * @param count Maximum number of characters to set.
 * @return string.
 *
 * @note Windows CE 3.0 and later.
 */
char *_strnset(char *string, int character, size_t count);
char *strerror(int number);

#ifdef __cplusplus
}
#endif

#endif
