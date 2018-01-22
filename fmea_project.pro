#-------------------------------------------------
#
# Project created by QtCreator 2017-07-21T15:10:53
#
#-------------------------------------------------

QT       += core gui avwidgets
CONFIG -= c++11
QMAKE_CXXFLAGS += -std=c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fmea
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cc \
    ribbon.cc \
    fmea_main.cc \
    fmea_ribbon.cc \
    fema_analysis.cc \
    openvaf.cc \
    video/progress_label.cpp \
    video/video_widget.cc \
    fmea_model.cc \
    fmea_delegate.cc \
    verification/des.cc \
    verification/encryption.cc \
    verification/verification.cpp

HEADERS += \
    ribbon.h \
    fmea_main.h \
    fmea_ribbon.h \
    fema_analysis.h \
    json.hpp \
    openvaf.h \
    utils.hpp \
    video/progress_label.h \
    video/video_player.hpp \
    video/video_widget.h \
    fmea_model.h \
    fmea_delegate.h \
    verification/des.h \
    verification/encryption.h \
    verification/verification.h

FORMS += \
    fmea_main.ui \
    fema_analysis.ui \
    video/video_widget.ui

LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_regex
LIBS += -lboost_thread
LIBS += -lboost_locale
LIBS += -liconv
LIBS += -lwininet
LIBS += -lws2_32
