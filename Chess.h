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
    Chess(int x = 0, int y = 0, QString name = "", bool camp = false, int number = 0);
    // SGeoPoint Pos;

private:
    bool _redOrBlack; // true -> red  and  false -> black
    QString _name;
    int _number;
    bool _canMove;
    bool _canKill;

};

#endif // CHESS_H
