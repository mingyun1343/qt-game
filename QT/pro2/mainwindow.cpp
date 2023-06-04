#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("小游戏");
   QPushButton *a=new QPushButton;
    a->setParent(this);
    a->setText("哈哈哈");
    a->resize(50,50);
   // a->show();
    QPushButton *b=new QPushButton("一个按钮",this);
    resize(1500,1000);
    b->move(500,500);
    b->resize(100,100);
    //信号发送者，信号，接收者，执行
     connect(b,&QPushButton::clicked,this,&MainWindow::close);

     this->bb=new moon(this);
     this->aa=new hungry(this);

     void (moon::*silnentsinal)(QString)=&moon::silent;
     void (hungry::*hungrysinal)(QString)=&hungry::eat;


     connect(bb,silnentsinal,aa,hungrysinal);

    MainWindow::time();

}
void MainWindow::time(){

    emit bb->silent("123");


}



MainWindow::~MainWindow()
{
    delete ui;
}
