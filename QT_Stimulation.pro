QT += quick \
      widgets \
      core

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
    Qml_Connection.cpp \
    Step.cpp \
    Test/TestChessMove.cpp \
    allBRChessesInclude.cpp \
    all_chesses/Advisor.cpp \
    all_chesses/Cannon.cpp \
    all_chesses/Chariot.cpp \
    all_chesses/Elephant.cpp \
    all_chesses/General.cpp \
    all_chesses/Horse.cpp \
    all_chesses/Soldier.cpp \
    all_chesses/black_chesses/black_advisor.cpp \
    all_chesses/black_chesses/black_cannon.cpp \
    all_chesses/black_chesses/black_chariot.cpp \
    all_chesses/black_chesses/black_elephant.cpp \
    all_chesses/black_chesses/black_general.cpp \
    all_chesses/black_chesses/black_horse.cpp \
    all_chesses/black_chesses/black_soldier.cpp \
    all_chesses/red_chesses/red_advisor.cpp \
    all_chesses/red_chesses/red_cannon.cpp \
    all_chesses/red_chesses/red_chariot.cpp \
    all_chesses/red_chesses/red_elephant.cpp \
    all_chesses/red_chesses/red_general.cpp \
    all_chesses/red_chesses/red_horse.cpp \
    all_chesses/red_chesses/red_soldier.cpp \
    definitionChessSet.cpp \
    global.cpp \
    globalChesses.cpp \
        main.cpp \
    SGeoPoint.cpp \
    coordinate.cpp \
    singleGame.cpp \
    singleton.cpp  \

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
    Qml_Connection.h \
    SGeoPoint.h \
    Step.h \
    Test/TestChessMove.h \
    allBRChessesInclude.h \
    all_chesses/Advisor.h \
    all_chesses/Cannon.h \
    all_chesses/Chariot.h \
    all_chesses/Elephant.h \
    all_chesses/General.h \
    all_chesses/Horse.h \
    all_chesses/Soldier.h \
    all_chesses/black_chesses/black_advisor.h \
    all_chesses/black_chesses/black_cannon.h \
    all_chesses/black_chesses/black_chariot.h \
    all_chesses/black_chesses/black_elephant.h \
    all_chesses/black_chesses/black_general.h \
    all_chesses/black_chesses/black_horse.h \
    all_chesses/black_chesses/black_soldier.h \
    all_chesses/red_chesses/red_advisor.h \
    all_chesses/red_chesses/red_cannon.h \
    all_chesses/red_chesses/red_chariot.h \
    all_chesses/red_chesses/red_elephant.h \
    all_chesses/red_chesses/red_general.h \
    all_chesses/red_chesses/red_horse.h \
    all_chesses/red_chesses/red_soldier.h \
    coordinate.h \
    definitionChessSet.h \
    global.h \
    globalChesses.h \
    singleGame.h \
    singleton.h \

INCLUDEPATH += \
    all_chesses/
    Test/
