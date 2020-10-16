
#ifndef MV_GRAPHICS_PNG_H
#define MV_GRAPHICS_PNG_H

#include <stdio.h>

int mv_graphics_png_read(const char* png_file, char** png_data, int* png_width, int* png_height, int* png_bits, size_t file_offset, char* msg);
int mv_graphics_png_read_fp(FILE* fp, char** png_data, int* png_width, int* png_height, int* png_bits, size_t file_offset, char* msg);
int mv_graphics_png_write(const char* png_file, const char* png_data, int png_width, int png_height, int png_bits);

#endif
