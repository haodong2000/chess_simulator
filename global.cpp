#include "global.h"
#include "Params.h"
#include <unordered_map>
#include <map>

#include "allBRChessesInclude.h"
#include "globalChesses.h"

/* * * * * * * * * * * * * * * * * * * * *
*   File:     global.cpp
*   Author:   Haodong LI
*   Usage:    empty file
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

namespace Global {
    enum CHESS_ALL_TABLE { // all chesses
        BLACK_1_GENERAL = 1,

        BLACK_1_ADVISOR,
        BLACK_2_ADVISOR,

        BLACK_1_ELEPHANT,
        BLACK_2_ELEPHANT,

        BLACK_1_HORSE,
        BLACK_2_HORSE,

        BLACK_1_CHARIOT,
        BLACK_2_CHARIOT,

        BLACK_1_CANNON,
        BLACK_2_CANNON,

        BLACK_1_SOLDIER,
        BLACK_2_SOLDIER,
        BLACK_3_SOLDIER,
        BLACK_4_SOLDIER,
        BLACK_5_SOLDIER,

        RED_1_GENERAL,
        RED_1_ADVISOR,
        RED_2_ADVISOR,

        RED_1_ELEPHANT,
        RED_2_ELEPHANT,

        RED_1_HORSE,
        RED_2_HORSE,

        RED_1_CHARIOT,
        RED_2_CHARIOT,

        RED_1_CANNON,
        RED_2_CANNON,

        RED_1_SOLDIER,
        RED_2_SOLDIER,
        RED_3_SOLDIER,
        RED_4_SOLDIER,
        RED_5_SOLDIER,
    };

    enum CHESS_TABLE {
        BLACK_GENERAL = 1,
        BLACK_ADVISOR,
        BLACK_ELEPHANT,
        BLACK_HORSE,
        BLACK_CHARIOT,
        BLACK_CANNON,
        BLACK_SOLDIER,
        RED_GENERAL,
        RED_ADVISOR,
        RED_ELEPHANT,
        RED_HORSE,
        RED_CHARIOT,
        RED_CANNON,
        RED_SOLDIER,
    };

    std::unordered_map<int, int> CHESS_VALUE = {
        {CHESS_TABLE::BLACK_GENERAL , 100},
        {CHESS_TABLE::BLACK_ADVISOR , 15},
        {CHESS_TABLE::BLACK_ELEPHANT, 15},
        {CHESS_TABLE::BLACK_HORSE   , 32},
        {CHESS_TABLE::BLACK_CHARIOT , 65},
        {CHESS_TABLE::BLACK_CANNON  , 30},
        {CHESS_TABLE::BLACK_SOLDIER , 10},
        {CHESS_TABLE::RED_GENERAL , 100},
        {CHESS_TABLE::RED_ADVISOR , 15},
        {CHESS_TABLE::RED_ELEPHANT, 15},
        {CHESS_TABLE::RED_HORSE   , 32},
        {CHESS_TABLE::RED_CHARIOT , 65},
        {CHESS_TABLE::RED_CANNON  , 30},
        {CHESS_TABLE::RED_SOLDIER , 10}
    };

    QVector<QString> CHESS_TABLE = {
        "一", // 0
        "将",
        "士",
        "象",
        "马",
        "车",
        "炮",
        "卒",
        "帅",
        "相",
        "仕",
        "马",
        "车",
        "炮",
        "兵",
    };

    std::unordered_map<QString, int> Chess_Qstr2Int {
        {"BGeneral",  1},
        {"BAdvisor",  2},
        {"BElephant", 3},
        {"BHorse",    4},
        {"BChariot",  5},
        {"BCannon",   6},
        {"BSoldier",  7},
        {"RGeneral",  1 + 7},
        {"RAdvisor",  2 + 7},
        {"RElephant", 3 + 7},
        {"RHorse",    4 + 7},
        {"RChariot",  5 + 7},
        {"RCannon",   6 + 7},
        {"RSoldier",  7 + 7},
    };

    std::unordered_map<int, QString> Chess_Int2Qstr {
        {1,  "BGeneral"},
        {2,  "BAdvisor"},
        {3,  "BElephant"},
        {4,  "BHorse"},
        {5,  "BChariot"},
        {6,  "BCannon"},
        {7,  "BSoldier"},
        {8,  "RGeneral"},
        {9,  "RAdvisor"},
        {10, "RElephant"},
        {11, "RHorse"},
        {12, "RChariot"},
        {13, "RCannon"},
        {14, "RSoldier"},
    };

    std::unordered_map<QString, int> Chess_Qstr2Int_simple {
        {"b_gen_", 1},
        {"b_adv_", 2},
        {"b_ele_", 3},
        {"b_hor_", 4},
        {"b_cha_", 5},
        {"b_can_", 6},
        {"b_sol_", 7},
        {"r_gen_", 1 + 7},
        {"r_adv_", 2 + 7},
        {"r_ele_", 3 + 7},
        {"r_hor_", 4 + 7},
        {"r_cha_", 5 + 7},
        {"r_can_", 6 + 7},
        {"r_sol_", 7 + 7},
    };

    std::unordered_map<int, QString> Chess_Int2Qstr_simple {
        {1,  "b_gen_"},
        {2,  "b_adv_"},
        {3,  "b_ele_"},
        {4,  "b_hor_"},
        {5,  "b_cha_"},
        {6,  "b_can_"},
        {7,  "b_sol_"},
        {8,  "r_gen_"},
        {9,  "r_adv_"},
        {10, "r_ele_"},
        {11, "r_hor_"},
        {12, "r_cha_"},
        {13, "r_can_"},
        {14, "r_sol_"},
    };
}

GlobalEnvironment::GlobalEnvironment() {
    __board = new int*[10];
    for(int i = 0; i < 10; i++) {
        __board[i] = new int[10];
    }
    __chessArray = new char[14];
    __chessArray[0]     = '\0'; // empty
    __chessArray[0 + 1] = 'g'; // black general
    __chessArray[1 + 1] = 'a';
    __chessArray[2 + 1] = 'e';
    __chessArray[3 + 1] = 'h';
    __chessArray[4 + 1] = 'c';
    __chessArray[5 + 1] = 'p'; // black cannon
    __chessArray[6 + 1] = 's';
    __chessArray[8 + 0] = 'G';
    __chessArray[8 + 1] = 'A';
    __chessArray[8 + 2] = 'E';
    __chessArray[8 + 3] = 'H';
    __chessArray[8 + 4] = 'C';
    __chessArray[8 + 5] = 'P'; // red cannon
    __chessArray[8 + 6] = 'S';
}

void GlobalEnvironment::__refreshBoard() {
    // init
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            __board[i][j] = 0;
        }
    }
    // loop every chess
    // if alive, assign
    const int chessNameIntMax = 14;
    const int numberNormal = 2;
    const int numberSoldier = 5;
    enum special {
        S_BLACK_GENERAL = 1,
        S_BLACK_SOLDIER = 7,
        S_RED_GENERAL = 8,
        S_RED_SOLDIER = 14};
    for(int index = 1; index <= chessNameIntMax; index++) {
        if(index == special::S_BLACK_GENERAL || index == special::S_RED_GENERAL) {
            // black_general
            if(__QStrOrInt2Chess(index, 1)->isAlive())
                __board[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()] = index;
        }
        else if(index == special::S_BLACK_SOLDIER || index == special::S_RED_SOLDIER) {
            for(int i = 1; i <= numberSoldier; i++) {
                if(__QStrOrInt2Chess(index, i)->isAlive())
                    __board[__QStrOrInt2Chess(index, i)->getPosX()][__QStrOrInt2Chess(index, i)->getPosY()] = index;
            }
        }
        else {
            // normal situation
            for(int i = 1; i <= numberNormal; i++) {
                if(__QStrOrInt2Chess(index, i)->isAlive())
                    __board[__QStrOrInt2Chess(index, i)->getPosX()][__QStrOrInt2Chess(index, i)->getPosY()] = index;
            }
        }
    }
}

void GlobalEnvironment::__printBoard() {
    __refreshBoard();
    std::cout << "__printBoard() called" << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << "[";
        for(int j = 0; j < 10; j++) {
            std::cout << " ";
            // QByteArray QStr2Char(Global::CHESS_TABLE.at(__board[i][j] - 1).toStdString().data());
            std::cout << Global::CHESS_TABLE.at(__board[j][i]).toStdString();
            if(j != 4) std::cout << " ";
            else std::cout << " |";
        }
        std::cout << "]\t" << std::endl;
    }
}

void GlobalEnvironment::__printAlive() {
    __refreshBoard();
    std::cout << "__printAlive() called" << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << "[";
        for(int j = 0; j < 10; j++) {
            std::cout << " ";
            QString printStr = __isThereHasChess(j, i) ? "X" : " ";
            std::cout << printStr.toStdString();
            if(j != 4) std::cout << " ";
            else std::cout << " |";
        }
        std::cout << "]\t" << std::endl;
    }
}

QString GlobalEnvironment::__int2QStrName(int name) {
    if(name == 0 || name > 14) {
        qDebug() << "global.cpp __int2QStrName(int name) line: 197 -> error: name(int) invalid!";
        return ""; // null
    }
    return Global::Chess_Int2Qstr_simple[name];
}

int GlobalEnvironment::__QStr2intName(QString name) {
    // Global::Chess_Qstr2Int_simple.find(name);
    std::unordered_map<QString, int>::iterator it;
    for(it = Global::Chess_Qstr2Int_simple.begin();
        it != Global::Chess_Qstr2Int_simple.end(); it++) {
        int tempInt = it->second;
        QString tempStr = it->first;
        if(name.compare(tempStr) == 0) break;
    }
    if(it == Global::Chess_Qstr2Int_simple.end()) {
        qDebug() << "global.cpp __QStr2intName(QString name) line: 197 -> error: name(QString) invalid!";
        return -1;
    }
    return Global::Chess_Qstr2Int_simple[name];
}

Chess* GlobalEnvironment::__QStrOrInt2Chess(int chessNameSimple, int number) {
    // chessNameSimple \in [1, 14], 0 is invalid
    switch (chessNameSimple) {
    case 0: // invalid
        qDebug() << "global.cpp line: 240 __QStrOrInt2Chess(int chessNameSimple) error: chessNameSimple = 0!";
        break;
    case Global::CHESS_TABLE::BLACK_GENERAL: // black_general
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_gen_1;
            break;
        default:
            qDebug() << "global.cpp line: 248 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::BLACK_ADVISOR: // black_advisor
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_adv_1;
            break;
        case 2:
            return Ab_adv_2;
            break;
        default:
            qDebug() << "global.cpp line: 261 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::BLACK_ELEPHANT: // black_elephant
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_ele_1;
            break;
        case 2:
            return Ab_ele_2;
            break;
        default:
            qDebug() << "global.cpp line: 277 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::BLACK_HORSE: // black_horse
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_hor_1;
            break;
        case 2:
            return Ab_hor_2;
            break;
        default:
            qDebug() << "global.cpp line: 293 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::BLACK_CHARIOT: // black_chariot
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_cha_1;
            break;
        case 2:
            return Ab_cha_2;
            break;
        default:
            qDebug() << "global.cpp line: 309 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::BLACK_CANNON: // black_cannon
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_can_1;
            break;
        case 2:
            return Ab_can_2;
            break;
        default:
            qDebug() << "global.cpp line: 325 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::BLACK_SOLDIER: // black_soldier
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ab_sol_1;
            break;
        case 2:
            return Ab_sol_2;
            break;
        case 3:
            return Ab_sol_3;
            break;
        case 4:
            return Ab_sol_4;
            break;
        case 5:
            return Ab_sol_5;
            break;
        default:
            qDebug() << "global.cpp line: 341 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_GENERAL: // red_general
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_gen_1;
            break;
        default:
            qDebug() << "global.cpp line: 366 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_ADVISOR: // red_advisor
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_adv_1;
            break;
        case 2:
            return Ar_adv_2;
            break;
        default:
            qDebug() << "global.cpp line: 379 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_ELEPHANT: // red_elephant
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_ele_1;
            break;
        case 2:
            return Ar_ele_2;
            break;
        default:
            qDebug() << "global.cpp line: 395 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_HORSE: // red_horse
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_hor_1;
            break;
        case 2:
            return Ar_hor_2;
            break;
        default:
            qDebug() << "global.cpp line: 411 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_CHARIOT: // red_chariot
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_cha_1;
            break;
        case 2:
            return Ar_cha_2;
            break;
        default:
            qDebug() << "global.cpp line: 427 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_CANNON: // red_cannon
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_can_1;
            break;
        case 2:
            return Ar_can_2;
            break;
        default:
            qDebug() << "global.cpp line: 443 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    case Global::CHESS_TABLE::RED_SOLDIER: // red_soldier
        // std::cout << Global::Chess_Int2Qstr_simple[chessNameSimple].toStdString() << " with num = " << number << std::endl;
        switch (number) {
        case 1:
            return Ar_sol_1;
            break;
        case 2:
            return Ar_sol_2;
            break;
        case 3:
            return Ar_sol_3;
            break;
        case 4:
            return Ar_sol_4;
            break;
        case 5:
            return Ar_sol_5;
            break;
        default:
            qDebug() << "global.cpp line: 459 __QStrOrInt2Chess() " +
                        Global::Chess_Int2Qstr_simple[chessNameSimple] +
                        " error: number is invalid";
            break;
        }
        break;
    default:
        qDebug() << "global.cpp line: 240 __QStrOrInt2Chess() error: chessNameSimple > 14!";
        break;
    }
    return nullptr; // null
}

Chess* GlobalEnvironment::__QStrOrInt2Chess(QString chessNameSimple, int number) {
    int chessNameInt = __QStr2intName(chessNameSimple);
    if(chessNameInt == -1) {
        std::unordered_map<QString, int>::iterator it;
        for(it = Global::Chess_Qstr2Int.begin(); it != Global::Chess_Qstr2Int.end(); it++) {
            if(it->first == chessNameSimple) break;
        }
        if(it == Global::Chess_Qstr2Int.end()) qDebug() << "global.cpp line: 276 __QStrOrInt2Chess() error: chessNameSimple invalid!";
        else chessNameInt = Global::Chess_Qstr2Int[chessNameSimple];
    }
    return __QStrOrInt2Chess(chessNameInt, number);// call other function
}

void GlobalEnvironment::__delayMsec(int Msec) {
    QTime dieTime = QTime::currentTime().addMSecs(Msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

bool GlobalEnvironment::__isThereHasChess(SGeoPoint *Pos) {
    const int chessNameIntMax = 14;
    const int numberNormal = 2;
    const int numberSoldier = 5;

//    enum special {
//        S_BLACK_GENERAL = 1,
//        S_BLACK_SOLDIER = 7,
//        S_RED_GENERAL = 8,
//        S_RED_SOLDIER = 14};

    for(int chessIndex = 1; chessIndex <= chessNameIntMax; chessIndex++) {
        switch (chessIndex) {
        case Global::CHESS_TABLE::BLACK_GENERAL:
            if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, 1), Pos)) return true;
            break;
        case Global::CHESS_TABLE::RED_GENERAL:
            if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, 1), Pos)) return true;
            break;
        case Global::CHESS_TABLE::BLACK_SOLDIER:
            for(int index = 1; index <= numberSoldier; index++) {
                if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, index), Pos)) return true;
            }
            break;
        case Global::CHESS_TABLE::RED_SOLDIER:
            for(int index = 1; index <= numberSoldier; index++) {
                if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, index), Pos)) return true;
            }
            break;
        default:
            for(int index = 1; index <= numberNormal; index++) {
                if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, index), Pos)) return true;
            }
        }
    }

    return false;
}

bool GlobalEnvironment::__isChessOnThere(Chess *chess, SGeoPoint *Pos) {
    return (chess->isAlive() && // important!
            chess->getPosX() == Pos->getPosX() &&
            chess->getPosY() == Pos->getPosY());
}

bool GlobalEnvironment::__isThereHasChess(int PosX, int PosY) {
    SGeoPoint* Pos = new SGeoPoint(PosX, PosY);
    return __isThereHasChess(Pos);
}

int GlobalEnvironment::__BoardEvaluate() {
    // One is the fixed piece strength value;
    // the other is the position value of the piece;
    // the third is the flexibility and cooperation value of the piece;
    // the fourth is the threat and protection value;
    // the fifth is the dynamic adjustment value.
    return 0;
}
