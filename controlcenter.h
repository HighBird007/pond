#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <AdultFishSystem/fishsystem.h>
class controlCenter:public QObject
{
    Q_OBJECT
public:
   static controlCenter &getInstance();
    void addFishSystem(QString,FishSystem*);
   void centerStart();
private:
    controlCenter();
    void receiveJson();
private:
    QTcpSocket* socket;
    std::unordered_map<QString,FishSystem*> umap;
};

#endif // CONTROLCENTER_H
