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

#include <PythonMudule.h>

QObject* object;
static const int CHESS_PLAY_MODE = 5; // one level, two level, three level, four level of stimulation
                                      // and 5 for CIMC show
static const bool TEST_MODE = false;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml_files/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QList<QObject*> objList = engine.rootObjects();
    std::cout << "objList.length() = " << objList.length() << std::endl; // 1: only main.qml
    PythonMudule *python_vision = new PythonMudule("vision");
    python_vision->start(); // python_vision->start(QThread::HighPriority);

    QObject *objectTemp(0); // initialization
    if(!objList.empty()) objectTemp = *objList.begin();
    else qDebug() << "object list is empty!";
    object = objectTemp->findChild<QObject*>("field_root");
    if(object) std::cout << "field_root loaded successfully!" << std::endl;
    else qDebug() << "field_root loading failed!";
    GlobalEnvirIn::Instance()->__refreshBoard();

    if(TEST_MODE) {
        TestChessMoveIn::Instance()->testMultiProcess();
    }
    else {
        switch (CHESS_PLAY_MODE) {
        case 1:
            singleGameIn::Instance()->oneLevelChessing_HumanVSAI(PARAM::NINE_NINE_NINE);
            break;
        case 2:
            singleGameIn::Instance()->twoLevelChessing_HumanVSAI(PARAM::NINE_NINE_NINE);
            break;
        case 3:
            singleGameIn::Instance()->threeLevelChessing_HumanVSAI(PARAM::NINE_NINE_NINE); // bug
            break;
        case 4:
            singleGameIn::Instance()->normalPlay_HumanVSAI(PARAM::NINE_NINE_NINE);
            break;
        case 5:
            singleGameIn::Instance()->normalPlay_HumanVSAI_CIMC(PARAM::NINE_NINE_NINE);
            break;
        default:
            qDebug() << "main.cpp line:67 CHESS_PLAY_MODE inValid!!!";
            break;
        }
    }

    return app.exec();
}

/* * * * * * * * * * * * * * * * * * * * *
*   File:     main.cpp
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-06-05
* * * * * * * * * * * * * * * * * * * * * */

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
*
*/
