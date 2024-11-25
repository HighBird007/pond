#ifndef ADULTFISHSYSTEMWIDGET_H
#define ADULTFISHSYSTEMWIDGET_H

#include <QWidget>
#include <fishsystem.h>
#include <../datashow.h>
#include <QRandomGenerator>
#include <../initcenter.h>
#include <../initcenterlabel.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <microfilter.h>
#include <oxygenconepump.h>
#include <uvlamp.h>
#include <waterpump.h>
#include <fishpond.h>
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
    void UpdateO2PumpHaveError(const QVector<bool> &vec);
    //更新设备状态
    void updateDeviceUsing(DeviceType,bool);
    void updateDeviceUsing(DeviceType t, const QVector<bool> &vec);

    //设置map
    void setMap(QJsonObject obj);
    void setDeviceLayout();

protected:
    void updateWasteDeviceStatus(int num,int order);
    void updateOxygenDeviceStatus(int num);
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AdultFishSystemWidget *ui;
    DataShow *showModel;
    initCenter *ic;
    QVector<OxygenConePump*> oxyVec;
    QVector<UVLamp*> uvVec;
    QVector<Microfilter*> mfVec;
    QVector<WaterPump*> wpVec;
    QVector<WaterSupplyPump*> wspVec;
    QVector<fishpond*> pondVec;
    //QVector<*> Vec;
};

#endif // ADULTFISHSYSTEMWIDGET_H
