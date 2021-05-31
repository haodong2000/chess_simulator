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

#include "Qml_Connection.h"

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
    std::cout << objList.length() << std::endl;
    QObject *object(0); // initialization
    if(!objList.empty()) object = *objList.begin();
    QObject *field = object->findChild<QObject*>("field_root");
    // object->setProperty("width", 999999);
    if (field) field->setProperty("chessSize", 25);
    else qDebug() << "field_root load error!";


    // Using QDeclarativeComponent // NO
//    QQmlEngine engine;
//    QQmlComponent component(&engine,
//                            QUrl::fromLocalFile("qml_files/main.qml"));
//    QObject *object = component.create();
//    ...
//    delete object;

    // Using QDeclarativeView // YES
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
