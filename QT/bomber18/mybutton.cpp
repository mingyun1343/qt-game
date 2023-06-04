#include "mybutton.h"
#include<QDebug>
#include<QPixmap>
#include<QSound>

mybutton::mybutton(QString bef, QString aft){

    this->befaddress=bef;
    this->aftaddress=aft;

    QPixmap pix;
    bool ret=pix.load(bef);
    if(!ret){
        qDebug()<<"图片有误";
        return;                                         //判断是否成功传入图片地址
    }

    this->setFixedSize(pix.width(),pix.height());

    this->setIcon(pix);

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIconSize(QSize(pix.width(),pix.height()));         //设置按钮格式


}

    QSound * btn_music=new QSound(":/music/btn_music.wav");
    QSound * btn_moveon=new QSound(":/music/mouse_slid.wav");

void mybutton:: enterEvent(QEvent *e){

    QPixmap pix;
    bool ret=pix.load(aftaddress);
    if(!ret){
        qDebug()<<"图片不存在";
        return;                                         //判断是否成功传入图片地址
    }
    this->setIcon(pix);                                  //设置鼠标进入时的图片

    btn_moveon->play();

    return QPushButton::enterEvent(e);                  //交给原来的函数处理

}
void mybutton:: leaveEvent(QEvent *e){

    QPixmap pix;
    bool ret=pix.load(befaddress);
    if(!ret){
        qDebug()<<"图片不存在";
        return;                                         //判断是否成功传入图片地址
    }
    this->setIcon(pix);                                 //还原图片

    btn_music->play();

    return QPushButton::leaveEvent(e);                  //交给原来的函数处理
}
