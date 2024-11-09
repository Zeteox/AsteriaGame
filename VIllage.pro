QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    building.cpp \
    healingpotion.cpp \
    hero.cpp \
    hostel.cpp \
    inventory.cpp \
    livingcreature.cpp \
    mage.cpp \
    main.cpp \
    mainwindow.cpp \
    merchant.cpp \
    mine.cpp \
    monster.cpp \
    paladin.cpp \
    potion.cpp \
    randomNumber.cpp \
    resistancepotion.cpp \
    shield.cpp \
    staff.cpp \
    strengthpotion.cpp \
    sword.cpp \
    warrior.cpp \
    village.cpp \
    weapon.cpp

HEADERS += \
    building.h \
    healingpotion.h \
    hero.h \
    hostel.h \
    inventory.h \
    livingcreature.h \
    mage.h \
    mainwindow.h \
    merchant.h \
    mine.h \
    monster.h \
    paladin.h \
    potion.h \
    randomNumber.h \
    resistancepotion.h \
    shield.h \
    staff.h \
    strengthpotion.h \
    sword.h \
    warrior.h \
    village.h \
    weapon.h
    hero.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
