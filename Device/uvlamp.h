#ifndef UVLAMP_H
#define UVLAMP_H


#include <Device/devicefather.h>

namespace Ui {
class UVLamp;
}

class UVLamp : public DeviceFather
{
    Q_OBJECT

public:
    explicit UVLamp(QWidget *parent = nullptr);
    ~UVLamp();
    void updateDeviceStatus(QString,statusType)override;
protected:
    void updateDeviceInfo()override;
private:
    Ui::UVLamp *ui;
};

#endif // UVLAMP_H
