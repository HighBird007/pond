#include "showuserset.h"
#include "ui_showuserset.h"

showUserSet::showUserSet(QString name , QString time ,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::showUserSet),n(name)
{
    ui->setupUi(this);

    ui->label->setText(name);

    ui->label_2->setText(time);
    this->setStyleSheet(
        "QWidget {"
        "    background-color: #f0f0f0;"  // 背景颜色
        "    border: 1px solid #cccccc;"  // 边框颜色和宽度
        "    border-radius: 5px;"         // 圆角
        "    padding: 10px;"               // 内边距
        "}"
        "QLabel {"
        "    font-size: 14px;"
        "    color: #333333;"
        "}"
        );

}

showUserSet::~showUserSet()
{
    delete ui;
}

void showUserSet::mouseDoubleClickEvent(QMouseEvent *event)
{
    auto i =  new AdultFishSystemWidget(n);
    i->show();
    event->accept();
}
