#include "g24/g24_status.h"


char* g24_read_status_message(enum g24_read_status status) {
    char* MESSAGES[G24_READ_STATUSES_NUMBER] = {
            "Successful g24 read",
            "Image is NULL",
            "Invalid header",
            "Invalid bits",
            "Memory exceed"
    };

    if (status >= G24_READ_STATUSES_NUMBER)
        return "G24 Read error";
    return MESSAGES[status];
}