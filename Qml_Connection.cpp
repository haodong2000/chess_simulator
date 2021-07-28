#include "Qml_Connection.h"

/*****************************************************************
*   File:     Qml_Connection.cpp
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-31 -> 20:29:48
*****************************************************************/

Qml_Connection::Qml_Connection()
{

}

void Qml_Connection::changeChessPos(int chessName, int number, bool camp, SGeoPoint *Pos) {
    // number already contain the infomation of camp, chessName also contains
    QString name = GlobalEnvirIn::Instance()->__int2QStrName(chessName) + QString::number(number);
    if(name.isEmpty()) {
        qDebug() << "ERROR! Qml_Connection.cpp changeChessPos() line: 17";
        return;
    }

    if(GlobalEnvirIn::Instance()->__isThereHasChess(Pos)) {
        killThisChess(Pos);
    }

    object->setProperty((name + QString("_posX")).toLatin1(), coordinateIn::Instance()->tranRealPosX(Pos->getPosX()));
    object->setProperty((name + QString("_posY")).toLatin1(), coordinateIn::Instance()->tranRealPosY(Pos->getPosY()));
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

    if(GlobalEnvirIn::Instance()->__isThereHasChess(posX, posY)) {
        killThisChess(posX, posY);
    }

    object->setProperty((name + QString("_posX")).toLatin1(), coordinateIn::Instance()->tranRealPosX(posX));
    object->setProperty((name + QString("_posY")).toLatin1(), coordinateIn::Instance()->tranRealPosY(posY));
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

