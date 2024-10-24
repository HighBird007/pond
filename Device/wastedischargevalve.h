#ifndef WASTEDISCHARGEVALVE_H
#define WASTEDISCHARGEVALVE_H

#include <QWidget>
#include <Device/devicefather.h>
namespace Ui {
class WasteDischargeValve;
}

class WasteDischargeValve : public QWidget,public DeviceFather
{
    Q_OBJECT

public:
    explicit WasteDischargeValve(QWidget *parent = nullptr);
    ~WasteDischargeValve();
    void setDeviceIcon()override;
    void updateDeviceStatus(QString,statusType)override;
private:
    Ui::WasteDischargeValve *ui;
};

#endif // WASTEDISCHARGEVALVE_H
