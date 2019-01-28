#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

/*
 * char ch: The character to be found.
 * char* raw_string: Pointer to the string that will be searched.
 * returns: Position of the @ch if found, -1 if @ch is not contained
 *          within @raw_string.
 */
int16_t find_char(char ch, char* raw_string);

#endif // UTILS_H