#ifndef SENDER_H
#define SENDER_H

#include <QWidget>

class sender : public QWidget
{
    Q_OBJECT
public:
    explicit sender(QWidget *parent = nullptr);

signals:
    void openwin();

public slots:
};

#endif // SENDER_H
