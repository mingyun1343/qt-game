#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"hungry.h"
#include"moon.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    hungry *aa;
    moon *bb;

    void time();


};

#endif // MAINWINDOW_H
