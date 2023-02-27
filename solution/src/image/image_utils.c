#include <string.h>
#include "../../include/image/image_utils.h"

char* get_substring(const char* const str, char first_char_of_substring) {
    return strrchr(str, '.');
}

enum Format return_file_format(const char* const path) {
    char* format_str = get_substring(path, '.');
    format_str++;
    if (strcmp(format_str,"bmp") == 0)
        return BMP;
    else if (strcmp(format_str,"G24") == 0)
        return G24;
    else
        return -1;
}

struct image alloc_image(uint64_t width, uint64_t height) {
    struct pixel* image_data = (struct pixel*) malloc(sizeof(struct pixel) * width * height);

    return (struct image) {.width = width, .height = height, .data = image_data};
}

static uint64_t array_index(uint64_t by_line, uint64_t by_column, uint64_t width) {
    return by_column + by_line * width;
}

struct pixel uint16_to_pixel(struct uint16_pixel extend_pixel) {
    return (struct pixel) {
            .b = ( extend_pixel.b > 255) ? 255 : extend_pixel.b,
            .g = ( extend_pixel.g > 255) ? 255 : extend_pixel.g,
            .r = ( extend_pixel.r > 255) ? 255 : extend_pixel.r,
    };
}

struct image convolution(const struct image img, struct kernel const kernel) {
    struct pixel* result = malloc(sizeof(struct pixel) * img.width * img.height);
    struct uint16_pixel temp = {0};
    int64_t x_kernel, y_kernel;

    for (uint64_t y = 0; y < img.height; ++y) {
        for (uint64_t x = 0; x < img.width; ++x) {
            temp.b = 0;
            temp.g = 0;
            temp.r = 0;

            for (uint64_t i = 0; i < kernel.height; ++i) {
                for (uint64_t j = 0; j < kernel.width; ++j) {
                    y_kernel = y + (i - (kernel.height / 2));
                    x_kernel = x + (j - (kernel.width / 2));

                    if (x_kernel < 0 || x_kernel >= img.width ||
                        y_kernel < 0 || y_kernel >= img.height)
                        continue;

                    temp.b += img.data[array_index(y_kernel, x_kernel, img.width)].b *
                              kernel.kernel[array_index(i, j, kernel.width)];
                    temp.g += img.data[array_index(y_kernel, x_kernel , img.width)].g *
                              kernel.kernel[array_index(i, j, kernel.width)];
                    temp.r += img.data[array_index(y_kernel, x_kernel , img.width)].r *
                              kernel.kernel[array_index(i, j, kernel.width)];
                }
            }

            result[array_index( y, x, img.width)] = uint16_to_pixel(temp);
        }
    }

    return (struct image) {
            .width = img.width,
            .height = img.height,
            .data = result
    };
}

void destroy_image(struct image* image) {
    if (!image) return;

    free(image->data);
    image->data = NULL;
}
