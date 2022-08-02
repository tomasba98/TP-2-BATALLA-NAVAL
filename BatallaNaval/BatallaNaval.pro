TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        barco.cpp \
        crucero.cpp \
        destructor.cpp \
        lancha.cpp \
        main.cpp \
        mapa.cpp \
        matriz.cpp \
        menu.cpp \
        portaaviones.cpp \
        submarino.cpp

HEADERS += \
    VectorDinamico.h \
    barco.h \
    crucero.h \
    destructor.h \
    lancha.h \
    mapa.h \
    matriz.h \
    menu.h \
    portaaviones.h \
    submarino.h
