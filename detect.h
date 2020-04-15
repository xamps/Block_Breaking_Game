#ifndef DETECT_H
#define DETECT_H
#include <QPainter>
#include "block.h"

class Detect
{
private:
    Block ball,striker;
    Block rect[10][10];
    QSize boundary;

public:
    Detect();
    Detect(QSize boundary);
    void draw(QPainter* p);
    void checkCollision(Block other);
    void setBoundary(QSize boundary);
    QColor nextColor();
    void createBlocks();
    //void checkCollisionStriker();
};
#endif // DETECT_H
