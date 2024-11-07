#include "initcenterlabel.h"
#include "ui_initcenterlabel.h"

initCenterLabel::initCenterLabel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::initCenterLabel)
{
    ui->setupUi(this);
    ui->comboBox->addItem("补水泵",0);
    ui->comboBox->addItem("水泵",1);
    ui->comboBox->addItem("氧锥泵",2);
    ui->comboBox->addItem("池塘",3);
    ui->comboBox->addItem("微滤机",4);
    ui->comboBox->addItem("紫外灯",5);
    ui->comboBox->addItem("鱼池",6);
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&initCenterLabel::deviceUse);
    QAction *a=new QAction("删除",this);
    menu.addAction(a);
    connect(a,&QAction::triggered,this,[=](){
        emit suicide(index);
        this->deleteLater();
    });

}

initCenterLabel::~initCenterLabel()
{
    delete ui;
}

int initCenterLabel::getDeviceType()
{
    return type;
}

int initCenterLabel::getIndex()
{
    return index;
}

void initCenterLabel::setIndex(int i)
{
    index = i;
}

void initCenterLabel::deviceUse(int index)
{
    Q_UNUSED(index);
    qDebug()<<ui->comboBox->currentData();
    type = ui->comboBox->currentData().toInt();
}

void initCenterLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton){
        QPoint p = this->mapToGlobal(e->pos());
        menu.exec(p);
    }
}
