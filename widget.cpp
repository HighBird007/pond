#include "widget.h"
#include "ui_widget.h"
#include "AdultFishSystem/adultfishsystemwidget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->goToAdultFishSystem,&QPushButton::clicked,this,&Widget::goAdultFishSystem);

    initFileShow();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::initFileShow()
{
    QDir dir("./userJson/pondJson");
    dir.setSorting(QDir::Time);

    QVBoxLayout * v = new QVBoxLayout();
    v->setAlignment(Qt::AlignTop);
    ui->scrollAreaWidgetContents->setLayout(v);

    QList<QFileInfo> files = dir.entryInfoList(QDir::Files);  // 获取文件列表，不包括子目录

    for (const auto &file : files) {
        showUserSet *s = new showUserSet(file.baseName(),file.fileTime(QFile::FileBirthTime).toString("dd.MM.yyyy"));
        v->addWidget(s,1);
    }

}

void Widget::goAdultFishSystem()
{

}

void Widget::on_goToAdultFishSystem_2_clicked()
{
    auto i =  new AdultFishSystemWidget();
    i->show();
    controlCenter::getInstance().addFishSystem("e46338809b281d30",i);
    controlCenter::getInstance().centerStart();
}

