#ifndef MICROFILTER_H
#define MICROFILTER_H

#include <Device/devicefather.h>
namespace Ui {
class Microfilter;
}

class Microfilter : public DeviceFather
{
    Q_OBJECT

public:
    explicit Microfilter(QWidget *parent = nullptr);
    ~Microfilter();
    void updateDeviceStatus(QString,statusType)override;
protected:
    void updateDeviceInfo()override;
private:
    Ui::Microfilter *ui;
};

#endif // MICROFILTER_H
