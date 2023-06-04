#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class mybutton : public QPushButton
{
    Q_OBJECT
public:

    mybutton(QString bef, QString aft="");  //构造函数

    QString befaddress;
    QString aftaddress;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);



signals:

public slots:
};

#endif // MYBUTTON_H
