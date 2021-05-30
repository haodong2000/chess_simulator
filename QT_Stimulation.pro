QT += quick \
      widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Chess.cpp \
    Params.cpp \
    all_chesses/Advisor.cpp \
    all_chesses/Cannon.cpp \
    all_chesses/Chariot.cpp \
    all_chesses/Elephant.cpp \
    all_chesses/General.cpp \
    all_chesses/Horse.cpp \
    all_chesses/Soldier.cpp \
    all_chesses/black_chesses/black_general.cpp \
    global.cpp \
        main.cpp \
    SGeoPoint.cpp \
    coordinate.cpp \

RESOURCES += \
    ChessRobot.qrc
    chess/
    logo/

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += \
    qml_files/
    chess/ # important! ot the images will not displayed!
    logo/

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Chess.h \
    Params.h \
    SGeoPoint.h \
    all_chesses/Advisor.h \
    all_chesses/Cannon.h \
    all_chesses/Chariot.h \
    all_chesses/Elephant.h \
    all_chesses/General.h \
    all_chesses/Horse.h \
    all_chesses/Soldier.h \
    all_chesses/black_chesses/black_general.h \
    coordinate.h \
    global.h \
