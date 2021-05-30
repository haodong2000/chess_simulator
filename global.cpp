#include "global.h"
#include "Params.h"

/* * * * * * * * * * * * * * * * * * * * *
*   File:     global.cpp
*   Author:   Haodong LI
*   Usage:    empty file
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

GlobalEnvironment::GlobalEnvironment() {
    __board = new int*[10];
    for(int i = 0; i < 10; i++) {
        __board[i] = new int[10];
    }
    __chessArray = new char[14];
    __chessArray[0] = 'g'; // black general
    __chessArray[1] = 'a';
    __chessArray[2] = 'e';
    __chessArray[3] = 'h';
    __chessArray[4] = 'c';
    __chessArray[5] = 'p'; // black cannon
    __chessArray[6] = 's';
    __chessArray[7 + 0] = 'G';
    __chessArray[7 + 1] = 'A';
    __chessArray[7 + 2] = 'E';
    __chessArray[7 + 3] = 'H';
    __chessArray[7 + 4] = 'C';
    __chessArray[7 + 5] = 'P'; // red cannon
    __chessArray[7 + 6] = 'S';
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

}
