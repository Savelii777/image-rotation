#ifndef IMAGE_TRANSFORMER_IMAGE_UTILS_H
#define IMAGE_TRANSFORMER_IMAGE_UTILS_H

#include "../image.h"

#include <stdlib.h>

struct image alloc_image(uint64_t width, uint64_t height);

void destroy_image(struct image* image);

#endif //IMAGE_TRANSFORMER_IMAGE_UTILS_H
