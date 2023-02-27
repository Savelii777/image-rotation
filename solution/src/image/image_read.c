#include "../../include/image/image_read.h"
#include "../../include/bmp/bmp.h"
#include "../../include/g24/g24.h"
#include "../../include/utils/utils.h"
#include "image/image_utils.h"

#include <errno.h>


static enum read_status read_image(FILE *const in, struct image *const image, enum Format format) {
    if (!in) return READ_NULL_FILE_POINTER;
    int status;
    char* status_message;

    switch (format) {
        case BMP:
            status = from_bmp(in, image);
            status_message = bmp_read_status_message(status);
            break;
        case G24:
            status = from_G24(in, image);
            status_message = g24_read_status_message(status);
            break;
        default:
            status = -1;
    }

    if (status != 0) {
        fprintf(stderr, "Read file error: %s\n", status_message);
        return READ_WRONG_CONTENT;
    }

    return READ_OK;
}


enum read_status read_image_from(const char* const path, struct image* const image) {
    if (!path) return READ_NULL_FILE_POINTER;

    enum Format file_format = return_file_format(path);
    if (file_format == -1) return READ_UNSUPPORTED_TYPE;

    FILE* in = fopen(path, "rb");
    if (!in) return errno_to_read_status(errno);

    enum read_status res = read_image(in, image, file_format);

    fclose(in);
    return res;
}
