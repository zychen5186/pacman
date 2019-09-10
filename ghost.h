#ifndef GHOST_H
#define GHOST_H
#include "map.h"
#include <QTime>
#include <QTimer>
#include <qrandom.h>
#include <QElapsedTimer>

class Ghost : public Map
{
public:
    Ghost(int num, int posx, int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setGhostPos(int x, int y);
    void setGhostColor(int num);
    void setDireciton(int dir);
    void ghost1MovePath();
    void ghost2MovePath();
    void ghost3MovePath();
    void ghost4MovePath();
    bool canmove(int a, int posx, int posy);
    void move();
    void move(int pacx,int pacy);
    void pacChangeDir();
    void ghostTurnBlue();
    void ghostNotScared();
    void ghostTurnWhite();
    void ghostTurnEyeball();
    int getghostfear();
    void ghostPriorityDirX(int pacx,int pacy);
    void ghostPriorityDirY(int pacx,int pacy);
    void ghostPriorityDirXY(int pacx,int pacy);
    int ghostColor;
    void findShortestDir(int pacx,int pacy,int step);
    void allGhostPath(int pacx,int pacy);

    QTime *mytime;

private:
    int checkPosX,checkPosY,dirx=0,diry=0;
    int ghostNum;
    int useless=0;
    int shortestDirCheck[2]={0,0},lastShortDirCheck[2]={0,0},step=0;
    bool buttonPressed;
    int direction,nextDirection,ghostState=0;
    int ghostfear=0;//0 normal, 1 blue, 2 white, 3 eyeball
    QPixmap ghostr1,ghostr2,ghostd1,ghostd2,ghostl1,ghostl2,ghostu1,ghostu2,scaredw1,scaredw2,scaredb1,scaredb2,eyeball;

};

#endif // GHOST_H
