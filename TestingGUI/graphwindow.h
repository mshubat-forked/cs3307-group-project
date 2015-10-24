#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <qcustomplot.h>

namespace Ui {
class graphwindow;
}

class graphwindow : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindow(QWidget *parent = 0);
    ~graphwindow();

private slots:
    void make_plot();

private:
    Ui::graphwindow *ui;
};

#endif // GRAPHWINDOW_H
