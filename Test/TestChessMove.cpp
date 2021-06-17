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
    object->setProperty("b_gen_1_alive", false);
    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL, 1)->setAlive(false);
    std::cout << GlobalEnvirIn::Instance()->__BoardEvaluate() << std::endl;
}

void TestChessMove::testIsThereOurChess() {
    std::cout << "TEST_MODE -> testIsThereOurChess()" << std::endl;
    bool test = GlobalEnvirIn::Instance()->__isThereHasOurChess(false, 9, 0);
    if(test) std::cout << "TRUE!!!" << std::endl;
}

void TestChessMove::testWhichChessOnThere() {
    std::cout << "TEST_MODE -> testWhichChessOnThere()" << std::endl;
    QString chessName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(0, 4)->chessName());
    int chessNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(0, 4)->chessNumber();
    std::cout << chessName.toStdString() << chessNumber << std::endl;
}

void TestChessMove::testMemory() {
    std::cout << "TEST_MODE -> testMemory()" << std::endl;
    QVector<chessStep*> test;
    test.clear();
    while(true) {
//        singleGameIn::Instance()->generateRedAllPossibleMoves();
//        singleGameIn::Instance()->generateBlackAllPossibleMoves();
        QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(Ab_gen_1->chessName());
        int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
        Ab_gen_1->generateMove();
        Ab_adv_1->generateMove();
        Ab_ele_1->generateMove(); ////////////////////////////
        Ab_hor_1->generateMove();
        Ab_cha_1->generateMove();
        Ab_can_1->generateMove();
        Ab_sol_1->generateMove();
        chessStep* temp = new chessStep(-1, -1, false, -1, -1, false, -1, -1);
        test.append(temp);
        delete temp;
        test.clear();
    }
}

void TestChessMove::testDBG() {
    GlobalEnvirIn::Instance()->__isThereHasChess(NULL);
}

void TestChessMove::testHorseGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(2, 2);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, Pos);
    delete Pos;
    std::cout << "TEST_MODE -> testHorseGenerateMove()" << std::endl;
    Ab_hor_1->generateMove();
    int countMove = Ab_hor_1->chessStepList.size();
    std::cout << "Ab_hor_1 -> " << countMove << std::endl;
    Ab_hor_1->printStepList();
}

void TestChessMove::testElephantGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(7, 4);
    SGeoPoint* PosTest = new SGeoPoint(8, 3);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, PosTest);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, Pos);
    delete Pos;
    delete PosTest;
    std::cout << "TEST_MODE -> testElephantGenerateMove()" << std::endl;
    Ar_ele_1->generateMove();
    int countMove = Ar_ele_1->chessStepList.size();
    std::cout << "Ar_ele_1 -> " << countMove << std::endl;
    Ar_ele_1->printStepList();
}

void TestChessMove::testGeneralGenerateMove() {
    SGeoPoint* PosTest = new SGeoPoint(7, 5);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, PosTest);
    SGeoPoint* Pos = new SGeoPoint(8, 5);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, Pos);
    delete Pos;
    delete PosTest;
    std::cout << "TEST_MODE -> testGeneralGenerateMove()" << std::endl;
    Ar_gen_1->generateMove();
    int countMove = Ar_gen_1->chessStepList.size();
    std::cout << "Ar_gen_1 -> " << countMove << std::endl;
    Ar_gen_1->printStepList();
}

void TestChessMove::testSoldierGenerateMove() {
//    SGeoPoint* PosTest = new SGeoPoint(5, 3);
//    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, false, PosTest);
    SGeoPoint* Pos = new SGeoPoint(5, 5);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, Pos);
    SGeoPoint* PosTT = new SGeoPoint(5, 4);
    QmlConnectIn::Instance()->changeChessPos("b_sol_", 3, false, PosTT);
    delete Pos;
    delete PosTT;
    std::cout << "TEST_MODE -> testGeneralGenerateMove()" << std::endl;
    Ab_sol_3->generateMove();
    int countMove = Ab_sol_3->chessStepList.size();
    std::cout << "Ab_sol_3 -> " << countMove << std::endl;
    Ab_sol_3->printStepList();
}

void TestChessMove::testAdvisorGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(1, 4);
    QmlConnectIn::Instance()->changeChessPos("b_adv_", 2, false, Pos);
    SGeoPoint* PosTT = new SGeoPoint(2, 3);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, PosTT);
    delete Pos;
    delete PosTT;
    std::cout << "TEST_MODE -> testAdvisorGenerateMove()" << std::endl;
    Ab_adv_2->generateMove();
    int countMove = Ab_adv_2->chessStepList.size();
    std::cout << "Ab_adv_2 -> " << countMove << std::endl;
    Ab_adv_2->printStepList();
}

void TestChessMove::testChariotGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(PARAM::globalEnvironment::middleRed, 4 + 1);
    QmlConnectIn::Instance()->changeChessPos("r_cha_", 2, true, Pos);
    SGeoPoint* PosTT = new SGeoPoint(PARAM::globalEnvironment::middleRed, PARAM::globalEnvironment::maxAxisOfY);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, PosTT);
    delete Pos;
    delete PosTT;
    std::cout << "TEST_MODE -> testChariotGenerateMove()" << std::endl;
    Ar_cha_2->generateMove();
    int countMove = Ar_cha_2->chessStepList.size();
    std::cout << "Ar_cha_2 -> " << countMove << std::endl;
    Ar_cha_2->printStepList();
}

void TestChessMove::testCannonGenerateMove() {
//    SGeoPoint* Pos = new SGeoPoint(PARAM::globalEnvironment::middleRed, 4 + 1);
//    QmlConnectIn::Instance()->changeChessPos("r_cha_", 2, true, Pos);
//    SGeoPoint* PosTT = new SGeoPoint(PARAM::globalEnvironment::middleRed, PARAM::globalEnvironment::maxAxisOfY);
//    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, PosTT);
    std::cout << "TEST_MODE -> testCannonGenerateMove()" << std::endl;
    Ar_can_2->generateMove();
    int countMove = Ar_can_2->chessStepList.size();
    std::cout << "Ar_can_2 -> " << countMove << std::endl;
    Ar_can_2->printStepList();
}

void TestChessMove::S_HorseGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(2, 2);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, Pos);
    delete Pos;
    std::cout << "TEST_MODE -> S_HorseGenerateMove()" << std::endl;
    Ab_hor_1->generateMove();
    int countMove = Ab_hor_1->SchessStepList.size();
    std::cout << "Ab_hor_1 -> " << countMove << std::endl;
    Ab_hor_1->SprintStepList();
}

void TestChessMove::S_ElephantGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(7, 4);
    SGeoPoint* PosTest = new SGeoPoint(8, 3);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, PosTest);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, Pos);
    delete Pos;
    delete PosTest;
    std::cout << "TEST_MODE -> S_ElephantGenerateMove()" << std::endl;
    Ar_ele_1->generateMove();
    int countMove = Ar_ele_1->SchessStepList.size();
    std::cout << "Ar_ele_1 -> " << countMove << std::endl;
    Ar_ele_1->SprintStepList();
}

void TestChessMove::S_GeneralGenerateMove() {
    SGeoPoint* PosTest = new SGeoPoint(7, 5);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, PosTest);
    SGeoPoint* Pos = new SGeoPoint(8, 5);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, Pos);
    delete Pos;
    delete PosTest;
    std::cout << "TEST_MODE -> S_GeneralGenerateMove()" << std::endl;
    Ar_gen_1->generateMove();
    int countMove = Ar_gen_1->SchessStepList.size();
    std::cout << "Ar_gen_1 -> " << countMove << std::endl;
    Ar_gen_1->SprintStepList();
}

void TestChessMove::S_SoldierGenerateMove() {
//    SGeoPoint* PosTest = new SGeoPoint(5, 3);
//    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, false, PosTest);
    SGeoPoint* Pos = new SGeoPoint(5, 5);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, Pos);
    SGeoPoint* PosTT = new SGeoPoint(5, 4);
    QmlConnectIn::Instance()->changeChessPos("b_sol_", 3, false, PosTT);
    delete Pos;
    delete PosTT;
    std::cout << "TEST_MODE -> S_SoldierGenerateMove()" << std::endl;
    Ab_sol_3->generateMove();
    int countMove = Ab_sol_3->SchessStepList.size();
    std::cout << "Ab_sol_3 -> " << countMove << std::endl;
    Ab_sol_3->SprintStepList();
}

void TestChessMove::S_AdvisorGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(1, 4);
    QmlConnectIn::Instance()->changeChessPos("b_adv_", 2, false, Pos);
    SGeoPoint* PosTT = new SGeoPoint(2, 3);
    QmlConnectIn::Instance()->changeChessPos("r_gen_", 1, true, PosTT);
    delete Pos;
    delete PosTT;
    std::cout << "TEST_MODE -> S_AdvisorGenerateMove()" << std::endl;
    Ab_adv_2->generateMove();
    int countMove = Ab_adv_2->SchessStepList.size();
    std::cout << "Ab_adv_2 -> " << countMove << std::endl;
    Ab_adv_2->SprintStepList();
}

void TestChessMove::S_ChariotGenerateMove() {
    SGeoPoint* Pos = new SGeoPoint(PARAM::globalEnvironment::middleRed, 4 + 1);
    QmlConnectIn::Instance()->changeChessPos("r_cha_", 2, true, Pos);
    SGeoPoint* PosTT = new SGeoPoint(PARAM::globalEnvironment::middleRed, PARAM::globalEnvironment::maxAxisOfY);
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, PosTT);
    delete Pos;
    delete PosTT;
    std::cout << "TEST_MODE -> S_ChariotGenerateMove()" << std::endl;
    Ar_cha_2->generateMove();
    int countMove = Ar_cha_2->SchessStepList.size();
    std::cout << "Ar_cha_2 -> " << countMove << std::endl;
    Ar_cha_2->SprintStepList();
}

void TestChessMove::S_CannonGenerateMove() {
//    SGeoPoint* Pos = new SGeoPoint(PARAM::globalEnvironment::middleRed, 4 + 1);
//    QmlConnectIn::Instance()->changeChessPos("r_cha_", 2, true, Pos);
//    SGeoPoint* PosTT = new SGeoPoint(PARAM::globalEnvironment::middleRed, PARAM::globalEnvironment::maxAxisOfY);
//    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, PosTT);
    std::cout << "TEST_MODE -> S_CannonGenerateMove()" << std::endl;
    Ar_can_2->generateMove();
    int countMove = Ar_can_2->SchessStepList.size();
    std::cout << "Ar_can_2 -> " << countMove << std::endl;
    Ar_can_2->SprintStepList();
}


void TestChessMove::testQVectorAdding() {
    std::cout << "TEST_MODE -> testQVectorAdding()" << std::endl;
    QVector<int> v1 = {1, 2, 3};
    QVector<int> v2 = {4, 5, 6};
//    int a = 999;
//    v1.insert(v1.size(), a);
    v1.append(v2);
    for(int index = 0; index < v1.size(); index++)
        std::cout << v1.at(index) << " " << std::endl;
}

void TestChessMove::testDisplayAllPossibleMoves() {
    std::cout << "TEST_MODE -> testDisplayAllPossibleMoves()" << std::endl;
    singleGameIn::Instance()->displayBlackAllPossibleMoves();
    singleGameIn::Instance()->displayRedAllPossibleMoves();
}

void TestChessMove::S_DisplayAllPossibleMoves() {
    std::cout << "TEST_MODE -> S_DisplayAllPossibleMoves()" << std::endl;
    singleGameIn::Instance()->SdisplayBlackAllPossibleMoves();
    singleGameIn::Instance()->SdisplayRedAllPossibleMoves();
}

void TestChessMove::testChessing() { // can not use!
    std::cout << "TEST_MODE -> testChessing()" << std::endl;
    bool gameIsOn = true;
    bool redOrBlack = false;
    while(gameIsOn) {
        testDisplayAllPossibleMoves();
        Step* red = singleGameIn::Instance()->chessRedStepList.at(singleGameIn::Instance()->chessRedStepList.size()/2);
        Step* black = singleGameIn::Instance()->chessBlackStepList.at(singleGameIn::Instance()->chessBlackStepList.size()/2);
        if(redOrBlack) red->executeStep();
        else black->executeStep();
        GlobalEnvirIn::Instance()->__delayMsec(1000);
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        redOrBlack = !redOrBlack;
    }
}

void TestChessMove::testChessingNew() {
    std::cout << "TEST_MODE -> testChessingNew()" << std::endl;
    singleGameIn::Instance()->testChessing();
}

void TestChessMove::testWin() {
//    GlobalEnvirIn::Instance()->__delayMsec(2000);
    std::cout << "TEST_MODE -> testWin()" << std::endl;
//    GlobalEnvirIn::Instance()->__killThisChess(8, 1);
    int DeltaX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(8, 1)->getPosX() - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(1, 1)->getPosX();
    int DeltaY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(8, 1)->getPosY() - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(1, 1)->getPosY();
    QmlConnectIn::Instance()->changeChessPos("b_gen_", 1, false, DeltaX, DeltaY);
    GlobalEnvirIn::Instance()->__printBoard();
}

void TestChessMove::test_Ar_hor_2_isAlive() {
    GlobalEnvirIn::Instance()->__fakeKillThisChess(11, 2);
    std::cout << (Ar_hor_2->isAlive() ? "Yes" : "No") << std::endl;
}

void TestChessMove::testMouseMoveChess() {
    std::cout << "TEST_MODE -> testMouseMoveChess()" << std::endl;
    int lastPosX = 9999;
    int lastPosY = 9999;
    int posx = 0;
    int posy = 0;
    while(true) {
        QVariant x = object->property("lastMousePosX");
        QVariant y = object->property("lastMousePosY");
        if(lastPosX == 9999 && lastPosY == 9999) {
            lastPosX = x.toInt();
            lastPosY = y.toInt();
            posx = coordinateIn::Instance()->transferPosX(lastPosX);
            posy = coordinateIn::Instance()->transferPosY(lastPosY);
            std::cout << "x = " << x.toInt() << "   y = " << y.toInt() << std::endl;
            std::cout << "posx = " << posx << "   posy = " << posy << std::endl;
            // std::cout << GlobalEnvirIn::Instance()->__whichChessOnThere(posx, posy)->chessName().toStdString() << " " << GlobalEnvirIn::Instance()->__whichChessOnThere(posx, posy)->chessNumber() << std::endl;
        }
        if(lastPosX != x.toInt() || lastPosY != y.toInt()) {
            lastPosX = x.toInt();
            lastPosY = y.toInt();
            posx = coordinateIn::Instance()->transferPosX(lastPosX);
            posy = coordinateIn::Instance()->transferPosY(lastPosY);
            object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(posx));
            object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(posy));
            std::cout << "x = " << x.toInt() << "   y = " << y.toInt() << std::endl;
            std::cout << "posx = " << posx << "   posy = " << posy << std::endl;
            // std::cout << GlobalEnvirIn::Instance()->__whichChessOnThere(posx, posy)->chessName().toStdString() << " " << GlobalEnvirIn::Instance()->__whichChessOnThere(posx, posy)->chessNumber() << std::endl;
        }
        GlobalEnvirIn::Instance()->__delayMsec(100);
    }
}

void TestChessMove::testHumanMove() {
    std::cout << "TEST_MODE -> testHumanMove()" << std::endl;
    singleGameIn::Instance()->generateRedAllPossibleMoves();
    while(!singleGameIn::Instance()->humanMove());
}

void TestChessMove::testMultiProcess() {
    PythonMuduleIn::Instance()->test();
}
