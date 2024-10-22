#include "fishpond.h"
#include "ui_fishpond.h"

fishpond::fishpond(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fishpond)
{
    ui->setupUi(this);
    ui->label->setText(pondId);
}
fishpond::fishpond(QString flag,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fishpond),pondId(flag)
{
    ui->setupUi(this);
    ui->label->setText(pondId);
}
fishpond::~fishpond()
{
    delete ui;
}
