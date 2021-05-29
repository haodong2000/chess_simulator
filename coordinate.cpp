#include "coordinate.h"
//#include "Params.h"

coordinate::coordinate()
{

}

//int coordinate::transferPosX(double originPosX) {
//    // pre-process
//    double preX = (originPosX - globalEnvironment::cubeSizeWidth/2.0)/globalEnvironment::cubeSizeWidth;
//    return qRound(preX);
//}

//int coordinate::transferPosY(double originPosY) {
//    double preY = (originPosY - globalEnvironment::cubeSizeHeight/2.0)/globalEnvironment::cubeSizeHeight;
//    return qRound(preY);
//}

//SGeoPoint coordinate::tranPos(double originPosX, double originPosY) {
//    return SGeoPoint(transferPosX(originPosX), transferPosY(originPosY));
//}

//double coordinate::tranRealPosX(SGeoPoint* Pos) {
//    int x = Pos->getPosX();
//    int y = Pos->getPosY();
//    double retVal = globalEnvironment::cubeSizeWidth * (x + 0.5);
//    return retVal;
//}

//double coordinate::tranRealPosY(SGeoPoint* Pos) {
//    int x = Pos->getPosX();
//    int y = Pos->getPosY();
//    double retVal = globalEnvironment::cubeSizeHeight * (y + 0.5);
//    return retVal;
//}
