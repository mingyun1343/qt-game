#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(20,20,QPixmap(":/temp/background.png"));
    painter.drawPixmap(0,0,QPixmap(":/temp/d1x.png"));
    painter.drawPixmap(63,-2,760,59,QPixmap(":/temp/t.png"));
    painter.drawPixmap(808,0,70,58,QPixmap(":/temp/d2x.png"));
    painter.drawPixmap(-2,50,45,530,QPixmap(":/temp/l.png"));
    painter.drawPixmap(0,565,76,130,QPixmap(":/temp/d3x.png"));
    painter.drawPixmap(76,586,730,113,QPixmap(":/temp/b.png"));
    painter.drawPixmap(839,58,42,530,QPixmap(":/temp/r.png"));
    painter.drawPixmap(76+730-5,562,77,133,QPixmap(":/temp/d4x.png"));
}


Widget::~Widget()
{
    delete ui;
}
