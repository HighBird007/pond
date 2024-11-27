#include "adultfishsystemwidget.h"
#include "ui_adultfishsystemwidget.h"

AdultFishSystemWidget::AdultFishSystemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdultFishSystemWidget)
{
    ui->setupUi(this);
    showModel = new DataShow(this);
    ui->tableView->setModel(showModel);
    ic=new initCenter();
    connect(ic,&initCenter::setSure,this,&AdultFishSystemWidget::setDeviceLayout);
    this->setWindowTitle("成鱼系统");
}

AdultFishSystemWidget::AdultFishSystemWidget(QString fileName, QWidget *parent)    : QWidget(parent)
    , ui(new Ui::AdultFishSystemWidget)
{
    ui->setupUi(this);

    showModel = new DataShow(this);
    ui->tableView->setModel(showModel);
    ic=new initCenter();
    connect(ic,&initCenter::setSure,this,&AdultFishSystemWidget::setDeviceLayout);
    this->setWindowTitle("成鱼系统");

    ic->jsonToMap(fileName);
}

AdultFishSystemWidget::~AdultFishSystemWidget()
{
    delete ui;
}

void AdultFishSystemWidget::updateDevicesStatus(int num,int order)
{
    updateWasteDeviceStatus(num,order);
    if(order==0){
    updateOxygenDeviceStatus(num);
    UpdateWaterPumpHasError(num);
    }else{
    UpdateWaterSupplyPumpHasError(num);
    UpdateMicroFilterHasError(num);
    }
}
//更新补水泵异常状态
void AdultFishSystemWidget::UpdateWaterSupplyPumpHasError(int b)
{
    if(b&(1<<10)){}
   // ui->wsp->updateDeviceStatus(QString("补水高液位超时"),statusType::error);
}
//更新微滤机 微滤池异常状态
void AdultFishSystemWidget::UpdateMicroFilterHasError(int num)
{
    /*
    if(num&(1<<11)&&num&(1<<12)){
        ui->widget->updateDeviceStatus(QString("跳闸高液位"),statusType::error);
        return ;
    }
    if(num&(1<<11)){
    ui->widget->updateDeviceStatus(QString("微滤池高液位超时"),statusType::error);
    }else if(num&(1<<12)){
    ui->widget->updateDeviceStatus(QString("微滤机电源跳闸"),statusType::error);
    }
    if(num&(1<<15)){
    ui->widget->updateDeviceStatus(QString("微滤池低液位长时间不消失报警"),statusType::error);
    }
    */
}
//微滤机是否使用
void AdultFishSystemWidget::UpdateMicroFilterIsUsing(bool b)
{
   // ui->wsp->updateDeviceStatus(b?"运行中":"未运行",statusType::ok);
}
//紫外线
void AdultFishSystemWidget::UpdateUvLampIsUsing(bool b)
{
   // ui->ul->updateDeviceStatus(b?"运行中":"未运行",statusType::ok);
}

void AdultFishSystemWidget::UpdateUvLampHasError(bool b)
{
    //if(b)ui->ul->updateDeviceStatus("故障",statusType::error);
}
//氧泵
void AdultFishSystemWidget::UpdateO2PumpAreUsing(const QVector<bool> &vec)
{
    for(int i = 0; i<oxyVec.size();i++){
        oxyVec[i]->updateDeviceStatus(vec[i]?"运行中":"未运行",statusType::ok);
    }
}

void AdultFishSystemWidget::UpdateO2PumpHaveError(const QVector<bool> &vec)
{
    for(int i = 0; i<oxyVec.size();i++){
        if(!vec[i])
        oxyVec[i]->updateDeviceStatus("故障",statusType::error);
    }
}


void AdultFishSystemWidget::updateDeviceUsing(DeviceType type, bool b)
{
    switch(type){
    case DeviceType::wspump:
        UpdateWaterSupplyPumpIsUsing(b);
        break;
    case DeviceType::mfilter:
        UpdateMicroFilterIsUsing(b);
        break;
    case DeviceType::ulamp:
        UpdateUvLampIsUsing(b);
        break;
    default:
        break;
    }
}

void AdultFishSystemWidget::updateDeviceUsing(DeviceType t,const QVector<bool> &vec)
{
    switch(t){
    case DeviceType::opump:
        UpdateO2PumpAreUsing(vec);
        break;
    case DeviceType::wpump:
        UpdateWaterPumpsAreUsing(vec);
        break;
    default:
        break;
    }
}

void AdultFishSystemWidget::setMap(QJsonObject obj)
{
   const map<QString, std::pair<DeviceType, int> >& s =  ic->getUserSet();

    for(const auto &it : s){
        //设备数量
        int deviceNum = it.second.second;
        //设备类型
        DeviceType t = it.second.first;
        if(deviceNum==1){
           if(obj.contains(it.first)){
                updateDeviceUsing(t,obj[it.first].toBool());
           }
           else
           //如果一个设备有多个
           {
               QJsonArray jsonArray = obj[it.first].toArray(); // 获取 JSON 数组
               QVector<bool> boolVector;
               for (const QJsonValue &value : jsonArray) {
                   // 假设 JSON 数组中的每个元素是布尔值
                   boolVector.append(value.toBool()); // 转换为 bool 后添加到 QVector
               }
             updateDeviceUsing(t,boolVector);
           }
       }
    }
}

void AdultFishSystemWidget::setDeviceLayout()
{
    const map<QString, std::pair<DeviceType, int> >& s =  ic->getUserSet();

    for(const auto &it : s){
        //设备数量
        int deviceNum = it.second.second;
        //设备类型
        DeviceType t = it.second.first;

        switch (t) {
        case DeviceType::wspump: {
            // 调整水泵设备数量
            int size = wspVec.size();
            if (size > deviceNum) {
                for (int i = size - deviceNum; i > 0; --i) {
                    wspVec.back()->deleteLater();
                    wspVec.pop_back();
                }
            }
            for (int i = wspVec.size(); i < deviceNum; ++i) {
                WaterSupplyPump *d = new WaterSupplyPump(this);
                ui->deviceLay1->addWidget(d, 1);
                wspVec.push_back(d);
            }
            break;
        }
        case DeviceType::mfilter: {
            // 调整微滤设备数量
            int size = mfVec.size();
            if (size > deviceNum) {
                for (int i = size - deviceNum; i > 0; --i) {
                    mfVec.back()->deleteLater();
                    mfVec.pop_back();
                }
            }
            for (int i = mfVec.size(); i < deviceNum; ++i) {
                Microfilter *m = new Microfilter(this);
                ui->deviceLay1->addWidget(m, 1);
                mfVec.push_back(m);
            }
            break;
        }
        case DeviceType::ulamp: {
            // 调整紫外灯设备数量
            int size = uvVec.size();
            if (size > deviceNum) {
                for (int i = size - deviceNum; i > 0; --i) {
                    uvVec.back()->deleteLater();
                    uvVec.pop_back();
                }
            }
            for (int i = uvVec.size(); i < deviceNum; ++i) {
                UVLamp *u = new UVLamp(this);
                ui->deviceLay1->addWidget(u, 1);
                uvVec.push_back(u);
            }
            break;
        }
        case DeviceType::opump: {
            // 调整氧锥泵设备数量
            int size = oxyVec.size();
            if (size > deviceNum) {
                for (int i = size - deviceNum; i > 0; --i) {
                    oxyVec.back()->deleteLater();
                    oxyVec.pop_back();
                }
            }
            for (int i = oxyVec.size(); i < deviceNum; ++i) {
                OxygenConePump *p = new OxygenConePump(i, this);
                ui->deviceLay2->addWidget(p, 1);
                oxyVec.push_back(p);
            }
            break;
        }
        case DeviceType::wpump: {
            // 调整其他类型的水泵设备数量
            int size = wpVec.size();
            if (size > deviceNum) {
                for (int i = size - deviceNum; i > 0; --i) {
                    wpVec.back()->deleteLater();
                    wpVec.pop_back();
                }
            }
            for (int i = wpVec.size(); i < deviceNum; ++i) {
                WaterPump *p = new WaterPump(this);
                ui->deviceLay1->addWidget(p,1);
                wpVec.push_back(p);
            }
            break;
        }
        case DeviceType::fpond:{
            int size = pondVec.size();
            if (size > deviceNum) {
                for (int i = size - deviceNum; i > 0; --i) {
                    pondVec.back()->deleteLater();
                    pondVec.pop_back();
                }
            }
            for (int i = pondVec.size(); i < deviceNum; ++i) {

                fishpond *p = new fishpond(i,this);

                if(i<4)
                ui->pondLay1->addWidget(p,1);
                else
                ui->pondLay2->addWidget(p,1);

                pondVec.push_back(p);

            }
            break;


        }

        default: {
            qWarning() << "Unknown device type:" << t;
            break;
        }
        }

    }
}


//水泵
void AdultFishSystemWidget::UpdateWaterPumpHasError(int num)
{
    /*
    if(num&(1<<0))
    ui->widget_4->updateDeviceStatus("水泵1故障",statusType::error);
    if(num&(1<<1))
    ui->widget_5->updateDeviceStatus("水泵2故障",statusType::error);
*/
}
void AdultFishSystemWidget::UpdateWaterPumpsAreUsing(const QVector<bool> &vec)
{
    /*
    ui->widget_4->updateDeviceStatus(vec[0]?"运行中":"未运行",statusType::ok);
    ui->widget_4->updateDeviceStatus(vec[1]?"运行中":"未运行",statusType::ok);
*/
}
//更新补水泵是否使用
void AdultFishSystemWidget::UpdateWaterSupplyPumpIsUsing(bool b)
{
    //ui->wsp->updateDeviceStatus(b?QString("运行中"):QString("未运行"),statusType::ok);
}
//更新排污阀状态异常
void AdultFishSystemWidget::updateWasteDeviceStatus(int num,int order)
{

}
//处理系统的氧气系统
void AdultFishSystemWidget::updateOxygenDeviceStatus(int num)
{
    for(int i = 2;i<6;i++){
        if(num&(1<<i)){
            oxyVec[i-2]->updateDeviceStatus("故障",statusType::error);
        }
    }
}



void AdultFishSystemWidget::on_pushButton_2_clicked()
{
    double t = QRandomGenerator64::global()->generateDouble()*50;
    double o = QRandomGenerator64::global()->generateDouble()*100;
    double e=QRandomGenerator64::global()->generateDouble()*20000;
    showModel->UpdateData(t,o,e);
    ic->show();
}


template<typename DT>
void AdultFishSystemWidget::updateVecAndShow(QVector<DT *> &vec, int deviceNum, QLayout *l)
{
    int size = vec.size();
    if (size > deviceNum) {
        for (int i = size - deviceNum; i > 0; --i) {
            vec.back()->deleteLater();
            vec.pop_back();
        }
    }
    for (int i = vec.size(); i < deviceNum; ++i) {

        DT *p = new DT(i,this);

        l->addWidget(p,1);

        vec.push_back(p);

    }
}
