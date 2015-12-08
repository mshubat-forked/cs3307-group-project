#ifndef GRAPH_SETUP_WINDOW_H
#define GRAPH_SETUP_WINDOW_H

#include <QDialog>

namespace Ui {
class graph_setup_window;
}

class graph_setup_window : public QDialog
{
    Q_OBJECT

public:
    explicit graph_setup_window(QWidget *parent = 0);
    ~graph_setup_window();

private:
    Ui::graph_setup_window *ui;
};

#endif // GRAPH_SETUP_WINDOW_H
