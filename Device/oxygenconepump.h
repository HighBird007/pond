#ifndef OXYGENCONEPUMP_H
#define OXYGENCONEPUMP_H

#include <QWidget>
#include <Device/devicefather.h>
namespace Ui {
class OxygenConePump;
}

class OxygenConePump : public QWidget,public DeviceFather
{
    Q_OBJECT

public:
    explicit OxygenConePump(QString,QWidget *parent = nullptr);
    ~OxygenConePump();
    void updateDeviceStatus(QString,statusType)override;
    void setDeviceIcon()override;
private:
    Ui::OxygenConePump *ui;
    QString oxyId;
};

#endif // OXYGENCONEPUMP_H
