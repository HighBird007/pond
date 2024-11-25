#include "initcenterlabel.h"
#include "ui_initcenterlabel.h"

initCenterLabel::initCenterLabel(int x,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::initCenterLabel),index(x)
{
    ui->setupUi(this);
    initCombox();
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&initCenterLabel::deviceUse);
    QAction *a=new QAction("删除",this);
    menu.addAction(a);
    connect(a,&QAction::triggered,this,[=](){
        emit suicide(index);
        this->deleteLater();
    });
    connect(ui->lineEdit,&QLineEdit::editingFinished,this,[this](){
        jname=ui->lineEdit->text();
    });
    connect(ui->spinBox,&QSpinBox::valueChanged,this,[=](int n){
        setNum(n);
    });
}

initCenterLabel::~initCenterLabel()
{
    delete ui;
}

DeviceType initCenterLabel::getDeviceType()
{
    return type;
}

int initCenterLabel::getIndex()
{
    return index;
}

void initCenterLabel::initCombox()
{
    ui->comboBox->addItem("补水泵",DeviceType::wspump);
    ui->comboBox->addItem("水泵",DeviceType::wpump);
    ui->comboBox->addItem("氧锥泵",DeviceType::opump);
    ui->comboBox->addItem("微滤机",DeviceType::mfilter);
    ui->comboBox->addItem("紫外灯",DeviceType::ulamp);
    ui->comboBox->addItem("排污阀",DeviceType::wdvalve);
}

QString initCenterLabel::getJsonName()
{
    return jname;
}

void initCenterLabel::deviceUse(int index)
{
    Q_UNUSED(index);
    type = static_cast<DeviceType>(ui->comboBox->currentData().toInt());
}

void initCenterLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton){
        QPoint p = this->mapToGlobal(e->pos());
        menu.exec(p);
    }
}

int initCenterLabel::getNum() const
{
    return num;
}

void initCenterLabel::setNum(int newNum)
{
    num = newNum;
}
