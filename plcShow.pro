QT       += core gui network mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
INCLUDEPATH += $$PWD/AdultFishSystem
include($$PWD/AdultFishSystem/AdultFishSystem.pri)
INCLUDEPATH += $$PWD/Device
include($$PWD/Device/Device.pri)
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controlcenter.cpp \
    datashow.cpp \
    fishpond.cpp \
    initcenter.cpp \
    initcenterlabel.cpp \
    main.cpp \
    showuserset.cpp \
    widget.cpp

HEADERS += \
    controlcenter.h \
    datashow.h \
    fishpond.h \
    initcenter.h \
    initcenterlabel.h \
    showuserset.h \
    widget.h

FORMS += \
    fishpond.ui \
    initcenter.ui \
    initcenterlabel.ui \
    showuserset.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
