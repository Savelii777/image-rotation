#include "../../include/bmp/bmp_io.h"


static uint8_t calc_img_padding(const uint64_t width) {
    return (IMAGE_PADDING_BYTES - width * sizeof(struct pixel) % IMAGE_PADDING_BYTES) % IMAGE_PADDING_BYTES;
}

static uint32_t calc_file_size(const size_t width, const size_t height) {
    size_t pad = (size_t) calc_img_padding(width);

    size_t size = sizeof(struct bmp_header) + width * height * sizeof(struct pixel) + pad * height;

    return size > UINT32_MAX ? 0 : size;
}

// read image

enum bmp_read_status read_image_data(FILE* const in, struct image* const image) {
    uint64_t width = image->width;
    uint8_t pad = calc_img_padding(width);

    for(uint32_t row = 0; row < image->height; ++row) {
        if(fread(image->data + row * width, sizeof(struct pixel), width, in) != width)
            return BMP_READ_INVALID_BITS;

        if(fseek(in, pad, SEEK_CUR))
            return BMP_READ_INVALID_BITS;
    }

    return BMP_READ_OK;
}

enum bmp_read_status read_BMP_header(FILE* const in, struct bmp_header* const header) {
    if(fread(header, sizeof(struct bmp_header), 1, in) != 1)
        return BMP_READ_INVALID_HEADER;

    if(header->biBitCount != BMP_BITS_COUNT)
        return BMP_READ_INVALID_BITS;

    if(header->bfType != BMP_FILE_SIGNATURE_LE && header->bfType != BMP_FILE_SIGNATURE_BE)
        return BMP_READ_INVALID_SIGNATURE;

    if(fseek(in, (long) header->bOffBits, SEEK_SET) != 0)
        return BMP_READ_INVALID_BITS;

    return BMP_READ_OK;
}

// write image

enum bmp_write_status write_raw_image(FILE* const out, const struct image* const image) {
    uint64_t width = image->width;
    uint8_t pad = calc_img_padding(width);

    for (int row = 0; row < image->height; ++row) {
        if (fwrite(image->data + row * width, sizeof(struct pixel), (size_t) width, out) != width)
            return BMP_WRITE_ERROR;

        if (fseek(out, pad, SEEK_CUR) != 0)
            return BMP_WRITE_ERROR;
    }

    return BMP_WRITE_OK;
}

enum bmp_write_status write_header(FILE* const out, const struct image* const image) {
    uint32_t size = calc_file_size(image->width, image->height);

    if (!size || image->width > UINT32_MAX || image->height > UINT32_MAX)
        return BMP_WRITE_TOO_BIG;

    struct bmp_header header = (struct bmp_header) {
            .bfType = BMP_FILE_SIGNATURE_LE,
            .bfileSize = size,
            .bOffBits = sizeof(struct bmp_header),
            .biSize = BMP_BI_SIZE,
            .biWidth = image->width,
            .biHeight = image->height,
            .biPlanes = BMP_BI_PLANES,
            .biBitCount = BMP_BITS_COUNT,
            .biSizeImage = sizeof(struct bmp_header) - size
    };

    if (fwrite(&header, sizeof(struct bmp_header), 1, out) != 1)
        return BMP_WRITE_ERROR;

    return BMP_WRITE_OK;
}
