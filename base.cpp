#include "base.h"

Base::Base()
{

}

QRectF Base::boundingRect() const
{
    return QRectF();
}

void Base::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawPixmap(100,100,100,100,QPixmap(":/new/prefix1/images/pacopen1.png"));
}

void Base::move()
{

}

Base::~Base()
{

}
