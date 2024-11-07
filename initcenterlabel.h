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
    explicit initCenterLabel(QWidget *parent = nullptr);
    ~initCenterLabel();
    int getDeviceType();
    int getIndex();
    void setIndex(int i);
private:
    void deviceUse(int index);
protected:
    void mousePressEvent(QMouseEvent*)override;
signals:
    void suicide(int);
private:
    Ui::initCenterLabel *ui;
    int type=-1;
    int index=0;
    QMenu menu;
};

#endif // INITCENTERLABEL_H
