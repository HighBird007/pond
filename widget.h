#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <controlcenter.h>
#include <initcenter.h>
#include <initcenterlabel.h>
#include <QVBoxLayout>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <showuserset.h>
#include "AdultFishSystem/adultfishsystemwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    //罗列出用户已经保存的渔场json配置文件
    void initFileShow();
private slots:
    void goAdultFishSystem();
    void on_goToAdultFishSystem_2_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* socket;
};
#endif // WIDGET_H
