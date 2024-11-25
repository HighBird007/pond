#ifndef FISHSYSTEM_H
#define FISHSYSTEM_H
#include <../fishpond.h>
#include <Device/oxygenconepump.h>
#include <Device/watersupplypump.h>
#include <Device/microfilter.h>
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
