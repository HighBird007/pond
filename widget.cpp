#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // socket =new QTcpSocket;
    // socket->connectToHost("192.168.2.253",1030);
    // connect(socket,&QTcpSocket::readyRead,this,[=](){
    //     qDebug()<<socket->readAll();
    // });
    connect(ui->goToAdultFishSystem,&QPushButton::clicked,this,&Widget::goAdultFishSystem);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::goAdultFishSystem()
{

}
