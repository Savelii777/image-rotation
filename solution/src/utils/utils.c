#include "../../include/utils/utils.h"

#include <string.h>


uint8_t check_file_format(const char* const path) {
    char *ext = strrchr(path, '.');

    if (ext && !strcmp(++ext, "bmp")) return 1;

    return 0;
}
