#ifndef IMAGE_TRANSFORMER_G24_IO_STATUS_H
#define IMAGE_TRANSFORMER_G24_IO_STATUS_H

#include <stdint.h>
#include <stdio.h>

#include "../image.h"

#include "g24_header.h";
#include "g24_status.h";

enum g24_read_status read_BMP_header(FILE* const in, struct bmp_header* const header);

enum g24_read_status read_image_data(FILE* const in, struct image* const image );

#endif //IMAGE_TRANSFORMER_G24_IO_STATUS_H