#ifndef IMAGE_TRANSFORMER_IMAGE_READ_H
#define IMAGE_TRANSFORMER_IMAGE_READ_H

#include <stdio.h>

#include "../image.h"

#include "image_status.h"

enum read_status read_image_from(const char* path, struct image* image);

#endif //IMAGE_TRANSFORMER_IMAGE_READ_H
