#ifndef IMAGE_TRANSFORMER_G24_HEADER_H
#define IMAGE_TRANSFORMER_G24_HEADER_H

#include <stdint.h>

struct __attribute__((packed)) g24_header {
    uint32_t biWidth;
    uint32_t biHeight;
};

#endif //IMAGE_TRANSFORMER_BMP_G24_HEADER_H