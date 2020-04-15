#include "detect.h"
#include <QPainter>
Detect::Detect()
{
}
Detect::Detect(QSize boundary)
{
    this->boundary = boundary;
}

void Detect::setBoundary(QSize boundary) {
    this->boundary = boundary;
}
QColor Detect::nextColor() {
    int h = (std::rand() * 10000) % 255;
    int s = (std::rand() * 10000) % 255;
    int l = (std::rand() * 10000) % 255;

    return QColor::fromHsl(h, s, l);
}
void Detect::checkCollision(Block other)
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(rect[i][j].intersects(other))
            {
                rect[i][j].setVisible(false);
            }
        }
    }
}
void Detect::createBlocks()
{
    int k=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            rect[i][j].setBounds((boundary.width()/10)*j,25*k,boundary.width()/10,25);
            //rect[i][j] = Block((boundary.width()/10)*j,boundary.height()-50,boundary.width()/10,50);
            rect[i][j].setBoundary(boundary);
        }
        k++;
    }
}
void Detect::draw(QPainter *p)
{
    int k=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            rect[i][j].setColor(nextColor());
            rect[i][j].draw(p);
        }
        k++;
    }
}
