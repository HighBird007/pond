#ifndef WATERSUPPLYPUMP_H
#define WATERSUPPLYPUMP_H

#include <Device/devicefather.h>

namespace Ui {
class WaterSupplyPump;
}

class WaterSupplyPump : public DeviceFather
{
    Q_OBJECT

public:
    explicit WaterSupplyPump(QWidget *parent = nullptr);
    ~WaterSupplyPump();
    void updateDeviceStatus(QString,statusType)override;
protected:
    virtual void updateDeviceInfo()override;
private:
    Ui::WaterSupplyPump *ui;
};

#endif // WATERSUPPLYPUMP_H
