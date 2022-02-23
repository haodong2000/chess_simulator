#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QDeclarativeEngine>
//#include <QDeclarativeView>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQmlProperty>
#include <QQuickView>
#include <QWidget>
#include <QList>
#include <QDebug>
#include <iostream>
#include <QTimer>

#include "coordinate.h"
#include "SGeoPoint.h"
#include "Qml_Connection.h"
#include "global.h"
#include "Test/TestChessMove.h"

#include "Step.h"
#include "singleGame.h"
#include "Navigation.h"

#include "vision_thread.h"
#include "rl_thread.h"
#include "StartGui.h"
#include <QtQuick>

#include <QFontDatabase>
#include <QFont>
#include <QMessageBox>
#include <QtGui>
//#include <QtSingleApplication>

QObject* object;
vision_thread *vision  = NULL;          // USB Camera
rl_thread *rl_brain    = NULL;          // RL AI in python
int ** Main_chessBoard = NULL;          // Chess Board
bool __curTurn;                         // true for red and false for black
bool CURRENT_TURN      = true;          // true means red finishes his turn
int TURN_COUNT         = 0;             // the number of turns
int CHESS_PLAY_MODE = Menu::Mode::Human_AI_EndGame;
int BACKGROUND_MODE = Menu::Background::ChristmasTree;
int STRATEGY_MODE = Menu::Manual::MeiHuaPu;
static const bool SHOW_INFOMATION = true;
int BASIC_DEPTH = PARAM::START_DEPTH;
int BEST_EXPONENT = BASIC_DEPTH * 2;
int MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
int SEARCH_DEPTH = PARAM::START_DEPTH;  // init search depth of alpha-beta purning
static const bool TEST_MODE = false;    // is Test Mode or not
static const bool START_GUI = true;     // show the init ui or not
bool Is_Game_Start = false;             // is user finish set up program or not
bool Is_Game_No_Play = false;           // is user don't execute or not
bool Is_CIMC_EndGame = CHESS_PLAY_MODE == Menu::Mode::Human_AI_CIMC_EndGame;
bool startGuiWindow();
bool LetUsPlayChess();

int main(int argc, char *argv[]) {

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    StartGui initGuiSetUp;
    engine.rootContext()->setContextProperty("InitSetUp", &initGuiSetUp);
    const QUrl url(QStringLiteral("qrc:/qml_files/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QList<QObject*> objList = engine.rootObjects();
    std::cout << "objList.length() = " << objList.length() << std::endl; // 1: only main.qml
    vision = new vision_thread;
    vision->name = "vision";
    vision->start();
    // PythonMudule *python_vision = new PythonMudule("vision");
    // python_vision->start(QThread::HighPriority);
    rl_brain = new rl_thread("rl_thread");
    vision->name = "rl_thread";
    rl_brain->start();

    QObject *objectTemp(0); // initialization
    if(!objList.empty()) objectTemp = *objList.begin();
    else qDebug() << "object list is empty!";
    object = objectTemp->findChild<QObject*>("field_root");
    if(object) std::cout << "field_root loaded successfully!" << std::endl;
    else qDebug() << "field_root loading failed!";
    GlobalEnvirIn::Instance()->__refreshBoard();

    if(START_GUI && false == startGuiWindow()) return -1;
    bool exitGame = LetUsPlayChess(); // real play API
    if(exitGame == true) return -1;
    return app.exec();
}

/* * * * * * * * * * * * * * * * * * * * *
*   File:     main.cpp
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-06-05
* * * * * * * * * * * * * * * * * * * * * */

bool startGuiWindow() {
    // object->setProperty(QString("infomationDone").toLatin1(), true);
    if(SHOW_INFOMATION) object->setProperty(QString("infomationDone").toLatin1(), false);
    else object->setProperty(QString("infomationDone").toLatin1(), true);
    while (Is_Game_Start == false && Is_Game_No_Play == false) {
        GlobalEnvirIn::Instance()->__delayMsec(5);
        if(Is_Game_Start) {
            std::cout << "Chess Game Executed! Enjoy!" << std::endl;
            object->setProperty(QString("isGameLoading").toLatin1(), true);
            object->setProperty(QString("initEnvironmentDone").toLatin1(), true);
            return true;
        }
        if(Is_Game_No_Play) {
            std::cout << "Chess Game Exit! Welcome Back!" << std::endl;
            return false;
        }
    }
}

bool LetUsPlayChess() {
    SEARCH_DEPTH = BASIC_DEPTH + 1;
    std::cout << "BACKGROUND_MODE = " << BACKGROUND_MODE << std::endl;
    std::cout << "CHESS_PLAY_MODE = " << CHESS_PLAY_MODE << std::endl;
    std::cout << "SEARCH_DEPTH    = " << SEARCH_DEPTH << std::endl;
    std::cout << "BASIC_DEPTH     = " << BASIC_DEPTH << std::endl;
    if(BACKGROUND_MODE == 0) {
        object->setProperty(QString("isBackgroundSet").toLatin1(), false);
    }
    else {
        object->setProperty(QString("isBackgroundSet").toLatin1(), true);
        object->setProperty(QString("background_source").toLatin1(), Menu::BackgroundUrl.at(BACKGROUND_MODE).toLatin1());
    }
    object->setProperty(QString("isGameLoading").toLatin1(), false);
    if(TEST_MODE)
        TestChessMoveIn::Instance()->testMultiProcess();
    else
        switch (CHESS_PLAY_MODE) {
        case 0: singleGameIn::Instance()->normalPlay(PARAM::NINE_NINE_NINE); break;
        case 1: singleGameIn::Instance()->normalPlay_HumanVSAI(PARAM::NINE_NINE_NINE); break;
        case 2: singleGameIn::Instance()->normalPlay_HumanVSHuman(PARAM::NINE_NINE_NINE); break;
        case 3: singleGameIn::Instance()->normalPlay_HumanVSAI_CIMC(PARAM::NINE_NINE_NINE); break;
        case 4: singleGameIn::Instance()->normalPlay_HumanVSAI_CIMC_EndGame(PARAM::NINE_NINE_NINE); break;
        case 5: singleGameIn::Instance()->normalPlay_EndGame(PARAM::NINE_NINE_NINE); break;
        case 6: singleGameIn::Instance()->normalPlay_HumanVSAI_EndGame(PARAM::NINE_NINE_NINE); break;
        case 7: singleGameIn::Instance()->normalPlay_HumanVSHuman_EndGame(PARAM::NINE_NINE_NINE); break;
        default: qDebug() << "main.cpp line:79 CHESS_PLAY_MODE inValid!!! (see Navigation.h)"; break;
        }
    while (Is_Game_No_Play == false) {
        GlobalEnvirIn::Instance()->__delayMsec(5);
        if(Is_Game_No_Play) {
            std::cout << "Chess Game Exit! Welcome Back!" << std::endl;
            break;
        }
    }
    return true;
}

/*
*  1. global vision   ->
*  2. image process   ->
*  3. chess identify  ->
*  4. matrix generate -> game decision algorithm ->
*  5. chess move      ->
*  6. avg robot move  ->
*  7. (next loop)     -> global vision
*
* board info:
*   _redNum
*   _BlackNum
*
* chess info:
*   _isAlive
*   _col
*   _row
*   _canMove
*   _canMovePos
*   _canKill
*   _canKillWho
*/
