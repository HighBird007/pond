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
};

#endif // FISHSYSTEM_H
