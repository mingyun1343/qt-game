#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include <QMainWindow>
#include<choosewin.h>
#include<qradiobutton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    bool sound=1;                       //全局声音

    static int role;
    static QRadioButton* role_radio;
    static QRadioButton* role_radio2;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
