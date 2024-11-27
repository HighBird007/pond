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
    connect(ui->saveSet,&QPushButton::clicked,this,&initCenter::saveJson);
}

initCenter::~initCenter()
{
    delete ui;
}

const map<QString, std::pair<DeviceType, int> > &initCenter::getUserSet()
{
    return data;
}
//将用户已经设置好的json配置读取并且设置对应的map
void initCenter::jsonToMap(QString name)
{
    QFile file(QString("./userJson/pondJson/%1.json").arg(name));

    if (file.exists() && file.open(QIODevice::ReadOnly)){

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();
        qDebug()<<obj;
        for(auto it = obj.begin();it!=obj.end();it++){

            QString key = it.key();
            QJsonObject son = it.value().toObject();

            int deviceType = son["DeviceType"].toInt();  // 获取设备类型（枚举值）
            int num = son["DeviceNum"].toInt();  // 获取设备数量

            DeviceType type = static_cast<DeviceType>(deviceType);

            data[key] = std::make_pair(type, num);

        }
        file.close();
        updateDevice();
        emit setSure();
    }
}

void initCenter::updateDevice()
{
    for(const auto &it:data){
        initCenterLabel *a=new initCenterLabel(initCenterLabelIndex,this);
        a->setComboxValue(it.second.first);
        a->setSpinBoxValue(it.second.second);
        a->setLineEditValue(it.first);
        connect(a,&initCenterLabel::suicide,this,&initCenter::delDevice);
        l->addWidget(a,1);
        initCenterLabelIndex++;
    }
}



//将用户的配置保存json文件
void initCenter::saveJson()
{
    bool isSure = false;
    QString str = QInputDialog::getText(this,"输入池塘名称","池塘编号",QLineEdit::Normal,QDateTime::currentDateTime().toString(),&isSure);
    if(isSure&&!str.isEmpty()){
        for(auto &it : umap){
            initCenterLabel *p = it.second;
            data[p->getJsonName()]=std::make_pair(p->getDeviceType(),p->getNum());
        }
        QFile file(QString("./userJson/pondJson/%1.json").arg(str));

       file.open(QIODevice::WriteOnly);

        QJsonObject obj ;

       for(const auto &it : data){

           std::pair<DeviceType,int> d = it.second;
           QString key = it.first;

               QJsonObject sonObj;
               sonObj["DeviceType"] = d.first;
               sonObj["DeviceNum"] = d.second;

               obj[key] = sonObj ;

        }
       QJsonDocument doc(obj);
       file.write(doc.toJson());
       file.close();
   }
}

void initCenter::addDevice()
{
    initCenterLabel *a=new initCenterLabel(initCenterLabelIndex,this);
    connect(a,&initCenterLabel::suicide,this,&initCenter::delDevice);
    umap[initCenterLabelIndex]=a;
    l->addWidget(a,1);
    initCenterLabelIndex++;
}

void initCenter::delDevice(int index)
{
    auto it =umap.find(index);
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

