#[...]

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += ../src/
DEPENDPATH += $${INCLUDEPATH} # force rebuild if the headers change

CONFIG += console
CONFIG -= app_bundle

TARGET = HistogramTool

# link against project lib
HISTO_LIB = ../src/libHistogramTool.a
LIBS += $${HISTO_LIB}
PRE_TARGETDEPS += $${HISTO_LIB}
