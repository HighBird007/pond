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
    //返回当前的设备类型
    DeviceType getDeviceType();
    int getIndex();

    void initCombox();

    QString getJsonName();

    //获取到spinbox的设置值
    int getNum() const;
    //槽函数  将spinbox修改的值映射到num
    void setNum(int newNum);

    //初始化函数 同setcombox
    void setComboxValue(int num);
    void setSpinBoxValue(int num);
    void setLineEditValue(QString str);

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
