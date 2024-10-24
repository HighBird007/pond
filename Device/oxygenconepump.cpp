#include "oxygenconepump.h"
#include "ui_oxygenconepump.h"

OxygenConePump::OxygenConePump(QString id,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OxygenConePump),oxyId(id)
{
    ui->setupUi(this);
    ui->label->setText(id);
    ui->DeviceStatus->setText("设备状态未知");
    ui->DeviceStatus->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
}

OxygenConePump::~OxygenConePump()
{
    delete ui;
}

void OxygenConePump::updateDeviceStatus(QString str, statusType type)
{
    if (type == statusType::ok) {
        // 设置淡绿色背景，字体颜色设置为深绿色
        ui->DeviceStatus->setText(str);
        ui->DeviceStatus->setStyleSheet("background-color: lightgreen; color: darkgreen; font-weight: bold;");
        ui->DeviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/o2ok.svg").scaledToHeight(ui->DeviceIcon->height()));
    }
    else if (type == statusType::error) {
        // 设置红色背景，字体为白色，加粗，增加警示效果
        ui->DeviceStatus->setText("设备故障！");
        ui->DeviceStatus->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
        ui->DeviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/o2error.svg").scaledToHeight(ui->DeviceIcon->height()));
    }
}

void OxygenConePump::setDeviceIcon()
{
    ui->DeviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/o2ok.svg").scaledToHeight(ui->DeviceIcon->height()));
}
