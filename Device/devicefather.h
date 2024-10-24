#ifndef DEVICEFATHER_H
#define DEVICEFATHER_H

#include <QObject>
enum statusType{ok,error};
class DeviceFather
{
    //Q_OBJECT
public:
    DeviceFather();
    virtual void updateDeviceStatus(QString,statusType) = 0;
    virtual     void setDeviceIcon()=0;
};

#endif // DEVICEFATHER_H
