#ifndef MOON_H
#define MOON_H

#include <QObject>

class moon : public QObject
{
    Q_OBJECT
public:
    explicit moon(QObject *parent = nullptr);

signals:
    void silent();
    void silent(QString);

public slots:
};

#endif // MOON_H
