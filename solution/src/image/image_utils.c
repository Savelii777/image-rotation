#include <string.h>
#include "../../include/image/image_utils.h"

char* get_substring(const char* const str, char first_char_of_substring) {
    return strrchr(str, '.');
}

enum Format return_file_format(const char* const path) {
    char* format_str = get_substring(path, '.');
    format_str++;
    if (strcmp(format_str,"bmp") == 0)
        return BMP;
    else if (strcmp(format_str,"g24") == 0)
        return G24;
    else
        return -1;
}

struct image alloc_image(uint64_t width, uint64_t height) {
    struct pixel* image_data = (struct pixel*) malloc(sizeof(struct pixel) * width * height);

    return (struct image) {.width = width, .height = height, .data = image_data};
}


void destroy_image(struct image* image) {
    if (!image) return;

    free(image->data);
    image->data = NULL;
}
