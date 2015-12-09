#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <DataEntry/teaching_entry.h>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_new_file_button_clicked();
    void on_last_session_button_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
