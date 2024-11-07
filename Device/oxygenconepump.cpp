#include "oxygenconepump.h"
#include "ui_oxygenconepump.h"

OxygenConePump::OxygenConePump(int id, QWidget *parent)
    : DeviceFather(parent)  // 调用 DeviceFather 的构造函数，而不是 QWidget
    , ui(new Ui::OxygenConePump), oxyId(id)
{
    ui->setupUi(this);
    ui->DeviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/o2error.svg").scaledToHeight(ui->DeviceIcon->height()));
    ui->label->setText(QString("氧气泵%1").arg(id));
    ui->DeviceStatus->setText("设备未知");
    ui->DeviceStatus->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
    ui->DeviceIcon->setPixmap(QPixmap(":/new/prefix1/G:/o2error.svg").scaledToHeight(ui->DeviceIcon->height()));
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

void OxygenConePump::updateDeviceInfo()
{
    ui->label->setText(QString("oxy %1").arg(deviceId));
}

