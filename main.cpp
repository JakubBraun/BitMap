#include<iostream>
#include<fstream>
using namespace std;

unsigned char* ReadBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");

    if(f == NULL)
        throw "Argument Exception";

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f);

    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    int16_t bitsPerPixel = *(int16_t*)&info[26];
    int compression = *(int*)&info[30];

    cout << endl;
    cout << "  Name: " << filename << endl;
    cout << " Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "bits per pixel: " << bitsPerPixel << endl;
    cout << "compression: " << compression << endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    fclose(f);
    return data;
}

int main() {
    char singleByte;
    uint8_t base;
    uint16_t color_planes, bits_per_pixel;
    uint32_t compression, image_size, pixels_per_meter, number_of_colors;

    ReadBMP("test.bmp");
    return 0;
}