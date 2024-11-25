#ifndef INITCENTER_H
#define INITCENTER_H

#include <QWidget>
#include <QVBoxLayout>
#include <initcenterlabel.h>
#include <Device/devicefather.h>
#include <QCloseEvent>
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
   const map<QString,std::pair<DeviceType,int>>& getUserSet();
private slots:
    void on_delDevice_clicked();
private:
    void addDevice();
    void delDevice(int index);
protected:
    void closeEvent(QCloseEvent *event) override;
    signals:
    void setSure();
private:
    Ui::initCenter *ui;
    QVBoxLayout *l;
    unordered_map<int,initCenterLabel*> umap;
    map<QString,std::pair<DeviceType,int>> data;
};

#endif // INITCENTER_H
