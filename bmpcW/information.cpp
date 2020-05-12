#include "information.h"
#include "ui_information.h"

information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
}

information::~information()
{
    delete ui;
}

void information::writeinfo(){
    ui->name->setText(info.name.toLocal8Bit().constData());
    ui->path->setText(info.path.toLocal8Bit().constData());
    ui->height->setText(QString::number(info.height));
    ui->width->setText(QString::number(info.width));
    ui->size->setText(QString::number(info.weight));
    ui->depth->setText(QString::number(info.depth));
}

void information::on_ok_clicked()
{
    this->close();
}
