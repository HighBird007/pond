#ifndef ADULTFISHSYSTEMWIDGET_H
#define ADULTFISHSYSTEMWIDGET_H

#include <QWidget>
#include <../fishpond.h>
namespace Ui {
class AdultFishSystemWidget;
}

class AdultFishSystemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdultFishSystemWidget(QWidget *parent = nullptr);
    ~AdultFishSystemWidget();
    void updateDevicesStatus(int,int);
    void initErrorVec(QVector<QString>);
private slots:
    void on_pushButton_clicked();

private:
    Ui::AdultFishSystemWidget *ui;
    QVector<fishpond*> pondVec;
    QVector<QVector<QString>> errorVec;
};

#endif // ADULTFISHSYSTEMWIDGET_H
