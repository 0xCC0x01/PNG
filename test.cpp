#include <stdio.h>
#include "png.h"

void test_greyscale(BIT_DEPTH bit_depth)
{
    PNG png;
    png.set_ihdr(3, 3, bit_depth, GREYSCALE);

    PIXEL img[3*3] = {{255, 255, 0}, {255, 122, 0}, {255, 0, 0}, {0, 255, 0}, {255, 255, 255}, {0, 0, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}};
    png.set_idat(img);

    char path[100] = {0};
    sprintf_s(path, "D:\\greyscale_bit_depth_%d.png", bit_depth);
    
    png.write(path);
}

void test_indexedcolor(BIT_DEPTH bit_depth)
{
    PNG png;
    png.set_ihdr(3, 3, bit_depth, INDEXED_COLOR);

    PIXEL pixels[2] = {{0xFF, 0, 0}, {0, 0xFF, 0}};
    png.set_plte(pixels, 2);

    unsigned char img[3*3] = {0, 1, 0, 1, 0, 1,  0, 1, 0};
    png.set_idat(img);

    char path[100] = {0};
    sprintf_s(path, "D:\\indexedcolor_bit_depth_%d.png", bit_depth);

    png.write(path);
}

void test_truecolor(BIT_DEPTH bit_depth)
{
    PNG png;
    png.set_ihdr(3, 3, bit_depth, TRUECOLOR);

    PIXEL img[3*3] = {{255, 255, 0}, {255, 122, 0}, {255, 0, 0}, {0, 255, 0}, {255, 255, 255}, {0, 0, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}};
    png.set_idat(img);
    
    char path[100] = {0};
    sprintf_s(path, "D:\\truecolor_bit_depth_%d.png", bit_depth);

    png.write(path);
}

void test_alpha_greyscale(BIT_DEPTH bit_depth)
{
    PNG png;
    png.set_ihdr(3, 3, bit_depth, ALPHA_GREYSCALE);

    PIXEL img[3*3] = {{255, 255, 0, 255}, {255, 122, 0, 255}, {255, 0, 0, 255}, {0, 255, 0, 255}, {255, 255, 255, 0}, {0, 0, 0, 0}, {0, 255, 255, 255}, {0, 0, 255, 255}, {255, 0, 255, 255}};
    png.set_idat(img);
    
    char path[100] = {0};
    sprintf_s(path, "D:\\alpha_greyscale_bit_depth_%d.png", bit_depth);

    png.write(path);
}

void test_alpha_truecolor(BIT_DEPTH bit_depth)
{
    PNG png;
    png.set_ihdr(3, 3, bit_depth, ALPHA_TRUECOLOR);

    PIXEL img[3*3] = {{255, 255, 0, 255}, {255, 122, 0, 255}, {255, 0, 0, 255}, {0, 255, 0, 255}, {255, 255, 255, 0}, {0, 0, 0, 0}, {0, 255, 255, 255}, {0, 0, 255, 255}, {255, 0, 255, 255}};
    png.set_idat(img);
    
    char path[100] = {0};
    sprintf_s(path, "D:\\alpha_truecolor_bit_depth_%d.png", bit_depth);

    png.write(path);
}

char error_correction_char(int ec_level)
{
    char ec[] = {'L', 'M', 'Q', 'H'};
    return ec[ec_level];
}

int main()
{
    test_greyscale(BIT_DEPTH_1);
    test_greyscale(BIT_DEPTH_2);
    test_greyscale(BIT_DEPTH_4);
    test_greyscale(BIT_DEPTH_8);
    test_greyscale(BIT_DEPTH_16);

    test_indexedcolor(BIT_DEPTH_1);
    test_indexedcolor(BIT_DEPTH_2);
    test_indexedcolor(BIT_DEPTH_4);
    test_indexedcolor(BIT_DEPTH_8);

    test_truecolor(BIT_DEPTH_8);
    test_truecolor(BIT_DEPTH_16);

    test_alpha_greyscale(BIT_DEPTH_8);
    test_alpha_greyscale(BIT_DEPTH_16);

    test_alpha_truecolor(BIT_DEPTH_8);
    test_alpha_truecolor(BIT_DEPTH_16);
}