#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>

struct Info{
    QString name;
    QString path;
    int  height;
    int width;
    int weight;
    int depth;
};

namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    Info info;
    void writeinfo();
    ~information();

private slots:
    void on_ok_clicked();

private:
    Ui::information *ui;
};

#endif // INFORMATION_H
