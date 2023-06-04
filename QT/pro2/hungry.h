#ifndef HUNGRY_H
#define HUNGRY_H

#include <QObject>

class hungry : public QObject
{
    Q_OBJECT
public:
    explicit hungry(QObject *parent = nullptr);

signals:

public slots:

    void eat();
    void eat(QString);
};

#endif // HUNGRY_H
