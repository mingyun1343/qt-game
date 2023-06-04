#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPushButton"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("第一次作业");
    resize(1000,800);

    QPushButton *btn=new QPushButton;
    btn->resize(100,50);
    btn->move(300,400);
    btn->setText("open");
    btn->setParent(this);

    QPushButton *btn2=new QPushButton;
    btn2->resize(100,50);
    btn2->move(500,400);
    btn2->setText("close");
    btn2->setParent(this);

   // MainWindow *w2=new MainWindow;
    QWidget*one=new QWidget;
  //  w2->show();
   // connect(btn,btn->clicked,w2,[=](){w2->close();});


}

MainWindow::~MainWindow()
{
    delete ui;
}
