#ifndef OXYGENCONEPUMP_H
#define OXYGENCONEPUMP_H
#include <Device/devicefather.h>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
namespace Ui {
class OxygenConePump;
}

class OxygenConePump : public DeviceFather
{
    Q_OBJECT

public:
    explicit OxygenConePump(int,QWidget *parent = nullptr);
    ~OxygenConePump();
    void updateDeviceStatus(QString,statusType)override;
protected:
    void updateDeviceInfo()override;
private:
    Ui::OxygenConePump *ui;
    int oxyId =-1;
};
#endif // OXYGENCONEPUMP_H
