#ifndef QML_CONNECTION_H
#define QML_CONNECTION_H

/*****************************************************************
*   File:     Qml_Connection.h
*   Author:   Haodong LI
*   Usage:    connect with qml file to change the position of chesses,
*             change the position and info of all chess board and update
*   Time:     2021-05-31 -> 13:59:25
*****************************************************************/

//#include "singleton.h"
//#include "Params.h"
#include "global.h"
#include "coordinate.h"

class Qml_Connection
{
public:
    Qml_Connection();
    virtual void changeChessPos(int chessName, SGeoPoint* Pos) {object->setProperty("b_sol_1_posX", coordinateIn::Instance()->tranRealPosX(7));};
    virtual void changeChessPos(QString chessName, SGeoPoint* Pos){};
    virtual void changeChessPos(int chessName, int deltaX, int deltaY){};
    virtual void changeChessPos(QString chessName, int deltaX, int deltaY){};
};

typedef NormalSingleton< Qml_Connection > QmlConnectIn;

#endif // QML_CONNECTION_H
