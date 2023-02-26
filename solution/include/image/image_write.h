#ifndef IMAGE_TRANSFORMER_IMAGE_WRITE_H
#define IMAGE_TRANSFORMER_IMAGE_WRITE_H

#include <stdio.h>

#include "../image.h"

#include "image_status.h"

enum write_status write_image_to(const char* path, const struct image* image);

#endif //IMAGE_TRANSFORMER_IMAGE_WRITE_H
