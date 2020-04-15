#ifndef BLOCK_H
#define BLOCK_H
#include <QtCore>
#include <QPainter>
#include <QBrush>
#include <QPoint>
#include <QRect>
#include <QSize>
#include "particle.h"

class Block : public Particle
{
private:
    QSize boundary;
    QBrush color;
    bool visible=true;

public:
    QRect shape;
    bool circular=false;

    Block();
    Block(QRect shape);
    Block(int x, int y, int width, int height);
    void resized(QSize boundary);
    void setBounds(int x, int y, int width, int height);
    void setSize(QSize size);
    void setBoundary(QSize boundary);
    void setColor(QBrush color);
    void setVisible(bool visible);
    bool intersects(Block block);
    void draw(QPainter* p);
    void move();
};
#endif // BLOCK_H
