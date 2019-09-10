#ifndef PACMAN_H
#define PACMAN_H
#include "map.h"


class Pacman : public Map
{
public:
    Pacman();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPos(int x,int y);
    void move();
    void setDirection(int a);


private:
    int pacState=0;
    int direction,nextDirection;//1 right, 2 down, 3 left, 4 up
    QPixmap up0,up1,up2,up3,right0,right1,right2,right3,down0,down1,down2,down3,left0,left1,left2,left3;
};

#endif // PACMAN_H
