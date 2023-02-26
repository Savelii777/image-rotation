#include "../../include/image/image_read.h"
#include "../../include/bmp/bmp.h"
#include "../../include/utils/utils.h"

#include <errno.h>


static enum read_status read_image(FILE* const in, struct image* const image) {
    if (!in) return READ_NULL_FILE_POINTER;

    const enum bmp_read_status status = from_bmp(in, image);

    if (status > 0) {
        fprintf(stderr, "Read BMP error: %s\n", bmp_read_status_message(status));
        return READ_WRONG_CONTENT;
    }

    return READ_OK;
}


enum read_status read_image_from(const char* const path, struct image* const image) {
    if (!path) return READ_NULL_FILE_POINTER;

    if (!check_file_format(path)) return READ_UNSUPPORTED_TYPE;

    FILE* in = fopen(path, "rb");
    if (!in) return errno_to_read_status(errno);

    enum read_status res = read_image(in, image);

    fclose(in);
    return res;
}
