#ifndef ADULTFISHSYSTEMWIDGET_H
#define ADULTFISHSYSTEMWIDGET_H

#include <QWidget>
#include <../fishpond.h>
#include <fishsystem.h>
#include <Device/oxygenconepump.h>
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
    void initErrorVec(QVector<QString>);
private slots:
    void on_pushButton_clicked();
protected:
    void updateWasteDeviceStatus(int num,int order);
    void updateOxygenDeviceStatus(int num,int order);
private:
    Ui::AdultFishSystemWidget *ui;
    QVector<fishpond*> pondVec;
    QVector<QVector<QString>> errorVec;
    QVector<OxygenConePump*> oxyVec;
};

#endif // ADULTFISHSYSTEMWIDGET_H
