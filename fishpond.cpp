#include "fishpond.h"
#include "ui_fishpond.h"

fishpond::fishpond(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fishpond)
{
    ui->setupUi(this);
    value =new WasteDischargeValve(this);
    ui->label_2->setText(pondId);
}
fishpond::fishpond(QString flag,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fishpond),pondId(flag)
{
    ui->setupUi(this);
    value =new WasteDischargeValve(this);
    ui->label_2->setText(pondId);
    value->setDeviceIcon();
}

void fishpond::updateWasteDeviceStatus(QString str)
{
    value->setCurrentStatus(str);
    qDebug()<<str<<"update";
}
fishpond::~fishpond()
{
    delete ui;
}


