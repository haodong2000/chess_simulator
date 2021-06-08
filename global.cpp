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

    enum WHOLE_BOARD {
        INIT_BOARD = 1,
        GOING_BOARD,
        END_BOARD,
        FINAL_BOARD
    };

    std::unordered_map<int, int> CHESS_VALUE = {
        {CHESS_TABLE::BLACK_GENERAL , 2*1000},
        {CHESS_TABLE::BLACK_ADVISOR , 2*200},
        {CHESS_TABLE::BLACK_ELEPHANT, 2*175},
        {CHESS_TABLE::BLACK_HORSE   , 2*400},
        {CHESS_TABLE::BLACK_CHARIOT , 2*600},
        {CHESS_TABLE::BLACK_CANNON  , 2*350},
        {CHESS_TABLE::BLACK_SOLDIER , 2*150},
        {CHESS_TABLE::RED_GENERAL , 2*1000},
        {CHESS_TABLE::RED_ADVISOR , 2*200},
        {CHESS_TABLE::RED_ELEPHANT, 2*175},
        {CHESS_TABLE::RED_HORSE   , 2*400},
        {CHESS_TABLE::RED_CHARIOT , 2*600},
        {CHESS_TABLE::RED_CANNON  , 2*350},
        {CHESS_TABLE::RED_SOLDIER , 2*150}
    };

    QVector<QString> CHESS_TABLE = {
        "一", // 0
        "将",
        "士",
        "象",
        "馬",
        "車",
        "砲",
        "卒",
        "帅",
        "仕",
        "相",
        "傌",
        "俥",
        "炮",
        "兵"
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

    const int randomRange = 250;
}

GlobalEnvironment::GlobalEnvironment() {
    __board = new int*[10];
    for(int i = 0; i < 10; i++) {
        __board[i] = new int[10];
    }

    __boardValueBlack = new int*[10];
    for(int i = 0; i < 10; i++) {
        __boardValueBlack[i] = new int[10];
    }

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            __boardValueBlack[j][i] = __boardValueBlackUnit(j, i);
        }
    }

    __boardValueRed = new int*[10];
    for(int i = 0; i < 10; i++) {
        __boardValueRed[i] = new int[10];
    }

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            __boardValueRed[j][i] = __boardValueRedUnit(j, i);
        }
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

QString GlobalEnvironment::__QString2SimpleName(QString originName) {
    // "BGeneral" -> "b_gen_"
    std::unordered_map<QString, int>::iterator it = Global::Chess_Qstr2Int.begin();
    for(it = Global::Chess_Qstr2Int.begin(); it != Global::Chess_Qstr2Int.end(); it++) {
        int tempInt = it->second;
        QString tempStr = it->first;
        if(originName.compare(tempStr) == 0) break;
    }
    if(it == Global::Chess_Qstr2Int.end()) {
        qDebug() << "global.cpp __QString2SimpleName() line 298 -> error: originName(QString) invalid!";
        return  "";
    }
    return __int2QStrName(Global::Chess_Qstr2Int[originName]);
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

bool GlobalEnvironment::__isPosInBoard(SGeoPoint *Pos) {
    if(Pos->getPosX() < 0 || Pos->getPosX() > PARAM::globalEnvironment::maxAxisOfX) return false;
    if(Pos->getPosY() < 0 || Pos->getPosY() > PARAM::globalEnvironment::maxAxisOfY) return false;
    return true;
}

bool GlobalEnvironment::__isPosInBoard(int PosX, int PosY) {
    SGeoPoint* Pos = new SGeoPoint(PosX, PosY);
    return __isPosInBoard(Pos);
}

bool GlobalEnvironment::__isThereHasChess(SGeoPoint *Pos) {
    if((Pos->getPosX() < 0 || Pos->getPosX() > PARAM::globalEnvironment::maxAxisOfX) ||
            (Pos->getPosY() < 0 || Pos->getPosY() > PARAM::globalEnvironment::maxAxisOfY)) {
        qDebug() << "global.cpp line:594 __isThereHasChess()  error:Pos out of boundary!";
        return true;
    }

    const int chessNameIntMax = 14;
    const int numberNormal = 2;
    const int numberSoldier = 5;

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

Chess* GlobalEnvironment::__whichChessOnThere(SGeoPoint *Pos) {
    if(!__isThereHasChess(Pos)) {
        qDebug() << "global.cpp __whichChessOnThere() line:666 error:no chess on Pos!!!";
        return 0;
    }

    if((Pos->getPosX() < 0 || Pos->getPosX() > PARAM::globalEnvironment::maxAxisOfX) ||
            (Pos->getPosY() < 0 || Pos->getPosY() > PARAM::globalEnvironment::maxAxisOfY)) {
        qDebug() << "global.cpp line:666 __whichChessOnThere()  error:Pos out of boundary!";
        return 0;
    }

    const int chessNameIntMax = 14;
    const int numberNormal = 2;
    const int numberSoldier = 5;

    for(int chessIndex = 1; chessIndex <= chessNameIntMax; chessIndex++) {
        switch (chessIndex) {
        case Global::CHESS_TABLE::BLACK_GENERAL:
            if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, 1), Pos)) return GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessIndex, 1);
            break;
        case Global::CHESS_TABLE::RED_GENERAL:
            if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, 1), Pos)) return GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessIndex, 1);
            break;
        case Global::CHESS_TABLE::BLACK_SOLDIER:
            for(int index = 1; index <= numberSoldier; index++) {
                if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, index), Pos)) return GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessIndex, index);
            }
            break;
        case Global::CHESS_TABLE::RED_SOLDIER:
            for(int index = 1; index <= numberSoldier; index++) {
                if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, index), Pos)) return GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessIndex, index);
            }
            break;
        default:
            for(int index = 1; index <= numberNormal; index++) {
                if(__isChessOnThere(__QStrOrInt2Chess(chessIndex, index), Pos)) return GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessIndex, index);
            }
        }
    }
    return 0;
}

Chess* GlobalEnvironment::__whichChessOnThere(int PosX, int PosY) {
    SGeoPoint* Pos = new SGeoPoint(PosX, PosY);
    return __whichChessOnThere(Pos);
}

bool GlobalEnvironment::__isThereHasOurChess(bool camp, SGeoPoint *Pos) {
    if((Pos->getPosX() < 0 || Pos->getPosX() > PARAM::globalEnvironment::maxAxisOfX) ||
            (Pos->getPosY() < 0 || Pos->getPosY() > PARAM::globalEnvironment::maxAxisOfY)) {
        qDebug() << "global.cpp line:667 __isThereHasOurChess()  error:Pos out of boundary!";
        return true;
    }

    if(!__isThereHasChess(Pos)) return false; // if no chess

    const int numberNormal = 2;
    const int numberSoldier = 5;

    const int startIndex = camp ? 8 : 1;
    const int chessNameIntMax = camp ? 14 : 7;

    for(int chessIndex = startIndex; chessIndex <= chessNameIntMax; chessIndex++) {
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

bool GlobalEnvironment::__isThereHasOurChess(bool camp, int PosX, int PosY) {
    SGeoPoint* Pos = new SGeoPoint(PosX, PosY);
    return __isThereHasOurChess(camp, Pos);
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

void GlobalEnvironment::__killThisChess(int killNum, int killNumber) {
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(killNum, killNumber)->setAlive(false);
    object->setProperty(
                (GlobalEnvirIn::Instance()->__int2QStrName(killNum) +
                 QString::number(killNumber) +
                 QString("_alive")).toLatin1(), false);
}

void GlobalEnvironment::__fakeKillThisChess(int killNum, int killNumber) {
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(killNum, killNumber)->setAlive(false);
}

void GlobalEnvironment::__setGameTurn(bool whosTurn) {
    // true: ai_turn, black
    // false: humen_turn, red
    object->setProperty("ai_turn", whosTurn);
}

int GlobalEnvironment::__BoardEvaluate() {
    if(Ab_gen_1->isAlive() == false) return -99999;
    if(Ar_gen_1->isAlive() == false) return 99999;
    // One is the fixed piece strength value;
    // the other is the position value of the piece;
    // the third is the flexibility and cooperation value of the piece;
    // the fourth is the threat and protection value;
    // the fifth is the dynamic adjustment value.
    int blackValue = 0;
    int redValue = 0;
    blackValue += __calculateBlackChessValue();
    redValue += __calculateRedChessValue();
    blackValue += __calculateBlackPosValue();
    redValue += __calculateRedPosValue();
    blackValue += __calculateBlackSpaceValue();
    redValue += __calculateRedSpaceValue();
//    std::cout << "blackValue = " << blackValue << std::endl;
//    std::cout << "redValue   = " << redValue << std::endl;
    int randomRangeBlack = blackValue/Global::randomRange;
    int randomRangeRed = redValue/Global::randomRange;
    blackValue -= __generateRandomNumber(randomRangeBlack);
    redValue -= __generateRandomNumber(randomRangeRed);
    return blackValue - redValue;
}

int GlobalEnvironment::__calculateBlackSpaceValue() {
    int blackSpaceValue = 0;
    for(int index = 1; index <= 7; index++) {
        switch (index) {
        case Global::CHESS_TABLE::BLACK_GENERAL:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_gen_1->space_value());
            break;
        case Global::CHESS_TABLE::BLACK_SOLDIER:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_sol_1->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_sol_2->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_sol_3->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_sol_4->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_sol_5->space_value());
            break;
        case Global::CHESS_TABLE::BLACK_ADVISOR:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_adv_1->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_adv_2->space_value());
            break;
        case Global::CHESS_TABLE::BLACK_ELEPHANT:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_ele_1->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_ele_2->space_value());
            break;
        case Global::CHESS_TABLE::BLACK_HORSE:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_hor_1->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_hor_2->space_value());
            break;
        case Global::CHESS_TABLE::BLACK_CHARIOT:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_cha_1->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_cha_2->space_value());
            break;
        case Global::CHESS_TABLE::BLACK_CANNON:
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_can_1->space_value());
            blackSpaceValue += qRound(Global::CHESS_VALUE[index] * Ab_can_2->space_value());
            break;
        default:
            qDebug() << "global.cpp __calculateBlackSpaceValue() line:692 error:invalid chess_num!!!";
            break;
        }
    }
    blackSpaceValue = qRound(blackSpaceValue/5.0);
//    std::cout << "__calculateBlackSpaceValue() = " << blackSpaceValue << std::endl;
    return blackSpaceValue*2;
}

int GlobalEnvironment::__calculateRedSpaceValue() {
    int redSpaceValue = 0;
    for(int index = 8; index <= 14; index++) {
        switch (index) {
        case Global::CHESS_TABLE::RED_GENERAL:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_gen_1->space_value());
            break;
        case Global::CHESS_TABLE::RED_SOLDIER:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_sol_1->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_sol_2->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_sol_3->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_sol_4->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_sol_5->space_value());
            break;
        case Global::CHESS_TABLE::RED_ADVISOR:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_adv_1->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_adv_2->space_value());
            break;
        case Global::CHESS_TABLE::RED_ELEPHANT:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_ele_1->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_ele_2->space_value());
            break;
        case Global::CHESS_TABLE::RED_HORSE:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_hor_1->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_hor_2->space_value());
            break;
        case Global::CHESS_TABLE::RED_CHARIOT:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_cha_1->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_cha_2->space_value());
            break;
        case Global::CHESS_TABLE::RED_CANNON:
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_can_1->space_value());
            redSpaceValue += qRound(Global::CHESS_VALUE[index] * Ar_can_2->space_value());
            break;
        default:
            qDebug() << "global.cpp __calculateRedSpaceValue() line:692 error:invalid chess_num!!!";
            break;
        }
    }
    redSpaceValue = qRound(redSpaceValue/5.0);
//    std::cout << "__calculateRedSpaceValue() = " << redSpaceValue << std::endl;
    return redSpaceValue*2;
}

int GlobalEnvironment::__calculateBlackChessValue() {
    if(Ar_gen_1->isAlive() == false && Ab_gen_1->isAlive()) return 99999;
    if(Ab_gen_1->isAlive() == false) return -99999;
    int blackChessValue = 0;
    for(int index = 1; index <= 7; index++) {
        switch (index) {
        case Global::CHESS_TABLE::BLACK_GENERAL:
            if(__QStrOrInt2Chess(index, 1)->isAlive()) blackChessValue += Global::CHESS_VALUE[index];
            break;
        case Global::CHESS_TABLE::BLACK_SOLDIER:
            for(int number = 1; number <= 5; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) blackChessValue += Global::CHESS_VALUE[index];
            }
            break;
        default:
            for(int number = 1; number <= 2; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) blackChessValue += Global::CHESS_VALUE[index];
            }
            break;
        }
    }
//    std::cout << "__calculateBlackChessValue() = " << blackChessValue << std::endl;
    return blackChessValue;
}

int GlobalEnvironment::__calculateRedChessValue() {
    if(Ab_gen_1->isAlive() == false && Ar_gen_1->isAlive()) return 99999;
    if(Ar_gen_1->isAlive() == false) return -99999;
    int redChessValue = 0;
    for(int index = 8; index <= 14; index++) {
        switch (index) {
        case Global::CHESS_TABLE::RED_GENERAL:
            if(__QStrOrInt2Chess(index, 1)->isAlive()) redChessValue += Global::CHESS_VALUE[index];
            break;
        case Global::CHESS_TABLE::RED_SOLDIER:
            for(int number = 1; number <= 5; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) redChessValue += Global::CHESS_VALUE[index];
            }
            break;
        default:
            for(int number = 1; number <= 2; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) redChessValue += Global::CHESS_VALUE[index];
            }
            break;
        }
    }
//    std::cout << "__calculateRedChessValue() = " << redChessValue << std::endl;
    return redChessValue;
}

int GlobalEnvironment::__calculateBlackPosValue() {
    int blackPosValue = 0;
    for(int index = 1; index <= 7; index++) {
        switch (index) {
        case Global::CHESS_TABLE::BLACK_GENERAL:
            if(__QStrOrInt2Chess(index, 1)->isAlive()) blackPosValue += __boardValueBlack[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()];
            break;
        case Global::CHESS_TABLE::BLACK_SOLDIER:
            for(int number = 1; number <= 5; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) blackPosValue += __boardValueBlack[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()];;
            }
            break;
        default:
            for(int number = 1; number <= 2; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) blackPosValue += __boardValueBlack[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()];
            }
            break;
        }
    }
//    std::cout << "__calculateBlackPosValue() = " << blackPosValue << std::endl;
    return blackPosValue;
}

int GlobalEnvironment::__calculateRedPosValue() {
    int redPosValue = 0;
    for(int index = 8; index <= 14; index++) {
        switch (index) {
        case Global::CHESS_TABLE::RED_GENERAL:
            if(__QStrOrInt2Chess(index, 1)->isAlive()) redPosValue += __boardValueRed[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()];
            break;
        case Global::CHESS_TABLE::RED_SOLDIER:
            for(int number = 1; number <= 5; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) redPosValue += __boardValueRed[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()];
            }
            break;
        default:
            for(int number = 1; number <= 2; number++) {
                if(__QStrOrInt2Chess(index, number)->isAlive()) redPosValue += __boardValueRed[__QStrOrInt2Chess(index, 1)->getPosX()][__QStrOrInt2Chess(index, 1)->getPosY()];
            }
            break;
        }
    }
//    std::cout << "__calculateRedPosValue() = " << redPosValue << std::endl;
    return redPosValue;
}

int GlobalEnvironment::__boardValueBlackUnit(int x, int y) {
    const int rate = (12 + __isWholeBoardEntire() * 4)*4;
    const int base = 75;
    int gen_y = __QStrOrInt2Chess(Global::CHESS_TABLE::RED_GENERAL, 1)->getPosY();
    int gen_x = __QStrOrInt2Chess(Global::CHESS_TABLE::RED_GENERAL, 1)->getPosX();
    return base + (PARAM::globalEnvironment::maxAxisOfX - abs(x - gen_x) + 4)*(rate - abs(y - gen_y));
    return 0;
}

int GlobalEnvironment::__boardValueRedUnit(int x, int y) {
    const int rate = (12 + __isWholeBoardEntire() * 4)*4;
    const int base = 75;
    int gen_y = __QStrOrInt2Chess(Global::CHESS_TABLE::BLACK_GENERAL, 1)->getPosY();
    int gen_x = __QStrOrInt2Chess(Global::CHESS_TABLE::BLACK_GENERAL, 1)->getPosX();
    return base + (PARAM::globalEnvironment::maxAxisOfX - abs(x - gen_x) + 4)*(rate - abs(y - gen_y));
    return 0;
}

int GlobalEnvironment::__calculateAlive() {
    __refreshBoard();
    int count = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            // TODO
            // simply counting is stupid
            if(__isThereHasChess(j, i)) count++;
        }
    }
    return count;
}

int GlobalEnvironment::__isWholeBoardEntire() {
    // function to judge Whole, End, Final
    // Whole = 1
    // End = 2
    // Final = 3
    int count = __calculateAlive();
    if(count > PARAM::globalEnvironment::goingChessCount &&
            count <= PARAM::globalEnvironment::initChessCount) return Global::WHOLE_BOARD::INIT_BOARD;
    else if(count > PARAM::globalEnvironment::endChessCount &&
            count <= PARAM::globalEnvironment::goingChessCount) return Global::WHOLE_BOARD::GOING_BOARD;
    else if(count > PARAM::globalEnvironment::finalChessCount &&
            count <= PARAM::globalEnvironment::endChessCount) return Global::WHOLE_BOARD::END_BOARD;
    else if(count >= 0 &&
            count <= PARAM::globalEnvironment::finalChessCount) return Global::WHOLE_BOARD::FINAL_BOARD;
    else {
        qDebug() << "global.cpp  line: 655  error: count = __calculateAlive() is illegal!";
        return -1;
    }
}

bool GlobalEnvironment::__isOtherChessAround(int chessNum, int chessNumber) {
    // if a chess is around in for direction, return true, else return false
    // for up direction
    if(__QStrOrInt2Chess(chessNum, chessNumber)->getPosY() - 1 >= 0 &&
            !(__isThereHasChess(__QStrOrInt2Chess(chessNum, chessNumber)->getPosX(), __QStrOrInt2Chess(chessNum, chessNumber)->getPosY() - 1)))
        return false;
    // for down direction
    if(__QStrOrInt2Chess(chessNum, chessNumber)->getPosY() + 1 <= PARAM::globalEnvironment::maxAxisOfY &&
            !(__isThereHasChess(__QStrOrInt2Chess(chessNum, chessNumber)->getPosX(), __QStrOrInt2Chess(chessNum, chessNumber)->getPosY() + 1)))
        return false;
    // for left direction
    if(__QStrOrInt2Chess(chessNum, chessNumber)->getPosX() - 1 >= 0 &&
            !(__isThereHasChess(__QStrOrInt2Chess(chessNum, chessNumber)->getPosX() - 1, __QStrOrInt2Chess(chessNum, chessNumber)->getPosY())))
        return false;
    // for right direction
    if(__QStrOrInt2Chess(chessNum, chessNumber)->getPosX() + 1 <= PARAM::globalEnvironment::maxAxisOfX &&
            !(__isThereHasChess(__QStrOrInt2Chess(chessNum, chessNumber)->getPosX() + 1, __QStrOrInt2Chess(chessNum, chessNumber)->getPosY())))
        return false;
    return true;
}

double GlobalEnvironment::__countSpaceAround(int chessNum, int chessNumber) {
    enum direction { // 0, 1, 2, 3
        up = 0,
        down,
        left,
        right
    };
    double count[4] = {0, 0, 0, 0};
    double maxValue = 0;
    const double enemyDirection = 1.5;
    const double moveOnY = 1.0;
    const double ourDirection = 0.5;
    const bool redOrBlack = (chessNum >= 8); // true is red and false is black

    maxValue += (PARAM::globalEnvironment::maxAxisOfY) * 1.0 * moveOnY;
    if (redOrBlack) {
        maxValue += (PARAM::globalEnvironment::maxAxisOfX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX()) * 1.0 * ourDirection;
        // if(GlobalEnvirIn::Instance()->__isPosInBoard(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX(), GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosY()))
        maxValue += (GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX()) * 1.0 * enemyDirection;
    }
    else {
        maxValue += (PARAM::globalEnvironment::maxAxisOfX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX()) * 1.0 * enemyDirection;
        // if(GlobalEnvirIn::Instance()->__isPosInBoard(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX(), GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosY()))
        maxValue += (GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX()) * 1.0 * ourDirection;
    }

    for(int up = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosY() - 1; up >= 0; up--) {
        if(!GlobalEnvirIn::Instance()->__isThereHasChess(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX(), up))
            count[direction::up] += 1.0 * moveOnY;
        else break;
    }
    for(int down = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosY() + 1; down <= PARAM::globalEnvironment::maxAxisOfY; down++) {
        if(!GlobalEnvirIn::Instance()->__isThereHasChess(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX(), down))
            count[direction::down] += 1.0 * moveOnY;
        else break;
    }
    for(int left = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX() - 1; left >= 0; left--) {
        if(!GlobalEnvirIn::Instance()->__isThereHasChess(left, GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosY()))
            count[direction::left] += 1.0 * (redOrBlack ? enemyDirection : ourDirection);
        else break;
    }
    for(int right = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosX() + 1; right <= PARAM::globalEnvironment::maxAxisOfX; right++) {
        if(!GlobalEnvirIn::Instance()->__isThereHasChess(right, GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber)->getPosY()))
            count[direction::right] += 1.0 * (redOrBlack ? ourDirection : enemyDirection);
        else break;
    }

//    std::cout << count[direction::up] << std::endl;
//    std::cout << count[direction::down] << std::endl;
//    std::cout << count[direction::left] << std::endl;
//    std::cout << count[direction::right] << std::endl;

    double totalValue = count[direction::up] + count[direction::down] + count[direction::left] + count[direction::right];
    return totalValue/maxValue; // 0~100%
}

int GlobalEnvironment::__countChessInPath(SGeoPoint *start, SGeoPoint *end) {
    if(!((start->getPosX() == end->getPosX()) || (start->getPosY() == end->getPosY()))) {
        qDebug() << "global.cpp line:1099 __countChessInPath() error:start and end must be straight line!";
        return -1;
    }
    int count = 0;
    if(start->getPosX() - end->getPosX() == 0) {
        for(int index = qMin(start->getPosY(), end->getPosY()) + 1; index < qMax(start->getPosY(), end->getPosY()); index++) {
            SGeoPoint* middle = new SGeoPoint(start->getPosX(), index);
            if(GlobalEnvirIn::Instance()->__isThereHasChess(middle)) count++;
        }
    }
    if(start->getPosY() - end->getPosY() == 0) {
        for(int index = qMin(start->getPosX(), end->getPosX()) + 1; index < qMax(start->getPosX(), end->getPosX()); index++) {
            SGeoPoint* middle = new SGeoPoint(index, start->getPosY());
            if(GlobalEnvirIn::Instance()->__isThereHasChess(middle)) count++;
        }
    }
    return count;
}

int GlobalEnvironment::__generateRandomNumber(int maxNumber) {
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int ret = qrand()%maxNumber;
    return ret;
}
