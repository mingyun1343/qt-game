#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1280,720);
    setWindowTitle("Q版泡泡堂7");
    setWindowIcon(QIcon(QPixmap(":/images/start.png")));    //窗口基本设置

    ui->mainbtn->move(455,400);
    ui->mainbtn->resize(300,100);
    ui->bomb->resize(80,80);
    ui->bomb->setPixmap(QPixmap(":/images/start.png"));
    ui->bomb->move(455,400);

    ui->mainbtn2->move(455,500);
    ui->mainbtn2->resize(300,100);
    ui->setting->resize(80,80);
    ui->setting->setPixmap(QPixmap(":/images/setting.png"));
    ui->setting->move(455,503);

    ui->mainbtn3->move(455,600);
    ui->mainbtn3->resize(300,100);
    ui->star->resize(80,80);
    ui->star->setPixmap(QPixmap(":/images/info.png"));
    ui->star->move(455,603);                                //主页三个按钮，文字在ui中添加


}
void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/images/mainland.png"));       //绘制背景

    painter.drawPixmap(290,40,QPixmap(":/images/maintitle.png"));   //绘制主页面大标题


}

MainWindow::~MainWindow()
{
    delete ui;
}
