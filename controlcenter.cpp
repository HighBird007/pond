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
   // QJsonDocument doc = QJsonDocument::fromJson(socket->readAll());
    QByteArray data=socket->readAll();
   data.replace("\\", "");
    QJsonDocument doc = QJsonDocument::fromJson(data);
    qDebug()<<data;
    if (!doc.isNull()) {
        qDebug() << doc;
    } else {
        qDebug() << "JSON解析失败";
    }
    qDebug()<<"--------";
   QJsonObject o =doc.object();
   QJsonArray arr= o["AdDeviceStatus"].toArray();
   umap[o["id"].toString()]->updateDevicesStatus(arr[0].toInt(),0);
    umap[o["id"].toString()]->updateDevicesStatus(arr[1].toInt(),1);
}
