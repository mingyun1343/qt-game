#ifndef RECEIVER_H
#define RECEIVER_H

#include <QWidget>

class receiver : public QWidget
{
    Q_OBJECT
public:
    explicit receiver(QWidget *parent = nullptr);

signals:

public slots:
    void openwin2();
};

#endif // RECEIVER_H
