#ifndef IMAGE_TRANSFORMER_IMAGE_STATUS_H
#define IMAGE_TRANSFORMER_IMAGE_STATUS_H

enum read_status {
    READ_OK = 0,

    READ_UNSUPPORTED_TYPE,
    READ_WRONG_CONTENT,
    READ_NULL_FILE_POINTER,
    READ_NO_ACCESS,
    READ_FILE_NOT_FOUND,
    READ_FILE_ERROR,
    READ_STATUSES_NUMBER
};

enum write_status {
    WRITE_OK = 0,

    WRITE_UNSUPPORTED_TYPE,
    WRITE_WRONG_CONTENT,
    WRITE_NULL_FILE_POINTER,
    WRITE_MEMORY_NOT_ALLOCATED,

    WRITE_NO_ACCESS,
    WRITE_FILE_ERROR,

    WRITE_STATUSES_NUMBER  // must be the last
};

char* read_status_message(enum read_status status);
enum read_status errno_to_read_status(int err_num);

char* write_status_message(enum write_status status);
enum write_status errno_to_write_status(int err_num);

#endif //IMAGE_TRANSFORMER_IMAGE_STATUS_H
