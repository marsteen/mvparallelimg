cmake_minimum_required(VERSION 3.10)
project("mvparallelimg")

link_directories(/usr/local/lib)


include_directories(
    /usr/local/include
    ./source/include
    ./source/mvlib/source/include
    )

add_executable(mvparallelimg
    source/src/main.cpp
    source/src/zip_compress.c
    source/mvlib/source/lib/mv_graphics_png.c
    )


target_link_libraries(mvparallelimg
    png16
    z)

