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

const map<QString, std::pair<DeviceType, int> > &initCenter::getUserSet()
{
    return data;
}

void initCenter::addDevice()
{
    static int index = 0;
    initCenterLabel *a=new initCenterLabel(index,this);
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

void initCenter::closeEvent(QCloseEvent *event)
{
    for(auto &it : umap){
        initCenterLabel *p = it.second;
        data[p->getJsonName()]=std::make_pair(p->getDeviceType(),p->getNum());
    }
    emit setSure();
    event->accept();
}

void initCenter::on_delDevice_clicked()
{

}

