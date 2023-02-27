#ifndef IMAGE_TRANSFORMER_BMP_IO_H
#define IMAGE_TRANSFORMER_BMP_IO_H

#include <stdint.h>
#include <stdio.h>

#include "../image.h"

#include "bmp_header.h"
#include "bmp_status.h"


#define BMP_BI_SIZE 40
#define BMP_BI_PLANES 1
#define BMP_BITS_COUNT 24
#define BMP_FILE_SIGNATURE_LE 0x4D42
#define BMP_FILE_SIGNATURE_BE 0x422D
#define IMAGE_PADDING_BYTES 4


enum bmp_read_status read_BMP_header(FILE* const in, struct bmp_header* const header);

enum bmp_read_status read_image_data(FILE* const in, struct image* const image );

enum bmp_write_status write_header(FILE* const out, const struct image* const image);

enum bmp_write_status write_raw_image(FILE* const out, const struct image* const image);

#endif //IMAGE_TRANSFORMER_BMP_IO_H
