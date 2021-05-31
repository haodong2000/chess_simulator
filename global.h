#ifndef GLOBAL_H
#define GLOBAL_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     global.h
*   Author:   Haodong LI
*   Usage:    global include files
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Params.h"
#include "SGeoPoint.h"
#include <QObject>
#include <QVector>
#include <iostream>
#include <string.h>
#include <string>
#include <QString>
#include <QDebug>

#include "singleton.h"
#include "Chess.h"

//#include "allBRChessesInclude.h"

class GlobalEnvironment {
public:
    GlobalEnvironment();
    virtual void __refreshBoard();
    virtual void __printBoard();
    virtual QString __int2QStrName(int name);
    virtual int __QStr2intName(QString name);
    virtual Chess* __QStrOrInt2Chess(int chessNameSimple);
    virtual Chess* __QStrOrInt2Chess(QString chessNameSimple);
    int ** __board; // result of chess identify, 0-14
                    // 0: empty
                    // 1-7:  black
                    // 8-14: red
    char * __chessArray; // 0-13
};

// extern Qml_Connection* QmlConnect;
extern QObject* object; // control the whole graphic panel

//extern black_horse    *Ab_hor_1;
//extern black_cannon   *Ab_can_1;
//extern black_advisor  *Ab_adv_1;
//extern black_chariot  *Ab_cha_1;
//extern black_elephant *Ab_ele_1;
//extern black_horse    *Ab_hor_2;
//extern black_cannon   *Ab_can_2;
//extern black_advisor  *Ab_adv_2;
//extern black_chariot  *Ab_cha_2;
//extern black_elephant *Ab_ele_2;

//extern black_soldier  *Ab_sol_1;
//extern black_soldier  *Ab_sol_2;
//extern black_soldier  *Ab_sol_3;
//extern black_soldier  *Ab_sol_4;
//extern black_soldier  *Ab_sol_5;

//extern black_general  *Ab_gen_1;

//extern red_horse      *Ar_hor_1;
//extern red_cannon     *Ar_can_1;
//extern red_advisor    *Ar_adv_1;
//extern red_chariot    *Ar_cha_1;
//extern red_elephant   *Ar_ele_1;
//extern red_horse      *Ar_hor_2;
//extern red_cannon     *Ar_can_2;
//extern red_advisor    *Ar_adv_2;
//extern red_chariot    *Ar_cha_2;
//extern red_elephant   *Ar_ele_2;

//extern red_soldier    *Ar_sol_1;
//extern red_soldier    *Ar_sol_2;
//extern red_soldier    *Ar_sol_3;
//extern red_soldier    *Ar_sol_4;
//extern red_soldier    *Ar_sol_5;

//extern red_general    *Ar_gen_1;

typedef NormalSingleton< GlobalEnvironment > GlobalEnvirIn;

#endif // GLOBAL_H
