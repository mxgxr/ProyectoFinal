QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    enemigo.cpp \
    flecha.cpp \
    fuego.cpp \
    llave.cpp \
    main.cpp \
    mainwindow.cpp \
    pared.cpp \
    personajes.cpp \
    puerta.cpp \
    resorte.cpp \
    usuarios.cpp

HEADERS += \
    dialog.h \
    enemigo.h \
    flecha.h \
    fuego.h \
    llave.h \
    mainwindow.h \
    pared.h \
    personajes.h \
    puerta.h \
    resorte.h \
    usuarios.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc \
    personajes.qrc

    Imagenes.qrc

    personajes.qrc

DISTFILES += \
    level1.txt \
    level2.txt \
    level3.txt

