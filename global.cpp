#include "global.h"
#include "Params.h"
#include "black_chesses/black_general.h"

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
