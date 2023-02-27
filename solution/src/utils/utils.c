#include "../../include/utils/utils.h"

#include <string.h>

int check_file_format(const char* const path) {
    char *ext = strrchr(path, '.');

    return (ext == NULL) ? 0 : 1;
}
