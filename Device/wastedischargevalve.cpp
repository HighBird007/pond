#include "wastedischargevalve.h"

WasteDischargeValve::WasteDischargeValve(QWidget *parent ) : Device(parent)
{
   // ui->setupUi(this);
    ui->deviceStatus->setText(normalUse);

}

void WasteDischargeValve::setDeviceIcon()
{
    ui->deviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/wastedischarge.svg").scaledToHeight(ui->deviceIcon->height()));
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/ok.svg").scaledToHeight(ui->label->height()));
}

void WasteDischargeValve::setCurrentStatus(QString str)
{
    ui->deviceStatus->setText(normalUse);
    qDebug()<<"waste"<<str;
}

