#ifndef IMAGE_TRANSFORMER_UTILS_H
#define IMAGE_TRANSFORMER_UTILS_H

#define MAX_STRING_SIZE 15

#include <stdint.h>

/**
 * Return substring from @param first_char_of_substring to the end of file
 * @param str
 * @param first_char_of_substring
 * @return
 */
char* get_substring(const char* const str, char first_char_of_substring);

int check_file_format(const char* const path);

#endif //IMAGE_TRANSFORMER_UTILS_H
