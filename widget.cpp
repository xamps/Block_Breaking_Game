#include "widget.h"
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    r = 50;
    needToApplyForce = false;

    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    updateComponents();

    startTimer(15);
}

Widget::~Widget()
{
}

void Widget::setPrintData(QString value){
   printData = value;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    ball.draw(&p);
    striker.draw(&p);
    d.draw(&p);
    p.drawText(ball.Location().intX(), ball.Location().intY(), QString::number(ball.Velocity().magnitude()));
}
void Widget::timerEvent(QTimerEvent *event)
{
    d.checkCollision(ball);
    if(ball.intersects(striker)) {
        striker_touch();
    }
    move();
    repaint();
}

void Widget::resizeEvent(QResizeEvent *event)
{
   updateComponents();
}
void Widget::updateComponents()
{
    d.setBoundary(this->size());
    d.createBlocks();

    striker.setBounds(width()-50,height()-40,100,30);
    striker.setColor(Qt::yellow);

    QPoint translatedPos;

    if(pos.x() == 0 && pos.y() == 0) {
        translatedPos.setX(width() - r);
        translatedPos.setY(height() - r);
    } else {
        translatedPos = pos;
    }

    ball.setBounds(translatedPos.x(),translatedPos.y(),r,r);
    ball.setColor(Qt::red);
    ball.circular = true;
    ball.Velocity(Vector(4, 4));
}
void Widget::striker_touch()
{
    needToApplyForce = true;
    Vector v = ball.Velocity();
    v.mirrorY();
    ball.Velocity(v);
}
void Widget::move() {
    Vector v = ball.Velocity();
    Vector l = ball.Location();
    if(pos.x() < 0 || pos.x() + r > width()) {
        int ds;
        if(pos.x() < 0 && (ds = -pos.x()) < v.x) {
            l.x += ds;
        } else if((ds = pos.x() - width()) > v.x) {
            l.x -= ds;
        }
        v.mirrorX();
    }
    if(pos.y() < 0 || pos.y() + r > height()) {
        int ds;
        if(pos.y() < 0 && (ds = -pos.y()) < v.y) {
            l.y += ds;
        } else if((ds = pos.y() - height()) > v.y) {
            l.y -= ds;
        }
        v.mirrorY();
    }


    ball.Location(l);
    ball.Velocity(v);
    ball.move();

    v = ball.Velocity();
    v.limit(-5, 5);
    ball.Velocity(v);

    pos.setX(ball.Location().intX());
    pos.setY(ball.Location().intY());
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x() + 100 > width()) {
        return;
    }
    striker.setBounds(event->x(), height()-40,100,30);

    if(needToApplyForce) {
        needToApplyForce = false;
        Vector force = Vector::sub(striker.Location(), restLocaion);
        Vector direction = force.copy();
        direction.normalize();
        force.y = 0;
        if(direction.x<0)
        {
         force.mirrorX();
        ball.applyForce(force);
        }
        else
        {
            ball.applyForce(force);
        }
    }

    restLocaion.x = event->x();
    restLocaion.y = event->y();
    restLocaion.z = 0;
    repaint();
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
//    ball.applyForce(Vector(3, 1));
}
