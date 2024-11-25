#include "uvlamp.h"
#include "ui_uvlamp.h"

UVLamp::UVLamp(QWidget *parent)
    : DeviceFather(parent)
    , ui(new Ui::UVLamp)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/UVLampClose.svg").scaledToHeight(ui->label->height()));
    updateDeviceStatus("未知",statusType::error);
    // 在C++代码中设置objectName
  //  this->setObjectName("MainWidget");
   // this->setStyleSheet("/* 为顶层主容器设置黑色边框 */#MainWidget {  border: 2px solid black; /* 设置边框为2像素黑色线 */ border-radius: 5px; /* 可选：增加圆角效果 */ padding: 5px; /* 可选：控制边框和内部内容之间的间距 */}");
}

UVLamp::~UVLamp()
{
    delete ui;
}

void UVLamp::updateDeviceStatus(QString str, statusType type)
{
    if (type == statusType::ok) {
        // 设置淡绿色背景，字体颜色设置为深绿色
        ui->label_2->setText(str);
        ui->label_2->setStyleSheet("background-color: lightgreen; color: darkgreen; font-weight: bold;");
        ui->label->setPixmap(QPixmap(":/new/prefix1/G:/UVLampOpen.svg").scaledToHeight(ui->label->height()));
    }
    else if (type == statusType::error) {
        // 设置红色背景，字体为白色，加粗，增加警示效果
        ui->label_2->setText(str);
        ui->label_2->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 10px;");
        ui->label->setPixmap(QPixmap(":/new/prefix1/G:/UVLampClose.svg").scaledToHeight(ui->label->height()));
    }
}

void UVLamp::updateDeviceInfo()
{

}
