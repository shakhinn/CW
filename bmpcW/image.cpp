#include "image.h"
#include "mainwindow.h"
#include<QMessageBox>

int Image::loadImage(const char *file){
    FILE* f = fopen(file, "rb");
       if (!f)
           return -1;
       fread(&bmfh, sizeof(bmfh), 1, f);
       fread(&bmif, sizeof(bmif), 1, f);
       if (bmif.height > 10000 || bmif.width > 10000)
           return -2;
       if(bmif.compression != 0){
           return -3;
       }
       if(bmif.bitsPerPixel != 24){
           return -4;
       }
       size_t padding = 0;
       if ((bmif.width*3) % 4)
           padding = 4 - (bmif.width*3) % 4;
       arr= new Rgb* [bmif.height];
       for (int i = 0; i < (int)bmif.height; i++){
           arr[i] = new Rgb [bmif.width + 1];
       }
       fseek(f, long(bmfh.pixelArrOffset), SEEK_SET);
       for (int i = 0; i <  (int)bmif.height; i++) {
           int j;
           for (j = 0;  j < (int)bmif.width; j++){
               fread(&arr[i][j], sizeof(Rgb), 1, f);
           }
           if (padding)
               fread(&arr[i][j], padding, 1, f);
       }
       fclose(f);
       return 0;
   }

int Image::saveImage(const char *path){
    FILE* f = fopen(path, "wb");
    if (!f)
        return -1;
    fwrite(&bmfh, sizeof(bmfh), 1, f);
    fwrite(&bmif, sizeof(bmif), 1, f);
    size_t padding = 0;
    if ((bmif.width*3) % 4)
        padding = 4 - (bmif.width*3) % 4;
    fseek(f, long(bmfh.pixelArrOffset), SEEK_SET);
    for (int i = 0; i < (int)bmif.height; i++) {
        int j;
        for (j = 0; j < (int)bmif.width; j++){
            fwrite(&arr[i][j], sizeof(Rgb), 1, f);
        }
        if (padding)
            fwrite(&arr[i][j], padding, 1, f);
    }
    fclose(f);
    return 0;
}




QPixmap Image::getPixmap(){
    QImage *image = new QImage(bmif.width, bmif.height, QImage::Format_RGB16);
    QColor pixel;
    for(int i = 0; i < (int)bmif.height; i++){
        for(int j = 0; j < (int)bmif.width; j++){
            pixel.setRed(arr[i][j].r);
            pixel.setGreen(arr[i][j].g);
            pixel.setBlue(arr[i][j].b);
            image->setPixel(j, bmif.height - i -1, pixel.rgb());
        }
    }
    return QPixmap::fromImage(*image);
}

void Image::drawCircle(int x0, int y0, int radius){
    for(int i = x0-radius; i <= x0+radius; i++){
        for(int j = y0-radius; j <= y0+radius; j++){
            if((sqrt(pow(i-x0,2)+pow(j-y0,2)))<=radius+1)
                if(i > 0 && i < (int)bmif.height && j > 0 && j < (int)bmif.width){
                    arr[i][j].r = 255 - arr[i][j].r;
                    arr[i][j].b = 255 - arr[i][j].b;
                    arr[i][j].g = 255 - arr[i][j].g;
                }
        }
    }
}

void Image::drawLine(int x1, int y1, int x2, int y2, QColor color) {
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    //
    int error = deltaX - deltaY;
    //
    arr[x2][y2].b = color.blue();
    arr[x2][y2].g = color.green();
    arr[x2][y2].r = color.red();
    while(x1 != x2 || y1 != y2)
   {
        arr[x1][y1].b = color.blue();
        arr[x1][y1].g = color.green();
        arr[x1][y1].r = color.red();
        const int error2 = error * 2;
        //
        if(error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

int Image::drawLine_thick(int x1, int y1, int x2, int y2, int thick, QColor color){
    if(thick == 1){
        drawLine(x1, y1, x2, y2, color);
        return 0;
    }
    if (abs(y2-y1) > abs(x2-x1)){
            if (x1-thick/2 < 0 || x2-thick/2 < 0 || x1+thick/2 >= (int)bmif.height || x2+thick/2 >= (int)bmif.height)
                return 1;
            for (int i = -thick/2; i < thick/2; i++)
                drawLine(x1+i, y1, x2+i, y2, color);
        }
        else{
            if (y1-thick/2 < 0 || y2-thick/2 < 0 || y1+thick/2 >= (int)bmif.width || y2+thick/2 >= (int)bmif.width)
                return 1;
            for (int i = -thick/2; i < thick/2; i++)
                drawLine(x1, y1+i, x2, y2+i, color);
        }
        return 0;
}

void Image::flood(int x, int y, QColor color){
    if(arr[x][y].r==color.red() && arr[x][y].b == color.blue() && arr[x][y].g == color.green())
        return;
    arr[x][y].r = color.red();
    arr[x][y].b = color.blue();
    arr[x][y].g = color.green();
    Image::flood(x+1,y,color);
    Image::flood(x,y+1,color);
    Image::flood(x-1,y,color);    
    Image::flood(x,y-1,color);
    return;

}

void Image::middle(int x1, int y1, int x2, int y2, int x3, int y3){
    center.x = ((x1 + x2 - 2*x3)*((y3 - y1)*(x2 + x3 - 2*x1) + x1*(y2 + y3 - 2*y1)) - x3*(x2 + x3 - 2*x1)*(y1 + y2 - 2*y3))/((y2 + y3 - 2*y1)*(x1 + x2 - 2*x3) - (x2 + x3 - 2*x1)*(y1 + y2 - 2*y3));
    center.y = ((center.x - x1)*(y2 + y3 - 2*y1)/(x2 + x3 - 2*x1)) + y1;
}

void Image::draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int thik, QColor color){
    Image::drawLine_thick(x1, y1, x2, y2, thik, color);
    Image::drawLine_thick(x2, y2, x3, y3, thik, color);
    Image::drawLine_thick(x1,y1,x3,y3,thik,color);

}
int Image::draw_flood_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int thik, QColor floodcolor, QColor edgecolor){
    long long int square = 0.5*abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
    if(square > 120000)
        return 1;
    Image::drawLine_thick(x1, y1, x2, y2, 1, floodcolor);
    Image::drawLine_thick(x2, y2, x3, y3, 1, floodcolor);
    Image::drawLine_thick(x1, y1, x3, y3, 1, floodcolor);

    if(square > 100000){
        int Xm = (x1+x2)/2;
        int Ym = (y1+y2)/2;
        drawLine_thick(x3, y3, Xm, Ym, 1, floodcolor);
        long long int sq1 = 0.5*abs((Xm-x1)*(y3-y1)-(x3-x1)*(Ym-y1));
        if(sq1 > 100000){
            return 1;
        }
        Image::middle(x1,y1,Xm,Ym,x3,y3);
        Image::flood(center.x, center.y, floodcolor);
        long long int sq2 = 0.5*abs((Xm-x2)*(y3-y2)-(x3-x2)*(Ym-y2));
        if(sq2 > 100000){
            return 1;
        }
        Image::middle(x2,y2,Xm,Ym,x3,y3);
        Image::flood(center.x, center.y, floodcolor);
        Image::draw_triangle(x1, y1, x2, y2, x3, y3, thik, edgecolor);
        return 0;

    }
    Image::middle(x1,y1,x2,y2,x3,y3);
    Image::flood(center.x, center.y, floodcolor);
    Image::draw_triangle(x1, y1, x2, y2, x3, y3, thik, edgecolor);
    return 0;
}

void Image::cut(int x1, int y1, int x2, int y2){
    int newheight = x2 - x1;
    int newwidth = y2 - y1;
    int padding = 4 - (newwidth * 3)%4;
    Rgb** tmp = new Rgb*[newheight];
    for (int i = 0; i < newheight ; i++){
        tmp[i] = new Rgb [newwidth + 1];
    }
    for(int i = 0; i < newheight; i++){
        int j;
        for(j = 0; j < newwidth; j++){
            tmp[i][j].r = arr[i+x1][j+y1].r;
            tmp[i][j].b = arr[i+x1][j+y1].b;
            tmp[i][j].g = arr[i+x1][j+y1].g;
        }
        if (padding)
                    memset(&tmp[i][j], 0, size_t(padding));
    }
    for(int i = 0; i < (int)bmif.height; i++){
        delete arr[i];
    }
    delete arr;
    arr = tmp;
    bmif.height = newheight;
    bmif.width = newwidth;
}

