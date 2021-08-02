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
    virtual void __printLastVisionBoard();
    void setReceived(bool recv);
    int __generateHumanStep(const QVector<chessStep> &curStepList);
    void analysis_human_setp();
    void reset_human_step();
    void refershLastVisionBoard();
    bool getIsVisionBoardAtLeastOnce();
    void setIsVisionBoardAtLeastOnce(bool curIsVisionBoardAtLeastOnce);

private slots:
    void client_read_data();
    void client_disconnect();

private:
    QString name;
    chessStep step;
    QString step_str;
    bool isValid;
    QTcpSocket* client = new QTcpSocket();

public:
    int MP_count;
    bool MP_received;
    bool isVisionBoardAtLeastOnce;

public:
    int ** __visionBoard;
    int ** __lastVisionBoard;
//    bool __isStepGenerated;
//    chessStep __humanStep;
    bool isBoardChanged = false;
    QPair<QPair<int, int>, QPair<int, int>> step_first;
    bool flagFirst = false;
    bool flagSecond = false;
    bool flagThird = false;
    bool isSimpleMoveOrKill = false; // true -> move and false -> kill
    QPair<QPair<int, int>, QPair<int, int>> step_second;
    QPair<QPair<int, int>, QPair<int, int>> step_third;
};

typedef NormalSingleton< PythonMudule > PythonMuduleIn;

#endif // PYTHONMUDULE_H
