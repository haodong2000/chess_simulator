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

class Chess: public SGeoPoint
{
public:
    Chess(int x = 0, int y = 0,
          QString name = "", // empty name is illegal
          bool camp = false, // black is default
          int number = 0, // 0 is an error number, only 1-5 is legal
          bool alive = true);
    bool isAlive();
    // SGeoPoint Pos;

private:
    bool _redOrBlack; // true -> red  and  false -> black
    QString _name;
    int _number; // sequence
    bool _canMove;
    bool _canKill;
    bool _isAlive;
};

#endif // CHESS_H
