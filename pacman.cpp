#include "pacman.h"

Pacman::Pacman()
{
    setPos(190,340);
    direction = 1;
    setDirection(1);
    up0.load(":/new/prefix1/images/paccloseu.png");
    up1.load(":/new/prefix1/images/pacopen1u.png");
    up2.load(":/new/prefix1/images/pacopen2u.png");
    up3.load(":/new/prefix1/images/pacopen3u.png");

    left0.load(":/new/prefix1/images/pacclosel.png");
    left1.load(":/new/prefix1/images/pacopen1l.png");
    left2.load(":/new/prefix1/images/pacopen2l.png");
    left3.load(":/new/prefix1/images/pacopen3l.png");

    down0.load(":/new/prefix1/images/pacclosed.png");
    down1.load(":/new/prefix1/images/pacopen1d.png");
    down2.load(":/new/prefix1/images/pacopen2d.png");
    down3.load(":/new/prefix1/images/pacopen3d.png");

    right0.load(":/new/prefix1/images/pacclose.png");
    right1.load(":/new/prefix1/images/pacopen1.png");
    right2.load(":/new/prefix1/images/pacopen2.png");
    right3.load(":/new/prefix1/images/pacopen3.png");

}

QRectF Pacman::boundingRect() const
{
    return QRectF(posx-15,posy-15,30,30);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->translate(-12,-29);


    if(direction == 1){
        if(pacState%4 == 0)
            painter->drawPixmap(pacx-15,pacy-15,30,30,right0);
        if(pacState%4 == 1)
            painter->drawPixmap(pacx-15,pacy-15,30,30,right1);
        if(pacState%4 == 2)
            painter->drawPixmap(pacx-15,pacy-15,30,30,right2);
        if(pacState%4 == 3)
            painter->drawPixmap(pacx-15,pacy-15,30,30,right3);
    }
    if(direction == 2){
        if(pacState%4 == 0)
            painter->drawPixmap(pacx-15,pacy-15,30,30,down0);
        if(pacState%4 == 1)
            painter->drawPixmap(pacx-15,pacy-15,30,30,down1);
        if(pacState%4 == 2)
            painter->drawPixmap(pacx-15,pacy-15,30,30,down2);
        if(pacState%4 == 3)
            painter->drawPixmap(pacx-15,pacy-15,30,30,down3);
    }
    if(direction == 3){
        if(pacState%4 == 0)
            painter->drawPixmap(pacx-15,pacy-15,30,30,left0);
        if(pacState%4 == 1)
            painter->drawPixmap(pacx-15,pacy-15,30,30,left1);
        if(pacState%4 == 2)
            painter->drawPixmap(pacx-15,pacy-15,30,30,left2);
        if(pacState%4 == 3)
            painter->drawPixmap(pacx-15,pacy-15,30,30,left3);
    }
    if(direction == 4){
        if(pacState%4 == 0)
            painter->drawPixmap(pacx-15,pacy-15,30,30,up0);
        if(pacState%4 == 1)
            painter->drawPixmap(pacx-15,pacy-15,30,30,up1);
        if(pacState%4 == 2)
            painter->drawPixmap(pacx-15,pacy-15,30,30,up2);
        if(pacState%4 == 3)
            painter->drawPixmap(pacx-15,pacy-15,30,30,up3);
    }

}

void Pacman::setPos(int x,int y)
{
    pacx = x;
    pacy = y;
}


void Pacman::setDirection(int a)
{
    nextDirection = a;
}

void Pacman::move()//check if the next position moveable
{
    if(nextDirection != direction){
        if(nextDirection==1){//right
            for (int i=0;i<9;++i){
                if(pathPoints[pacx+5][pacy-i]!=-1){
                    direction=1;
                    setPos(pacx,pacy-i);
                    ++pacState;
                    break;
                }
                if(pathPoints[pacx+5][pacy+i]!=-1){
                    direction=1;
                    setPos(pacx,pacy+i);
                    ++pacState;
                    break;
                }
            }
            nextDirection = direction;
        }
        if(nextDirection==2){//down
            for (int i=0;i<9;++i) {
                if(pathPoints[pacx-i][pacy+5]!=-1){
                    direction=2;
                    setPos(pacx-i,pacy);
                    ++pacState;
                    break;
                }
                if(pathPoints[pacx+i][pacy+5]!=-1){
                    direction=2;
                    setPos(pacx+i,pacy);
                    ++pacState;
                    break;
                }
            }
            nextDirection = direction;
        }
        if(nextDirection==3){//left
            for (int i=0;i<9;++i) {
                if(pathPoints[pacx-5][pacy-i]!=-1){
                    direction=3;
                    setPos(pacx,pacy-i);
                    ++pacState;
                    break;
                }
                if(pathPoints[pacx-5][pacy+i]!=-1){
                    direction=3;
                    setPos(pacx,pacy+i);
                    ++pacState;
                    break;
                }
            }
            nextDirection = direction;
        }
        if(nextDirection==4){//up
            for (int i=0;i<9;++i) {
                if(pathPoints[pacx-i][pacy-5]!=-1){
                    direction=4;
                    setPos(pacx-i,pacy);
                    ++pacState;
                    break;
                }
                if(pathPoints[pacx+i][pacy-5]!=-1){
                    direction=4;
                    setPos(pacx+i,pacy);
                    ++pacState;
                    break;
                }
            }
            nextDirection = direction;
        }
    }
    else {

        if(direction==1){//right
            if(pacx == 470 && pacy ==290)
                pacx = 10;
            if(pathPoints[pacx+1][pacy]!=-1){
                setPos(pacx+5,pacy);
                ++pacState;
            }
        }
        if(direction==2){//down
            if(pathPoints[pacx][pacy+1]!=-1){
                setPos(pacx,pacy+5);
                ++pacState;
            }
        }
        if(direction==3){//left
            if(pacx==10 && pacy == 290)
                pacx = 470;
            if(pathPoints[pacx-1][pacy]!=-1){
             setPos(pacx-5,pacy);
                ++pacState;
            }
        }
        if(direction==4){//up
            if(pathPoints[pacx][pacy-1]!=-1){
                setPos(pacx,pacy-5);
                ++pacState;
            }
        }
    }
}
