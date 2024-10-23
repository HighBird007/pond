#ifndef WASTEDISCHARGEVALVE_H
#define WASTEDISCHARGEVALVE_H

#include <QWidget>
#include "Device/device.h"
#include "ui_device.h"
class WasteDischargeValve : public Device
{
    Q_OBJECT
public:
    explicit WasteDischargeValve(QWidget *parent = nullptr);
    //所有设备都必须重写设置icon函数
    virtual void setDeviceIcon()override;
    void setCurrentStatus(QString);
private:
    Ui::Device *ui;
};

#endif // WASTEDISCHARGEVALVE_H
