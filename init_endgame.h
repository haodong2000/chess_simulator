#ifndef INIT_ENDGAME_H
#define INIT_ENDGAME_H

/*****************************************************************
*   File:     init_endgame.h
*   Author:   Haodong LI
*   Usage:    set init chess board through vision
*   Time:     2021-08-02 -> 16:13:45
*****************************************************************/

#include "global.h"
#include "singleton.h"
#include "Qml_Connection.h"
#include "vision_thread.h"

extern vision_thread *vision;

class init_endgame
{
public:
    init_endgame();
    void setInitVisionBoard();
    void printVisionBoard();
private:
    bool isEndGameMode;
    bool isVisionBoardDone;
    int **initChessBoard;
};

typedef NormalSingleton< init_endgame > initEndgameIn;

#endif // INIT_ENDGAME_H
