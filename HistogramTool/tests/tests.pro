#[...]

TEMPLATE = app

SOURCES += \
    test_histogram.cpp \
    test_histogram_tool.cpp \
    test_main.cpp

HEADERS += \
    test_histogram.h \
    test_histogram_tool.h

INCLUDEPATH += ../src/
DEPENDPATH += $${INCLUDEPATH} # force rebuild if the headers change

CONFIG += console
CONFIG -= app_bundle
CONFIG += qtestlib

TARGET = TestHistogramTool

# link against project lib
HISTO_LIB = ../src/libHistogramTool.a
LIBS += $${HISTO_LIB}
PRE_TARGETDEPS += $${HISTO_LIB}
