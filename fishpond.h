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
    explicit fishpond(QString,QWidget *parent = nullptr);
    void updateWasteDeviceStatus(QString);
    ~fishpond();

private:
    Ui::fishpond *ui;
    QString pondId="unknown";
    WasteDischargeValve *value;

};

#endif // FISHPOND_H
