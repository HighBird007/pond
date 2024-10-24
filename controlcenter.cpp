#include "controlcenter.h"

controlCenter &controlCenter::getInstance()
{
    static controlCenter center;
    return center;
}

void controlCenter::addFishSystem(QString str, FishSystem *point)
{
    umap[str]=point;
    qDebug()<<str;
}

void controlCenter::centerStart()
{
    socket=new QTcpSocket();
    socket->connectToHost("192.168.2.253",1030);
    connect(socket,&QTcpSocket::readyRead,this,&controlCenter::receiveJson);
}

controlCenter::controlCenter() {
}

void controlCenter::receiveJson()
{
    QJsonDocument doc = QJsonDocument::fromJson(socket->readAll());
    qDebug()<<doc;
    QJsonObject o =doc.object();
    qDebug()<<o["id"].toString()<<o["k1"].toInt();
    umap[o["id"].toString()]->updateDevicesStatus(o["k1"].toInt(),0);
}
