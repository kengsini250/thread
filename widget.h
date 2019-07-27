#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include "work.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private:
    QThread *thread;
    Work* w1,*w2;

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void updateA(const int& a);
    void updateB(const int& a);

private:
    Ui::Widget *ui;

signals:
    void Awork();
    void Bwork();
};

#endif // WIDGET_H
