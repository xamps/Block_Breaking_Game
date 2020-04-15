#include "block.h"

Block::Block() : Particle()
{
}
Block::Block(QRect shape)
{
    this->shape = shape;
    this->Location(Vector(shape.x(), shape.y()));
}
Block::Block(int x, int y, int width, int height)
{
    this->setBounds(x, y, width, height);
}
void Block::resized(QSize boundary)
{
    this->boundary = boundary;
}
void Block::setBounds(int x, int y, int width, int height)
{
    shape.setRect(x, y, width, height);
    this->Location(Vector(x, y));
}
void Block::setSize(QSize size)
{
    shape.setSize(size);
}
void Block::setBoundary(QSize boundary){
    this->boundary = boundary;
}
void Block::setColor(QBrush color)
{
    this->color = color;
}
void Block::setVisible(bool visible)
{
    this->visible = visible;
}
bool Block::intersects(Block other)
{
    return (shape.x()+shape.width()>other.shape.x() && other.shape.x() + other.shape.width() > shape.x() && other.shape.y()+other.shape.height()>shape.y() && other.shape.y() < shape.y() + shape.height());
}
void Block::move()
{
   Particle::move();
   shape = QRect(this->Location().intX(), this->Location().intY(), shape.width(), shape.height());
}
void Block::draw(QPainter* p)
{
    if(!visible) {
        return;
    }

    p->setRenderHint(QPainter::Antialiasing);
    p->setPen(QPen(Qt::black, 2));
    p->setBrush(color);

    if(circular) {
        p->drawEllipse(shape);
    } else {
        p->drawRect(shape);
    }
}
