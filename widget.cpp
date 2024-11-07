#include "widget.h"
#include "ui_widget.h"
#include "AdultFishSystem/adultfishsystemwidget.h">

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->goToAdultFishSystem,&QPushButton::clicked,this,&Widget::goAdultFishSystem);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::goAdultFishSystem()
{

}

void Widget::on_goToAdultFishSystem_2_clicked()
{
    auto i =  new AdultFishSystemWidget();
    i->show();
    controlCenter::getInstance().addFishSystem("e46338809b281d30",i);
    controlCenter::getInstance().centerStart();

}

