#include "device.h"


Device::Device(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Device)
{
    ui->setupUi(this);
}

Device::~Device()
{
    delete ui;
}

