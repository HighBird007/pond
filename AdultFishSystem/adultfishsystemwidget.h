#ifndef ADULTFISHSYSTEMWIDGET_H
#define ADULTFISHSYSTEMWIDGET_H

#include <QWidget>
#include <../fishpond.h>
#include <fishsystem.h>
#include <Device/oxygenconepump.h>
#include <Device/microfilter.h>
#include <Device/watersupplypump.h>
namespace Ui {
class AdultFishSystemWidget;
}

class AdultFishSystemWidget : public QWidget,public FishSystem
{
    Q_OBJECT

public:
    explicit AdultFishSystemWidget(QWidget *parent = nullptr);
    ~AdultFishSystemWidget();
    void updateDevicesStatus(int,int);
    //补水泵
    void UpdateWaterSupplyPumpIsUsing(bool);
    void UpdateWaterSupplyPumpHasError(int);
    //微滤机
    void UpdateMicroFilterHasError(int num);
    void UpdateMicroFilterIsUsing(bool);
    //水泵
    void UpdateWaterPumpHasError(int);
    void UpdateWaterPumpsAreUsing(const QVector<bool> &);
    //紫外线
    void UpdateUvLampIsUsing(bool b);
    void UpdateUvLampHasError(bool b);
    //氧泵
    void UpdateO2PumpAreUsing(const QVector<bool> &vec);
    void UpdateO2PumpHaveError(QVector<bool> vec);

    void updateDeviceIsUsing(DeviceType,bool);
    void updateDeviceIsUsing(DeviceType,QVector<bool> vec);
    void updateDeviceIsUsing(DeviceType t, const QVector<bool> &vec);
protected:
    void updateWasteDeviceStatus(int num,int order);
    void updateOxygenDeviceStatus(int num);
private:
    Ui::AdultFishSystemWidget *ui;
};

#endif // ADULTFISHSYSTEMWIDGET_H
