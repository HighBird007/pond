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
    //所有设备都必须重写至少两种错误情况
    virtual void setWrongString()=0;
    void initDevice();
protected:
        Ui::Device *ui;
    QString normalUse;
    QString normalUnuse;
    QString wrongOccurOne;
    QString wrongOccurTwo;
};

#endif // DEVICE_H
