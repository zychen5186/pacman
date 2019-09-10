#ifndef BASE_H
#define BASE_H
#include <QGraphicsItem>
#include <QPainter>

class Base : public QGraphicsItem
{
public:
    Base();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void move();
    virtual ~Base();
};

#endif // BASE_H
