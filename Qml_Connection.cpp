#include "Qml_Connection.h"

/*****************************************************************
*   File:     Qml_Connection.cpp
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-31 -> 20:29:48
*****************************************************************/

Qml_Connection::Qml_Connection()
{
    isEndGameMode = false;
}

void Qml_Connection::moveChessAnimationBegin(int start_X, int start_Y, int end_X, int end_Y) {
    object->setProperty(QString("isAnimation").toLatin1(), true);
    object->setProperty(QString("animation_start_X").toLatin1(), start_X);
    object->setProperty(QString("animation_start_Y").toLatin1(), start_Y);
    object->setProperty(QString("animation_end_X").toLatin1(), end_X);
    object->setProperty(QString("animation_end_Y").toLatin1(), end_Y);
}

void Qml_Connection::moveChessAnimationEnd() {
    object->setProperty(QString("isAnimation").toLatin1(), false);
}

void Qml_Connection::changeChessPos(int chessName, int number, bool camp, SGeoPoint *Pos) {
    // number already contain the infomation of camp, chessName also contains
    QString name = GlobalEnvirIn::Instance()->__int2QStrName(chessName) + QString::number(number);
    if(name.isEmpty()) {
        qDebug() << "ERROR! Qml_Connection.cpp changeChessPos() line: 17";
        return;
    }

    moveChessAnimationBegin(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX(),
                            GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY(),
                            Pos->getPosX(),
                            Pos->getPosY());

    int cur_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX();
    int cur_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY();
    double current_x = coordinateIn::Instance()->tranRealPosX(cur_x);
    double current_y = coordinateIn::Instance()->tranRealPosY(cur_y);
    double target_x = coordinateIn::Instance()->tranRealPosX(Pos->getPosX());
    double target_y = coordinateIn::Instance()->tranRealPosY(Pos->getPosY());
    double length = sqrt((Pos->getPosX() - cur_x) * (Pos->getPosX() - cur_x) + (Pos->getPosY() - cur_y) * (Pos->getPosY() - cur_y));
    int num_pieces = 10;
    int num_pieces_d = 10.0;
    if(length >= 4.0) {
        num_pieces += int((length - 4.0)/2.0);
        num_pieces_d = double(num_pieces);
    }
    double delta_x = (target_x - current_x)/num_pieces_d;
    double delta_y = (target_y - current_y)/num_pieces_d;
    for(int i = 0; i < num_pieces; i++) {
        object->setProperty((name + QString("_posX")).toLatin1(), current_x + delta_x * (double)i);
        object->setProperty((name + QString("_posY")).toLatin1(), current_y + delta_y * (double)i);
        GlobalEnvirIn::Instance()->__delayMsec(20);
    }

    object->setProperty((name + QString("_posX")).toLatin1(), coordinateIn::Instance()->tranRealPosX(Pos->getPosX()));
    object->setProperty((name + QString("_posY")).toLatin1(), coordinateIn::Instance()->tranRealPosY(Pos->getPosY()));

    if(GlobalEnvirIn::Instance()->__isThereHasChess(Pos)) {
        killThisChess(Pos);
    }

    moveChessAnimationEnd();

    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosX(Pos->getPosX());
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosY(Pos->getPosY());

    if(chessName == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL || chessName == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) {
        GlobalEnvirIn::Instance()->__refershPosValueUnit();
    }
}

void Qml_Connection::changeChessPos(QString chessName, int number, bool camp, SGeoPoint *Pos) {
    int chessNameInt = GlobalEnvirIn::Instance()->__QStr2intName(chessName);
    if(chessNameInt == -1) {
        qDebug() << "ERROR! Qml_Connection.cpp changeChessPos() line: 27";
        return;
    }
    changeChessPos(chessNameInt, number, camp, Pos); // call other function
}

void Qml_Connection::changeChessPos(int chessName, int number, bool camp, int deltaX, int deltaY) {
    // chessName like b_gen_, r_adv_
    QString name = GlobalEnvirIn::Instance()->__int2QStrName(chessName) + QString::number(number);
    if(name.isEmpty()) {
        qDebug() << "ERROR! Qml_Connection.cpp changeChessPos() line: 36";
        return;
    }
    int posX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX() + deltaX; // first call
    int posY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY() + deltaY; // second call

    moveChessAnimationBegin(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX(),
                            GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY(),
                            posX,
                            posY);

    int cur_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX();
    int cur_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY();
    double current_x = coordinateIn::Instance()->tranRealPosX(cur_x);
    double current_y = coordinateIn::Instance()->tranRealPosY(cur_y);
    double target_x = coordinateIn::Instance()->tranRealPosX(posX);
    double target_y = coordinateIn::Instance()->tranRealPosY(posY);
    double length = sqrt((posX - cur_x) * (posX - cur_x) + (posY - cur_y) * (posY - cur_y));
    int num_pieces = 10;
    int num_pieces_d = 10.0;
    if(length >= 4.0) {
        num_pieces += int((length - 4.0)/2.0);
        num_pieces_d = double(num_pieces);
    }
    double delta_x = (target_x - current_x)/num_pieces_d;
    double delta_y = (target_y - current_y)/num_pieces_d;
    for(int i = 0; i < num_pieces; i++) {
        object->setProperty((name + QString("_posX")).toLatin1(), current_x + delta_x * (double)i);
        object->setProperty((name + QString("_posY")).toLatin1(), current_y + delta_y * (double)i);
        GlobalEnvirIn::Instance()->__delayMsec(20);
    }

    object->setProperty((name + QString("_posX")).toLatin1(), coordinateIn::Instance()->tranRealPosX(posX));
    object->setProperty((name + QString("_posY")).toLatin1(), coordinateIn::Instance()->tranRealPosY(posY));

    if(GlobalEnvirIn::Instance()->__isThereHasChess(posX, posY)) {
        killThisChess(posX, posY);
    }

    moveChessAnimationEnd();

    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosX(posX);
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosY(posY);

    if(chessName == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL || chessName == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) {
        GlobalEnvirIn::Instance()->__refershPosValueUnit();
    }
}

void Qml_Connection::changeChessPos(QString chessName, int number, bool camp, int deltaX, int deltaY) {
    int chessNameInt = GlobalEnvirIn::Instance()->__QStr2intName(chessName);
    if(chessNameInt == -1) {
        qDebug() << "ERROR! Qml_Connection.cpp changeChessPos() line: 44";
        return;
    }
    changeChessPos(chessNameInt, number, camp, deltaX ,deltaY); // call other function
}

void Qml_Connection::killThisChess(SGeoPoint *Pos) {
    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(Pos)->chessName());
    int killNum =  GlobalEnvirIn::Instance()->__QStr2intName(killName);
    int killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(Pos)->chessNumber();
    GlobalEnvirIn::Instance()->__whichChessOnThere(Pos)->setAlive(false);
    object->setProperty(
                (GlobalEnvirIn::Instance()->__int2QStrName(killNum) +
                 QString::number(killNumber) +
                 QString("_alive")).toLatin1(), false);
}

void Qml_Connection::killThisChess(int PosX, int PosY) {
    SGeoPoint* Pos = new SGeoPoint(PosX, PosY);
    killThisChess(Pos);
    delete Pos;
}

void Qml_Connection::fakeChangeChessPos(int chessName, int number, bool camp, SGeoPoint *Pos) {
    // number already contain the infomation of camp, chessName also contains
    QString name = GlobalEnvirIn::Instance()->__int2QStrName(chessName) + QString::number(number);
    if(name.isEmpty()) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeChangeChessPos() line: 87";
        return;
    }

    if(GlobalEnvirIn::Instance()->__isThereHasChess(Pos)) {
        fakeKillThisChess(Pos);
    }

    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosX(Pos->getPosX());
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosY(Pos->getPosY());

    if(chessName == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL || chessName == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) {
        GlobalEnvirIn::Instance()->__refershPosValueUnit();
    }
}

void Qml_Connection::fakeChangeChessPos(QString chessName, int number, bool camp, SGeoPoint *Pos) {
    int chessNameInt = GlobalEnvirIn::Instance()->__QStr2intName(chessName);
    if(chessNameInt == -1) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeChangeChessPos() line: 104";
        return;
    }
    fakeChangeChessPos(chessNameInt, number, camp, Pos); // call other function
}

void Qml_Connection::fakeChangeChessPos(int chessName, int number, bool camp, int deltaX, int deltaY) {
    // chessName like b_gen_, r_adv_
    QString name = GlobalEnvirIn::Instance()->__int2QStrName(chessName) + QString::number(number);
    if(name.isEmpty()) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeChangeChessPos() line: 113";
        return;
    }
    int posX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX() + deltaX; // first call
    int posY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY() + deltaY; // second call

    if(GlobalEnvirIn::Instance()->__isThereHasChess(posX, posY)) {
        fakeKillThisChess(posX, posY);
    }

    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosX(posX);
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosY(posY);

    if(chessName == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL || chessName == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) {
        GlobalEnvirIn::Instance()->__refershPosValueUnit();
    }
}

void Qml_Connection::fakeChangeChessPos(QString chessName, int number, bool camp, int deltaX, int deltaY) {
    int chessNameInt = GlobalEnvirIn::Instance()->__QStr2intName(chessName);
    if(chessNameInt == -1) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeChangeChessPos() line: 44";
        return;
    }
    fakeChangeChessPos(chessNameInt, number, camp, deltaX ,deltaY); // call other function
}

void Qml_Connection::fakeKillThisChess(SGeoPoint *Pos) {
    GlobalEnvirIn::Instance()->__whichChessOnThere(Pos)->setAlive(false);
}

void Qml_Connection::fakeKillThisChess(int PosX, int PosY) {
    SGeoPoint* Pos = new SGeoPoint(PosX, PosY);
    fakeKillThisChess(Pos);
    delete Pos;
}

void Qml_Connection::fakeBackChangeChessPos(int chessName, int number, bool camp, int deltaX, int deltaY) {
    // chessName like b_gen_, r_adv_
    QString name = GlobalEnvirIn::Instance()->__int2QStrName(chessName) + QString::number(number);
    if(name.isEmpty()) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeBackChangeChessPos() line: 177";
        return;
    }
    int posX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosX() + deltaX; // first call
    int posY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->getPosY() + deltaY; // second call

    if(GlobalEnvirIn::Instance()->__isThereHasChess(posX, posY)) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeBackChangeChessPos() line: 185  Back Pos Has Chess! " << posX << "," << posY << " " << chessName << number;
        return;
    }

    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosX(posX);
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessName, number)->setPosY(posY);

    if(chessName == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL || chessName == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) {
        GlobalEnvirIn::Instance()->__refershPosValueUnit();
    }
}

void Qml_Connection::fakeBackChangeChessPos(QString chessName, int number, bool camp, int deltaX, int deltaY) {
    int chessNameInt = GlobalEnvirIn::Instance()->__QStr2intName(chessName);
    if(chessNameInt == -1) {
        qDebug() << "ERROR! Qml_Connection.cpp fakeBackChangeChessPos() line: 195";
        return;
    }
    fakeBackChangeChessPos(chessNameInt, number, camp, deltaX ,deltaY); // call other function
}

void Qml_Connection::setWinnerWhenOnlyGeneralsInRow(bool redOrBlack) {
    if(redOrBlack) object->setProperty("onlyTwoGeneralsInRow_redWin", true);
    else object->setProperty("onlyTwoGeneralsInRow_blackWin", true);
}

void Qml_Connection::setEndGameMode(bool isInEndGameMode) {
    isEndGameMode = isInEndGameMode;
    object->setProperty("is_endgame_mode", isInEndGameMode);
}

void Qml_Connection::setWhetherVisionDone(bool isVisionDone) {
    if(isEndGameMode == false) {
        qDebug() << "Qml_Connection.cpp function:setWhetherVisionDone() line:210 EngGameMode = false!!!!!";
    }
    else object->setProperty("is_vision_board_done", isVisionDone);
}

void Qml_Connection::eraseChessOnCanvas(int num, int number) {
    object->setProperty((GlobalEnvirIn::Instance()->__int2QStrName(num) +
                         QString::number(number) + QString("_alive")).toLatin1(), false);
}

void Qml_Connection::moveChessOnCanvas(int num, int number) {
    QString chessName = GlobalEnvirIn::Instance()->__int2QStrName(num) + QString::number(number);
    int PosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(num, number)->getPosX();
    int PosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(num, number)->getPosY();
    object->setProperty((chessName + QString("_posX")).toLatin1(), coordinateIn::Instance()->tranRealPosX(PosX));
    object->setProperty((chessName + QString("_posY")).toLatin1(), coordinateIn::Instance()->tranRealPosY(PosY));
    if(num == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL || num == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) {
        GlobalEnvirIn::Instance()->__refershPosValueUnit();
    }
}

void Qml_Connection::whetherStrategyMode(bool curStrategyMode) {
    object->setProperty("is_strategy_mode", curStrategyMode);
}

void Qml_Connection::setStrategyMode(int curStrategyMode) {
    object->setProperty("strategy_mode", curStrategyMode);
}
