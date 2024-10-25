#include "wastedischargevalve.h"
#include "ui_wastedischargevalve.h"

WasteDischargeValve::WasteDischargeValve(QWidget *parent)
    : DeviceFather(parent)
    , ui(new Ui::WasteDischargeValve)
{
    ui->setupUi(this);
    ui->label_2->setText("设备状态未知");
    ui->label_2->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
    ui->label_3->setText("未定义编号");
}

WasteDischargeValve::~WasteDischargeValve()
{
    delete ui;
}

void WasteDischargeValve::setDeviceIcon()
{
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/wastedischarge.svg").scaledToHeight(ui->label->height()));
}

void WasteDischargeValve::updateDeviceStatus(QString str, statusType type)
{
    if (type == statusType::ok) {
        // 设置淡绿色背景，字体颜色设置为深绿色
        ui->label_2->setText(str);
        ui->label_2->setStyleSheet("background-color: lightgreen; color: darkgreen; font-weight: bold;");
    }
    else if (type == statusType::error) {
        // 设置红色背景，字体为白色，加粗，增加警示效果
        ui->label_2->setText("设备故障！");
        ui->label_2->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
    }
}

void WasteDischargeValve::updateDeviceInfo()
{
    ui->label_3->setText(QString("waste %1").arg(deviceId));
}
