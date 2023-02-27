#include <stdio.h>

#include "../include/transform/rotate.h"

#include "../include/image/image_io.h"
#include "../include/image/image_utils.h"

int main( int argc, char** argv ) {

    if (argc <= 1) {
        printf("Please, pass the input file in first argument and output file in second argument");
        return 1;
    } else if (argc == 2) {
        printf("Please, pass output file in second argument");
        return 1;
    }

    struct image image;

    const enum read_status read_status = read_image_from(argv[1], &image);

    if(read_status > 0) {
        destroy_image(&image);
        fprintf(stderr, "%s\n", read_status_message(read_status));
        return 1;
    }

    // TODO: -----------------------------------------------------------------------------------------------------------
    //  1. rotate image by 0.5 * Pi
    //  2. blur the image by 3x3 kernel

    /// 1.
    //struct image result = rotate(image);

    struct kernel kernel3 = {
            .height = 3,
            .width = 3,
            .kernel = (double[]){ 1./29, 4./29, 1./29,
                                  4./29, 9./29, 4./29,
                                  1./29, 4./29, 1./29}
    };

    /// 2.
    struct image result = convolution(image, kernel3);

    enum write_status write_status = WRITE_MEMORY_NOT_ALLOCATED;

    if (result.data) {
        write_status = write_image_to(argv[2], &result);
    }

    // Clear images data
    destroy_image(&image);
    destroy_image(&result);

    if(write_status > 0) {
        fprintf(stderr, "%s\n", write_status_message(write_status));
        return 1;
    }

    return 0;
}
