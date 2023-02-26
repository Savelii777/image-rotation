#include "../../include/transform/rotate.h"
#include "../../include/image/image_utils.h"


struct image rotate(const struct image image) {
    struct image res = alloc_image(image.height, image.width);

    if (res.data) {
        for (uint64_t row = 0; row < image.height; row++) {
            for (uint64_t col = 0; col < image.width; col++) {
                res.data[(col + 1) * image.height - row - 1] = image.data[row * image.width + col];
            }
        }
    }

    return res;
}
