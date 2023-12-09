TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        ostossovellus.cpp \
        tiedostohallinta.cpp

HEADERS += \
    ostossovellus.h \
    tiedostohallinta.h

DISTFILES += \
    ostoslista.txt
