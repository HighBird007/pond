#ifndef INITCENTER_H
#define INITCENTER_H

#include <QWidget>
#include <QVBoxLayout>
#include <initcenterlabel.h>
#include <Device/devicefather.h>
#include <QCloseEvent>
#include <QFile>
#include <QDir>
#include <QInputDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
namespace Ui {
class initCenter;
}
using std::unordered_map;
using std::map;
class initCenter : public QWidget
{
    Q_OBJECT

public:
    explicit initCenter(QWidget *parent = nullptr);
    ~initCenter();
    //返回用户当前保存的配置map
   const map<QString,std::pair<DeviceType,int>>& getUserSet();
    //将用户已经设置好的json配置读取并且设置对应的map
   void jsonToMap(QString name);
private slots:
    void saveJson();
private:
    void addDevice();
    void delDevice(int index);
    //根据现有的map更新一下initcenterlabel 适用于用户读取配置json文件 只能调用一次否则出问题
    void updateDevice();
protected:
    void closeEvent(QCloseEvent *event) override;
    signals:
    //此信号发送 那么此类控制的养鱼界面就会根据data 数据 进行界面的部署
    void setSure();
private:
    Ui::initCenter *ui;
    QVBoxLayout *l;
    unordered_map<int,initCenterLabel*> umap;
    map<QString,std::pair<DeviceType,int>> data;
    int initCenterLabelIndex = 0;
};
#endif // INITCENTER_H
