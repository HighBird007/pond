#ifndef FISHSYSTEM_H
#define FISHSYSTEM_H

class FishSystem
{
public:
    FishSystem();
    virtual  void updateDevicesStatus(int,int)=0;
};

#endif // FISHSYSTEM_H
