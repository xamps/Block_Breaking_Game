#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QRect>
#include "detect.h"
#include <QResizeEvent>
#include <QMouseEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setPrintData(QString value);

protected:
    QPoint pos;
    Detect d;
    Block ball, striker;
    int r;
    bool needToApplyForce;
    Vector restLocaion;

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void striker_touch();
private:
    QString printData;
    void move();
    void updateComponents();
};
#endif // WIDGET_H
