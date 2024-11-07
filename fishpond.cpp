#include "fishpond.h"
#include "ui_fishpond.h"

fishpond::fishpond(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fishpond)
{
    ui->setupUi(this);
}
fishpond::fishpond(int flag,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fishpond),pondId(flag)
{
    ui->setupUi(this);
    value =new WasteDischargeValve(flag,this);
    ui->label_2->setText(QString("pond %1").arg(flag));
    ui->gridLayout->addWidget(value,2,0, Qt::AlignTop | Qt::AlignLeft);
    value->show();
}

void fishpond::updateWasteDeviceStatus(QString str,statusType type)
{
    value->updateDeviceStatus(str,type);
}
fishpond::~fishpond()
{
    delete ui;
}


