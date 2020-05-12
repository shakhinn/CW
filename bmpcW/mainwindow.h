#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QColorDialog>
#include <QColor>
#include "mygraphicview.h"
#include "image.h"
#include "information.h"
#include "instruction.h"

#define DRAW_CIRCLE 1
#define DRAW_LINE 2
#define DRAW_TR 3
#define DRAW_TR_TH 4
#define CUT 5

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selection();

    void on_open_triggered();

    void on_save_triggered();

    void on_draw_circle_clicked();

    void on_draw_line_clicked();

    void on_treg_clicked();

    void on_floodtreg_clicked();

    void on_cut_clicked();

    void on_test_clicked();

    void on_info_triggered();

    void on_instruction_triggered();

private:
    QColor color;
    QColor floodcolor;
    QColor edgecolor;
    information* inform;
    instruction* instruct;
    Image* img;
    MyGraphicView* picture;
    int button_pressed = 0;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
