#ifndef FISHPOND_H
#define FISHPOND_H

#include <QWidget>
#include <Device/wastedischargevalve.h>
namespace Ui {
class fishpond;
}

class fishpond : public QWidget
{
    Q_OBJECT

public:
    explicit fishpond(QWidget *parent = nullptr);
    explicit fishpond(int,QWidget *parent = nullptr);
    void updateWasteDeviceStatus(QString,statusType);
    ~fishpond();

private:
    Ui::fishpond *ui;
    int pondId=-1;
    WasteDischargeValve *value;

};

#endif // FISHPOND_H
