#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionnew->setIcon(QIcon(":/pic/123.jpg"));
    ui->actionopen->setIcon(QIcon(":/pic/a.jpg"));

//    connect(ui->actionnew,&QAction::triggered,this,[=](){
//    QDialog dlg(this);
//    dlg.resize(300,200);
//    dlg.exec();
//    qDebug()<<"已关闭";        //模态创建
//    });

//    connect(ui->actionopen,&QAction::triggered,this,[=](){

//       QDialog *dlg2=new QDialog(this);
//       dlg2->resize(400,300);
//       dlg2->show();
//       qDebug()<<"已开启";
//       dlg2->setAttribute(Qt::WA_DeleteOnClose);

//    });                         //非模态创建
         connect(ui->actionnew,&QAction::triggered,this,[=](){

             QMessageBox::critical(this,"error","错误！");
             if(QMessageBox::Ok==QMessageBox::question(this,"ques","选哪个呢",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel))
             {
                 qDebug()<<"ok";
             }
             else{
                 qDebug()<<"cancel";
             }
                                            //对话框的创建
        });




}

MainWindow::~MainWindow()
{
    delete ui;
}
