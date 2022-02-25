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
#include "chessstep.h"

#include <QTime>

/*****************************************************************
*   File:     rl_thread.h
*   Author:   Haodong LI
*   Usage:    reinforcement learning engine
*   Time:     2022-02-23 -> 10:28:23
*****************************************************************/

struct tranChessStep {
    int chessNum;
    int pos_x;
    int pos_y;
    int tar_x;
    int tar_y;
    bool kill;
    int kill_num;
    tranChessStep(int _chessNum, int _pos_x, int _pos_y, int _tar_x, int _tar_y, bool _kill = false, int _kill_num = 0) {
        this->chessNum = _chessNum;
        this->pos_x    = _pos_x;
        this->pos_y    = _pos_y;
        this->tar_x    = _tar_x;
        this->tar_y    = _tar_y;
        this->kill     = _kill;
        this->kill_num = _kill_num;
    }
};

class rl_thread: public QThread
{
public:
    rl_thread(QString name);
    rl_thread();
    void run();
    virtual void __delayMsec(int Msec);
    virtual void __displayCurrentChessBoard();
    virtual QString generateRequest(int count);
    virtual void generateStep(QString msg);
    virtual bool retuanIsTranStepReady();
    virtual void setIsTranStepReady(bool curIsTranStepReady);
public:
    QString name;
    int **currentChessBoard;
    chessStep chessStep_RL;
    tranChessStep tranChessStep_RL;
public:
    int MP_count;
    bool MP_received;
    int RL_sent;
    int last_TURN_COUNT;
    bool isTranStepReady;
private:
    QTcpSocket* client = new QTcpSocket();
};

typedef NormalSingleton< rl_thread > RL_In;

#endif // RL_THREAD_H
