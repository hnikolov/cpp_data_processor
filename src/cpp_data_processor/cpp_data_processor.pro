QT += core
QT -= gui

CONFIG += c++11

TARGET = cpp_data_processor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../main.cpp \
    ../tdata_1.cpp \
    ../tdataprocessor_1.cpp \
    ../tdpimplementation_1.cpp \
    ../tlogger_1.cpp \
    ../tprocessor_1.cpp \
    ../tdata_map.cpp \
    ../test/ttestsuite.cpp \
    ../test_cases/test_tdata_1.cpp \
    ../test_cases/test_func1.cpp \
    ../test_cases/test_func2.cpp \
    ../test_cases/testsuite_mytests.cpp \
    ../test/btest.cpp \
    ../test/test_example.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ../tdata_1.h \
    ../tdataprocessor_1.h \
    ../tdpimplementation_1.h \
    ../tlogger_1.h \
    ../tprocessor_1.h \
    ../tdata_map.h \
    ../test/ttestsuite.h \
    ../test_cases/testsuite_mytests.h \
    ../idata.h \
    ../iprocessor.h \
    ../ilogger.h \
    ../idataprocessor.h \
    ../test/btest.h \
    ../test/cu_macros.h \
    ../test/test_example.h
