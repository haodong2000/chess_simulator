#ifndef PYTHONMUDULE_H
#define PYTHONMUDULE_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>
#include <iostream>
#include <QVector>

#include "chessstep.h"

#include <QTcpSocket>
#include <QTcpServer>

#include "Params.h"
#include "singleton.h"

#include <QDateTime>
#include <QDate>
#include <QTime>

#include <global.h>

/*****************************************************************
*   File:     PythonMudule.h
*   Author:   Haodong LI
*   Usage:    connect with pycharm to generator real world chessStep
*   Time:     2021-06-17 -> 22:16:25
*****************************************************************/

class PythonMudule: public QObject
{
    Q_OBJECT
public:
    PythonMudule(QString N = "default_name");
    void run_TCP_vision();
    void vision_step();
    void test() {qDebug() << "test";}
    void step_msg_check(QString recv);
    virtual void __delayMsec(int Msec);
    virtual void __QString2Board(QString origin_message);
    virtual int __QStr2intName(QString name);
    virtual void __printVisionBoard();
    void setReceived(bool recv);
    int __generateHumanStep(const QVector<chessStep> &curStepList);

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
    bool received;
    int ** __visionBoard;
    int ** __lastVisionBoard;
//    bool __isStepGenerated;
//    chessStep __humanStep;
};

typedef NormalSingleton< PythonMudule > PythonMuduleIn;

#endif // PYTHONMUDULE_H
