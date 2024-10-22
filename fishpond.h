#ifndef FISHPOND_H
#define FISHPOND_H

#include <QWidget>

namespace Ui {
class fishpond;
}

class fishpond : public QWidget
{
    Q_OBJECT

public:
    explicit fishpond(QWidget *parent = nullptr);
    explicit fishpond(QString,QWidget *parent = nullptr);
    ~fishpond();

private:
    Ui::fishpond *ui;
    QString pondId="unknown";
};

#endif // FISHPOND_H
