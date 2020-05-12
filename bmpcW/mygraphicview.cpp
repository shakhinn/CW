#include "mainwindow.h"

MyGraphicView::MyGraphicView(QWidget* parent):QGraphicsView (parent)
{
    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);
      group = new QGraphicsItemGroup();

}
MyGraphicView::~MyGraphicView() {

}

void MyGraphicView::update(QPixmap pixmap){
    scene = new QGraphicsScene();
    scene->addPixmap(pixmap);
    this->setScene(scene);
}

void MyGraphicView::mousePressEvent(QMouseEvent *event){
    QPoint pos = mapToScene(event->pos()).toPoint();
    clicked.x1 = pos.x();
    clicked.y1 = pos.y();
}

void MyGraphicView::mouseReleaseEvent(QMouseEvent *event){
    QPoint pos = mapToScene(event->pos()).toPoint();
    clicked.x2 = pos.x();
    clicked.y2 = pos.y();
    if(botton_pressed == DRAW_TR && flag !=3){
        tre[flag].x = clicked.x1;
        tre[flag].y = clicked.y1;
        flag++;
        if(flag == 3)
            botton_pressed = 0;
    }
    if(botton_pressed == 0)
        emit selection();
}
