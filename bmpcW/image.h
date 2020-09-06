#ifndef IMAGE_H
#define IMAGE_H

#include <QMessageBox>
#include<iostream>
#include<cmath>
#include "mygraphicview.h"

class Image{

#pragma pack (push, 1)
typedef struct
{
    unsigned short signature;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct
{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsInColorTable;
    unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Rgb;

#pragma pack(pop)
public:
    point center;
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmif;
    Rgb** arr;
    int loadImage(const char*);
    int saveImage(const char*);
    void drawCircle(int x0, int y0, int radius);
    int drawLine_thick(int x1, int y1, int x2, int y2, int thick, QColor color);
    QPixmap getPixmap();        
    void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int thik, QColor color);
    int draw_flood_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int thik, QColor floodcolor, QColor edgecolor);
    void cut(int x1, int y1, int x2, int y2);
    void resize();
private:
    void drawLine(int x1, int y1, int x2, int y2, QColor color);
    void middle(int x1, int y1, int x2, int y2, int x3, int y3);
    void flood(int x, int y, QColor color);

};

#endif // IMAGE_H
