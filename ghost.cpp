#include "ghost.h"

Ghost::Ghost(int num, int posx, int posy)
{
    mytime = new QTime;
    setGhostPos(posx,posy);
    ghostColor = num;
    setGhostColor(ghostColor);
    setDireciton(1);
}

QRectF Ghost::boundingRect() const
{
    return QRectF(posx-15,posy-15,30,30);
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->translate(-12,-29);
    if(ghostfear==0){
        if(direction == 1){
            if(ghostState%4 == 0 ||ghostState%4 == 1){
                painter->drawPixmap(posx-15,posy-15,30,30,ghostr1);
            }
            else{
                painter->drawPixmap(posx-15,posy-15,30,30,ghostr2);
            }
        }
        if(direction == 2){
            if(ghostState%4 == 0 ||ghostState%4 == 1)
                painter->drawPixmap(posx-15,posy-15,30,30,ghostd1);
            else
                painter->drawPixmap(posx-15,posy-15,30,30,ghostd2);
        }
        if(direction == 3){
            if(ghostState%4 == 0 ||ghostState%4 == 1)
                painter->drawPixmap(posx-15,posy-15,30,30,ghostl1);
            else
                painter->drawPixmap(posx-15,posy-15,30,30,ghostl2);
        }
        if(direction == 4){
            if(ghostState%4 == 0 ||ghostState%4 == 1)
                painter->drawPixmap(posx-15,posy-15,30,30,ghostu1);
            else
                painter->drawPixmap(posx-15,posy-15,30,30,ghostu2);
        }
    }
    if(ghostfear==1){
        if(ghostState%4 == 0 ||ghostState%4 == 1)
            painter->drawPixmap(posx-15,posy-15,30,30,scaredb1);
        else
            painter->drawPixmap(posx-15,posy-15,30,30,scaredb2);
    }
    if(ghostfear==2){
        if(ghostState%4 == 0 ||ghostState%4 == 1)
            painter->drawPixmap(posx-15,posy-15,30,30,scaredw1);
        else
            painter->drawPixmap(posx-15,posy-15,30,30,scaredw2);
    }
    if(ghostfear==3){
        painter->drawPixmap(posx-15,posy-15,30,30,eyeball);
    }


}

void Ghost::setGhostPos(int x,int y)
{
    this->posx = x;
    this->posy = y;
}

void Ghost::setGhostColor(int num)
{
    scaredb1.load(":/new/prefix1/images/ghostscaredblue1.png");
    scaredb2.load(":/new/prefix1/images/ghostscaredblue2.png");
    scaredw1.load(":/new/prefix1/images/ghostscaredwhite1.png");
    scaredw2.load(":/new/prefix1/images/ghostscaredwhite2.png");
    eyeball.load(":/new/prefix1/images/eyeball.png");
    switch (num) {
    case 1:
        ghostd1.load(":/new/prefix1/images/ghostdown1.png");
        ghostd2.load(":/new/prefix1/images/ghostdown2.png");
        ghostr1.load(":/new/prefix1/images/ghostright1.png");
        ghostr2.load(":/new/prefix1/images/ghostright2.png");
        ghostu1.load(":/new/prefix1/images/ghostup1.png");
        ghostu2.load(":/new/prefix1/images/ghostup2.png");
        ghostl1.load(":/new/prefix1/images/ghostleft1.png");
        ghostl2.load(":/new/prefix1/images/ghostleft2.png");
        break;
    case 2:
        ghostd1.load(":/new/prefix1/images/ghostdownblue1.png");
        ghostd2.load(":/new/prefix1/images/ghostdownblue2.png");
        ghostr1.load(":/new/prefix1/images/ghostrightblue1.png");
        ghostr2.load(":/new/prefix1/images/ghostrightblue2.png");
        ghostu1.load(":/new/prefix1/images/ghostupblue1.png");
        ghostu2.load(":/new/prefix1/images/ghostupblue2.png");
        ghostl1.load(":/new/prefix1/images/ghostleftblue1.png");
        ghostl2.load(":/new/prefix1/images/ghostleftblue2.png");
        break;
    case 3:
        ghostd1.load(":/new/prefix1/images/ghostdownorange1.png");
        ghostd2.load(":/new/prefix1/images/ghostdownorange2.png");
        ghostr1.load(":/new/prefix1/images/ghostrightorange1.png");
        ghostr2.load(":/new/prefix1/images/ghostrightorange2.png");
        ghostu1.load(":/new/prefix1/images/ghostuporange1.png");
        ghostu2.load(":/new/prefix1/images/ghostuporange2.png");
        ghostl1.load(":/new/prefix1/images/ghostleftorange1.png");
        ghostl2.load(":/new/prefix1/images/ghostleftorange2.png");
        break;
    case 4:
        ghostd1.load(":/new/prefix1/images/ghostdownred1.png");
        ghostd2.load(":/new/prefix1/images/ghostdownred2.png");
        ghostr1.load(":/new/prefix1/images/ghostrightred1.png");
        ghostr2.load(":/new/prefix1/images/ghostrightred2.png");
        ghostu1.load(":/new/prefix1/images/ghostupred1.png");
        ghostu2.load(":/new/prefix1/images/ghostupred2.png");
        ghostl1.load(":/new/prefix1/images/ghostleftred1.png");
        ghostl2.load(":/new/prefix1/images/ghostleftred2.png");
        break;
    default:
        break;

    }
}

void Ghost::setDireciton(int dir)
{
    direction = dir;
}

void Ghost::ghost1MovePath()
{
    qsrand(QTime::currentTime().msec()+3);
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }

}

void Ghost::ghost2MovePath()
{
    int count=0;
    qsrand(QTime::currentTime().msec()+6);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2)
        direction = qrand()%4+1;
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
}

void Ghost::ghost3MovePath()
{
    if(buttonPressed == true){
        direction = qrand()%4+1;
        while(!canmove(direction,posx,posy)){
            direction = qrand()%4+1;
        }
    }
    int count=0;
    qsrand(QTime::currentTime().msec()+1);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2)
        direction = qrand()%4+1;
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
    buttonPressed = false;
}

void Ghost::ghost4MovePath()
{
    int count=0;
    qsrand(QTime::currentTime().msec()+6);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2){
        direction = qrand()%4+1;
    }
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
}

bool Ghost::canmove(int a,int posx,int posy)
{
    switch (a) {
    case 1:
        if(posx==470 && posy == 290)
            return true;
        if(pathPoints[posx+1][posy]!=-1)
            return true;
        else
            return false;
    case 2:
        if(pathPoints[posx][posy+1]!=-1)
            return true;
        else
            return false;
    case 3:
        if(posx==10 && posy == 290)
            return true;
        if(pathPoints[posx-1][posy]!=-1)
            return true;
        else
            return false;
    case 4:
        if(pathPoints[posx][posy-1]!=-1)
            return true;
        else
            return false;
    default:
        break;
    }
}

void Ghost::move()//when ghost are scared
{
    if(ghostColor==1){
        ghost1MovePath();
        ghostState++;
    }
    if(ghostColor==2){
        ghost2MovePath();
        ghostState++;
    }
    if(ghostColor==3){
        ghost3MovePath();
        ghostState++;
    }
    if(ghostColor==4){
        ghost4MovePath();
        ghostState++;
    }
}

void Ghost::move(int pacx, int pacy)//when ghost are not scared
{
    if(ghostColor==1){
        ghostPriorityDirY(pacx,pacy);
        ghostState++;
    }
    if(ghostColor==2){
        ghostPriorityDirX(pacx,pacy);
        ghostState++;
    }
    if(ghostColor==3){
        ghostPriorityDirXY(pacx,pacy);
        ghostState++;
    }
    if(ghostColor==4){
        ghost4MovePath();
        ghostState++;
    }
}

void Ghost::pacChangeDir()
{
    buttonPressed = true;
}

void Ghost::ghostTurnBlue()
{
    ghostfear = 1;
}

void Ghost::ghostNotScared()
{
    ghostfear = 0;
}

void Ghost::ghostTurnWhite()
{
    ghostfear = 2;
}

void Ghost::ghostTurnEyeball()
{
    ghostfear = 3;
}

void Ghost::ghostPriorityDirX(int pacx, int pacy)
{
    int count=0;
    qsrand(QTime::currentTime().msec()+6);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2){
        int dirx=0,diry=0;
        if(pacx-posx>0)
            dirx = 1;
        if(pacx-posx<0)
            dirx = 3;
        if(pacy-posy>0)
            diry = 2;
        if(pacy-posy<0)
            diry = 4;
        if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;
        else if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
    }
    while(!canmove(direction,posx,posy)){
        int dirx=0,diry=0;
        if(pacx-posx>0)
            dirx = 1;
        if(pacx-posx<0)
            dirx = 3;
        if(pacy-posy>0)
            diry = 2;
        if(pacy-posy<0)
            diry = 4;
        if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;
        else if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
        if(!canmove(direction,posx,posy))
            direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
}

void Ghost::ghostPriorityDirY(int pacx, int pacy)
{
    int count=0;
    qsrand(QTime::currentTime().msec()+4);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(count>2){
        int dirx=0,diry=0;
        if(pacx-posx>0)
            dirx = 1;
        if(pacx-posx<0)
            dirx = 3;
        if(pacy-posy>0)
            diry = 2;
        if(pacy-posy<0)
            diry = 4;
        if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
        else if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;
    }
    while(!canmove(direction,posx,posy)){
        int dirx=0,diry=0;
        if(pacx-posx>0)
            dirx = 1;
        if(pacx-posx<0)
            dirx = 3;
        if(pacy-posy>0)
            diry = 2;
        if(pacy-posy<0)
            diry = 4;
        if(canmove(2,posx,posy)&&diry==2)
            direction = 2;
        else if(canmove(4,posx,posy)&&diry==4)
            direction = 4;
        else if(canmove(1,posx,posy)&&dirx==1)
            direction = 1;
        else if(canmove(3,posx,posy)&&dirx==3)
            direction = 3;

        if(!canmove(direction,posx,posy))
            direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
}

void Ghost::ghostPriorityDirXY(int pacx, int pacy)
{
    ++useless;
    int count=0;
    qsrand(QTime::currentTime().msec()+8);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;
    if(useless%2==0){
        if(count>2){
            int dirx=0,diry=0;
            if(pacx-posx>0)
                dirx = 1;
            if(pacx-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;
            else if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
        }
        while(!canmove(direction,posx,posy)){
            int dirx=0,diry=0;
            if(pacx-posx>0)
                dirx = 1;
            if(pacx-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;
            else if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
            if(!canmove(direction,posx,posy))
                direction = qrand()%4+1;
        }
    }
    else {
        if(count>2){
            int dirx=0,diry=0;
            if(pacx-posx>0)
                dirx = 1;
            if(pacx-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
            else if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;
        }
        while(!canmove(direction,posx,posy)){
            int dirx=0,diry=0;
            if(pacx-posx>0)
                dirx = 1;
            if(pacx-posx<0)
                dirx = 3;
            if(pacy-posy>0)
                diry = 2;
            if(pacy-posy<0)
                diry = 4;
            if(canmove(2,posx,posy)&&diry==2)
                direction = 2;
            else if(canmove(4,posx,posy)&&diry==4)
                direction = 4;
            else if(canmove(1,posx,posy)&&dirx==1)
                direction = 1;
            else if(canmove(3,posx,posy)&&dirx==3)
                direction = 3;

            if(!canmove(direction,posx,posy))
                direction = qrand()%4+1;
        }
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
}

int Ghost::getghostfear()
{
    return ghostfear;
}


/*void Ghost::findShortestDir(int pacx, int pacy,int step)//under circumstance that have more than 3 dir
{
    if(pacx-posx>0)
        dirx = 1;
    else if(pacx-posx<0)
        dirx = 3;
    else
        dirx = 0;
    if(pacy-posy>0)
        diry = 2;
    else if(pacy-posy<0)
        diry = 4;
    else
        diry = 0;
    switch(dirx){
    case 1:
        while(1){
            if(!canmove(1,checkPosX,checkPosY))
                break;
            checkPosX+=5;
            step += 5;
            if(pacx==checkPosX && pacy==checkPosY){
                if(step<lastShortDirCheck[1]){
                    lastShortDirCheck[1]=step;
                    lastShortDirCheck[0]=shortestDirCheck[0];
                }
                return;
            }
            int count = 0;
            if(pathPoints[checkPosX+1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY+1]!=-1)
                count++;
            if(pathPoints[checkPosX-1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY-1]!=-1)
                count++;

            if(count>2){//three ways
                findShortestDir(checkPosX,checkPosY,step);//determine the best direction
            }
            if(!canmove(1,checkPosX,checkPosY))//in corner
                findShortestDir(checkPosX,checkPosY,step);
        }
        break;
    case 3:
        while(1){
            if(!canmove(3,checkPosX,checkPosY))
                break;
            checkPosX-=5;
            step += 5;
            if(pacx==checkPosX && pacy==checkPosY){
                if(step<lastShortDirCheck[1]){
                    lastShortDirCheck[1]=step;
                    lastShortDirCheck[0]=shortestDirCheck[0];
                }
                return;
            }
            int count = 0;
            if(pathPoints[checkPosX+1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY+1]!=-1)
                count++;
            if(pathPoints[checkPosX-1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY-1]!=-1)
                count++;

            if(count>2){//three ways
                findShortestDir(checkPosX,checkPosY,step);//determine the best direction
            }
            if(!canmove(3,checkPosX,checkPosY))//in corner
                findShortestDir(checkPosX,checkPosY,step);
        }
        break;
    default:
        break;
    }
    switch(diry){
    case 2:
        while(1){
            if(!canmove(2,checkPosX,checkPosY))
                break;
            checkPosY+=5;
            step += 5;
            if(pacx==checkPosX && pacy==checkPosY){
                if(step<lastShortDirCheck[1]){
                    lastShortDirCheck[1]=step;
                    lastShortDirCheck[0]=shortestDirCheck[0];
                }
                return;
            }
            int count = 0;
            if(pathPoints[checkPosX+1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY+1]!=-1)
                count++;
            if(pathPoints[checkPosX-1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY-1]!=-1)
                count++;

            if(count>2){//three ways
                findShortestDir(checkPosX,checkPosY,step);//determine the best direction
            }
            if(!canmove(2,checkPosX,checkPosY))//in corner
                findShortestDir(checkPosX,checkPosY,step);
        }
        break;
    case 4:
        while(1){
            if(!canmove(4,checkPosX,checkPosY))
                break;
            checkPosX-=5;
            step += 5;
            if(pacx==checkPosX && pacy==checkPosY){
                if(step<lastShortDirCheck[1]){
                    lastShortDirCheck[1]=step;
                    lastShortDirCheck[0]=shortestDirCheck[0];
                }
                return;
            }
            int count = 0;
            if(pathPoints[checkPosX+1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY+1]!=-1)
                count++;
            if(pathPoints[checkPosX-1][checkPosY]!=-1)
                count++;
            if(pathPoints[checkPosX][checkPosY-1]!=-1)
                count++;

            if(count>2){//three ways
                findShortestDir(checkPosX,checkPosY,step);//determine the best direction
            }
            if(!canmove(4,checkPosX,checkPosY))//in corner
                findShortestDir(checkPosX,checkPosY,step);
        }
        break;
    default:
        break;
    }
}*/

/*void Ghost::allGhostPath(int pacx,int pacy)
{
    int count=0;
    qsrand(QTime::currentTime().msec()+10);
    if(pathPoints[posx+1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy+1]!=-1)
        count++;
    if(pathPoints[posx-1][posy]!=-1)
        count++;
    if(pathPoints[posx][posy-1]!=-1)
        count++;

    if(count>2){
        checkPosX = posx;
        checkPosY = posy;
        if(pacx-posx>0){
            shortestDirCheck[0] = 1;
            while(1){
                if(!canmove(1,checkPosX,checkPosY))
                    break;
                checkPosX+=5;
                step += 5;
                if(pacx==checkPosX && pacy==checkPosY){
                    if(step<lastShortDirCheck[1]){
                        lastShortDirCheck[1]=step;
                        lastShortDirCheck[0]=shortestDirCheck[0];
                    }
                    break;
                }
                int count = 0;
                if(pathPoints[checkPosX+1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY+1]!=-1)
                    count++;
                if(pathPoints[checkPosX-1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY-1]!=-1)
                    count++;

                if(count>2){//three ways
                    break;
                }
            }
        }
        if(pacx-posx<0){
            shortestDirCheck[0] = 3;
            while(1){
                if(!canmove(3,checkPosX,checkPosY))
                    break;
                checkPosX-=5;
                step += 5;
                if(pacx==checkPosX && pacy==checkPosY){
                    if(step<lastShortDirCheck[1]){
                        lastShortDirCheck[1]=step;
                        lastShortDirCheck[0]=shortestDirCheck[0];
                    }
                    break;
                }
                int count = 0;
                if(pathPoints[checkPosX+1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY+1]!=-1)
                    count++;
                if(pathPoints[checkPosX-1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY-1]!=-1)
                    count++;

                if(count>2){//three ways
                    break;
                }
            }
        }
        findShortestDir(pacx,pacy,step);//get the shortest dirx(shortestDirCheck[1])
        step = 0;
        dirx = 0;
        diry = 0;
        checkPosX = posx;
        checkPosY = posy;
        if(pacy-posy>0){
            shortestDirCheck[0] = 2;
            while(1){
                if(!canmove(2,checkPosX,checkPosY))
                    break;
                checkPosY+=5;
                step += 5;
                if(pacx==checkPosX && pacy==checkPosY){
                    if(step<lastShortDirCheck[1]){
                        lastShortDirCheck[1]=step;
                        lastShortDirCheck[0]=shortestDirCheck[0];
                    }
                    break;
                }
                int count = 0;
                if(pathPoints[checkPosX+1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY+1]!=-1)
                    count++;
                if(pathPoints[checkPosX-1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY-1]!=-1)
                    count++;

                if(count>2){//three ways
                    break;
                }
            }
        }
        if(pacy-posy<0){
            shortestDirCheck[0] = 4;
            while(1){
                if(!canmove(4,checkPosX,checkPosY))
                    break;
                checkPosY-=5;
                step += 5;
                if(pacx==checkPosX && pacy==checkPosY){
                    if(step<lastShortDirCheck[1]){
                        lastShortDirCheck[1]=step;
                        lastShortDirCheck[0]=shortestDirCheck[0];
                    }
                    break;
                }
                int count = 0;
                if(pathPoints[checkPosX+1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY+1]!=-1)
                    count++;
                if(pathPoints[checkPosX-1][checkPosY]!=-1)
                    count++;
                if(pathPoints[checkPosX][checkPosY-1]!=-1)
                    count++;

                if(count>2){//three ways
                    break;
                }
            }
        }
        findShortestDir(pacx,pacy,step);
        step = 0;
        dirx = 0;
        diry = 0;
        direction = lastShortDirCheck[0];
    }
    while(!canmove(direction,posx,posy)){
        direction = qrand()%4+1;
    }
    switch (direction) {
    case 1:
        if(posx == 470 && posy ==290)
            posx = 10;
        setGhostPos(posx+5,posy);
        break;
    case 2:
        setGhostPos(posx,posy+5);
        break;
    case 3:
        if(posx==10 && posy == 290)
            posx = 470;
        setGhostPos(posx-5,posy);
        break;
    case 4:
        setGhostPos(posx,posy-5);
        break;
    default:
        break;
    }
}*/
