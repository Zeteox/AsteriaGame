QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    building.cpp \
    hero.cpp \
    hostel.cpp \
    livingcreature.cpp \
    main.cpp \
    mainwindow.cpp \
    potion.cpp \
    shield.cpp \
    staff.cpp \
    sword.cpp \
    weapon.cpp

HEADERS += \
    building.h \
    hostel.h \
    livingcreature.h \
    mainwindow.h \
    potion.h \
    shield.h \
    staff.h \
    sword.h \
    weapon.h
    hero.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
