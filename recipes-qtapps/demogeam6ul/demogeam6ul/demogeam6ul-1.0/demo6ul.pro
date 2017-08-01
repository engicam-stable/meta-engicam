TEMPLATE = app


QT +=  qml declarative
CONFIG += c++11
CONFIG+=declarative_debug

SOURCES += main.cpp \
    qmlapplicationviewer.cpp \
    cprfilerclass.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    qmlapplicationviewer.h \
    cprfilerclass.h

DISTFILES +=


