
#include <iostream>

using namespace std;

extern "C"
{
    void png_set_longjmp_fn() {}
}


extern "C"
{
    #include <mvlib/graphics/mv_graphics_png.h>
}

int main(int argc, char* argv[])
{

    if (argc == 2)
    {
        char* png_data;
        int   png_width;
        int   png_height;
        int   png_bits;
        if (mv_graphics_png_read(argv[1], &png_data, &png_width, &png_height, &png_bits, 0, nullptr))
        {
            cout << "png_width  =" << png_width << endl;
            cout << "png_height =" << png_height << endl;
            cout << "png_bits   =" << png_bits << endl;

        }





    }
    return 0;
}




