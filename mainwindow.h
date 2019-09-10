#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include "ball.h"
#include "graphicsscene.h"
#include "pacman.h"
#include "map.h"
#include "gameend.h"
#include "gameover.h"
#include "ghost.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void func();
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    int encounterGhost();
    bool eatPowerPill();
    void ghostTurnWhite();
    void ghostTurnBlue();
    void checkEncounterGhost();



    GraphicsScene *myscene;
    QTimer *myTimer,*ghostTimer,*ghost4Timer;
    GameEnd *gameend;
    gameover *g;

private slots:
    void update();
    void ghost1UpdateWhenScared();
    void ghost2UpdateWhenScared();
    void ghost3UpdateWhenScared();
    void ghost4UpdateWhenScared();
    void ghost1Update();
    void ghost2Update();
    void ghost3Update();
    void ghost4Update();
    void closeGame();
private:
    Map *ball;
    Map *pac;
    Map *myMap;
    Map *ghost1,*ghost2,*ghost3,*ghost4;
    QTime *t,*time1,*time2,*time3,*time4;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPainter *painter;
    int point=0;
    bool eyeTurnNormal1=false,eyeTurnNormal2=false,eyeTurnNormal3=false,eyeTurnNormal4=false;


};

#endif // MAINWINDOW_H
