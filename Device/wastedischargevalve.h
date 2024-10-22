#ifndef WASTEDISCHARGEVALVE_H
#define WASTEDISCHARGEVALVE_H

#include <QWidget>
#include "Device/device.h"
class WasteDischargeValve : public Device
{
    Q_OBJECT
public:
    explicit WasteDischargeValve(QWidget *parent = nullptr);
    //所有设备都必须重写设置icon函数
    virtual void setDeviceIcon()override;
    //所有设备都必须重写
    virtual void setWrongString()override;
};

#endif // WASTEDISCHARGEVALVE_H
