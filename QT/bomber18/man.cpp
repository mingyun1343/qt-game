#include "man.h"
#include<QKeyEvent>
#include<gamewin.h>
#include<mainwindow.h>
#include<qradiobutton.h>
#include<QDebug>

man::man(int num,int x,int y){

    QPixmap pix;
    pix.load(":/images/front.png");

    this->setFixedSize(pix.width(),pix.height());

    this->setIcon(QIcon(":/images/front.png"));



    if(num==0){
        this->setIcon(QIcon(":/images/front.png"));
    }
     if(num==1){
        this->setIcon(QIcon(":/images/woman.png"));
    }









    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIconSize(QSize(pix.width(),pix.height()));

}

//void man::keyPressEvent(QKeyEvent *ev){

//    switch (ev->key()) {
//    case Qt::Key_W:                                     //    1
//                                                        // 4      2
//        action(0,1);                                    //    3
//        break;
//    case Qt::Key_D:
//        action(0,2);
//        break;
//    case Qt::Key_S:
//        action(0,3);
//        break;
//    case Qt::Key_A:
//        action(0,4);
//        break;
//    }


//}

