#include "microfilter.h"
#include "ui_microfilter.h"

Microfilter::Microfilter(QWidget *parent)
    : DeviceFather(parent)
    , ui(new Ui::Microfilter)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/filtererror.svg").scaledToHeight(ui->label->height()));
    ui->label_2->setText("设备故障！");
    ui->label_2->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/filtererror.svg").scaledToHeight(ui->label->height()));
    ui->label_3->setText("微滤机");
}

Microfilter::~Microfilter()
{
    delete ui;
}

void Microfilter::updateDeviceStatus(QString str, statusType type)
{
    if (type == statusType::ok) {
        // 设置淡绿色背景，字体颜色设置为深绿色
        ui->label_2->setText(str);
        ui->label_2->setStyleSheet("background-color: lightgreen; color: darkgreen; font-weight: bold;");
        ui->label->setPixmap(QPixmap(":/new/prefix1/G:/filterok.svg").scaledToHeight(ui->label->height()));
    }
    else if (type == statusType::error) {
        // 设置红色背景，字体为白色，加粗，增加警示效果
        ui->label_2->setText("设备故障！");
        ui->label_2->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
        ui->label->setPixmap(QPixmap(":/new/prefix1/G:/filtererror.svg").scaledToHeight(ui->label->height()));
    }
}

void Microfilter::updateDeviceInfo()
{
        ui->label_2->setText(QString("oxy %1").arg(deviceId));
}
