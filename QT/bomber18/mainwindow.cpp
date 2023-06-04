#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<mybutton.h>
#include<QPushButton>
#include<choosewin.h>
#include<qwidget.h>
#include<QDebug>
#include<qradiobutton.h>
#include<qlabel.h>
#include<QSound>

QSound* backMusic=new QSound(":/music/backGroundMusic.wav");

int MainWindow::role=0;
QRadioButton* MainWindow::role_radio;
QRadioButton* MainWindow::role_radio2;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(1280,720);
    setWindowTitle("Q版泡泡堂7");
    setWindowIcon(QIcon(QPixmap(":/images/bombs.png")));        //窗口基本设置


    backMusic->setLoops(-1);
    backMusic->play();



    //以下为首页三个主按钮

   auto mainbtn1=new mybutton(QString(":/images/mainbutton1.png"),QString(":/images/mainbutton1s.png"));
   mainbtn1->setParent(this);
   mainbtn1->move(470,400);
   auto mainbtn2=new mybutton(QString(":/images/mainbutton2.png"),QString(":/images/mainbutton2s.png"));
   mainbtn2->setParent(this);
   mainbtn2->move(470,500);
   auto mainbtn3=new mybutton(QString(":/images/mainbutton3.png"),QString(":/images/mainbutton3s.png"));
   mainbtn3->setParent(this);
   mainbtn3->move(470,600);

   //-----------------------------

   QPushButton *soundbtn = new QPushButton;
   soundbtn->setIcon(QIcon(":/images/nmute.png"));
   soundbtn->setFixedSize(60,60);
   soundbtn->setIconSize(QSize(60,60));
   soundbtn->setStyleSheet("QPushButton{border:0px;}");
   soundbtn->setParent(this);
   soundbtn->move(1100,625);
   connect(soundbtn,&QPushButton::clicked,this,[=](){
       if(MainWindow::sound==1){
           soundbtn->setIcon(QIcon(":/images/mute.png"));
           backMusic->stop();

           sound=0;
       }
       else{
           soundbtn->setIcon(QIcon(":/images/nmute.png"));

           backMusic->play();
           sound=1;
       }
   });                                                          //首页静音键的建立
   choosewin *choose=new choosewin(role);
   connect(mainbtn1,&mybutton::clicked,[=]{
      this->hide();
      choose->show();
   });                                                      //开始按钮

   connect(choose,&choosewin::closeback,this,[=](){
       choose->close();
       this->show();
   });                                                  //选关页的返回按钮

   connect(mainbtn2,&mybutton::clicked,this,[=](){          //设置按钮
       this->hide();
        auto set=new QWidget;
        set->setFixedSize(840,600);
        set->setWindowIcon(QIcon(QPixmap(":/images/bombs.png")));

        QLabel* background=new QLabel;
        background->setPixmap(QPixmap(":/images/background.png"));
        background->setFixedSize(840,600);
        background->setParent(set);
        background->move(0,0);

        mybutton *set_yes=new mybutton(QString(":/images/backbtn1.png"),QString(":/images/backbtn2.png"));
        set_yes->setParent(set);
        set_yes->move(420-57,600-85);
        connect(set_yes,&mybutton::clicked,set,[=](){
            set->close();
            this->show();
        });

        QLabel *role1=new QLabel;
        role1->setPixmap(QPixmap(":/images/blueone.png"));
        role1->resize(200,250);
        role1->move(60,125);
        role1->setParent(set);

        role_radio=new QRadioButton;
//        role_radio2=new QRadioButton;


        role_radio->setParent(set);
        role_radio->move(150,400);
        connect(role_radio,&QRadioButton::clicked,this,[=]{
            role=0;
        });


        QLabel *tips=new QLabel;
        QFont tips_font;
        tips_font.setFamily("华文琥珀");
        tips_font.setBold(true);
        tips_font.setPointSize(15);
        QPalette tips_pal=tips->palette();
        tips_pal.setColor(QPalette::WindowText,QColor(73,248,98));
        tips->setFont(tips_font);
        tips->setPalette(tips_pal);
        tips->setParent(set);
        tips->setAlignment(Qt::AlignTop);
        tips->setWordWrap(true);
        tips->setFixedSize(550,300);
        tips->move(300,30);
        tips->setText(QString("wasd分别控制上下左右移动\n\n j为放炸弹"));

        QLabel* op1=new QLabel;
        op1->setPixmap(QPixmap(":/images/op1.png"));
        QLabel* op2=new QLabel;
        op2->setPixmap(QPixmap(":/images/op2.png"));
        op1->setParent(set);
        op2->setParent(set);
        op1->move(300,200);
        op2->move(650,300);


        set->show();

   });



   connect(mainbtn3,&mybutton::clicked,this,[=](){          //设置信息按钮所示信息
       this->hide();
       auto info=new QWidget;
       info->setFixedSize(600,400);
       info->setWindowIcon(QIcon(QPixmap(":/images/bombs.png")));

       auto info_label=new QLabel;

       QFont info_font;
       info_font.setFamily("华文琥珀");
       info_font.setBold(true);
       info_font.setPointSize(13);
       QPalette info_pal=info_label->palette();
       info_pal.setColor(QPalette::WindowText,QColor(106,197,250));
       info_label->setFont(info_font);
       info_label->setPalette(info_pal);

       info_label->setParent(info);
       info_label->resize(600,400);
       info_label->move(0,0);
       info_label->setText("本游戏由南京理工大学计算机科学与工程学院9211068405班QT小组制作，素材取自网络\n制作时间：2022.07-2022.10\n小组成员：\n顾怀安（921106840513）\n冷杰（921106840515）\n联系方式：18015538184");
       info_label->setAlignment(Qt::AlignTop);
       info_label->setWordWrap(true);

       mybutton *info_yes=new mybutton(QString(":/images/backbtn1.png"),QString(":/images/backbtn2.png"));
       info_yes->setParent(info);
       info_yes->move(300-57,400-85);
       connect(info_yes,&mybutton::clicked,info,[=](){
           info->close();
           this->show();
       });


       info->show();

   });



}



void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/images/mainland.png"));
    painter.drawPixmap(300,40,QPixmap(":/images/maintitle.png"));       //首页背景以及大标题

}

MainWindow::~MainWindow()
{
    delete ui;
}
