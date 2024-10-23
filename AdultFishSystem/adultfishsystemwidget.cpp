#include "adultfishsystemwidget.h"
#include "ui_adultfishsystemwidget.h"

AdultFishSystemWidget::AdultFishSystemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdultFishSystemWidget)
{
    ui->setupUi(this);
    for (int i = 0; i < 4; ++i) {
        fishpond *pond = new fishpond(QString("pond %1").arg(i),this);
        pondVec.push_back(pond);
        pond->setFixedSize(150, 150);  // 设置每个 fishpond 的固定大小
        ui->horizontalLayout->addWidget(pond, 1);  // 添加到布局中，并设置拉伸因子
    }
    for (int i = 0; i < 4; ++i) {
        fishpond *pond = new fishpond(QString("pond %1").arg(i),this);
        pondVec.push_back(pond);
        pond->setFixedSize(150, 150);  // 设置每个 fishpond 的固定大小
        ui->horizontalLayout_2->addWidget(pond, 1);  // 添加到布局中，并设置拉伸因子
    }
    ui->label->setPixmap(QPixmap(":/new/prefix1/G:/reservoir.svg"));
}

AdultFishSystemWidget::~AdultFishSystemWidget()
{
    delete ui;
}

void AdultFishSystemWidget::updateDevicesStatus(int num,int order)
{
    if(order>=errorVec.size())return ;
    for(int i = 8,j=0;i < 16 ;i+=2,j++){
        if(num&(1<<i)){
            qDebug()<<"first"<<errorVec[order][i];
            pondVec[j]->updateWasteDeviceStatus(errorVec[order][i]);
        }else if(num&(1<<(i+1))){
            pondVec[j]->updateWasteDeviceStatus(errorVec[order][i]);
             qDebug()<<"second";
        }
    }
}

void AdultFishSystemWidget::initErrorVec(QVector<QString> v)
{
    for(auto it:v)qDebug()<<it;
    errorVec.push_back(v);
}

void AdultFishSystemWidget::on_pushButton_clicked()
{
    updateDevicesStatus(10000,0);
}

