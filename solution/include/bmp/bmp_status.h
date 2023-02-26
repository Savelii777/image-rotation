#ifndef IMAGE_TRANSFORMER_BMP_STATUS_H
#define IMAGE_TRANSFORMER_BMP_STATUS_H


enum bmp_read_status  {
    BMP_READ_OK = 0,
    BMP_READ_INVALID_SIGNATURE,
    BMP_READ_INVALID_BITS,
    BMP_READ_INVALID_HEADER,
    BMP_READ_NULL_IMAGE,
    BMP_READ_OUT_OF_MEMORY,

    BMP_READ_STATUSES_NUMBER
};

enum bmp_write_status  {
    BMP_WRITE_OK = 0,
    BMP_WRITE_NULL_IMAGE,
    BMP_WRITE_TOO_BIG,
    BMP_WRITE_ERROR,

    BMP_WRITE_STATUSES_NUMBER
};

char* bmp_read_status_message(enum bmp_read_status status);

char* bmp_write_status_message(enum bmp_write_status status);

#endif //IMAGE_TRANSFORMER_BMP_STATUS_H
