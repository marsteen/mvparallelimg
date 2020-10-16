#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>


int zip_compress(
    const void* uncompressed_data,
    size_t uncompressed_data_size,
    void** compressed_data,
    size_t* compressed_data_size)
{
    uInt avail_out = uncompressed_data_size * 2;
    char* compressed_data_buffer = (char*) malloc(avail_out);

    z_stream defstream;
    defstream.zalloc    = Z_NULL;
    defstream.zfree     = Z_NULL;
    defstream.opaque    = Z_NULL;

    defstream.avail_in  = uncompressed_data_size;              // size of input, string + terminator
    defstream.next_in   = (Bytef*) (&uncompressed_data[0]);    // input char array
    defstream.avail_out = avail_out;                           // size of output
    defstream.next_out  = (Bytef*) compressed_data_buffer;     // output char array

    // the actual compression work.
    deflateInit(&defstream, Z_BEST_COMPRESSION);
    deflate(&defstream, Z_FINISH);
    deflateEnd(&defstream);

    *compressed_data_size = defstream.total_out;
    *compressed_data = (char*) malloc(*compressed_data_size);
    memcpy(*compressed_data, compressed_data_buffer, *compressed_data_size);
    free(compressed_data_buffer);

    return 0;
}