#ifndef MAINBUTTON_H
#define MAINBUTTON_H

#include <QWidget>

namespace Ui {
class mainbutton;
}

class mainbutton : public QWidget
{
    Q_OBJECT

public:
    explicit mainbutton(QWidget *parent = 0);
    ~mainbutton();

      void paintEvent(QPaintEvent *);

private:
    Ui::mainbutton *ui;
};

#endif // MAINBUTTON_H
