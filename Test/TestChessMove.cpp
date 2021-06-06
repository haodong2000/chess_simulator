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
        GlobalEnvirIn::Instance()->__delayMsec(500);
        QmlConnectIn::Instance()->changeChessPos("b_sol_", 1, true, temp, 0);
        temp *= -1;
        GlobalEnvirIn::Instance()->__printBoard();
    }
    return;
}

void TestChessMove::turnSwitch(int indexSwitch) {
    std::cout << "TEST_MODE -> turnSwitch()" << std::endl;
    int index = 0;
    bool curTurn = false;
    while(index++ < indexSwitch) {
        GlobalEnvirIn::Instance()->__delayMsec(500);
        object->setProperty("ai_turn", curTurn);
        curTurn = !curTurn;
    }
    return;
}

void TestChessMove::testEvaluate() {
    std::cout << "TEST_MODE -> testEvaluate()" << std::endl;
    object->setProperty("b_gen_alive", false);
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL, 1)->setAlive(false);
    std::cout << GlobalEnvirIn::Instance()->__BoardEvaluate() << std::endl;
}
