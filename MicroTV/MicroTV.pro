#-------------------------------------------------
#
# Project created by QtCreator 2017-06-09T16:56:13
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MicroTV
TEMPLATE = app


QT += multimedia
QT += multimediawidgets
QT += widgets
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        homewindow.cpp \
    dateandtime.cpp \
    rollcaption.cpp \
    account.cpp \
    management.cpp \
    user.cpp \
    administrator.cpp \
    film.cpp \
    tv_view.cpp \
    videoplayer.cpp \
    videowidget.cpp \
    videowidgetsurface.cpp \
    mysql.cpp \
    register.cpp \
    tipwin.cpp

HEADERS  += homewindow.h \
    dateandtime.h \
    rollcaption.h \
    account.h \
    management.h \
    user.h \
    administrator.h \
    film.h \
    tv_view.h \
    videoplayer.h \
    videowidget.h \
    videowidgetsurface.h \
    mysql.h \
    register.h \
    tipwin.h

FORMS    += homewindow.ui \
    tv_view.ui \
    register.ui \
    tipwin.ui

RESOURCES += \
    backgroundpic.qrc \
    bg_re.qrc



target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/customvideosurface/customvideowidget
INSTALLS += target

DISTFILES +=

RC_FILE   +=myico.rc
