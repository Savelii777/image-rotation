#ifndef IMAGE_TRANSFORMER_IMAGE_UTILS_H
#define IMAGE_TRANSFORMER_IMAGE_UTILS_H

#include "../image.h"

#include <stdlib.h>

struct kernel {
    uint64_t height, width;
    double* kernel;
};

struct uint16_pixel {
    uint8_t b, g, r;
};

enum Format {
    BMP = 1,
    G24 = 2
};

enum Format return_file_format(const char* const path);

struct image alloc_image(uint64_t width, uint64_t height);

struct image convolution(const struct image img, struct kernel const kernel);

void destroy_image(struct image* image);

#endif //IMAGE_TRANSFORMER_IMAGE_UTILS_H
