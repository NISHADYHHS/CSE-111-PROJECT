QT += core gui sql
QT += opengl
QT += openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = opengl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ability.cpp \
    attackanimation.cpp \
    attackanimatione.cpp \
    battle.cpp \
    battlewidget.cpp \
    battlewindow.cpp \
    createteam.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    miwidget.cpp \
    move.cpp \
    physicalanimation.cpp \
    pokemon.cpp \
    pokemonscreen.cpp \
    team.cpp \
    typebackground.cpp \
    viewpokemonwindow.cpp

HEADERS += \
    Ability.h \
    Battle.h \
    Move.h \
    Pokemon.h \
    Team.h \
    attackanimation.h \
    attackanimatione.h \
    battlewidget.h \
    battlewindow.h \
    createteam.h \
    item.h \
    mainwindow.h \
    miwidget.h \
    physicalanimation.h \
    pokemonscreen.h \
    typebackground.h \
    viewpokemonwindow.h

FORMS += \
    battlewindow.ui \
    createteam.ui \
    mainwindow.ui \
    pokemonscreen.ui \
    viewpokemonwindow.ui

LIBS += -lopengl32
DISTFILES +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
