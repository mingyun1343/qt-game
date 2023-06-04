#include "mainbutton.h"
#include "ui_mainbutton.h"
#include<QPainter>


mainbutton::mainbutton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainbutton)
{
    ui->setupUi(this);
}
void mainbutton::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,10,QPixmap(":/images/mainbutton.png"));
    //painter.drawPixmap(0,0,QPixmap(":/images/start.png"));
}

mainbutton::~mainbutton()
{
    delete ui;
}
