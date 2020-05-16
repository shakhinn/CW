#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inform = new information();
    instruct = new instruction();
    img = new Image();
    picture = new MyGraphicView();
    connect(picture, SIGNAL(selection()),this, SLOT(selection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_triggered()
{
    QString path = QFileDialog::getOpenFileName(nullptr, "Выберете файл", "/home/user", "*.bmp");
    if(path == nullptr)
        return;
    int error = img->loadImage(path.toLocal8Bit().constData());
    if (error == -1){
        QMessageBox::critical(this, "Ошибка", "Невозможно прочитать файл");
        return;
    }
    if (error == -3){
        QMessageBox::critical(this, "Ошибка", "Программа не поддерживает сжатые файлы");
        return;
    }
    if(error == -4){
        QMessageBox::critical(this, "Ошибка", "Программа поддреживает картинки только с глубиной 24.\n Попробкйте другую картинку");
        return;
    }
    picture->update(img->getPixmap());
    ui->gridLayout->addWidget(picture);
    inform->info.name = QFileInfo(path).baseName();
    inform->info.path = QFileInfo(path).filePath();
    inform->info.height = img->bmif.height;
    inform->info.width = img->bmif.width;
    inform->info.depth = img->bmif.bitsPerPixel;
    inform->info.weight = img->bmfh.filesize;
}

void MainWindow::on_save_triggered(){
    if(img->bmif.width == 0 || img->bmif.height == 0){
        QMessageBox::critical(this, "Ошибка", "Невозможно сохранить пустое изображение");
                return;
    }
    QString path = QFileDialog::getSaveFileName(nullptr, "Выберете путь", "/home/user", "*.bmp");
    int error = img->saveImage(path.toLocal8Bit().constData());
    if(error == -1){
        QMessageBox::critical(this, "Ошибка", "Невозможно сохранить файл");
        return;
    }
}



void MainWindow::selection(){    
    if(button_pressed == DRAW_CIRCLE){
        if(picture->clicked.x1 > (int)img->bmif.width || picture->clicked.y1 > (int)img->bmif.height || picture->clicked.x1 < 0 || picture->clicked.y1 < 0 || picture->clicked.x2 > (int)img->bmif.width || picture->clicked.y2 > (int)img->bmif.height || picture->clicked.x2 < 0 || picture->clicked.y2 < 0){
            QMessageBox::critical(this, "Ошибка", "точки выходят за границы изображения");
            button_pressed = 0;
            return;
        }
        int rad = ui->radius->value();
        img->drawCircle(img->bmif.height-picture->clicked.y1, picture->clicked.x1, rad);
        picture->update(img->getPixmap());
        button_pressed = 0;
    }
    else if(button_pressed == DRAW_LINE){
        if(picture->clicked.x1 > (int)img->bmif.width || picture->clicked.y1 > (int)img->bmif.height || picture->clicked.x1 < 0 || picture->clicked.y1 < 0 ||
                picture->clicked.x2 > (int)img->bmif.width || picture->clicked.y2 > (int)img->bmif.height || picture->clicked.x2 < 0 || picture->clicked.y2 < 0){
            QMessageBox::critical(this, "Ошибка", "точки выходят за границы изображения");
            button_pressed = 0;
            return;
        }
        int thick = ui->thick->value();
        int mistake =  img->drawLine_thick(img->bmif.height-picture->clicked.y1, picture->clicked.x1, img->bmif.height-picture->clicked.y2, picture->clicked.x2, thick, color);
        if(mistake){
            QMessageBox::critical(this,"Ошибка","чтобы нарисовать линию рядом с краем уменьшите её ширину");
        }
        picture->update(img->getPixmap());
        button_pressed = 0;
    }
    else if(button_pressed == DRAW_TR){
        if(picture->tre[0].x > (int)img->bmif.width || picture->tre[0].y > (int)img->bmif.height || picture->tre[0].x < 0 || picture->tre[0].y < 0 ||
                picture->tre[1].x > (int)img->bmif.width || picture->tre[1].y > (int)img->bmif.height || picture->tre[1].x < 0 || picture->tre[1].y < 0 ||
                picture->tre[2].x > (int)img->bmif.width || picture->tre[2].y > (int)img->bmif.height || picture->tre[2].x < 0 || picture->tre[2].y < 0 ){
            QMessageBox::critical(this, "Ошибка", "точки выходят за границы изображения");
            button_pressed = 0;
            return;
        }
        int thik = ui->tregthik->value();
        img->draw_triangle(img->bmif.height-picture->tre[0].y, picture->tre[0].x, img->bmif.height-picture->tre[1].y, picture->tre[1].x, img->bmif.height-picture->tre[2].y, picture->tre[2].x,thik, edgecolor);
        picture->update(img->getPixmap());
        button_pressed = 0;
    }
    else if(button_pressed == DRAW_TR_TH){
        if(picture->tre[0].x > (int)img->bmif.width || picture->tre[0].y > (int)img->bmif.height || picture->tre[0].x < 0 || picture->tre[0].y < 0 ||
                picture->tre[1].x > (int)img->bmif.width || picture->tre[1].y > (int)img->bmif.height || picture->tre[1].x < 0 || picture->tre[1].y < 0 ||
                picture->tre[2].x > (int)img->bmif.width || picture->tre[2].y > (int)img->bmif.height || picture->tre[2].x < 0 || picture->tre[2].y < 0 ){
            QMessageBox::critical(this, "Ошибка", "точки выходят за границы изображения");
            button_pressed = 0;
            return;
        }
        int thik = ui->tregthik->value();
        int mistake = img->draw_flood_triangle(img->bmif.height-picture->tre[0].y, picture->tre[0].x, img->bmif.height-picture->tre[1].y, picture->tre[1].x, img->bmif.height-picture->tre[2].y, picture->tre[2].x,thik,floodcolor, edgecolor);
        if(mistake){
            QMessageBox::critical(this, "треугольник слишком большой", "выберете треугольник поменьше");
            return;
        }
        picture->update(img->getPixmap());
        button_pressed = 0;
    }
    else if(button_pressed == CUT){
        if(picture->clicked.x1 < picture->clicked.x2 && picture->clicked.y1 < picture->clicked.y2){
            img->cut(img->bmif.height-picture->clicked.y2, picture->clicked.x1, img->bmif.height-picture->clicked.y1, picture->clicked.x2);
            inform->info.height = img->bmif.height;
            inform->info.width = img->bmif.width;
            picture->update(img->getPixmap());
            button_pressed = 0;
        }
        else{
            QMessageBox::critical(this,"Ошибка", "сначала ЛЕВАЯ ВЕРХНЯЯ потом ПРАВАЯ НИЖНЯЯ границы");
            button_pressed = 0;
            return;
        }
    }
}

void MainWindow::on_draw_circle_clicked()
{
    if(img->bmif.width == 0 || img->bmif.height == 0){
        QMessageBox::critical(this,"Ошибка!", "загрузите изображение");
        return;
    }
    button_pressed = DRAW_CIRCLE;

}

void MainWindow::on_draw_line_clicked()
{
    if(img->bmif.width == 0 || img->bmif.height == 0){
        QMessageBox::critical(this,"Ошибка!", "загрузите изображение");
        return;
    }
    color = QColorDialog::getColor();
    button_pressed = DRAW_LINE;
}

void MainWindow::on_treg_clicked()
{
    if(img->bmif.width == 0 || img->bmif.height == 0){
        QMessageBox::critical(this,"Ошибка!", "загрузите изображение");
        return;
    }
    edgecolor = QColorDialog::getColor();
    picture->botton_pressed = DRAW_TR;
    picture->flag = 0;
    button_pressed = DRAW_TR;
}

void MainWindow::on_floodtreg_clicked()
{
    if(img->bmif.width == 0 || img->bmif.height == 0){
        QMessageBox::critical(this,"Ошибка!", "загрузите изображение");
        return;
    }
    edgecolor = QColorDialog::getColor();
    floodcolor = QColorDialog::getColor();
    picture->botton_pressed = DRAW_TR;
    picture->flag = 0;
    button_pressed = DRAW_TR_TH;
}

void MainWindow::on_cut_clicked()
{
    if(img->bmif.width == 0 || img->bmif.height == 0){
        QMessageBox::critical(this,"Ошибка!", "загрузите изображение");
        return;
    }
    button_pressed = CUT;
}



void MainWindow::on_info_triggered()
{
    if(img->bmif.height == 0 || img->bmif.width == 0){
        QMessageBox::critical(this, "Ошибка", "загрузите изобажение");
        return;
    }
    inform->writeinfo();
    inform->exec();
}

void MainWindow::on_instruction_triggered()
{
    instruct->exec();
}
