#include "../../include/bmp/bmp.h"
#include "../../include/image/image_utils.h"


enum bmp_read_status from_bmp( FILE* const in, struct image* const image ) {
    if (!in || !image) return BMP_READ_NULL_IMAGE;

    struct bmp_header header;
    enum bmp_read_status header_read_status = read_BMP_header(in, &header);

    if (header_read_status > 0) return header_read_status;

    *image = alloc_image(header.biWidth, header.biHeight);

    if (!image->data) return BMP_READ_OUT_OF_MEMORY;

    return read_image_data(in, image);
}



enum bmp_write_status to_bmp(FILE* const out, const struct image* const image ) {
    if (!out || !image) return BMP_WRITE_NULL_IMAGE;

    enum bmp_write_status header_write_status = write_header(out, image);

    return header_write_status > 0 ? header_write_status : write_raw_image(out, image);
}
