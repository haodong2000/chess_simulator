#include <QGuiApplication>
#include <QQmlApplicationEngine>

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
