#ifndef FISHSYSTEM_H
#define FISHSYSTEM_H
#include <../fishpond.h>
#include <Device/oxygenconepump.h>
#include <Device/watersupplypump.h>
enum DeviceType{wspump,mfilter,wpump,wdvalve,ulamp,opump};
class FishSystem
{
public:
    FishSystem();
    virtual  void updateDevicesStatus(int,int)=0;
protected:
    QVector<fishpond*> pondVec;
    QVector<OxygenConePump*> oxyVec;
};

#endif // FISHSYSTEM_H
