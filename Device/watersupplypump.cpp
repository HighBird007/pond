#include "watersupplypump.h"
#include "ui_watersupplypump.h"

WaterSupplyPump::WaterSupplyPump(QWidget *parent)
    : DeviceFather(parent)
    , ui(new Ui::WaterSupplyPump)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/WaterSupplyPumpOpen.svg").scaledToHeight(ui->label->height()));
    ui->label_2->setText("补水泵");
    ui->label_3->setText("状态未知");
}

WaterSupplyPump::~WaterSupplyPump()
{
    delete ui;
}

void WaterSupplyPump::updateDeviceStatus(QString str, statusType type)
{
    if (type == statusType::ok) {
        // 设置淡绿色背景，字体颜色设置为深绿色
        ui->label_3->setText(str);
        ui->label_3->setStyleSheet("background-color: lightgreen; color: darkgreen; font-weight: bold;");
    }
    else if (type == statusType::error) {
        // 设置红色背景，字体为白色，加粗，增加警示效果
        ui->label_3->setText(str);
        ui->label_3->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
    }
}

void WaterSupplyPump::updateDeviceInfo()
{

}
