#ifndef IMAGE_TRANSFORMER_UTILS_H
#define IMAGE_TRANSFORMER_UTILS_H

#define MAX_STRING_SIZE 15

#include <stdint.h>

/**
 * Return substring from @param position to the end of file
 * @param str
 * @param position
 * @return
 */
char* get_substring(const char* const str, size_t position);

uint8_t check_file_format(const char* const path);

#endif //IMAGE_TRANSFORMER_UTILS_H
