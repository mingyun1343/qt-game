#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<wid.h>
#include<iostream>


using namespace std;
int MainWindow::x=10;
int MainWindow::y=20;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    wid* t=new wid;
    t->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
