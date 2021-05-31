#include "coordinate.h"
#include "global.h"
#include <QtMath>

coordinate::coordinate()
{

}

int coordinate::transferPosX(double originPosX) {
    // PARAM::chessPos::black::General::x = 0; // test
    // pre-process
    double preX = (originPosX - PARAM::globalEnvironment::cubeSizeWidth/2.0)/PARAM::globalEnvironment::cubeSizeWidth;
    return qRound(preX);
}

int coordinate::transferPosY(double originPosY) {
    double preY = (originPosY - PARAM::globalEnvironment::cubeSizeHeight/2.0)/PARAM::globalEnvironment::cubeSizeHeight;
    return qRound(preY);
}

SGeoPoint coordinate::tranPos(double originPosX, double originPosY) {
    return SGeoPoint(transferPosX(originPosX), transferPosY(originPosY));
}

double coordinate::tranRealPosX(SGeoPoint* Pos) {
    int x = Pos->getPosX();
    int y = Pos->getPosY();
    double retVal = PARAM::globalEnvironment::cubeSizeWidth * (x + 0.5) - PARAM::chessInitPos::chessSize/2.0;
    return retVal;
}

double coordinate::tranRealPosY(SGeoPoint* Pos) {
    int x = Pos->getPosX();
    int y = Pos->getPosY();
    double retVal = PARAM::globalEnvironment::cubeSizeHeight * (y + 0.5) - PARAM::chessInitPos::chessSize/2.0;
    return retVal;
}

double coordinate::tranRealPosX(int PosX) {
    return PARAM::globalEnvironment::cubeSizeWidth * (PosX + 0.5) - PARAM::chessInitPos::chessSize/2.0;
}

double coordinate::tranRealPosY(int PosY) {
    return PARAM::globalEnvironment::cubeSizeHeight * (PosY + 0.5) - PARAM::chessInitPos::chessSize/2.0;
}
