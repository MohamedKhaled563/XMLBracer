QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkConsistency.cpp \
    compressing.cpp \
    dataFormatsExtraction.cpp \
    fileManipulation.cpp \
    helperFunctions.cpp \
    main.cpp \
    mainwindow.cpp \
    minify.cpp \
    openFile.cpp \
    prettify.cpp \
    reset.cpp \
    save.cpp \
    solveErrors.cpp \
    xmlToJson.cpp

HEADERS += \
    HelperFunctions.h \
    dataFormatsExtraction.h \
    fileManipulation.h \
    headerfiles.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
