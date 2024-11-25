
#ifndef DEVICEFATHER_H
#define DEVICEFATHER_H
#include <QObject>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QInputDialog>
#include <QWidget>
enum statusType{ok,error};
enum DeviceType{wspump,mfilter,wpump,wdvalve,ulamp,opump};
class DeviceFather:public QWidget
{
    Q_OBJECT
public:
     DeviceFather();
     DeviceFather(QWidget *parent = nullptr);  // 添加父对象构造
    virtual void updateDeviceStatus(QString,statusType) = 0;
protected:
    int deviceId;
    QMenu* menu;
protected:
    //鼠标右击弹出输入框触发
    virtual void setDeviceId();
    //更新设备显示的设备id文本
    virtual void updateDeviceInfo()=0;
protected:
    void mousePressEvent(QMouseEvent* event)override;

};
#endif // DEVICEFATHER_H
