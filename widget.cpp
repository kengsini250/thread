#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pB1->setValue(0);
    ui->pB2->setValue(0);

//-----------------------必须要有的-------------------------------
    thread = new QThread;

    w1 = new Work;
    w1->moveToThread(thread);

    w2= new Work;
    w2->moveToThread(thread);

    connect(thread,&QThread::finished,w1,&QObject::deleteLater);
    connect(thread,&QThread::finished,w2,&QObject::deleteLater);
//-----------------------必须要有的-------------------------------


    connect(ui->P1,&QAbstractButton::clicked,w1,&Work::add);
    connect(ui->P2,&QAbstractButton::clicked,w2,&Work::add);

    connect(w1,&Work::sendEnd,thread,&QThread::quit);
    connect(w2,&Work::sendEnd,thread,&QThread::quit);

    connect(ui->pushButton,&QAbstractButton::clicked,[=]{
        thread->start();
    });

    connect(ui->pushButton_2,&QAbstractButton::clicked,[=]{
        thread->quit();
    });


    //ui是主线程，不能和子线程有交互
    /*
    connect(w1,&Work1::send,[&](const int& a){
        //ui->pB1->setValue(a);
    });
    connect(w2,&Work2::send,[&](const int& a){
        //ui->pB2->setValue(a);
    });
    */
    //主线程和子线程的交互，要用槽函数
    connect(w1,SIGNAL(send(const int&)),this,SLOT(updateA(const int&)));
    connect(w2,SIGNAL(send(const int&)),this,SLOT(updateB(const int&)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateA(const int &a)
{
    ui->pB1->setValue(a);
    qDebug()<<"workA : "<< a;
}

void Widget::updateB(const int &a)
{
    ui->pB2->setValue(a);
    qDebug()<<"workB : "<< a;
}





