#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QMainWindow>
#include<choosewin.h>
#include<qtimer.h>
#include<man.h>

class gameWin : public QMainWindow
{
    Q_OBJECT
public:


    gameWin(int num);

    void paintEvent(QPaintEvent *);

    int gamenum;

    int arr_x=7;
    int arr_y=1;
    int bomb_flag=0;
    int bomb_x=2;
    int bomb_y=2;
    int fin_x=0;
    int fin_y=0;
    int game_time=60;
    int game_state=0;

    man* person;



protected:
    void keyPressEvent(QKeyEvent *);


signals:
    void closeback();



public slots:
};

#endif // GAMEWIN_H
