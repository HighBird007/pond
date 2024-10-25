#include "devicefather.h"

DeviceFather::DeviceFather() {
    menu=new QMenu();
    QAction* a=new QAction("设置");
    menu->addAction(a);
    connect(a,&QAction::triggered,this,&DeviceFather::setDeviceId);
}

DeviceFather::DeviceFather(QWidget *parent):QWidget(parent)
{
    menu=new QMenu();
    QAction* a=new QAction("设置");
    menu->addAction(a);
    connect(a,&QAction::triggered,this,&DeviceFather::setDeviceId);
}

void DeviceFather::setDeviceId()
{
    bool ok;

    int id = QInputDialog::getInt( this,tr("设置编号"), tr("请输入设备编号(0-20):不可重复"), deviceId, 0, 20, 1, &ok);

    if (ok) {
        deviceId = id;
        updateDeviceInfo();
    }
}

void DeviceFather::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        QPoint globalPos = this->mapToGlobal(event->pos());
        qDebug()<<event->pos()<<globalPos;
        //event pos 是相对应用窗口的坐标 global相对显示屏的坐标
        menu->exec(globalPos);  // 在正确的全局坐标位置显示菜单
    }
}

