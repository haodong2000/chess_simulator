#ifndef PYTHONMUDULE_H
#define PYTHONMUDULE_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>

#include "Chess.h"
#include "global.h"

#include <QTcpSocket>
#include <QTcpServer>

#include <Params.h>
#include "singleton.h"

/*****************************************************************
*   File:     PythonMudule.h
*   Author:   Haodong LI
*   Usage:    connect with pycharm to generator real world chessStep
*   Time:     2021-06-17 -> 22:16:25
*****************************************************************/

class PythonMudule: public QThread
{
    Q_OBJECT
public:
    PythonMudule(QString N = "default_name");
    void run() override;
    void vision_step();
    void test() {qDebug() << "test";}
    void step_msg_check(QString recv);

private slots:
    void client_read_data();
    void client_disconnect();

private:
    QString name;
    chessStep step;
    QString step_str;
    bool isValid;
    QTcpSocket* client = new QTcpSocket();
    int count;
};

typedef NormalSingleton< PythonMudule > PythonMuduleIn;

#endif // PYTHONMUDULE_H
