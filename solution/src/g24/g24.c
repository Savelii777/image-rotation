#include "../../include/image/image_utils.h"
#include "../../include/g24/g24.h"
#include "g24/g24_header.h"
#include "g24/g24_io.h"


enum g24_read_status from_G24( FILE* in, struct image* image ) {
    if (!in || !image) return G24_READ_NULL_IMAGE;

    struct g24_header header;
    enum g24_read_status status = read_G24_header(in, &header);

    if (status > 0) return status;

    *image = alloc_image(header.biWidth, header.biHeight);

    if (!image->data) return G24_READ_OUT_OF_MEMORY;

    return read_G24_image_data(in, image);
}
