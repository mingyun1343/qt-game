#include "hungry.h"
#include"QDebug"
hungry::hungry(QObject *parent) : QObject(parent)
{

}

void hungry::eat(){

    qDebug()<<"狂吃不止";

}
void hungry::eat(QString con){
    qDebug()<<"吃的无敌巨多！！！"<<con.toUtf8().data();

}
