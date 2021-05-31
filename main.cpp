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

#include "coordinate.h"
#include "SGeoPoint.h"
#include "Qml_Connection.h"
#include "global.h"

QObject* object;

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

//    QObject *object(0); // initialization
//    if(!objList.empty()) object = *objList.begin();
//    else qDebug() << "object list is empty!";
//    QObject *field = object->findChild<QObject*>("field_root");

    QObject *objectTemp(0); // initialization
    if(!objList.empty()) objectTemp = *objList.begin();
    else qDebug() << "object list is empty!";
    object = objectTemp->findChild<QObject*>("field_root");
//    SGeoPoint* ppppp = new SGeoPoint(5, 0); // test interface
//    QmlConnectIn::Instance()->changeChessPos("b_cha_", 1, false, ppppp);

//    if (field) { // test connection
//        field->setProperty("chessSize", (1080*2.0/15.0) * 0.45);
//        SGeoPoint* b_gen_pos = new SGeoPoint(1, 4);
//        field->setProperty("b_gen_posX", coordinateIn::Instance()->tranRealPosX(b_gen_pos));
//        field->setProperty("b_gen_posY", coordinateIn::Instance()->tranRealPosY(b_gen_pos));
//        field->setProperty("b_hor_2_posX", coordinateIn::Instance()->tranRealPosX(2));
//        field->setProperty("b_hor_2_posY", coordinateIn::Instance()->tranRealPosY(6));
//        field->setProperty("r_adv_2_posX", coordinateIn::Instance()->tranRealPosX(8));
//        field->setProperty("r_adv_2_posY", coordinateIn::Instance()->tranRealPosY(4));
//        field->setProperty("r_sol_2_posX", coordinateIn::Instance()->tranRealPosX(5));
//        field->setProperty("r_sol_2_posY", coordinateIn::Instance()->tranRealPosY(2));
//    }
//    else qDebug() << "field_root load error!";


    // Using QDeclarativeComponent // NO
//    QQmlEngine engine;
//    QQmlComponent component(&engine,
//                            QUrl::fromLocalFile("qml_files/main.qml"));
//    QObject *object = component.create();
//    ...
//    delete object;

    // Using QDeclarativeView // YES, and that what we use
//    QQuickView view;
//    view.setSource(QUrl::fromLocalFile("../QT_Stimulation/qml_files/main.qml"));
//    view.show();
//    QObject *object = view.rootObject();

    return app.exec();
}

/*

  SRTP & SIEMENS

  date: 2021年5月29日

  author: LI Haodong

   1. global vision   ->
   2. image process   ->
   3. chess identify  ->
   4. matrix generate -> game decision algorithm ->
   5. chess move      ->
   6. avg robot move  ->
   7. (next loop)     -> global vision

  board info:
    _redNum
    _BlackNum

  chess info:
    _isAlive
    _col
    _row
    _canMove
    _canMovePos
    _canKill
    _canKillWho

*/
