#ifndef CHESS_H
#define CHESS_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     Chess.h
*   Author:   Haodong LI
*   Usage:    basic class of chess
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include <QString>
#include "SGeoPoint.h"
#include <QVector>
#include <unordered_map>
#include <QDebug>
#include <iostream>

//#include "singleton.h"

struct chessStep {
    int _chessNum;
    int _chessNumber;
    bool _chessCamp;
    int _deltaX;
    int _deltaY;
    bool _isKill = false;
    int _chessKilledNum = -1;
    int _chessKilledNumber = -1;
    chessStep(int ChessNum, int ChessNumber, bool camp,
              int DeltaX, int DeltaY,
              bool Kill = false, int ChessKilledNum = -1, int ChessKilledNumber = -1):_chessNum(ChessNum),
                                                                    _chessNumber(ChessNumber),
                                                                    _chessCamp(camp),
                                                                    _deltaX(DeltaX),
                                                                    _deltaY(DeltaY),
                                                                    _isKill(Kill),
                                                                    _chessKilledNum(ChessKilledNum),
                                                                    _chessKilledNumber(ChessKilledNumber){};
    void initChessStep(int ChessNum, int ChessNumber, bool camp,
                       int DeltaX, int DeltaY,
                       bool Kill = false, int ChessKilledNum = -1, int ChessKilledNumber = -1) {
        this->_chessNum = ChessNum;
        this->_chessNumber = ChessNumber;
        this->_chessCamp = camp;
        this->_deltaX = DeltaX;
        this->_deltaY = DeltaY;
        this->_isKill = Kill;
        this->_chessKilledNum = ChessKilledNum;
        this->_chessKilledNumber = ChessKilledNumber;
    };
};

//    Step(int ChessNum, int ChessNumber, bool camp,
//         int DeltaX, int DeltaY,
//         bool Kill = false, int ChessKilledNum = -1, int ChessKilledNumber = -1);

class Chess: public SGeoPoint
{
public:
    Chess(int x = 0, int y = 0,
          const QString name = "", // empty name is illegal
          const bool camp = false, // black is default
          const int number = 0, // 0 is an error number, only 1-5 is legal
          bool alive = true);
    virtual bool isAlive();
    virtual void setAlive(bool isAliveNow);
    virtual bool canKill();
    virtual bool canMove();
    virtual bool chessCamp();
    virtual QString chessName(); // "BGeneral"
    virtual int chessNumber();
    virtual void setSpaceValue(double value);
    virtual double getSpaceValue();
    virtual void printStepList();

    QVector<chessStep> chessStepList;
    QVector<chessStep*> SchessStepList;

    // std::unordered_map<QString, SGeoPoint> StepList;
    // std::unordered_map<QString, QString> StepKillList;

    // virtual void refersh();
    // SGeoPoint Pos;

private:
    SGeoPoint Pos; // no use currently
    const bool _redOrBlack; // true -> red  and  false -> black
    const QString _name;
    const int _number; // sequence
    bool _canMove;
    bool _canKill;
    bool _isAlive;
    double _spaceValue;
};

//typedef NormalSingleton< Chess > ChessIn;

#endif // CHESS_H
