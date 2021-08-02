QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ratemyprof.cpp

HEADERS += \
    ../../../CLionProjects/RateMyProfMenu/BST.h \
    ../../../CLionProjects/RateMyProfMenu/Node.h \
    ../../../CLionProjects/RateMyProfMenu/Professor.h \
    ../../../CLionProjects/RateMyProfMenu/University.h \
    BST.h \
    BST.h \
    HashTable.h \
    Node.h \
    Professor.h \
    University.h \
    ratemyprof.h

FORMS += \
    ratemyprof.ui

TRANSLATIONS += \
    rateMyProfessorFrontEnd_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Project_3_Raw_Data.csv
