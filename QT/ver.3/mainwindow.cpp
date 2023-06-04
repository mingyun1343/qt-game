#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QMenuBar>
#include<QToolBar>

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

    QWidget *secwin=new QWidget;
    connect(btn,&QPushButton::clicked,secwin,[=](){
        secwin->show();
    });
    connect(btn2,&QPushButton::clicked,secwin,[=](){
        secwin->close();
    });

    QPushButton *btn3=new QPushButton;
    btn3->resize(100,50);
    btn3->move(400,550);
    btn3->setText("open");
    btn3->setParent(this);
    QWidget *thiwin =new QWidget;
    connect(btn3,&QPushButton::clicked,thiwin,[=](){
        if(btn3->text()=="open"){
            thiwin->show();
            btn3->setText("close");
        }
        else{
            thiwin->close();
            btn3->setText("open");
        }
    });

    auto *menubar=new QMenuBar;
    setMenuBar(menubar);
    auto *files=menubar->addMenu("文件");
    auto *edit=menubar->addMenu("编辑");

    QAction*create=files->addAction("新建");
    files->addSeparator();
    QAction*open=files->addAction("打开");
    edit->addAction("返回");
    edit->addAction("复制");          //菜单栏

    QToolBar * tool=new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,tool);
    tool->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    tool->setFloatable(false);
    tool->setMovable(true);
    tool->addAction(create);
    tool->addAction(open);
    QPushButton * closebtn=new QPushButton;
    closebtn->setText("关闭窗口");
    tool->addWidget(closebtn);
    connect(closebtn,&QPushButton::clicked,this,[=](){
        this->close();
    });






//    connect(btn3,&QPushButton::clicked,btn3,[=](){
//        if(btn3->text()=="close"){
//            btn3->setText("open");
//            disconnect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->close();
//            });
//            connect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->show();
//            });
//        }
//        else{
//            btn3->setText("close");
//            disconnect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->show();
//            });
//            connect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->close();
//            });
//        }
//    });
//    connect(btn3,&QPushButton::clicked,thiwin,[=](){
//        thiwin->show();
//    });
//    while(1){
//        if(btn3->text()=="open"){
//            disconnect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->show();
//            });
//            connect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->();
//            });
//        }
//        else{
//            disconnect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->show();
//            });
//            connect(btn3,&QPushButton::clicked,thiwin,[=](){
//                thiwin->close();
//            });
//        }

//    }




}
void change(){

}
MainWindow::~MainWindow()
{
    delete ui;
}
