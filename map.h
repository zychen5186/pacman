#ifndef MAP_H
#define MAP_H
#include <QVector>
#include <QPoint>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QCoreApplication>
class Map : public QGraphicsItem
{
public:
    Map();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addPathPoints(int a,int b,int c,int d);
    int pathPoints[480][570];//-1 wall, 0 empty, 1 ball, 2 pacman, 3 powerpill, 4 ghost
    virtual void move();
    //virtual void setPos(int x,int y);
    virtual void setDirection(int a);
    int posx,posy;//ghost position
    int pacx,pacy;//pacman position
private:

    QRectF m_boundingRect;
};


#endif // MAP_H
