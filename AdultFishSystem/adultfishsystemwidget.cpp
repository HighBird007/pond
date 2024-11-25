#include "adultfishsystemwidget.h"
#include "ui_adultfishsystemwidget.h"

AdultFishSystemWidget::AdultFishSystemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdultFishSystemWidget)
{
    ui->setupUi(this);
    for (int i = 0; i < 4; ++i) {
        fishpond *pond = new fishpond(i+1,this);
        pondVec.push_back(pond);
        ui->horizontalLayout->addWidget(pond, 1);  // 添加到布局中，并设置拉伸因子
    }
    for (int i = 0; i < 4; ++i) {
        fishpond *pond = new fishpond(i+5,this);
        pondVec.push_back(pond);
        ui->horizontalLayout_2->addWidget(pond, 1);  // 添加到布局中，并设置拉伸因子
    }
      ui->label->setPixmap(QPixmap(":/new/prefix1/G:/reservoir.svg"));
    for (int i = 0; i < 4; ++i) {
        auto *it = new OxygenConePump(i,this);
        oxyVec.push_back(it);
        ui->verticalLayout_2->addWidget(it, 1);  // 添加到布局中，并设置拉伸因子
    }
    showModel = new DataShow(this);
    ui->tableView->setModel(showModel);
    ic=new initCenter();
    //connect(ic,&initCenter::setSure,this,&AdultFishSystemWidget::setMap);
    this->setWindowTitle("成鱼系统");
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
    if(b&(1<<10))
    ui->wsp->updateDeviceStatus(QString("补水高液位超时"),statusType::error);
}
//更新微滤机 微滤池异常状态
void AdultFishSystemWidget::UpdateMicroFilterHasError(int num)
{
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
}
//微滤机是否使用
void AdultFishSystemWidget::UpdateMicroFilterIsUsing(bool b)
{
    ui->wsp->updateDeviceStatus(b?"运行中":"未运行",statusType::ok);
}
//紫外线
void AdultFishSystemWidget::UpdateUvLampIsUsing(bool b)
{
    ui->ul->updateDeviceStatus(b?"运行中":"未运行",statusType::ok);
}

void AdultFishSystemWidget::UpdateUvLampHasError(bool b)
{
    if(b)ui->ul->updateDeviceStatus("故障",statusType::error);
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

void AdultFishSystemWidget::setMap()
{
    const map<QString, std::pair<DeviceType, int> >& s =  ic->getUserSet();
    for(const auto &it : s){
        //设备数量
        int deviceNum = it.second.second;
        //设备类型
        DeviceType t = it.second.first;

        switch(t){
        case DeviceType::wspump:
            WaterSupplyPump *d = new WaterSupplyPump(this);
            ui->deviceLay->addWidget(d,1);
            break;
        case DeviceType::mfilter :
            Microfilter *m = new Microfilter(this);
            ui->deviceLay->addWidget(m,1);
            break;
        case DeviceType::ulamp:
            UpdateUvLampIsUsing(b);
            break;

        }
    }
}
//水泵
void AdultFishSystemWidget::UpdateWaterPumpHasError(int num)
{
    if(num&(1<<0))
    ui->widget_4->updateDeviceStatus("水泵1故障",statusType::error);
    if(num&(1<<1))
    ui->widget_5->updateDeviceStatus("水泵2故障",statusType::error);
}
void AdultFishSystemWidget::UpdateWaterPumpsAreUsing(const QVector<bool> &vec)
{
    ui->widget_4->updateDeviceStatus(vec[0]?"运行中":"未运行",statusType::ok);
    ui->widget_4->updateDeviceStatus(vec[1]?"运行中":"未运行",statusType::ok);
}
//更新补水泵是否使用
void AdultFishSystemWidget::UpdateWaterSupplyPumpIsUsing(bool b)
{
    ui->wsp->updateDeviceStatus(b?QString("运行中"):QString("未运行"),statusType::ok);
}
//更新排污阀状态异常
void AdultFishSystemWidget::updateWasteDeviceStatus(int num,int order)
{
    if(order==0){
        for(int i = 8,j=0;i < 16 ;i+=2,j++){
            if(num&(1<<i)){
                pondVec[j]->updateWasteDeviceStatus(QString("排污阀%1%2").arg(i+1).arg("开不到"),statusType::error);
            }else if(num&(1<<(i+1))){
                pondVec[j]->updateWasteDeviceStatus(QString("排污阀%1%2").arg(i+1).arg("关不到"),statusType::error);
            }
        }
    }else{
        for(int i = 8,j=4;i < 16 ;i+=2,j++){
            if(num&(1<<i)){
                pondVec[j]->updateWasteDeviceStatus(QString("排污阀%1%2").arg(i+1).arg("开不到"),statusType::error);
            }else if(num&(1<<(i+1))){
                pondVec[j]->updateWasteDeviceStatus(QString("排污阀%1%2").arg(i+1).arg("关不到"),statusType::error);
            }
        }
    }
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

