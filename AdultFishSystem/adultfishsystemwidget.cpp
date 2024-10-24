#include "adultfishsystemwidget.h"
#include "ui_adultfishsystemwidget.h"

AdultFishSystemWidget::AdultFishSystemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdultFishSystemWidget)
{
    ui->setupUi(this);
    for (int i = 0; i < 4; ++i) {
        fishpond *pond = new fishpond(QString("pond %1").arg(i+1),this);
        pondVec.push_back(pond);
        ui->horizontalLayout->addWidget(pond, 1);  // 添加到布局中，并设置拉伸因子
    }
    for (int i = 0; i < 4; ++i) {
        fishpond *pond = new fishpond(QString("pond %1").arg(i+5),this);
        pondVec.push_back(pond);
        ui->horizontalLayout_2->addWidget(pond, 1);  // 添加到布局中，并设置拉伸因子
    }
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/reservoir.svg"));
    for (int i = 0; i < 4; ++i) {
        auto *it = new OxygenConePump(QString("oxy %1").arg(i+1));
        oxyVec.push_back(it);
        it->setDeviceIcon();
        ui->verticalLayout_2->addWidget(it, 1);  // 添加到布局中，并设置拉伸因子
    }
}

AdultFishSystemWidget::~AdultFishSystemWidget()
{
    delete ui;
}

void AdultFishSystemWidget::updateDevicesStatus(int num,int order)
{
    if(order>=errorVec.size())return ;
    updateWasteDeviceStatus(num,order);
    updateOxygenDeviceStatus(num,order);
}

void AdultFishSystemWidget::initErrorVec(QVector<QString> v)
{
    errorVec.push_back(v);
}

void AdultFishSystemWidget::on_pushButton_clicked()
{
    updateDevicesStatus(10000,0);
}
//处理排水阀
void AdultFishSystemWidget::updateWasteDeviceStatus(int num,int order)
{
    for(int i = 8,j=0;i < 16 ;i+=2,j++){
        if(num&(1<<i)){
            pondVec[j]->updateWasteDeviceStatus(errorVec[order][i],statusType::error);
        }else if(num&(1<<(i+1))){
            pondVec[j]->updateWasteDeviceStatus(errorVec[order][i],statusType::error);
        }
    }
}
//处理系统的氧气系统
void AdultFishSystemWidget::updateOxygenDeviceStatus(int num, int order)
{
    for(int i = 2;i<6;i++){
        if(num&(1<<i)){
            oxyVec[i-2]->updateDeviceStatus(errorVec[order][i],statusType::error);
        }
    }
}

