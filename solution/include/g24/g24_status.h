#ifndef IMAGE_TRANSFORMER_G24_STATUS_H
#define IMAGE_TRANSFORMER_G24_STATUS_H

enum g24_read_status {
    G24_READ_OK = 0,
    G24_READ_ERROR
};

char* g24_read_status_message(enum g24_read_status status);

#endif //IMAGE_TRANSFORMER_G24_STATUS_H