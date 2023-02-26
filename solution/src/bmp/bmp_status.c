#include "../../include/bmp/bmp_status.h"


char* bmp_read_status_message(const enum bmp_read_status status) {
    char* MESSAGES[BMP_READ_STATUSES_NUMBER] = {
            "Successful bmp read",
            "Invalid signature",
            "Invalid bits",
            "Invalid header",
            "Image is NULL",
            "Memory exceed"
    };

    if (status >= BMP_READ_STATUSES_NUMBER)
        return "BMP Read error";
    return MESSAGES[status];
}


char* bmp_write_status_message(const enum bmp_write_status status) {
    char* MESSAGES[BMP_WRITE_STATUSES_NUMBER] = {
            "Successful bmp write",
            "image is NULL",
            "image to big",
            "IO error"
    };

    if (status >= BMP_WRITE_STATUSES_NUMBER)
        return "BMP Write error";

    return MESSAGES[status];
}
