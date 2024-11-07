#ifndef INITCENTER_H
#define INITCENTER_H

#include <QWidget>
#include <QVBoxLayout>
#include <initcenterlabel.h>
#include <Device/devicefather.h>
#include <QList>
#include <AdultFishSystem/adultfishsystemwidget.h>
namespace Ui {
class initCenter;
}
using std::unordered_map;
class initCenter : public QWidget
{
    Q_OBJECT

public:
    explicit initCenter(QWidget *parent = nullptr);
    ~initCenter();
private slots:
    void on_delDevice_clicked();

private:
    void addDevice();
    void delDevice(int index);
private:
    Ui::initCenter *ui;
    QVBoxLayout *l;
    unordered_map<int,initCenterLabel*> umap;
};

#endif // INITCENTER_H
