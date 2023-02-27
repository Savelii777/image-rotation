#include "../../include/image/image_write.h"
#include "../../include/bmp/bmp.h"
#include "../../include/utils/utils.h"

#include <errno.h>


static enum write_status write_image(FILE* const out, const struct image* const img) {
    if(!out) return WRITE_NULL_FILE_POINTER;

    const enum bmp_write_status status = to_bmp(out, img);

    if (status > 0) {
        fprintf(stderr, "Write BMP error: %s\n", bmp_write_status_message(status));
        return WRITE_WRONG_CONTENT;
    }

    return WRITE_OK;
}


enum write_status write_image_to(const char* const path, const struct image* const img) {
    if (!path) return WRITE_NULL_FILE_POINTER;

    if (!return_file_format(path)) return WRITE_UNSUPPORTED_TYPE;

    FILE* out = fopen(path, "wb+");
    if (!out) return errno_to_write_status(errno);

    enum write_status res = write_image(out, img);

    fclose(out);
    return res;
}
