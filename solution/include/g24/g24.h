#ifndef IMAGE_TRANSFORMER_G24_H
#define IMAGE_TRANSFORMER_G24_H

#include <stdio.h>
#include "g24/g24_status.h"

/**
 * Read .g24 image file
 * @param in
 * @param image
 * @return
 */
enum g24_read_status from_G24( FILE* in, struct image* image );

#endif //IMAGE_TRANSFORMER_G24_H