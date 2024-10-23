#include "widget.h"
#include "ui_widget.h"
#include "AdultFishSystem/adultfishsystemwidget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->goToAdultFishSystem,&QPushButton::clicked,this,&Widget::goAdultFishSystem);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::goAdultFishSystem()
{
    auto i =  new AdultFishSystemWidget();
    QVector<QString> pumpErrors{
        "水泵1故障", "水泵2故障",
        "氧锥泵1故障", "氧锥泵2故障", "氧锥泵3故障", "氧锥泵4故障", "排污泵故障"      ,  "排污阀1开不到位", "排污阀1关不到位", "排污阀2开不到位", "排污阀2关不到位",
        "排污阀3开不到位", "排污阀3关不到位", "排污阀4开不到位", "排污阀4关不到位"
    };
    QVector<QString> valveErrors{

        "排污阀5开不到位", "排污阀5关不到位", "排污阀6开不到位", "排污阀6关不到位",
        "排污阀7开不到位", "排污阀7关不到位", "排污阀8开不到位", "排污阀8关不到位",
        "补水高液位超时", "微滤池高液位超时", "微滤机电源跳闸", "紫外杀菌灯跳闸",
        "溶氧超限报警", "微滤池低液位长时间不消失报警"
    };
    i->initErrorVec(std::move(pumpErrors));
    i->initErrorVec(std::move(valveErrors));
    i->show();
}
