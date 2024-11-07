#ifndef WATERPUMP_H
#define WATERPUMP_H

#include <Device/devicefather.h>

namespace Ui {
class WaterPump;
}

class WaterPump : public DeviceFather
{
    Q_OBJECT

public:
    explicit WaterPump(QWidget *parent = nullptr);
    ~WaterPump();
 void updateDeviceStatus(QString,statusType)override;
protected:
    virtual void updateDeviceInfo()override;
private:
    Ui::WaterPump *ui;
};

#endif // WATERPUMP_H
