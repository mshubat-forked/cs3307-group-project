#ifndef LEGENDWIDGET_H
#define LEGENDWIDGET_H

#include <QWidget>
#include <QRectf>

class LegendWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LegendWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // LEGENDWIDGET_H
