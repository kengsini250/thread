#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Work1 : public QObject
{
    Q_OBJECT

    int a = 0;
public:


public slots:
    void add()
    {
        if(a>=100)
            emit sendEnd();
        else {
            a += 10;
            emit send(a);
        }
    }

signals:
    void send(const int&);
    void sendEnd();
};

class Work2 : public QObject
{
    Q_OBJECT

    int a = 0;
public:


public slots:
    void add()
    {
        if(a>=100)
            emit sendEnd();
        else {
            a += 10;
            emit send(a);
        }
    }


signals:
    void send(const int&);
    void sendEnd();
};

#endif // CONTROL_H
