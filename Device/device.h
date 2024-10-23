#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>
#include "ui_device.h"
namespace Ui {
class Device;
}

class Device : public QWidget
{
    Q_OBJECT

public:
    explicit Device(QWidget *parent = nullptr);
    ~Device();
    //所有设备都必须重写设置icon函数
    virtual void setDeviceIcon()=0;
protected:
        Ui::Device *ui;
    QString normalUse="正常开";
    QString normalUnuse="正常关";
};

#endif // DEVICE_H
