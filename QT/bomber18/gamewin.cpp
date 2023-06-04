#include "gamewin.h"
#include<choosewin.h>
#include<qpushbutton.h>
#include<QPainter>
#include<QMenuBar>
#include<mainwindow.h>
#include<mybutton.h>
#include<qlabel.h>
#include<man.h>
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>
#include<QSound>

int allmap[12][13][23]={
    {
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,2,0,2,0,0,2,2,0,0,2,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,1,2,1,0,1,2,1,0,1,0,1,2,1},
        {0,0,0,0,0,0,1,2,0,0,4,0,0,0,0,0,2,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,2,1,2,1,2,1,0,1,2,1,2,1,2,1},
        {0,0,0,0,0,0,1,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,1},
        {0,0,0,0,0,0,1,2,2,2,1,2,2,2,1,2,1,0,2,0,1,0,1},
        {0,0,0,0,0,0,1,0,2,0,2,0,0,2,0,2,0,0,2,2,0,2,1},
        {0,0,0,0,0,0,1,0,1,2,1,2,1,0,1,0,1,0,2,0,1,0,1},
        {0,0,0,0,0,0,1,2,1,0,2,0,0,2,0,0,2,0,2,2,0,2,1},
        {0,0,0,0,0,0,1,0,1,0,1,2,1,0,1,2,1,2,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,2,2,0,2,0,2,0,0,2,2,2,0,2,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,2,0,0,0,0,2,1,0,0,2,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,2,0,2,1,1,2,1,0,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,2,1,0,0,2,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,1,0,1,2,1,2,1,0,1,2,1,0,2,2,1},
        {0,0,0,0,0,0,1,0,0,0,2,0,0,2,0,2,0,0,2,0,2,0,1},
        {0,0,0,0,0,0,1,0,1,1,1,2,1,2,2,0,1,0,2,0,1,0,1},
        {0,0,0,0,0,0,1,0,2,0,2,0,0,2,0,4,0,0,2,0,0,2,1},
        {0,0,0,0,0,0,1,0,1,2,1,2,1,0,1,0,1,0,1,0,2,0,1},
        {0,0,0,0,0,0,1,2,0,0,2,0,0,2,0,0,2,2,2,0,2,0,1},
        {0,0,0,0,0,0,1,0,1,0,2,2,1,0,1,0,1,2,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,2,2,2,2,0,2,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,2,0,0,0,0,2,2,0,0,2,4,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,1,2,1,0,1,2,1,0,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,2,0,2,0,1},
        {0,0,0,0,0,0,1,0,1,0,1,2,1,2,1,0,1,2,1,0,1,2,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,2,0,0,0,2,0,2,0,2,0,1},
        {0,0,0,0,0,0,1,2,1,2,1,2,1,2,1,0,1,0,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,2,0,2,2,0,2,0,2,0,0,2,0,0,2,1},
        {0,0,0,0,0,0,1,0,2,0,1,0,1,0,2,1,1,0,1,0,1,0,1},
        {0,0,0,0,0,0,1,2,0,2,2,0,0,2,0,0,2,0,2,0,2,0,1},
        {0,0,0,0,0,0,1,0,1,1,1,2,1,0,1,0,1,2,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,2,0,2,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,2,0,0,0,2,0,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,2,0,0,0,0,1,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,2,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,2,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,2,4,0,1,0,2,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,1,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,2,1,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,2,0,0,1,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,4,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,1,0,1,1,1,1,1,1,1,1,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,1,0,0,0,0,1,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,2,0,0,0,1,1,1,1,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,4,0,0,2,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,1,1,1,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,1,0,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,2,1,2,0,0,0,0,1,1,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,2,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,2,0,2,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,1,0,2,1,1,0,0,0,2,0,2,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,2,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,4,0,0,0,0,0,0,1,1,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,0,2,0,0,0,1,1,1,1,2,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,2,0,0,0,2,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,2,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,2,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,2,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,4,0,0,2,0,0,1,1,1,1,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,2,1,2,0,0,2,0,2,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,1,0,0,0,2,0,0,1,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,2,0,0,0,0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,1,2,0,0,2,0,2,0,1,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,2,0,0,2,0,1,1},
        {0,0,0,0,0,0,1,0,0,4,2,2,1,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,2,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,1,0,0,0,2,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,1,2,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,0,0,1,2,2,2,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,2,0,0,2,1,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,2,0,0,1,0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,0,0,2,1},
        {0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,2,0,0,1,0,0,0,0,2,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,0,1,0,0,2,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,4,2,1,0,0,0,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,2,1,2,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,2,1,2,1,2,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,2,0,0,0,1,0,0,1,0,1,0,2,0,0,0,1},
        {0,0,0,0,0,0,1,0,1,0,0,2,0,1,0,0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,2,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,2,1,1,2,2,2,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,1,2,1,0,0,0,2,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,4,0,0,1,0,1,0,1,0,1},
        {0,0,0,0,0,0,1,1,0,0,0,2,2,2,2,2,2,2,2,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    },{
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,4,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,1,0,0,1},
        {0,0,0,0,0,0,1,2,0,0,0,2,0,0,2,0,2,0,2,0,0,2,1},
        {0,0,0,0,0,0,1,0,1,1,0,2,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,1,0,0,2,0,2,0,0,1,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,2,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,1,0,0,0,0,2,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,2,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,1,1,1,0,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
        {0,0,0,0,0,0,1,0,0,2,0,0,0,1,1,1,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    }


};


gameWin::gameWin(int num){

    arr_x=7;
    arr_y=1;
    gamenum=num%13;

    for(int i=0;i<=12;i++){
        for(int j=0;j<=22;j++){
            if(allmap[gamenum-1][i][j]==4){
                fin_x=j;
                fin_y=i;
                break;
            }
        }
    }

    setFixedSize(1280,720);
    setWindowTitle("Q版泡泡堂7");
    setWindowIcon(QIcon(QPixmap(":/images/bombs.png")));


    QSound* bomb_music=new QSound(":/music/bombing_sound.wav");
    QSound* bomb_set=new QSound(":/music/setbomb_sound.wav");



    QPushButton *all_label[13][23]={NULL};

    for(int i=0;i<=1280-55;i+=55){
        for(int j=0;j<=720-55;j+=55){

            if(allmap[gamenum-1][j/55][i/55]==1&&i<=22*55&&j<=12*55){
                all_label[j/55][i/55]=new QPushButton;
                all_label[j/55][i/55]->setParent(this);
                all_label[j/55][i/55]->move(i,j);
                all_label[j/55][i/55]->setFixedSize(55,55);
                all_label[j/55][i/55]->setIconSize(QSize(55,55));
                all_label[j/55][i/55]->setStyleSheet("QPushButton{border:0px;}");
                all_label[j/55][i/55]->setIcon(QIcon(":/images/wood.png"));


            }
            else if(((allmap[gamenum-1][j/55][i/55]==2)||(allmap[gamenum-1][j/55][i/55]==4))&&(i<=22*55&&j<=12*55)){
                all_label[j/55][i/55]=new QPushButton;
                all_label[j/55][i/55]->setParent(this);
                all_label[j/55][i/55]->move(i,j);
                all_label[j/55][i/55]->setFixedSize(55,55);
                all_label[j/55][i/55]->setIconSize(QSize(55,55));
                all_label[j/55][i/55]->setStyleSheet("QPushButton{border:0px;}");
                all_label[j/55][i/55]->setIcon(QIcon(":/images/straw.png"));

            }
            else {
                all_label[j/55][i/55]=new QPushButton;
                all_label[j/55][i/55]->setParent(this);
                all_label[j/55][i/55]->move(i,j);
                all_label[j/55][i/55]->setFixedSize(55,55);
                all_label[j/55][i/55]->setIconSize(QSize(55,55));
                all_label[j/55][i/55]->setStyleSheet("QPushButton{border:0px;}");
            }
        }
    }




   QLabel *time_label=new QLabel;
   time_label->setFixedSize(300,720);

    QTimer *game_timer=new QTimer(this);

    connect(game_timer,&QTimer::timeout,this,[=](){
        game_time--;
        if(game_time==0){
            game_state=2;
        }
        QString time_str;
        time_str=QString("TIME:%1").arg(game_time);
        time_label->setText(time_str);

    });
    QLabel *game_label=new QLabel;
    game_label->setParent(this);
    game_label->setFixedSize(1000,720);
    game_label->resize(1000,720);

    QTimer *state_timer=new QTimer(this);
    state_timer->start(30);

    connect(state_timer,&QTimer::timeout,this,[=](){
        if(game_state==2){
            game_label->setPixmap(QPixmap(":/images/time_out.png"));
            game_label->move(400,0);
            game_timer->stop();
            person->hide();
            state_timer->stop();
        }
        if(game_state==3){
            game_label->setPixmap(QPixmap(":/images/game_win.png"));
            game_label->move(400,0);
            game_timer->stop();
            person->hide();
            state_timer->stop();
        }
        if(game_state==4){
            game_label->setPixmap(QPixmap(":/images/game_lose.png"));
            game_label->move(400,0);
            game_timer->stop();
            person->hide();
            state_timer->stop();
        }

    });

    QLabel *tips=new QLabel;
    QFont tips_font;
    tips_font.setFamily("华文琥珀");
    tips_font.setBold(true);
    tips_font.setPointSize(15);
    QPalette tips_pal=tips->palette();
    tips_pal.setColor(QPalette::WindowText,QColor(85,128,250));
    tips->setFont(tips_font);
    tips->setPalette(tips_pal);
    tips->setParent(this);
    tips->setAlignment(Qt::AlignTop);
    tips->setWordWrap(true);
    tips->setFixedSize(300,600);
    tips->move(10,130);
    tips->setText(QString("<1>开始游戏前请点击“开始”按钮！\n\n<2>请在60s找到指定道具通关。\n\n<3>中途离开游戏将被判输！\n\n<4>炸弹有短暂的CD"));



    QFont time_font;
    time_font.setFamily("Arial Rounded MT Bold");
    time_font.setBold(true);
    time_font.setPointSize(20);
    QPalette time_pal=time_label->palette();
    time_pal.setColor(QPalette::WindowText,QColor(249,32,88));
    time_label->setFont(time_font);
    time_label->setPalette(time_pal);
    time_label->setParent(this);
    time_label->setAlignment(Qt::AlignTop);
    time_label->setWordWrap(true);
    time_label->setFixedSize(400,100);
    time_label->move(50,50);


    auto backInGame=new mybutton(QString(":/images/backbtn1.png"),QString(":/images/backbtn2.png"));
    backInGame->setParent(this);
    backInGame->move(200,625);
    backInGame->resize(100,50);

    connect(backInGame,&mybutton::clicked,this,[=](){
        game_state=4;
        emit closeback();
    });                                                 //创建返回按钮

    auto begin_game=new mybutton(QString(":/images/begin_btn.png"),QString(":/images/begin_btn2.png"));
    begin_game->setParent(this);
    begin_game->move(30,620);
    begin_game->resize(100,50);


    gameWin::person=new man(MainWindow::role,55*7,30);
    person->setParent(this);
    person->QPushButton::move(7*55,30);
    person->setIconSize(QSize(100,100));


    connect(begin_game,&mybutton::clicked,this,[=]()mutable{

        if(game_state==0){
           game_timer->start(1000);
           game_state=1;
        }                                               //开始游戏

        });





    QLabel *bomb_label=new QLabel(this);
    bomb_label->setGeometry(0,0,66,78);
    bomb_label->setFixedSize(66,78);
    bomb_label->setPixmap(QPixmap(":/images/bomber1.png"));
    bomb_label->hide();

    QTimer *timer1=new QTimer(this);            //每40ms刷新一次场景

    int flag_bug1=0;
    int flag_bug2=0;
    int flag_bug3=0;
    int flag_bug4=0;

    timer1->start(40);
    connect(timer1,&QTimer::timeout,this,[=]()mutable{
        person->move(arr_x*55,arr_y*55-55+30);
        if(arr_x==fin_y&&arr_y==fin_x){
            game_time=0;
        }
        if(bomb_flag==100){                             //炸弹放置

            bomb_set->play();


            allmap[gamenum-1][arr_y][arr_x]=3;

            bomb_label->move(arr_x*55,arr_y*55-55+30);
            bomb_label->show();
        }

        if((bomb_flag<=100&&bomb_flag>=90)||(bomb_flag<=80&&bomb_flag>=70)||(bomb_flag<=60&&bomb_flag>=50)){
            bomb_label->setPixmap(QPixmap(":/images/bomber1.png"));
        }
        else{
            bomb_label->setPixmap(QPixmap(":/images/bomber2.png"));     //炸弹闪烁
        }

        if(bomb_flag==50){                                  //炸弹爆炸,周围出现火焰

            bomb_label->hide();

            bomb_music->play();

            if(arr_x==bomb_x&&arr_y==bomb_y){
                game_state=4;
            }


            if(allmap[gamenum-1][bomb_y-2][bomb_x]!=1&&allmap[gamenum-1][bomb_y-1][bomb_x]!=1){
                all_label[bomb_y-2][bomb_x]->setIcon(QIcon(":/images/frame_edge1.png"));
                all_label[bomb_y-2][bomb_x]->QPushButton::move(all_label[bomb_y-2][bomb_x]->x(),all_label[bomb_y-2][bomb_x]->y()+10);
                flag_bug1=1;
                allmap[gamenum-1][bomb_y-2][bomb_x]=10;
                if(arr_x==bomb_x&&arr_y==bomb_y-2){
                    game_state=4;
                }
            }
            if(allmap[gamenum-1][bomb_y][bomb_x+2]!=1&&allmap[gamenum-1][bomb_y][bomb_x+1]!=1){
                all_label[bomb_y][bomb_x+2]->setIcon(QIcon(":/images/frame_edge2.png"));
                all_label[bomb_y][bomb_x+2]->QPushButton::move(all_label[bomb_y][bomb_x+2]->x()-10,all_label[bomb_y][bomb_x+2]->y());
                flag_bug2=1;
                allmap[gamenum-1][bomb_y][bomb_x+2]=11;
                if(arr_x==bomb_x+2&&arr_y==bomb_y){
                    game_state=4;
                }
            }
            if(allmap[gamenum-1][bomb_y+2][bomb_x]!=1&&allmap[gamenum-1][bomb_y+1][bomb_x]!=1){
                all_label[bomb_y+2][bomb_x]->setIcon(QIcon(":/images/frame_edge3.png"));
                all_label[bomb_y+2][bomb_x]->QPushButton::move(all_label[bomb_y+2][bomb_x]->x(),all_label[bomb_y+2][bomb_x]->y()-10);
                flag_bug3=1;
                allmap[gamenum-1][bomb_y+2][bomb_x]=12;
                if(arr_x==bomb_x&&arr_y==bomb_y+2){
                    game_state=4;
                }
            }
            if(allmap[gamenum-1][bomb_y][bomb_x-2]!=1&&allmap[gamenum-1][bomb_y][bomb_x-1]!=1){
                all_label[bomb_y][bomb_x-2]->setIcon(QIcon(":/images/frame_edge4.png"));
                all_label[bomb_y][bomb_x-2]->QPushButton::move(all_label[bomb_y][bomb_x-2]->x()+10,all_label[bomb_y][bomb_x-2]->y());
                flag_bug4=1;
                allmap[gamenum-1][bomb_y][bomb_x-2]=13;
                if(arr_x==bomb_x-2&&arr_y==bomb_y){
                    game_state=4;
                }
            }

            if(allmap[gamenum-1][bomb_y-1][bomb_x]!=1){
                all_label[bomb_y-1][bomb_x]->setIcon(QIcon(":/images/frame_body1.png"));
                allmap[gamenum-1][bomb_y-1][bomb_x]=6;
                if(arr_x==bomb_x&&arr_y==bomb_y-1){
                    game_state=4;
                }
            }
            if(allmap[gamenum-1][bomb_y][bomb_x+1]!=1){
                all_label[bomb_y][bomb_x+1]->setIcon(QIcon(":/images/frame_body2.png"));
                allmap[gamenum-1][bomb_y][bomb_x+1]=7;
                if(arr_x==bomb_x+1&&arr_y==bomb_y){
                    game_state=4;
                }
            }
            if(allmap[gamenum-1][bomb_y+1][bomb_x]!=1){
                all_label[bomb_y+1][bomb_x]->setIcon(QIcon(":/images/frame_body1.png"));
                allmap[gamenum-1][bomb_y+1][bomb_x]=8;
                if(arr_x==bomb_x&&arr_y==bomb_y+1){
                    game_state=4;
                }
            }
            if(allmap[gamenum-1][bomb_y][bomb_x-1]!=1){
                all_label[bomb_y][bomb_x-1]->setIcon(QIcon(":/images/frame_body2.png"));
                allmap[gamenum-1][bomb_y][bomb_x-1]=9;
                if(arr_x==bomb_x-1&&arr_y==bomb_y){
                    game_state=4;
                }
            }
            allmap[gamenum-1][bomb_y][bomb_x]=5;
            all_label[bomb_y][bomb_x]->setIcon(QIcon(":/images/frame_ceter.png"));

        }

        if(bomb_flag==35){
            if(allmap[gamenum-1][bomb_y-1][bomb_x]!=1){
                if(bomb_y-1==fin_y&&bomb_x==fin_x){
                    all_label[bomb_y-1][bomb_x]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y-1][bomb_x]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y-1][bomb_x]=0;
            }
            if(allmap[gamenum-1][bomb_y][bomb_x+1]!=1){
                if(bomb_y==fin_y&&bomb_x+1==fin_x){
                    all_label[bomb_y][bomb_x+1]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y][bomb_x+1]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y][bomb_x+1]=0;
            }
            if(allmap[gamenum-1][bomb_y+1][bomb_x]!=1){
                if(bomb_y+1==fin_y&&bomb_x==fin_x){
                    all_label[bomb_y+1][bomb_x]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y+1][bomb_x]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y+1][bomb_x]=0;
            }
            if(allmap[gamenum-1][bomb_y][bomb_x-1]!=1){
                if(bomb_y==fin_y&&bomb_x-1==fin_x){
                    all_label[bomb_y][bomb_x-1]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y][bomb_x-1]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y][bomb_x-1]=0;
            }

            allmap[gamenum-1][bomb_y][bomb_x]=0;
            all_label[bomb_y][bomb_x]->setIcon(QIcon(":/images/grass.png"));

            if(allmap[gamenum-1][bomb_y-2][bomb_x]!=1&&flag_bug1){
                if(allmap[gamenum-1][bomb_y-1][bomb_x]!=1){
                all_label[bomb_y-2][bomb_x]->QPushButton::move((bomb_x)*55,(bomb_y-2)*55);
                flag_bug1=0;
                if(bomb_y-2==fin_y&&bomb_x==fin_x){
                    all_label[bomb_y-2][bomb_x]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y-2][bomb_x]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y-2][bomb_x]=0;
                }
            }
            if(allmap[gamenum-1][bomb_y][bomb_x+2]!=1&&flag_bug2){
                if(allmap[gamenum-1][bomb_y][bomb_x+1]!=1){
                all_label[bomb_y][bomb_x+2]->QPushButton::move((bomb_x+2)*55,(bomb_y)*55);
                flag_bug2=0;
                if(bomb_y==fin_y&&bomb_x+2==fin_x){
                    all_label[bomb_y][bomb_x+2]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y][bomb_x+2]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y][bomb_x+2]=0;
                }
            }
            if(allmap[gamenum-1][bomb_y+2][bomb_x]!=1&&flag_bug3){
                if(allmap[gamenum-1][bomb_y+1][bomb_x]!=1){
                all_label[bomb_y+2][bomb_x]->QPushButton::move(bomb_x*55,(bomb_y+2)*55);
                flag_bug3=0;
                if(bomb_y+2==fin_y&&bomb_x==fin_x){
                    all_label[bomb_y+2][bomb_x]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y+2][bomb_x]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y+2][bomb_x]=0;
                }
            }
            if(allmap[gamenum-1][bomb_y][bomb_x-2]!=1&&flag_bug4){
                if(allmap[gamenum-1][bomb_y][bomb_x-1]!=1){
                    all_label[bomb_y][bomb_x-2]->QPushButton::move((bomb_x-2)*55,bomb_y*55);
                flag_bug4=0;
                if(bomb_y==fin_y&&bomb_x-2==fin_x){
                    all_label[bomb_y][bomb_x-2]->setIcon(QIcon(":/images/win.png"));}
                else all_label[bomb_y][bomb_x-2]->setIcon(QIcon(":/images/grass.png"));
                allmap[gamenum-1][bomb_y][bomb_x-2]=0;
                }
            }
        }



    });



//    connect(begin_game,&mybutton::clicked,this,[=](){
//        if(game_state==0){
//           game_timer->start(1000);
//           game_state=1;
//        }
//    });                                                     //开始按钮



}
//数字含义：0为草地，1为树桩，2为草堆，3为炸弹，4为隐藏钥匙的草堆,5为爆炸中心，  10    此为爆炸图
//                                                                    6
//                                                             13  9  5  7 11
//                                                                    8
//                                                                    12

//game_state:0为未开始，1为开始，2为超时，3为胜利,4为被炸死
void gameWin:: keyPressEvent(QKeyEvent *ev){

    if(game_state!=1){
        return;
    }

    if(ev->key()==Qt::Key_A){
        if(allmap[gamenum-1][arr_y][arr_x-1]!=0){
            arr_x+=1;
        }
        arr_x-=1;
        gameWin::person->setIcon(QIcon(":/images/left.png"));
        if(arr_x==fin_x&&arr_y==fin_y){
            game_state=3;
        }
    }
    if(ev->key()==Qt::Key_W){
        if(allmap[gamenum-1][arr_y-1][arr_x]!=0){
            arr_y+=1;
        }
        arr_y-=1;
        gameWin::person->setIcon(QIcon(":/images/behind.png"));
        if(arr_x==fin_x&&arr_y==fin_y){
            game_state=3;
        }
    }
    if(ev->key()==Qt::Key_D){
        if(allmap[gamenum-1][arr_y][arr_x+1]!=0){
            arr_x-=1;
        }
        gameWin::person->setIcon(QIcon(":/images/right.png"));
        arr_x+=1;
        if(arr_x==fin_x&&arr_y==fin_y){
            game_state=3;
        }
    }
    if(ev->key()==Qt::Key_S){
        if(allmap[gamenum-1][arr_y+1][arr_x]!=0){
            arr_y-=1;
        }
        arr_y+=1;
        gameWin::person->setIcon(QIcon(":/images/front.png"));
        if(arr_x==fin_x&&arr_y==fin_y){
            game_state=3;
        }
    }
    if(ev->key()==Qt::Key_J){
        if(bomb_flag==0){
            bomb_x=arr_x;
            bomb_y=arr_y;
            bomb_flag=100;
            QTimer *bomb_timer=new QTimer(this);
            bomb_timer->start(50);
            connect(bomb_timer,&QTimer::timeout,this,[=]{
                bomb_flag--;
                if(bomb_flag==0){
                    bomb_timer->stop();
                }
            });
        }

    }


}



void gameWin::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for(int i=0;i<=1280;i+=55){
        for(int j=0;j<=720;j+=55){
            painter.drawPixmap(i,j,QPixmap(":/images/grass.png"));
        }
    }


}
