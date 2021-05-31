#include "global.h"
#include "Params.h"
#include <unordered_map>
#include <map>

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

    QVector<QString> CHESS_TABLE = {
        "_",
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
}

void GlobalEnvironment::__printBoard() {
    for(int i = 0; i < 10; i++) {
        std::cout << "[\t";
        for(int j = 0; j < 10; j++) {
            std::cout << " ";
            QByteArray QStr2Char(Global::CHESS_TABLE.at(__board[i][j]).toStdString().data());
            std::cout << QStr2Char.data(); // << Global::CHESS_TABLE.at(__board[i][j]).toStdString().data();
            if(j != 9) std::cout << ", \t";
            else std::cout << " \t";
        }
        std::cout << std::endl;
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
