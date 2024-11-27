#ifndef SHOWUSERSET_H
#define SHOWUSERSET_H

#include <QWidget>
#include <QMouseEvent>
#include "AdultFishSystem/adultfishsystemwidget.h"
namespace Ui {
class showUserSet;
}

class showUserSet : public QWidget
{
    Q_OBJECT

public:
    explicit showUserSet(QString name , QString time ,QWidget *parent = nullptr);
    ~showUserSet();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event)override;
private:
    Ui::showUserSet *ui;
    QString n;
};

#endif // SHOWUSERSET_H
