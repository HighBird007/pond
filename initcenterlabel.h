#ifndef INITCENTERLABEL_H
#define INITCENTERLABEL_H

#include <QWidget>
#include <Device/devicefather.h>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
namespace Ui {
class initCenterLabel;
}

class initCenterLabel : public QWidget
{
    Q_OBJECT
public:
    explicit initCenterLabel(int,QWidget *parent = nullptr);
    ~initCenterLabel();
    DeviceType getDeviceType();
    int getIndex();
    void initCombox();
    QString getJsonName();
    int getNum() const;
    void setNum(int newNum);

private:
    void deviceUse(int index);
protected:
    void mousePressEvent(QMouseEvent*)override;
signals:
    void suicide(int);
private:
    Ui::initCenterLabel *ui;
    DeviceType type = wspump;
    int index;
    QMenu menu;
    QString jname;
    int num=1;
};

#endif // INITCENTERLABEL_H
