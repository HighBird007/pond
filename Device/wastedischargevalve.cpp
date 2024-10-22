#include "wastedischargevalve.h"

WasteDischargeValve::WasteDischargeValve(QWidget *parent ) : Device(parent)
{
    initDevice();
}

void WasteDischargeValve::setDeviceIcon()
{
    ui->deviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/wastedischarge.svg").scaledToHeight(ui->deviceIcon->height()));
}

void WasteDischargeValve::setWrongString()
{
    this->normalUse="正常开";
    this->normalUnuse="正常关";
    this->wrongOccurOne="开不到位";
    this->wrongOccurTwo="关不到位";
}
