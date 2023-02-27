#include "../../include/g24/g24_io.h"

enum g24_read_status read_G24_header(FILE* const in, struct g24_header* const header) {
    if(fread(header, sizeof(struct g24_header), 1, in) != 1)
        return G24_READ_INVALID_HEADER;

    return G24_READ_OK;
}

enum g24_read_status read_G24_image_data(FILE* const in, struct image* const image ) {
    if ( fread(image->data,sizeof (struct pixel),image->height * image->width,in)
                    != image->height * image->width )
        return G24_READ_INVALID_BITS;

    return G24_READ_OK;
}