#ifndef RL_THREAD_H
#define RL_THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <QDebug>
#include <iostream>
#include <QVector>

#include "Params.h"
#include "global.h"
#include "chessstep.h"
#include "singleton.h"

#include <QTime>

/*****************************************************************
*   File:     rl_thread.h
*   Author:   Haodong LI
*   Usage:    reinforcement learning engine
*   Time:     2022-02-23 -> 10:28:23
*****************************************************************/

class rl_thread: public QThread
{
public:
    rl_thread(QString name);
    rl_thread();
    void run();
    virtual void __delayMsec(int Msec);
    virtual void __displayCurrentChessBoard();
    virtual QString generateRequest(int count);
public:
    QString name;
    int **currentChessBoard;
public:
    int MP_count;
    bool MP_received;
    int RL_sent;
    int last_TURN_COUNT;
private:
    QTcpSocket* client = new QTcpSocket();
};

typedef NormalSingleton< rl_thread > RL_In;

#endif // RL_THREAD_H
