#include "TestChessMove.h"
#include "global.h"
#include "Qml_Connection.h"
#include <iostream>

TestChessMove::TestChessMove()
{

}

void TestChessMove::LoopMove(int indexMaxIn) {
    std::cout << "TEST_MODE -> LoopMove()" << std::endl;
    int index = 0;
    int indexMax = indexMaxIn;
    int temp = 1;
    while(index++ < indexMax) {
        GlobalEnvirIn::Instance()->delayMsec(500);
        QmlConnectIn::Instance()->changeChessPos("b_sol_", 1, true, temp, 0);
        temp *= -1;
        GlobalEnvirIn::Instance()->__printBoard();
    }
    return;
}
