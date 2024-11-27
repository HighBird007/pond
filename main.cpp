#include "widget.h"
#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir dir;
    dir.mkdir("./userJson");
    dir.mkdir("./userJson/pondJson");

    Widget w;
    w.show();
    return a.exec();
}
