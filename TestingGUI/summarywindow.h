#ifndef SUMMARYWINDOW_H
#define SUMMARYWINDOW_H

#include <QMainWindow>

namespace Ui {
class SummaryWindow;
}

class SummaryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SummaryWindow(QWidget *parent = 0);
    ~SummaryWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SummaryWindow *ui;
};

#endif // SUMMARYWINDOW_H
