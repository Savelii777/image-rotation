#ifndef IMAGE_TRANSFORMER_BMP_H
#define IMAGE_TRANSFORMER_BMP_H

#include "bmp_io.h"

enum bmp_read_status from_bmp(FILE* in, struct image* image);

enum bmp_write_status to_bmp(FILE* out, const struct image* image);

#endif //IMAGE_TRANSFORMER_BMP_H
