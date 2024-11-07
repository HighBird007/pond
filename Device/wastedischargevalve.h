#ifndef WASTEDISCHARGEVALVE_H
#define WASTEDISCHARGEVALVE_H
#include <Device/devicefather.h>
namespace Ui {
class WasteDischargeValve;
}

class WasteDischargeValve : public DeviceFather
{
    // Q_OBJECT

public:
    explicit WasteDischargeValve(int,QWidget *parent = nullptr);
    ~WasteDischargeValve();
    void updateDeviceStatus(QString,statusType)override;
private:
    Ui::WasteDischargeValve *ui;
protected:
    virtual void updateDeviceInfo()override;
};

#endif // WASTEDISCHARGEVALVE_H
