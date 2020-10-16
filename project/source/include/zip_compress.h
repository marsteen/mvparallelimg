#ifndef zip_compress_H
#define zip_compress_H

#include <zlib.h>

int zip_compress(
    const void* uncompressed_data,
    size_t uncompressed_data_size,
    const void** compressed_data,
    size_t* compressed_data_size);

#endif
