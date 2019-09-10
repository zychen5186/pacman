#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myTimer = new QTimer(this);
    ghostTimer = new QTimer(this);
    ghost4Timer = new QTimer(this);
    t = new QTime;
    time1 = new QTime;
    time2 = new QTime;
    time3 = new QTime;
    time4 = new QTime;

    ui->setupUi(this);
    this->scene = new QGraphicsScene(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);
    myTimer->start(50);
    ghostTimer->start(70);
    ghost4Timer->start(50);

    scene->setBackgroundBrush(Qt::darkBlue);
    scene->addPixmap(QPixmap(":/new/prefix1/images/pac_map_old.png"));
    ball = new Ball();
    pac = new Pacman();
    myMap = new Map();
    ghost1 = new Ghost(1,430,70);
    ghost2 = new Ghost(2,40,70);
    ghost3 = new Ghost(3,40,550);
    ghost4 = new Ghost(4,430,550);
    scene->addItem(myMap);
    scene->addItem(ball);
    scene->addItem(pac);
    scene->addItem(ghost1);
    scene->addItem(ghost2);
    scene->addItem(ghost3);
    scene->addItem(ghost4);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1Update()));
    connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2Update()));
    connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3Update()));
    connect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4Update()));
    ui->label->setText("SCORE : ");
    ui->pointlabel->setNum(point);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{

    qDebug()<<e->x()<<e->y();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_D){
        pac->setDirection(1);
        static_cast<Ghost*>(ghost3)->pacChangeDir();
    }
    if(e->key()==Qt::Key_S){
        pac->setDirection(2);
        static_cast<Ghost*>(ghost3)->pacChangeDir();
    }
    if(e->key()==Qt::Key_A){
        pac->setDirection(3);
        static_cast<Ghost*>(ghost3)->pacChangeDir();
    }
    if(e->key()==Qt::Key_W){
        pac->setDirection(4);
        static_cast<Ghost*>(ghost3)->pacChangeDir();
    }
}

int MainWindow::encounterGhost()
{

    if((pac->pacx-6 < ghost1->posx && pac->pacx+6 > ghost1->posx && pac->pacy == ghost1->posy)||
       (pac->pacy-6 < ghost1->posy && pac->pacy+6 > ghost1->posy && pac->pacx == ghost1->posx)){
        if(static_cast<Ghost*>(ghost1)->getghostfear()==0){
            return 0;
        }
        else if(static_cast<Ghost*>(ghost1)->getghostfear()==1||static_cast<Ghost*>(ghost1)->getghostfear()==2){
            return 1;
        }
    }
    else if((pac->pacx-6 < ghost2->posx && pac->pacx+6 > ghost2->posx && pac->pacy == ghost2->posy)||
            (pac->pacy-6 < ghost2->posy && pac->pacy+6 > ghost2->posy && pac->pacx == ghost2->posx)){
        if(static_cast<Ghost*>(ghost2)->getghostfear()==0){
            return 0;
        }
        else if(static_cast<Ghost*>(ghost2)->getghostfear()==1||static_cast<Ghost*>(ghost2)->getghostfear()==2){
            return 2;
        }
    }
    else if((pac->pacx-6 < ghost3->posx && pac->pacx+6 > ghost3->posx && pac->pacy == ghost3->posy)||
            (pac->pacy-6 < ghost3->posy && pac->pacy+6 > ghost3->posy && pac->pacx == ghost3->posx)){
        if(static_cast<Ghost*>(ghost3)->getghostfear()==0){
            return 0;
        }
        else if(static_cast<Ghost*>(ghost3)->getghostfear()==1||static_cast<Ghost*>(ghost3)->getghostfear()==2){
            return 3;
        }
    }
    else if((pac->pacx-6 < ghost4->posx && pac->pacx+6 > ghost4->posx && pac->pacy == ghost4->posy)||
            (pac->pacy-6 < ghost4->posy && pac->pacy+6 > ghost4->posy && pac->pacx == ghost4->posx)){
        if(static_cast<Ghost*>(ghost4)->getghostfear()==0){
            return 0;
        }
        else if(static_cast<Ghost*>(ghost4)->getghostfear()==1||static_cast<Ghost*>(ghost4)->getghostfear()==2){
            return 4;
        }
    }
    return 5;
}

bool MainWindow::eatPowerPill()
{
    if(ball->pathPoints[pac->pacx][pac->pacy] == 3)
        return true;
    else {
        return false;
    }
}

void MainWindow::ghostTurnWhite()
{
    if((t->elapsed()>7000&&t->elapsed()<7100)||(t->elapsed()>8000&&t->elapsed()<8100)||(t->elapsed()>9000&&t->elapsed()<9100)){
        if(static_cast<Ghost*>(ghost1)->getghostfear()!=0&&static_cast<Ghost*>(ghost1)->getghostfear()!=3)
            static_cast<Ghost*>(ghost1)->ghostTurnWhite();
        if(static_cast<Ghost*>(ghost2)->getghostfear()!=0&&static_cast<Ghost*>(ghost2)->getghostfear()!=3)
            static_cast<Ghost*>(ghost2)->ghostTurnWhite();
        if(static_cast<Ghost*>(ghost3)->getghostfear()!=0&&static_cast<Ghost*>(ghost3)->getghostfear()!=3)
            static_cast<Ghost*>(ghost3)->ghostTurnWhite();
        if(static_cast<Ghost*>(ghost4)->getghostfear()!=0&&static_cast<Ghost*>(ghost4)->getghostfear()!=3)
            static_cast<Ghost*>(ghost4)->ghostTurnWhite();
    }
}

void MainWindow::ghostTurnBlue()
{
    if((t->elapsed()>7500&&t->elapsed()<7600)||(t->elapsed()>8500&&t->elapsed()<8600)||(t->elapsed()>9500&&t->elapsed()<9600)){

        if(static_cast<Ghost*>(ghost1)->getghostfear()!=0&&static_cast<Ghost*>(ghost1)->getghostfear()!=3)
            static_cast<Ghost*>(ghost1)->ghostTurnBlue();
        if(static_cast<Ghost*>(ghost2)->getghostfear()!=0&&static_cast<Ghost*>(ghost2)->getghostfear()!=3)
            static_cast<Ghost*>(ghost2)->ghostTurnBlue();
        if(static_cast<Ghost*>(ghost3)->getghostfear()!=0&&static_cast<Ghost*>(ghost3)->getghostfear()!=3)
            static_cast<Ghost*>(ghost3)->ghostTurnBlue();
        if(static_cast<Ghost*>(ghost4)->getghostfear()!=0&&static_cast<Ghost*>(ghost4)->getghostfear()!=3)
            static_cast<Ghost*>(ghost4)->ghostTurnBlue();
    }
}

void MainWindow::checkEncounterGhost()
{
    if(encounterGhost()==0){
        g = new gameover(point);
        g->show();
        connect(g,SIGNAL(closeGame()),this,SLOT(closeGame()));
        disconnect(myTimer,SIGNAL(timeout()),this,SLOT(update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1Update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2Update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3Update()));
        disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4Update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1UpdateWhenScared()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2UpdateWhenScared()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3UpdateWhenScared()));
        disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4UpdateWhenScared()));
    }
    else if(encounterGhost()==1){
        point+=200;
        ui->pointlabel->setNum(point);
        ghost1->posx = 430;
        ghost1->posy = 70;
        qDebug()<<"disconnectscared1aaaaa";
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1UpdateWhenScared()));
        time1->start();
        qDebug()<<time1->elapsed();
        static_cast<Ghost*>(ghost1)->ghostTurnEyeball();
        eyeTurnNormal1 = true;
    }
    else if(encounterGhost()==2){
        point+=200;
        ui->pointlabel->setNum(point);
        ghost2->posx = 40;
        ghost2->posy = 70;
        qDebug()<<"disconnectscared2aaaaa";
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2UpdateWhenScared()));
        time2->start();
        qDebug()<<time2->elapsed();
        static_cast<Ghost*>(ghost2)->ghostTurnEyeball();
        eyeTurnNormal2 = true;
    }
    else if(encounterGhost()==3){
        point+=200;
        ui->pointlabel->setNum(point);
        ghost3->posx = 40;
        ghost3->posy = 550;
        qDebug()<<"disconnectscared3aaaaa";
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3UpdateWhenScared()));
        time3->start();
        qDebug()<<time3->elapsed();
        static_cast<Ghost*>(ghost3)->ghostTurnEyeball();
        eyeTurnNormal3 = true;
    }
    else if(encounterGhost()==4){
        point+=200;
        ui->pointlabel->setNum(point);
        ghost4->posx = 430;
        ghost4->posy = 550;
        qDebug()<<"disconnectscared4aaaaa";
        disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4UpdateWhenScared()));
        time4->start();
        qDebug()<<time4->elapsed();
        static_cast<Ghost*>(ghost4)->ghostTurnEyeball();
        eyeTurnNormal4 = true;
    }
}

void MainWindow::update()
{
    pac->move();

    if(ball->pathPoints[pac->pacx][pac->pacy] == 1){//eat ball
        static_cast<Ball*>(ball)->clearPoints(pac->pacx,pac->pacy);//path are setted to 0 only in *ball
        point+=10;
        ui->pointlabel->setNum(point);
    }

    if(eatPowerPill()){//eat powerpill
        if(static_cast<Ghost*>(ghost1)->getghostfear()==0){
            qDebug()<<"disconnect1bbb connectscared1bbb";
            disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1Update()));
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost1)->getghostfear()==3){
            qDebug()<<"connectscared1bbb";
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost2)->getghostfear()==0){
            qDebug()<<"disconnect2bbb connectscared2bbb";
            disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2Update()));
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost2)->getghostfear()==3){
            qDebug()<<"connectscared2bbb";
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost3)->getghostfear()==0){
            qDebug()<<"disconnect3bbb connectscared3bbb";
            disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3Update()));
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost3)->getghostfear()==3){
            qDebug()<<"connectscared3bbb";
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost4)->getghostfear()==0){
            qDebug()<<"disconnect4bbb connectscared4bbb";
            disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4Update()));
            connect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost4)->getghostfear()==3){
            qDebug()<<"connectscared4bbb";
            connect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4UpdateWhenScared()));
        }
        static_cast<Ghost*>(ghost1)->ghostTurnBlue();
        static_cast<Ghost*>(ghost2)->ghostTurnBlue();
        static_cast<Ghost*>(ghost3)->ghostTurnBlue();
        static_cast<Ghost*>(ghost4)->ghostTurnBlue();
        t->start();
    }
    ghostTurnWhite();
    ghostTurnBlue();
    if(t->elapsed()>10000&&t->elapsed()<10100){
        if(static_cast<Ghost*>(ghost1)->getghostfear()!=0){
            qDebug()<<"disconnectscared1ccc connect1ccc";
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1Update()));
            disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost2)->getghostfear()!=0){
           qDebug()<<"disconnectscared2ccc connect2ccc";
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2Update()));
            disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost3)->getghostfear()!=0){
            qDebug()<<"disconnectscared3ccc connect3ccc";
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3Update()));
            disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3UpdateWhenScared()));
        }
        if(static_cast<Ghost*>(ghost4)->getghostfear()!=0){
            qDebug()<<"disconnectscared4ccc connect4ccc";
            connect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4Update()));
            disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4UpdateWhenScared()));
        }
        static_cast<Ghost*>(ghost1)->ghostNotScared();
        static_cast<Ghost*>(ghost2)->ghostNotScared();
        static_cast<Ghost*>(ghost3)->ghostNotScared();
        static_cast<Ghost*>(ghost4)->ghostNotScared();
    }
    if(ball->pathPoints[pac->pacx][pac->pacy] == 3){//check if eat powerpill
        static_cast<Ball*>(ball)->clearPoints(pac->pacx,pac->pacy);//path are setted to 0 only in *ball
        point+=50;
        ui->pointlabel->setNum(point);
    }

    if(static_cast<Ball*>(ball)->checkIfEnd()){//check if end
        gameend = new GameEnd(point);
        gameend->show();
        connect(gameend,SIGNAL(closeGame()),this,SLOT(closeGame()));
        disconnect(myTimer,SIGNAL(timeout()),this,SLOT(update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1Update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2Update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3Update()));
        disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4Update()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1UpdateWhenScared()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2UpdateWhenScared()));
        disconnect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3UpdateWhenScared()));
        disconnect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4UpdateWhenScared()));

    }
    //dqDebug()<<static_cast<Ghost*>(ghost1)->getghostfear()<<static_cast<Ghost*>(ghost2)->getghostfear()<<static_cast<Ghost*>(ghost3)->getghostfear()<<static_cast<Ghost*>(ghost4)->getghostfear();
    checkEncounterGhost();
    if(eyeTurnNormal1==true&&static_cast<Ghost*>(ghost1)->getghostfear()==3){
        if(time1->elapsed()>2000 && time1->elapsed()<2100){
            qDebug()<<"connect1 ddd";
            qDebug()<<"1";
            static_cast<Ghost*>(ghost1)->ghostNotScared();
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost1Update()));
            eyeTurnNormal1 = false;
        }
    }
    if(eyeTurnNormal2==true&&static_cast<Ghost*>(ghost2)->getghostfear()==3){
        if(time2->elapsed()>2000 && time2->elapsed()<2100){
            qDebug()<<"connect2 ddd";
            qDebug()<<"2";
            static_cast<Ghost*>(ghost2)->ghostNotScared();
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost2Update()));
            eyeTurnNormal2 = false;
        }
    }
    if(eyeTurnNormal3==true&&static_cast<Ghost*>(ghost3)->getghostfear()==3){
        if(time3->elapsed()>2000 && time3->elapsed()<2100){
            qDebug()<<"connect3 ddd";
            qDebug()<<"3";
            static_cast<Ghost*>(ghost3)->ghostNotScared();
            connect(ghostTimer,SIGNAL(timeout()),this,SLOT(ghost3Update()));
            eyeTurnNormal3 = false;
        }
    }
    if(eyeTurnNormal4==true&&static_cast<Ghost*>(ghost4)->getghostfear()==3){
        if(time4->elapsed()>2000 && time4->elapsed()<2100){
            qDebug()<<"connect4 ddd";
            qDebug()<<"4";
            static_cast<Ghost*>(ghost4)->ghostNotScared();
            connect(ghost4Timer,SIGNAL(timeout()),this,SLOT(ghost4Update()));
            eyeTurnNormal4 = false;
        }
    }
    scene->update();

}

void MainWindow::ghost1UpdateWhenScared()
{
    ghost1->move();
    scene->update();
}
void MainWindow::ghost2UpdateWhenScared()
{
    ghost2->move();
    scene->update();
}
void MainWindow::ghost3UpdateWhenScared()
{
    ghost3->move();
    scene->update();
}
void MainWindow::ghost4UpdateWhenScared()
{
    ghost4->move();
    scene->update();
}

void MainWindow::ghost1Update()
{
    static_cast<Ghost*>(ghost1)->move(pac->pacx,pac->pacy);
    scene->update();
}

void MainWindow::ghost2Update()
{
    static_cast<Ghost*>(ghost2)->move(pac->pacx,pac->pacy);
    scene->update();
}
void MainWindow::ghost3Update()
{
    static_cast<Ghost*>(ghost3)->move(pac->pacx,pac->pacy);
    scene->update();
}
void MainWindow::ghost4Update()
{
    static_cast<Ghost*>(ghost4)->move();
    scene->update();
}

void MainWindow::closeGame()
{
    close();
}
