QT       += core gui sql
QT += widgets multimedia

QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agences.cpp \
    avion.cpp \
    carte.cpp \
    client.cpp \
    compagnie.cpp \
    connexion.cpp \
    equipement.cpp \
    main.cpp \
    mainwindow.cpp \
    offre.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    reservation.cpp \
    service.cpp

HEADERS += \
    agences.h \
    avion.h \
    carte.h \
    client.h \
    compagnie.h \
    connexion.h \
    equipement.h \
    mainwindow.h \
    offre.h \
    personnel.h \
    qcustomplot.h \
    reservation.h \
    service.h

FORMS += \
    mainwindow.ui
    RC_SONS = myappico.ico
    QMAKE_CXXFLAGS+= -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \

    ressources.qrc
