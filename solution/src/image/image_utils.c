#include "../../include/image/image_utils.h"

struct image alloc_image(uint64_t width, uint64_t height) {
    struct pixel* image_data = (struct pixel*) malloc(sizeof(struct pixel) * width * height);

    return (struct image) {.width = width, .height = height, .data = image_data};
}


void destroy_image(struct image* image) {
    if (!image) return;

    free(image->data);
    image->data = NULL;
}
