#include "choosewin.h"
#include<QPainter>
#include<mybutton.h>
#include<QPushButton>
#include<ui_mainwindow.h>
#include<gamewin.h>
#include<qlabel.h>

choosewin::choosewin(int role)
{
    setFixedSize(1280,720);
    setWindowTitle("Q版泡泡堂7");
    setWindowIcon(QIcon(QPixmap(":/images/bombs.png")));

    for(int i=this->height()/2-200;i<550;i+=150){
        for(int j=this->width()/2-270;j<900;j+=150){
            auto chbtn=new mybutton(QString(":/images/bomb1.png"),QString(":/images/bomb2.png"));
            chbtn->setParent(this);                            //创建选关炸弹
            chbtn->move(j,i);


            auto* game=new gameWin(role*13+k++);

            connect(chbtn,&mybutton::clicked,this,[=](){
                this->hide();
                game->show();

            });

            connect(game,&gameWin::closeback,this,[=](){
                game->close();
                this->show();


            });


            auto gamenum=new QLabel;
            QFont font;
            font.setFamily("华文琥珀");                       //设置字体及样式
            font.setPointSize(20);

            gamenum->setFont(font);
            gamenum->setParent(this);
            if((k-1)<=9){
                gamenum->move(j+35,i+55);
            }
            else{
                gamenum->move(j+20,i+55);
            }

            QString numstr=QString::number(k-1,10);
            gamenum->setText(numstr);
            gamenum->resize(60,60);
            QPalette pal=gamenum->palette();
            pal.setColor(QPalette::WindowText,QColor(Qt::lightGray));
            gamenum->setPalette(pal);
            gamenum->setAttribute(Qt::WA_TransparentForMouseEvents);    //鼠标穿透事件


        }
    }






    auto back=new mybutton(QString(":/images/backbtn1.png"),QString(":/images/backbtn2.png"));
    back->setParent(this);
    back->move(900,600);
    back->resize(100,50);

    connect(back,&mybutton::clicked,this,[=](){
        emit closeback();
    });                                                 //创建返回按钮






}
void choosewin::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/images/mainland.png"));          //选关页面背景
    painter.drawPixmap(220,60,QPixmap(":/images/background.png"));
    //------
    painter.drawPixmap(0+200,0+40,QPixmap(":/images/d1x.png"));
    painter.drawPixmap(63+200,-2+40,760,59,QPixmap(":/images/t.png"));
    painter.drawPixmap(808+200,0+40,70,58,QPixmap(":/images/d2x.png"));
    painter.drawPixmap(-2+200,50+40,45,530,QPixmap(":/images/l.png"));
    painter.drawPixmap(0+200,565+40,76,110,QPixmap(":/images/d3x.png"));
    painter.drawPixmap(76+200,583+40,730,95,QPixmap(":/images/b.png"));
    painter.drawPixmap(839+200,58+40,42,530,QPixmap(":/images/r.png"));
    painter.drawPixmap(76+730-5+200,562+40,77,110,QPixmap(":/images/d4x.png"));
    // 用拼图的方式完成边框的设置

    painter.drawPixmap(270,25,QPixmap(":/images/deco.png"));
    painter.drawPixmap(225,35,150,170,QPixmap(":/images/cup.png")); //一些小装饰

}

