#include "../../include/image/image_status.h"
#include <errno.h>

char* read_status_message(const enum read_status status) {
    char * MESSAGES[READ_STATUSES_NUMBER] = {
            "Successful read",
            "Unsupported image type!",
            "Reading has failed during parsing file",
            "ERROR! File pointer equals to NULL",
            "No access to file to read",
            "File not found",
            "Read failed"
    };

    if(status >= READ_STATUSES_NUMBER)
        return "Read error!";

    return MESSAGES[status];
}

enum read_status errno_to_read_status(const int err_num) {
    switch (err_num) {
        case EACCES:
            return READ_NO_ACCESS;
        case ENOENT:
            return READ_FILE_NOT_FOUND;
        default:
            return READ_FILE_ERROR;
    }
}

char* write_status_message(const enum write_status status) {
    char * MESSAGES[WRITE_STATUSES_NUMBER] = {
            "Successfully write",
            "Unsupported image type!",
            "Writing has failed during parsing file",
            "ERROR! File pointer equals to NULL",
            "Not enough memory to write result image! ",
            "Unable to open file: no access",
            "Write failed"
    };

    if(status >= WRITE_STATUSES_NUMBER)
        return "Write error!";

    return MESSAGES[status];
}

enum write_status errno_to_write_status(const int err_num) {
    switch (err_num) {
        case EACCES:
            return WRITE_NO_ACCESS;
        default:
            return WRITE_FILE_ERROR;
    }
}
