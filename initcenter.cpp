#include "initcenter.h"
#include "oxygenconepump.h"
#include "ui_initcenter.h"

initCenter::initCenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::initCenter)
{
    ui->setupUi(this);
    l=new QVBoxLayout(this);
    connect(ui->addDevice,&QPushButton::clicked,this,&initCenter::addDevice);
    ui->scrollArea->widget()->setLayout(l);
}

initCenter::~initCenter()
{
    delete ui;
}

void initCenter::addDevice()
{
    static int index = 0;
    initCenterLabel *a=new initCenterLabel(this);
    a->setIndex(index);
    connect(a,&initCenterLabel::suicide,this,&initCenter::delDevice);
    umap[index]=a;
    l->addWidget(a,1);
    index++;
}

void initCenter::delDevice(int index)
{   auto it =umap.find(index);
    if(it!=umap.end()){
        umap.erase(it);
    }
}

void initCenter::on_delDevice_clicked()
{
    QVector<OxygenConePump *> vec;

    QVector<fishpond *> pondVec;
    for(auto it : umap) {
        switch (it.second->getDeviceType()) {
        case 0:  // 补水泵
               // vec.push_back();
            break;
        case 1:  // 水泵
               // vec.push_back(it);
            break;
        case 2:  // 氧锥泵
            vec.push_back(new OxygenConePump(it.second->getIndex()));
            break;
        case 3://池塘
            pondVec.push_back(new fishpond(it.second->getIndex()));
            break;
        case 4:  // 微滤机
            //    vec.push_back(it);
            break;
        case 5:  // 紫外灯
          //  if (dynamic_cast<UVLamp*>(it)) {
              //  vec.push_back(it);
           // }
            break;
        default:
            break;
        }
    }

    // 输出调试信息，查看找到的设备数量
    qDebug() << "Found" << vec.size() << "devices of selected type.";
    AdultFishSystemWidget *afsw=new AdultFishSystemWidget();

    afsw->show();
}

