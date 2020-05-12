#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QColor>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>

struct point{
    int x;
    int y;
};

struct coorditate{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
};

class MyGraphicView: public QGraphicsView
{
    Q_OBJECT
public:
    int botton_pressed = 0;
    int flag = 3;
    point tre[3];
    QPoint* pos;
    coorditate clicked;
    void update(QPixmap pixmap);
    explicit MyGraphicView(QWidget* parent = nullptr);
    ~MyGraphicView();
private:
    QGraphicsItemGroup* group;
    QPixmap pixmap;
    QGraphicsScene* scene;

signals:
    void selection();
private slots:
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYGRAPHICVIEW_H
