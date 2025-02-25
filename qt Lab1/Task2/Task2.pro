QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    circle.cpp \
    figure.cpp \
    hexagon.cpp \
    main.cpp \
    mainscene.cpp \
    mainwindow.cpp \
    myfigure.cpp \
    point.cpp \
    rectangle.cpp \
    rhombus.cpp \
    square.cpp \
    star.cpp \
    tools.cpp \
    triangle.cpp

HEADERS += \
    canvas.h \
    circle.h \
    figure.h \
    hexagon.h \
    mainscene.h \
    mainwindow.h \
    myfigure.h \
    point.h \
    rectangle.h \
    rhombus.h \
    square.h \
    star.h \
    tools.h \
    triangle.h

FORMS += \
    canvas.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
