#ifndef GRAPHWINDOWPIE_H
#define GRAPHWINDOWPIE_H

#include <QDialog>

namespace Ui {
class graphwindowpie;
}

class graphwindowpie : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowpie(QWidget *parent = 0);
    ~graphwindowpie();

private:
    Ui::graphwindowpie *ui;
};

#endif // GRAPHWINDOWPIE_H
