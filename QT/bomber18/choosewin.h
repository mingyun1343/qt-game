#ifndef CHOOSEWIN_H
#define CHOOSEWIN_H

#include <QMainWindow>
#include<gamewin.h>
class choosewin : public QMainWindow
{
    Q_OBJECT
public:
     choosewin(int);

    void paintEvent(QPaintEvent *);
    int k=1;


signals:
    void closeback();



public slots:

};

#endif // CHOOSEWIN_H
