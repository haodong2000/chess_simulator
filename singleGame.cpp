﻿#include "singleGame.h"

singleGame::singleGame():
    Step_RL(chessStep(-1, -1, false, 0, 0)),
    redCurStep (chessStep(-1, -1, false, 0, 0)),
    redLastStep(chessStep(-1, -1, false, 0, 0)),
    blackCurStep (chessStep(-1, -1, false, 0, 0)),
    blackLastStep(chessStep(-1, -1, false, 0, 0))
{
    finalChessStep = new Step(-1, -1, false, 0, 0, false);
//    redCurStep    = chessStep(-1, -1, false, 0, 0);
//    redLastStep   = chessStep(-1, -1, false, 0, 0);
//    blackCurStep  = chessStep(-1, -1, false, 0, 0);
//    blackLastStep = chessStep(-1, -1, false, 0, 0);
    chessBlackStepList.clear();
    originBlackChessStepList.clear();
    chessRedStepList.clear();
    originRedChessStepList.clear();
    SoriginRedChessStepList.clear();
    SoriginBlackChessStepList.clear();
//    allRedAndBlackStepList.clear();

    _level = SEARCH_DEPTH - 1; // initialization, actuall level is 4
    _strategy_mode = STRATEGY_MODE;
    R_value = 1;
    COUNT_RED = 0;
    COUNT_BLACK = 0;
    _redLevel = _level;
    _blackLevel = _level;

    M1_client->connectToHost(PARAM::M1_HOST, PARAM::M1_PORT);
    if(M1_client->waitForConnected(10000)) {
        qDebug() << "M1_ROBOT" << " Connected!";
    }
    else {
        qDebug() << "M1_ROBOT" << " Connection Failed!!!";
    }
    //connect(M1_client, SIGNAL(disconnected()), this, SLOT(M1_client_disconnect()));
}

void singleGame::setLevel(int level) {
    _level = level;
}

int singleGame::getLevel() {
    return _level;
}

void singleGame::generateBlackAllPossibleMoves() {
    Ab_hor_1->generateMove();
    Ab_can_1->generateMove();
    Ab_adv_1->generateMove();
    Ab_cha_1->generateMove();
    Ab_ele_1->generateMove();
    Ab_hor_2->generateMove();
    Ab_can_2->generateMove();
    Ab_adv_2->generateMove();
    Ab_cha_2->generateMove();
    Ab_ele_2->generateMove();

    Ab_sol_1->generateMove();
    Ab_sol_2->generateMove();
    Ab_sol_3->generateMove();
    Ab_sol_4->generateMove();
    Ab_sol_5->generateMove();

    Ab_gen_1->generateMove();

    originBlackChessStepList.clear();
    SoriginBlackChessStepList.clear();

    originBlackChessStepList.append(Ab_hor_1->chessStepList);
    originBlackChessStepList.append(Ab_can_1->chessStepList);
    originBlackChessStepList.append(Ab_adv_1->chessStepList);
    originBlackChessStepList.append(Ab_cha_1->chessStepList);
    originBlackChessStepList.append(Ab_ele_1->chessStepList);
    originBlackChessStepList.append(Ab_hor_2->chessStepList);
    originBlackChessStepList.append(Ab_can_2->chessStepList);
    originBlackChessStepList.append(Ab_adv_2->chessStepList);
    originBlackChessStepList.append(Ab_cha_2->chessStepList);
    originBlackChessStepList.append(Ab_ele_2->chessStepList);

    originBlackChessStepList.append(Ab_sol_1->chessStepList);
    originBlackChessStepList.append(Ab_sol_2->chessStepList);
    originBlackChessStepList.append(Ab_sol_3->chessStepList);
    originBlackChessStepList.append(Ab_sol_4->chessStepList);
    originBlackChessStepList.append(Ab_sol_5->chessStepList);

    originBlackChessStepList.append(Ab_gen_1->chessStepList);

    Ab_hor_1->chessStepList.clear();
    Ab_can_1->chessStepList.clear();
    Ab_adv_1->chessStepList.clear();
    Ab_cha_1->chessStepList.clear();
    Ab_ele_1->chessStepList.clear();
    Ab_hor_2->chessStepList.clear();
    Ab_can_2->chessStepList.clear();
    Ab_adv_2->chessStepList.clear();
    Ab_cha_2->chessStepList.clear();
    Ab_ele_2->chessStepList.clear();

    Ab_sol_1->chessStepList.clear();
    Ab_sol_2->chessStepList.clear();
    Ab_sol_3->chessStepList.clear();
    Ab_sol_4->chessStepList.clear();
    Ab_sol_5->chessStepList.clear();

    Ab_gen_1->chessStepList.clear();

    SoriginBlackChessStepList.append(Ab_hor_1->SchessStepList);
    SoriginBlackChessStepList.append(Ab_can_1->SchessStepList);
    SoriginBlackChessStepList.append(Ab_adv_1->SchessStepList);
    SoriginBlackChessStepList.append(Ab_cha_1->SchessStepList);
    SoriginBlackChessStepList.append(Ab_ele_1->SchessStepList);
    SoriginBlackChessStepList.append(Ab_hor_2->SchessStepList);
    SoriginBlackChessStepList.append(Ab_can_2->SchessStepList);
    SoriginBlackChessStepList.append(Ab_adv_2->SchessStepList);
    SoriginBlackChessStepList.append(Ab_cha_2->SchessStepList);
    SoriginBlackChessStepList.append(Ab_ele_2->SchessStepList);

    SoriginBlackChessStepList.append(Ab_sol_1->SchessStepList);
    SoriginBlackChessStepList.append(Ab_sol_2->SchessStepList);
    SoriginBlackChessStepList.append(Ab_sol_3->SchessStepList);
    SoriginBlackChessStepList.append(Ab_sol_4->SchessStepList);
    SoriginBlackChessStepList.append(Ab_sol_5->SchessStepList);

    SoriginBlackChessStepList.append(Ab_gen_1->SchessStepList);

    Ab_hor_1->SchessStepList.clear();
    Ab_can_1->SchessStepList.clear();
    Ab_adv_1->SchessStepList.clear();
    Ab_cha_1->SchessStepList.clear();
    Ab_ele_1->SchessStepList.clear();
    Ab_hor_2->SchessStepList.clear();
    Ab_can_2->SchessStepList.clear();
    Ab_adv_2->SchessStepList.clear();
    Ab_cha_2->SchessStepList.clear();
    Ab_ele_2->SchessStepList.clear();

    Ab_sol_1->SchessStepList.clear();
    Ab_sol_2->SchessStepList.clear();
    Ab_sol_3->SchessStepList.clear();
    Ab_sol_4->SchessStepList.clear();
    Ab_sol_5->SchessStepList.clear();

    Ab_gen_1->SchessStepList.clear();
}

void singleGame::generateRedAllPossibleMoves() {
    Ar_hor_1->generateMove();
    Ar_can_1->generateMove();
    Ar_adv_1->generateMove();
    Ar_cha_1->generateMove();
    Ar_ele_1->generateMove();
    Ar_hor_2->generateMove();
    Ar_can_2->generateMove();
    Ar_adv_2->generateMove();
    Ar_cha_2->generateMove();
    Ar_ele_2->generateMove();

    Ar_sol_1->generateMove();
    Ar_sol_2->generateMove();
    Ar_sol_3->generateMove();
    Ar_sol_4->generateMove();
    Ar_sol_5->generateMove();

    Ar_gen_1->generateMove();

    originRedChessStepList.clear();
    SoriginRedChessStepList.clear();

    originRedChessStepList.append(Ar_hor_1->chessStepList);
    originRedChessStepList.append(Ar_can_1->chessStepList);
    originRedChessStepList.append(Ar_adv_1->chessStepList);
    originRedChessStepList.append(Ar_cha_1->chessStepList);
    originRedChessStepList.append(Ar_ele_1->chessStepList);
    originRedChessStepList.append(Ar_hor_2->chessStepList);
    originRedChessStepList.append(Ar_can_2->chessStepList);
    originRedChessStepList.append(Ar_adv_2->chessStepList);
    originRedChessStepList.append(Ar_cha_2->chessStepList);
    originRedChessStepList.append(Ar_ele_2->chessStepList);
    originRedChessStepList.append(Ar_sol_1->chessStepList);
    originRedChessStepList.append(Ar_sol_2->chessStepList);
    originRedChessStepList.append(Ar_sol_3->chessStepList);
    originRedChessStepList.append(Ar_sol_4->chessStepList);
    originRedChessStepList.append(Ar_sol_5->chessStepList);
    originRedChessStepList.append(Ar_gen_1->chessStepList);

    Ar_hor_1->chessStepList.clear();
    Ar_can_1->chessStepList.clear();
    Ar_adv_1->chessStepList.clear();
    Ar_cha_1->chessStepList.clear();
    Ar_ele_1->chessStepList.clear();
    Ar_hor_2->chessStepList.clear();
    Ar_can_2->chessStepList.clear();
    Ar_adv_2->chessStepList.clear();
    Ar_cha_2->chessStepList.clear();
    Ar_ele_2->chessStepList.clear();

    Ar_sol_1->chessStepList.clear();
    Ar_sol_2->chessStepList.clear();
    Ar_sol_3->chessStepList.clear();
    Ar_sol_4->chessStepList.clear();
    Ar_sol_5->chessStepList.clear();

    Ar_gen_1->chessStepList.clear();

    SoriginRedChessStepList.append(Ar_hor_1->SchessStepList);
    SoriginRedChessStepList.append(Ar_can_1->SchessStepList);
    SoriginRedChessStepList.append(Ar_adv_1->SchessStepList);
    SoriginRedChessStepList.append(Ar_cha_1->SchessStepList);
    SoriginRedChessStepList.append(Ar_ele_1->SchessStepList);
    SoriginRedChessStepList.append(Ar_hor_2->SchessStepList);
    SoriginRedChessStepList.append(Ar_can_2->SchessStepList);
    SoriginRedChessStepList.append(Ar_adv_2->SchessStepList);
    SoriginRedChessStepList.append(Ar_cha_2->SchessStepList);
    SoriginRedChessStepList.append(Ar_ele_2->SchessStepList);

    SoriginRedChessStepList.append(Ar_sol_1->SchessStepList);
    SoriginRedChessStepList.append(Ar_sol_2->SchessStepList);
    SoriginRedChessStepList.append(Ar_sol_3->SchessStepList);
    SoriginRedChessStepList.append(Ar_sol_4->SchessStepList);
    SoriginRedChessStepList.append(Ar_sol_5->SchessStepList);

    SoriginRedChessStepList.append(Ar_gen_1->SchessStepList);

    Ar_hor_1->SchessStepList.clear();
    Ar_can_1->SchessStepList.clear();
    Ar_adv_1->SchessStepList.clear();
    Ar_cha_1->SchessStepList.clear();
    Ar_ele_1->SchessStepList.clear();
    Ar_hor_2->SchessStepList.clear();
    Ar_can_2->SchessStepList.clear();
    Ar_adv_2->SchessStepList.clear();
    Ar_cha_2->SchessStepList.clear();
    Ar_ele_2->SchessStepList.clear();

    Ar_sol_1->SchessStepList.clear();
    Ar_sol_2->SchessStepList.clear();
    Ar_sol_3->SchessStepList.clear();
    Ar_sol_4->SchessStepList.clear();
    Ar_sol_5->SchessStepList.clear();

    Ar_gen_1->SchessStepList.clear();
}

void singleGame::displayBlackAllPossibleMoves() {
    generateBlackAllPossibleMoves();

    if(originBlackChessStepList.size() == 0) {
        qDebug() << "singleGame.cpp line:99 displayBlackAllPossibleMoves() error: originBlackChessStepList is EMPTY!!!!!";
        return;
    }

    int size = originBlackChessStepList.size();
    for(int i = 0; i < size; i++) {
        std::cout << "=================== <" << i << "> ===================" << std::endl;
        int Num = originBlackChessStepList.at(i)._chessNum;
        int Number = originBlackChessStepList.at(i)._chessNumber;
        int PosX = originBlackChessStepList.at(i)._deltaX;
        int PosY = originBlackChessStepList.at(i)._deltaY;
        bool kill = originBlackChessStepList.at(i)._isKill;
        QString killString = kill ? "True" : "False";
        int killNum = originBlackChessStepList.at(i)._chessKilledNum;
        int killNumber = originBlackChessStepList.at(i)._chessKilledNumber;
        std::cout << "B_Num\t = " << Num << std::endl;
        std::cout << "B_Number\t = " << Number << std::endl;
        std::cout << "B_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
        std::cout << "B_PosX\t = " << PosX << std::endl;
        std::cout << "B_PosY\t = " << PosY << std::endl;
        std::cout << "B_kill\t = " << killString.toStdString() << std::endl;
        if(kill) {
            std::cout << "B_k_Num\t = " << killNum << std::endl;
            std::cout << "B_k_Number\t = " << killNumber << std::endl;
            std::cout << "B_k_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
        }
    }
}

void singleGame::displayRedAllPossibleMoves() {
    generateRedAllPossibleMoves();

    if(originRedChessStepList.size() == 0) {
        qDebug() << "singleGame.cpp line:99 displayBlackAllPossibleMoves() error: originRedChessStepList is EMPTY!!!!!";
        return;
    }

    int size = originRedChessStepList.size();
    for(int i = 0; i < size; i++) {
        std::cout << "=================== <" << i << "> ===================" << std::endl;
        int Num = originRedChessStepList.at(i)._chessNum;
        int Number = originRedChessStepList.at(i)._chessNumber;
        int PosX = originRedChessStepList.at(i)._deltaX;
        int PosY = originRedChessStepList.at(i)._deltaY;
        bool kill = originRedChessStepList.at(i)._isKill;
        QString killString = kill ? "True" : "False";
        int killNum = originRedChessStepList.at(i)._chessKilledNum;
        int killNumber = originRedChessStepList.at(i)._chessKilledNumber;
        std::cout << "R_Num\t = " << Num << std::endl;
        std::cout << "R_Number\t = " << Number << std::endl;
        std::cout << "R_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
        std::cout << "R_PosX\t = " << PosX << std::endl;
        std::cout << "R_PosY\t = " << PosY << std::endl;
        std::cout << "R_kill\t = " << killString.toStdString() << std::endl;
        if(kill) {
            std::cout << "R_k_Num\t = " << killNum << std::endl;
            std::cout << "R_k_Number\t = " << killNumber << std::endl;
            std::cout << "R_k_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
        }
    }
}

void singleGame::SdisplayBlackAllPossibleMoves() {
    generateBlackAllPossibleMoves();

    if(SoriginBlackChessStepList.size() == 0) {
        qDebug() << "singleGame.cpp line:227 SdisplayBlackAllPossibleMoves() error: SoriginBlackChessStepList is EMPTY!!!!!";
        return;
    }

    int size = SoriginBlackChessStepList.size();
    for(int i = 0; i < size; i++) {
        std::cout << "=================== <" << i << "> ===================" << std::endl;
        int Num = SoriginBlackChessStepList.at(i)->_chessNum;
        int Number = SoriginBlackChessStepList.at(i)->_chessNumber;
        int PosX = SoriginBlackChessStepList.at(i)->_deltaX;
        int PosY = SoriginBlackChessStepList.at(i)->_deltaY;
        bool kill = SoriginBlackChessStepList.at(i)->_isKill;
        QString killString = kill ? "True" : "False";
        int killNum = SoriginBlackChessStepList.at(i)->_chessKilledNum;
        int killNumber = SoriginBlackChessStepList.at(i)->_chessKilledNumber;
        std::cout << "B_Num\t = " << Num << std::endl;
        std::cout << "B_Number\t = " << Number << std::endl;
        std::cout << "B_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
        std::cout << "B_PosX\t = " << PosX << std::endl;
        std::cout << "B_PosY\t = " << PosY << std::endl;
        std::cout << "B_kill\t = " << killString.toStdString() << std::endl;
        if(kill) {
            std::cout << "B_k_Num\t = " << killNum << std::endl;
            std::cout << "B_k_Number\t = " << killNumber << std::endl;
            std::cout << "B_k_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
        }
    }
}

void singleGame::SdisplayRedAllPossibleMoves() {
    generateRedAllPossibleMoves();

    if(SoriginRedChessStepList.size() == 0) {
        qDebug() << "singleGame.cpp line:260 SdisplayRedAllPossibleMoves() error: SoriginRedChessStepList is EMPTY!!!!!";
        return;
    }

    int size = SoriginRedChessStepList.size();
    for(int i = 0; i < size; i++) {
        std::cout << "=================== <" << i << "> ===================" << std::endl;
        int Num = SoriginRedChessStepList.at(i)->_chessNum;
        int Number = SoriginRedChessStepList.at(i)->_chessNumber;
        int PosX = SoriginRedChessStepList.at(i)->_deltaX;
        int PosY = SoriginRedChessStepList.at(i)->_deltaY;
        bool kill = SoriginRedChessStepList.at(i)->_isKill;
        QString killString = kill ? "True" : "False";
        int killNum = SoriginRedChessStepList.at(i)->_chessKilledNum;
        int killNumber = SoriginRedChessStepList.at(i)->_chessKilledNumber;
        std::cout << "R_Num\t = " << Num << std::endl;
        std::cout << "R_Number\t = " << Number << std::endl;
        std::cout << "R_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
        std::cout << "R_PosX\t = " << PosX << std::endl;
        std::cout << "R_PosY\t = " << PosY << std::endl;
        std::cout << "R_kill\t = " << killString.toStdString() << std::endl;
        if(kill) {
            std::cout << "R_k_Num\t = " << killNum << std::endl;
            std::cout << "R_k_Number\t = " << killNumber << std::endl;
            std::cout << "R_k_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
        }
    }
}

void singleGame::tranStructToClass() {
    if(originBlackChessStepList.size() == 0) {
        qDebug() << "singleGame.cpp line:130 tranStructToClass() error: originBlackChessStepList is EMPTY!!!!!";
        return;
    }

    int size = originBlackChessStepList.size();
    for(int i = 0; i < size; i++) {
        int Num = originBlackChessStepList.at(i)._chessNum;
        int Number = originBlackChessStepList.at(i)._chessNumber;
        bool camp = (Num >= 8); // true is red and false is black
        int PosX = originBlackChessStepList.at(i)._deltaX;
        int PosY = originBlackChessStepList.at(i)._deltaY;
        bool kill = originBlackChessStepList.at(i)._isKill;
        QString killString = kill ? "True" : "False";
        int killNum = originBlackChessStepList.at(i)._chessKilledNum;
        int killNumber = originBlackChessStepList.at(i)._chessKilledNumber;
        Step* tempStep = new Step(Num, Number, camp, PosX, PosY, kill, killNum, killNumber);
        chessBlackStepList.append(tempStep);
    }

    if(originRedChessStepList.size() == 0) {
        qDebug() << "singleGame.cpp line:130 tranStructToClass() error: originRedChessStepList is EMPTY!!!!!";
        return;
    }

    int sizeRed = originRedChessStepList.size();
    for(int i = 0; i < sizeRed; i++) {
        int Num = originRedChessStepList.at(i)._chessNum;
        int Number = originRedChessStepList.at(i)._chessNumber;
        bool camp = (Num >= 8); // true is red and false is black
        int PosX = originRedChessStepList.at(i)._deltaX;
        int PosY = originRedChessStepList.at(i)._deltaY;
        bool kill = originRedChessStepList.at(i)._isKill;
        QString killString = kill ? "True" : "False";
        int killNum = originRedChessStepList.at(i)._chessKilledNum;
        int killNumber = originRedChessStepList.at(i)._chessKilledNumber;
        Step* tempStep = new Step(Num, Number, camp, PosX, PosY, kill, killNum, killNumber);
        chessRedStepList.append(tempStep);
    }
}

void singleGame::testChessing(int maxCount) {
    bool gameIsOn = true;
    bool redOrBlack = false;
    int count = 0;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count -> " << count << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(1000);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(1000);
        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        if(redOrBlack && (!originRedChessStepList.empty())) {
            int size   = originRedChessStepList.size();
            int sizeIndex = generateRandomNumber(size);
            realMove(originRedChessStepList.at(sizeIndex));
        }
        if(!redOrBlack && (!originBlackChessStepList.empty())) {
            int size   = originBlackChessStepList.size();
            int sizeIndex = generateRandomNumber(size);
            realMove(originBlackChessStepList.at(sizeIndex));
        }

        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
        }
        redOrBlack = !redOrBlack;
    }
}

void singleGame::testFakeChessing(int maxCount) {
    bool gameIsOn = true;
    bool redOrBlack = false;
    int count = 0;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count -> " << count << std::endl;
        int value = GlobalEnvirIn::Instance()->__BoardEvaluate();
        std::cout << "value -> " << value << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(1000);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(1000);
        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        if(redOrBlack && (!originRedChessStepList.empty())) {
            int size   = originRedChessStepList.size();
            int sizeIndex = generateRandomNumber(size);
            fakeMove(originRedChessStepList.at(sizeIndex));
        }
        if(!redOrBlack && (!originBlackChessStepList.empty())) {
            int size   = originBlackChessStepList.size();
            int sizeIndex = generateRandomNumber(size);
            fakeMove(originBlackChessStepList.at(sizeIndex));
        }

        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
        }
        redOrBlack = !redOrBlack;
    }
}

void singleGame::testFakeBackMove() {
    std::cout << "init " << GlobalEnvirIn::Instance()->__BoardEvaluate() << std::endl;
    generateRedAllPossibleMoves();
    chessStep step = originRedChessStepList.at(0);
    int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(step._chessNum, step._chessNumber)->getPosX();
    int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(step._chessNum, step._chessNumber)->getPosY();
    while(true){
       fakeMove(step);
       GlobalEnvirIn::Instance()->__delayMsec(500);
       GlobalEnvirIn::Instance()->__printBoard();
       std::cout << "fake " << GlobalEnvirIn::Instance()->__BoardEvaluate() << std::endl;
       fakeBackMove(step, lastPosX, lastPosY);
       GlobalEnvirIn::Instance()->__delayMsec(500);
       GlobalEnvirIn::Instance()->__printBoard();
       std::cout << "back " << GlobalEnvirIn::Instance()->__BoardEvaluate() << std::endl;
    }
}

int singleGame::generateRandomNumber(int maxInt)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int ret = qrand()%maxInt;
    return ret;
}

void singleGame::testStepClass() {
    std::cout << "LALALA" << std::endl;
    QmlConnectIn::Instance()->changeChessPos(1, 1, false, 1, 0);
    GlobalEnvirIn::Instance()->__delayMsec(1000);
    QmlConnectIn::Instance()->changeChessPos(1, 1, false, -1, 0);
    GlobalEnvirIn::Instance()->__delayMsec(1000);

    int index = 0;
    while(index++ < 10)
    {
        generateRedAllPossibleMoves();
        if(!originRedChessStepList.empty()) {
            int Num = originRedChessStepList.at(0)._chessNum;
            int Number = originRedChessStepList.at(0)._chessNumber;
            int PosX = originRedChessStepList.at(0)._deltaX;
            int PosY = originRedChessStepList.at(0)._deltaY;
            bool camp = originRedChessStepList.at(0)._chessCamp;
            QString campString = camp ? "Red" : "Black";
            bool kill = originRedChessStepList.at(0)._isKill;
            QString killString = kill ? "True" : "False";
            int killNum = originRedChessStepList.at(0)._chessKilledNum;
            int killNumber = originRedChessStepList.at(0)._chessKilledNumber;
            std::cout << "index\t = " << index << std::endl;
            std::cout << "Num\t = " << Num << std::endl;
            std::cout << "Number\t = " << Number << std::endl;
            std::cout << "Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
            std::cout << "Camp\t = " << campString.toStdString() << std::endl;
            std::cout << "PosX\t = " << PosX << std::endl;
            std::cout << "PosY\t = " << PosY << std::endl;
            std::cout << "kill\t = " << killString.toStdString() << std::endl;
            if(kill) {
                std::cout << "k_Num\t = " << killNum << std::endl;
                std::cout << "k_Number\t = " << killNumber << std::endl;
                std::cout << "k_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
            }
            QmlConnectIn::Instance()->changeChessPos(Num, Number, camp, PosX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosX(), PosY - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosY());
            GlobalEnvirIn::Instance()->__printBoard();
        }
        GlobalEnvirIn::Instance()->__delayMsec(1000);
    }

    Step* test = new Step(1, 1, false, 0, 0);
    std::cout << "step" << test->getStepX() << std::endl;
    SGeoPoint* t = new SGeoPoint(0, 0);
    std::cout << t->getPosX() << std::endl;
}

void singleGame::normalPlay_HumanVSAI_CIMC(int maxCount) {
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(PARAM::WHOLE_GAME);
    initEndgameIn::Instance()->setInitStrategyBoard(PARAM::WHOLE_GAME);
    // alpha-beta
    // human: red
    // AI: black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            // @TODO
            // just refersh the bosrd once the human has finished his turn
            // if the board unchanged(from vision), remain
            // once changed(from vision), break
            int humanIndex = -1;
            while(humanIndex == -1) {
//                humanIndex = VisionIn::Instance()->get_human_step_from_vision(curStepList);
//                GlobalEnvirIn::Instance()->__delayMsec(1000);
//                std::cout <<  (vision->python_vision->isBoardChanged ? "LLLLLLLLLLLLLLL" : "HHHHHHHHHHHHHHH") << std::endl;
                humanIndex = VisionHumanStepIndex(curStepList);
//                std::cout << "singleGame.cpp line:2042 humanIndex = " << humanIndex << std::endl;
            }
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 10; j++) {
                    vision->python_vision->__lastVisionBoard[i][j] = Main_chessBoard[i][j];
                    // refresh the chess board of the last state
                }
            }
            realMove(curStepList.at(humanIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_black(_level);
            }
            int dest_x = curStepList.at(sizeIndex)._deltaX;
            int dest_y = curStepList.at(sizeIndex)._deltaY;
            int init_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosX();
            int init_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosY();
            int kill_or_not = curStepList.at(sizeIndex)._isKill ? 1 : 0;
            GlobalEnvirIn::Instance()->__delayMsec(25);
            QString M1_request = QString::number(kill_or_not) + QString::number(init_y) + QString::number(init_x) + QString::number(dest_y) + QString::number(dest_x);
            if(M1_client->write(M1_request.toLatin1(), M1_request.length()) == -1) {
                qDebug() << "singleGame.cpp line:2055 normalPlay_HumanVSAI_CIMC() write failed!";
            }
            std::cout << "Message sent to M1 Robot -> " << M1_request.toStdString() << std::endl;
            char M1_Receive[1024] = {0};
            M1_client->read(M1_Receive, 1024);
            if(strlen(M1_Receive) > 0) std::cout << "Receive from M1 Robot   ->" << M1_Receive << std::endl;
            else std::cout << "Receive from M1 Robot ERROR" << std::endl;
            GlobalEnvirIn::Instance()->__delayMsec(25);
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:2071 normalPlay_HumanVSAI_CIMC() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_HumanVSAI_CIMC_EndGame(int maxCount) {
    // human: red
    // AI: black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    // @TODO
    // Get the initial chess board from the vision
    initEndgameIn::Instance()->setInitVisionBoard();
    Is_CIMC_EndGame = false;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            int humanIndex = -1;
            while(humanIndex == -1) {
                humanIndex = VisionHumanStepIndex(curStepList);
            }
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 10; j++) {
                    vision->python_vision->__lastVisionBoard[i][j] = Main_chessBoard[i][j];
                }
            }
            realMove(curStepList.at(humanIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_black(_level);
            }
            int dest_x = curStepList.at(sizeIndex)._deltaX;
            int dest_y = curStepList.at(sizeIndex)._deltaY;
            int init_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosX();
            int init_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosY();
            int kill_or_not = curStepList.at(sizeIndex)._isKill ? 1 : 0;
            GlobalEnvirIn::Instance()->__delayMsec(25);
            QString M1_request = QString::number(kill_or_not) + QString::number(init_y) + QString::number(init_x) + QString::number(dest_y) + QString::number(dest_x);
            if(M1_client->write(M1_request.toLatin1(), M1_request.length()) == -1) {
                qDebug() << "singleGame.cpp line:2055 normalPlay_HumanVSAI_CIMC_EndGame() write failed!";
            }
            std::cout << "Message sent to M1 Robot -> " << M1_request.toStdString() << std::endl;
            char M1_Receive[1024] = {0};
            M1_client->read(M1_Receive, 1024);
            if(strlen(M1_Receive) > 0) std::cout << "Receive from M1 Robot   ->" << M1_Receive << std::endl;
            else std::cout << "Receive from M1 Robot ERROR" << std::endl;
            GlobalEnvirIn::Instance()->__delayMsec(25);
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:2071 normalPlay_HumanVSAI_CIMC_EndGame() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

int singleGame::VisionHumanStepIndex(const QVector<chessStep>& curStepList) {
    if(vision->python_vision->MP_count <= 1 || vision->python_vision->MP_received == false) return -1;
    if(vision->python_vision->isBoardChanged == false) {
        // std::cout << "singleGame.cpp line:2071 VisionHumanStepIndex() vision->python_vision->isBoardChanged == false" << std::endl;
        return -1;
    }
    // generate step
    // 2022-05-17
//    int num = step_first.second.first;
    int init_x = vision->python_vision->step_first.first.first;
    int init_y = vision->python_vision->step_first.first.second;
    int swap_init = init_x; // zjjjnb
    init_x = init_y;        // zjjjnb
    init_y = swap_init;     // zjjjnb
    int num = 0;
    std::cout << "init_x -> " << init_x << "\t\tinit_y -> " << init_y << " PYTHONMODULE ------------" << std::endl;
    if (GlobalEnvirIn::Instance()->__isThereHasChess(init_x, init_y))
        num = GlobalEnvirIn::Instance()->__QStr2intName(
                    GlobalEnvirIn::Instance()->__QString2SimpleName(
                        GlobalEnvirIn::Instance()->__whichChessOnThere(init_x, init_y)->chessName()));
    else
        return -1;
    int number = -1;
//    if(vision->python_vision->isSimpleMoveOrKill == false) number = GlobalEnvirIn::Instance()->__whichChessOnThere(init_x, init_y)->chessNumber();
//    bool kill = !vision->python_vision->isSimpleMoveOrKill;
    // bool kill = (step_second.second.first != 0);
//    int k_num = kill ? (step_second.second.first) : -1;
    int posX = vision->python_vision->step_second.first.first;
    int posY = vision->python_vision->step_second.first.second;
//    int k_num = kill ? (GlobalEnvirIn::Instanc
//    int num = vision->python_vision->step_first.second.first;
//    int init_x = vision->python_vision->step_first.first.first;
//    int init_y = vision->python_vision->step_first.first.second;
//    int number = -1;
//    init_y = 8 - init_y;
    number = GlobalEnvirIn::Instance()->__whichChessOnThere(init_x, init_y)->chessNumber();
////    std::cout << init_x << " llll " << init_y << "   >>>>   " << num << "   " << number << std::endl;
////    bool kill = !(vision->python_vision->isSimpleMoveOrKill);
    int swap_pos = posX;    // zjjjnb
    posX = posY;            // zjjjnb
    posY = swap_pos;        // zjjjnb
    std::cout << "posX -> " << posX << "\t\tposY -> " << posY << " SINGLEGAME ----------" << std::endl;
    bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(posX, posY);
////    int k_num = kill ? (vision->python_vision->step_second.second.first) : -1;
//    int posX = vision->python_vision->step_second.first.first;
//    int posY = vision->python_vision->step_second.first.second;
//    int swap_init = init_x; // zjjjnb
//    init_x = init_y;        // zjjjnb
//    init_y = init_x;        // zjjjnb
    std::cout << "In SingleGame.cpp " << num << " " << init_x << " " << init_y << " " << number << " " << posX << " " << posY << std::endl;
    // start to compare
    int size = curStepList.length();
    int index = -1;
    for(int i = 0; i < size; i++) {
        std::cout << "In for() " << curStepList.at(i)._chessNum << " "
                  << init_x << " " << init_y << " "
                  << curStepList.at(i)._chessNumber << " "
                  << curStepList.at(i)._deltaX << " "
                  << curStepList.at(i)._deltaY;
        std::cout << " Kill " << (kill ? "AAAAAAAAAAAAA " : "BBBBBBBBBBBBB") << " "
                  << (curStepList.at(i)._isKill ? "AAAAAAAAAAAAA " : "BBBBBBBBBBBBB") << std::endl;
        if(curStepList.at(i)._chessNum == num &&
                curStepList.at(i)._chessNumber == number &&
                curStepList.at(i)._deltaX == posX &&
                curStepList.at(i)._deltaY == posY) {
            if(kill == true && curStepList.at(i)._isKill == kill) {
                // kill
                index = i;
                break;
            }
            else if(kill == false) {
                // simple move
                index = i;
                break;
            }
            else {
                // kill = true and curStepList.at(i)._isKill != kill
                continue;
            }
        }
    }
//    if(index >= 0) std::cout << "OHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH index = " << index << std::endl;
//    else std::cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW index = " << index << std::endl;
    return index;
}

void singleGame::normalPlay_HumanVSHuman(int maxCount) {
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(PARAM::WHOLE_GAME);
    initEndgameIn::Instance()->setInitStrategyBoard(PARAM::WHOLE_GAME);
    // alpha-beta
    // human: red
    // AI: black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        // std::cout << "CURRENT_TURN -> " << CURRENT_TURN << std::endl;
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            // @TODO
            // just refersh the bosrd once the human has finished his turn
            // if the board unchanged(from mousearea), remain
            // once changed(from mousearea), break
            while(!humanMove());
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            while(!humanMove_black());
        }
        else {
            qDebug() << "singleGame.cpp line:2198 normalPlay_HumanVSHuman() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_HumanVSHuman_EndGame(int maxCount) {
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(_strategy_mode);
    initEndgameIn::Instance()->setInitStrategyBoard(_strategy_mode);
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            // @TODO
            // just refersh the bosrd once the human has finished his turn
            // if the board unchanged(from mousearea), remain
            // once changed(from mousearea), break
            while(!humanMove());
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            while(!humanMove_black());
        }
        else {
            qDebug() << "singleGame.cpp line:2198 normalPlay_HumanVSHuman_EndGame() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_HumanVSAI(int maxCount) {
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(PARAM::WHOLE_GAME);
    initEndgameIn::Instance()->setInitStrategyBoard(PARAM::WHOLE_GAME);
    // alpha-beta
    // human: red
    // AI: black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        // debug
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        std::cout << "current turn: CurTurn = " << CURRENT_TURN << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            // @TODO
            // just refersh the bosrd once the human has finished his turn
            // if the board unchanged(from mousearea), remain
            // once changed(from mousearea), break
            while(!humanMove());
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_black(_level);
            }
//            int sizeIndex = QuiescentSearch_black(_level + 2); // 2021-08-02
            int dest_x = curStepList.at(sizeIndex)._deltaX;
            int dest_y = curStepList.at(sizeIndex)._deltaY;
            int init_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosX();
            int init_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosY();
            int kill_or_not = curStepList.at(sizeIndex)._isKill ? 1 : 0;
            QString M1_request = QString::number(kill_or_not) + QString::number(init_y) + QString::number(init_x) + QString::number(dest_y) + QString::number(dest_x);
            if(M1_client->write(M1_request.toLatin1(), M1_request.length()) == -1) {
                qDebug() << "singleGame.cpp line:2099 normalPlay_HumanVSAI() write failed!";
            }
            std::cout << "Message sent to M1 Robot -> " << M1_request.toStdString() << std::endl;
            char M1_Receive[1024] = {0};
            M1_client->read(M1_Receive, 1024);
            if(strlen(M1_Receive) > 0) std::cout << "Receive from M1 Robot   ->" << M1_Receive << std::endl;
            else std::cout << "Receive from M1 Robot ERROR" << std::endl;
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:499 normalPlay_HumanVSAI() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_HumanVSAI_RL_Test(int maxCount) {
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(PARAM::WHOLE_GAME);
    initEndgameIn::Instance()->setInitStrategyBoard(PARAM::WHOLE_GAME);
    // alpha-beta
    // human: red
    // AI: black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        // debug
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        std::cout << "current turn: CurTurn = " << CURRENT_TURN << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            // @TODO
            // just refersh the bosrd once the human has finished his turn
            // if the board unchanged(from mousearea), remain
            // once changed(from mousearea), break
            while(!humanMove());
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = getStepIndex_RL(curStepList);
//            int sizeIndex = QuiescentSearch_black(_level + 2); // 2021-08-02
            int dest_x = curStepList.at(sizeIndex)._deltaX;
            int dest_y = curStepList.at(sizeIndex)._deltaY;
            int init_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosX();
            int init_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosY();
            int kill_or_not = curStepList.at(sizeIndex)._isKill ? 1 : 0;
            QString M1_request = QString::number(kill_or_not) + QString::number(init_y) + QString::number(init_x) + QString::number(dest_y) + QString::number(dest_x);
            if(M1_client->write(M1_request.toLatin1(), M1_request.length()) == -1) {
                qDebug() << "singleGame.cpp line:2099 normalPlay_HumanVSAI() write failed!";
            }
            std::cout << "Message sent to M1 Robot -> " << M1_request.toStdString() << std::endl;
            char M1_Receive[1024] = {0};
            M1_client->read(M1_Receive, 1024);
            if(strlen(M1_Receive) > 0) std::cout << "Receive from M1 Robot   ->" << M1_Receive << std::endl;
            else std::cout << "Receive from M1 Robot ERROR" << std::endl;
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:499 normalPlay_HumanVSAI() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_HumanVSAI_EndGame(int maxCount) {
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(_strategy_mode);
    initEndgameIn::Instance()->setInitStrategyBoard(_strategy_mode);
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves(); // no use
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList); // no use
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            while(!humanMove());
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_black(_level);
            }
            int dest_x = curStepList.at(sizeIndex)._deltaX;
            int dest_y = curStepList.at(sizeIndex)._deltaY;
            int init_x = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosX();
            int init_y = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(curStepList.at(sizeIndex)._chessNum, curStepList.at(sizeIndex)._chessNumber)->getPosY();
            int kill_or_not = curStepList.at(sizeIndex)._isKill ? 1 : 0;
            QString M1_request = QString::number(kill_or_not) + QString::number(init_y) + QString::number(init_x) + QString::number(dest_y) + QString::number(dest_x);
            if(M1_client->write(M1_request.toLatin1(), M1_request.length()) == -1) {
                qDebug() << "singleGame.cpp line:2099 normalPlay_HumanVSAI_EndGame() write failed!";
            }
            std::cout << "Message sent to M1 Robot -> " << M1_request.toStdString() << std::endl;
            char M1_Receive[1024] = {0};
            M1_client->read(M1_Receive, 1024);
            if(strlen(M1_Receive) > 0) std::cout << "Receive from M1 Robot   ->" << M1_Receive << std::endl;
            else std::cout << "Receive from M1 Robot ERROR" << std::endl;
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:499 normalPlay_HumanVSAI_EndGame() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

//void singleGame::M1_client_disconnect() {
//    std::cout << "M1_ROBOT Connection Closed!" << std::endl;
//}

void singleGame::normalPlay(int maxCount) {
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(PARAM::WHOLE_GAME);
    initEndgameIn::Instance()->setInitStrategyBoard(PARAM::WHOLE_GAME);
    // alpha-beta
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        // debug
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList);
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_red(_level);
            }
            realMove(curStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
//            curStepList.append(originBlackChessStepList);
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_black(_level);
            }
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:499 normalPlay() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_AIVSAI_AB_RL_Test(int maxCount) {
    std::cout << "normalPlay_AIVSAI_AB_RL_Test -> " << "Red is AB -> " << "Black is RL" << std::endl;
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(PARAM::WHOLE_GAME);
    initEndgameIn::Instance()->setInitStrategyBoard(PARAM::WHOLE_GAME);
    // alpha-beta
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "normalPlay_AIVSAI_AB_RL_Test -> count chess moves -> " << count << std::endl;
        // debug
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList);
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            int sizeIndex = alpha_beta_red(_level);
            realMove(curStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            int sizeIndex = getStepIndex_RL(curStepList);
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:1307 normalPlay_AIVSAI_AB_RL_Test() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::normalPlay_EndGame(int maxCount) {
    QmlConnectIn::Instance()->whetherStrategyMode(true);
    QmlConnectIn::Instance()->setStrategyMode(_strategy_mode);
    initEndgameIn::Instance()->setInitStrategyBoard(_strategy_mode);
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 5;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        TURN_COUNT = count - 1;
        CURRENT_TURN = (count % 2) == 0;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) curStepList.append(originRedChessStepList);
        else curStepList.append(originBlackChessStepList);
        if(redOrBlack && (!curStepList.empty())) {
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_red(_level);
            }
            realMove(curStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
//            curStepList.append(originBlackChessStepList);
            int sizeIndex = 0;
            if(_level >= 4) {
                std::cout << "Using RL Step Generator ..." << std::endl;
                sizeIndex = getStepIndex_RL(curStepList);
            }
            else {
                sizeIndex = alpha_beta_black(_level);
            }
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:2584 normalPlay_EndGame() error: curStepList is EMPTY!!!!!";
            return;
        }
        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            GlobalEnvirIn::Instance()->__printBoard();
        }
        if(GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
            gameIsOn = false;
            if(redOrBlack) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
            if(redOrBlack) QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(false); // black win
            else QmlConnectIn::Instance()->setWinnerWhenOnlyGeneralsInRow(true); // red win
            GlobalEnvirIn::Instance()->__printBoard();
        }
        redOrBlack = !redOrBlack;
    }
    bool isHumanWin = (Ab_gen_1->isAlive() && Ar_gen_1->isAlive()) ? redOrBlack : (!redOrBlack);
    GlobalEnvirIn::Instance()->__evaluatePlayerLevel(count, isHumanWin);
}

void singleGame::getChessStep_RL() {
    tranStepIn::Instance()->tranStep2ChessStep();
    while (tranStepIn::Instance()->returnIsStepReady() == false) {
        GlobalEnvirIn::Instance()->__delayMsec(10);
    }
    Step_RL._chessNum = tranStepIn::Instance()->Step._chessNum;
    Step_RL._chessNumber = tranStepIn::Instance()->Step._chessNumber;
    Step_RL._isKill = tranStepIn::Instance()->Step._isKill;
    Step_RL._deltaX = tranStepIn::Instance()->Step._deltaX;
    Step_RL._deltaY = tranStepIn::Instance()->Step._deltaY;
    if(Step_RL._chessNum >= PARAM::globalEnvironment::RED_GENERAL) {
        Step_RL._chessCamp = true;
    }
    else {
        Step_RL._chessCamp = false;
    }
    std::cout << "-!-!-!- getChessStep_RL -> " << Step_RL._chessNum << " "
              << Step_RL._chessNumber << " " << Step_RL._deltaX << " " << Step_RL._deltaY << " "
              << Step_RL._isKill << " " << Step_RL._chessCamp
              << "\n==========NUM, NUMBER, X, Y, K, C=========" << std::endl;
    if(Step_RL._isKill) {
        Step_RL._chessKilledNum = tranStepIn::Instance()->Step._chessKilledNum;
        Step_RL._chessKilledNumber = tranStepIn::Instance()->Step._chessKilledNumber;
    }
    tranStepIn::Instance()->setIsStepReady(false);
}

int singleGame::getStepIndex_RL(QVector<chessStep> stepList) {
    int size = stepList.size();
    for(int i = 0; i < size; i++) {
        if(stepList.at(i)._isKill == true && (stepList.at(i)._chessKilledNum == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL ||
                stepList.at(i)._chessKilledNum == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL)) {
//            std::cout << "-@-@-@- getStepIndex_RL -> " << stepList.at(i)._chessNum << " "
//                      << stepList.at(i)._chessNumber << " " << stepList.at(i)._deltaX << " " << stepList.at(i)._deltaY << " "
//                      << stepList.at(i)._isKill << " " << i << "\n==========NUM, NUMBER, X, Y, K=========" << std::endl;
            return i;
        }
    }
    getChessStep_RL();
    for(int i = 0; i < size; i++) {
//        std::cout << "-%-%-%- getStepIndex_RL -> " << stepList.at(i)._chessNum << " "
//                  << stepList.at(i)._chessNumber << " " << stepList.at(i)._deltaX << " " << stepList.at(i)._deltaY << " "
//                  << stepList.at(i)._isKill << " " << stepList.at(i)._chessCamp
//                  << "\n==========NUM, NUMBER, X, Y, K, C=========" << std::endl;
        if (compareSteps(stepList.at(i), Step_RL)) {
            return i;
        }
    }
    qDebug() << "ERROR!!!!!!!!!! singleGame.cpp line:1428 NO step_rl match!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    return -1; // BE CAREFUL !!!
}

int singleGame::alpha_beta_red(int depth) {
    int retIndex = 0;
    COUNT_RED++;

    QVector<chessStep> allRed, allBlack;
    allRed.clear();
    allRed.append(originRedChessStepList);
    int sizeRed = allRed.size();

    if(depth <= 0) {
        std::cout << "alpha_beta_red() Depth -> " << depth << std::endl;
        return GlobalEnvirIn::Instance()->__generateRandomNumber(sizeRed);
    }

    int minInMax = 999999999;
    int theHorseCannonIndex_1st = -1;
    int theHorseCannonIndex_2nd = -1;
    QVector<int> toAvoidGeneralDied;
    bool noHopeToLive = false;
    toAvoidGeneralDied.clear();

    for(int index = 0; index < sizeRed; index++) {
        if(allRed.at(index)._isKill == true && allRed.at(index)._chessKilledNum == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL)
            return index;
        if(COUNT_RED <= 4 && isHorseCannonStep_red(allRed.at(index))) {
            if(theHorseCannonIndex_1st == -1) theHorseCannonIndex_1st = index;
            else theHorseCannonIndex_2nd = index;
        }

        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRed.at(index)._chessNum, allRed.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRed.at(index)._chessNum, allRed.at(index)._chessNumber)->getPosY();
        fakeMove(allRed.at(index));

        allBlack.clear();
        generateBlackAllPossibleMoves();
        allBlack.append(originBlackChessStepList);
        int sizeBlack = allBlack.size();
        for(int i = 0; i < sizeBlack; i++) {
            if((allBlack.at(i)._isKill == true && allBlack.at(i)._chessKilledNum == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL) ||
                    GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()){
                toAvoidGeneralDied.append(index);
                break;
            }
        }

        fakeBackMove(allRed.at(index), lastPosX, lastPosY);
    }

    int avoidSize = toAvoidGeneralDied.size();
    noHopeToLive = avoidSize >= sizeRed;
    bool isNeedContinue = false;
    if(noHopeToLive == true) {
        std::cout << "-*- Red(Human) Lose -*-" << std::endl;
        return 0;
    }

    for(int index = 0; index < sizeRed; index++) {
        if(index == theHorseCannonIndex_1st || index == theHorseCannonIndex_2nd) continue;
        for(int i = 0; i < avoidSize; i++) {
            if(index == toAvoidGeneralDied.at(i)) {
                isNeedContinue = true;
                break;
            }
        }
        if(isNeedContinue && noHopeToLive == false) {
            isNeedContinue = false;
            continue;
        }

        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRed.at(index)._chessNum, allRed.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRed.at(index)._chessNum, allRed.at(index)._chessNumber)->getPosY();

        fakeMove(allRed.at(index));
        __curTurn = true;
//        GlobalEnvirIn::Instance()->__printBoard();
//        GlobalEnvirIn::Instance()->__delayMsec(500);
        int maxScore = alpha_beta_getMax(depth - 1, minInMax);
        fakeBackMove(allRed.at(index), lastPosX, lastPosY);
//        GlobalEnvirIn::Instance()->__printBoard();
//        GlobalEnvirIn::Instance()->__delayMsec(500);

        if(maxScore < minInMax) {
            retIndex = index;
            minInMax = maxScore;
        }
    }

    return retIndex;
}

int singleGame::alpha_beta_black(int depth) {
    int retIndex = 0;
    COUNT_BLACK++;

    // generateBlackAllPossibleMoves();
    QVector<chessStep> allBlack, allRed;
    allBlack.clear();
    allBlack.append(originBlackChessStepList);
    int sizeBlack = allBlack.size();

    if(depth <= 0) {
        std::cout << "alpha_beta_black() Depth -> " << depth << std::endl;
        return GlobalEnvirIn::Instance()->__generateRandomNumber(sizeBlack);
    }

    int maxInMin = -999999999;
    int theHorseCannonIndex_1st = -1;
    int theHorseCannonIndex_2nd = -1;
    QVector<int> toAvoidGeneralDied;
    bool noHopeToLive = false;
    toAvoidGeneralDied.clear();

    for(int index = 0; index < sizeBlack; index++) {
        if(allBlack.at(index)._isKill == true && allBlack.at(index)._chessKilledNum == PARAM::globalEnvironment::CHESS_TABLE::RED_GENERAL)
            return index;
        if(COUNT_BLACK <= 4 && isHorseCannonStep_black(allBlack.at(index))) {
            if(theHorseCannonIndex_1st == -1) theHorseCannonIndex_1st = index;
            else theHorseCannonIndex_2nd = index;
        }

        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlack.at(index)._chessNum, allBlack.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlack.at(index)._chessNum, allBlack.at(index)._chessNumber)->getPosY();
        fakeMove(allBlack.at(index));

        allRed.clear();
        generateRedAllPossibleMoves();
        allRed.append(originRedChessStepList);
        int sizeRed = allRed.size();
        for(int i = 0; i < sizeRed; i++) {
            if((allRed.at(i)._isKill == true && allRed.at(i)._chessKilledNum == PARAM::globalEnvironment::CHESS_TABLE::BLACK_GENERAL) ||
                    GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow()) {
                toAvoidGeneralDied.append(index);
                break;
            }
        }

        fakeBackMove(allBlack.at(index), lastPosX, lastPosY);
    }

    int avoidSize = toAvoidGeneralDied.size();
    noHopeToLive = avoidSize >= sizeBlack;
    bool isNeedContinue = false;
    if(noHopeToLive == true) {
        std::cout << "-*- Black(AI) Lose -*-" << std::endl;
        return 0;
    }

    for(int index = 0; index < sizeBlack; index++) {
        if(index == theHorseCannonIndex_1st || index == theHorseCannonIndex_2nd) continue;
        for(int i = 0; i < avoidSize; i++) {
            if(index == toAvoidGeneralDied.at(i)) {
                isNeedContinue = true;
                break;
            }
        }
        if(isNeedContinue && noHopeToLive == false) {
            isNeedContinue = false;
            continue;
        }

        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlack.at(index)._chessNum, allBlack.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlack.at(index)._chessNum, allBlack.at(index)._chessNumber)->getPosY();

        fakeMove(allBlack.at(index));
        __curTurn = false;
        int minScore = alpha_beta_getMin(depth - 1, maxInMin);
        fakeBackMove(allBlack.at(index), lastPosX, lastPosY);

        if(minScore > maxInMin) {
            retIndex = index;
            maxInMin = minScore;
        }
    }

    return retIndex;

    /*Step* ret = NULL;
    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int maxInAllMinScore = -300000;

    while(steps.count())
    {
        Step* step = steps.last();
        steps.removeLast();

        fakeMove(step);
        int minScore = getMinScore(this->_level-1, maxInAllMinScore);
        unfakeMove(step);

        if(minScore > maxInAllMinScore)
        {
            if(ret) delete ret;

            ret = step;
            maxInAllMinScore = minScore;
        }
        else
        {
            delete step;
        }
    }
    return ret;*/
}

int singleGame::alpha_beta_getMin(int depth, int curMin) {
    if(depth == 0) return GlobalEnvirIn::Instance()->__BoardEvaluate();

    int minInMax = 987654321;

    generateRedAllPossibleMoves();
    QVector<chessStep> allRedMin;
    allRedMin.clear();
    allRedMin.append(originRedChessStepList);
    int sizeAllRed = allRedMin.size();

    for(int index = 0; index < sizeAllRed; index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedMin.at(index)._chessNum, allRedMin.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedMin.at(index)._chessNum, allRedMin.at(index)._chessNumber)->getPosY();

        fakeMove(allRedMin.at(index));
        __curTurn = true;
        int maxScore = alpha_beta_getMax(depth - 1, minInMax);
        fakeBackMove(allRedMin.at(index), lastPosX, lastPosY);

        if(maxScore <= curMin) {
            return maxScore;
        }

        if(maxScore < minInMax) {
            minInMax = maxScore;
        }
    }

    return minInMax;

}

int singleGame::alpha_beta_getMax(int depth, int curMax) {
    if(depth == 0) return GlobalEnvirIn::Instance()->__BoardEvaluate();

    int maxInMin = -987654321;

    generateBlackAllPossibleMoves();
    QVector<chessStep> allBlackMax;
    allBlackMax.clear();
    allBlackMax.append(originBlackChessStepList);
    int sizeAllBlack = allBlackMax.size();

    for(int index = 0; index < sizeAllBlack; index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlackMax.at(index)._chessNum, allBlackMax.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlackMax.at(index)._chessNum, allBlackMax.at(index)._chessNumber)->getPosY();

        fakeMove(allBlackMax.at(index));
        __curTurn = false;
        int minScore = alpha_beta_getMin(depth - 1, maxInMin);
        fakeBackMove(allBlackMax.at(index), lastPosX, lastPosY);

        if(minScore >= curMax) {
            return minScore;
        }
        if(minScore > maxInMin) {
            maxInMin = minScore;
        }
    }

    return maxInMin;

}

bool singleGame::isHorseCannonStep_red(const chessStep &curStep) {
    int num = curStep._chessNum;
    if(num != PARAM::globalEnvironment::CHESS_TABLE::RED_CANNON) return false;
    int kill = curStep._isKill;
    if(kill == false) return false;
    int PosX = curStep._deltaX;
    int PosY = curStep._deltaY;
    if(((PosX == 0 && PosY == 1) || (PosX == 0 && PosY == 7)) == false) return false;
    int killNum = curStep._chessKilledNum;
    if(killNum != PARAM::globalEnvironment::CHESS_TABLE::BLACK_HORSE) return false;
    if(false == (PosY == 1 && GlobalEnvirIn::Instance()->__isThereHasChess(PosX, PosY - 1) &&
            GlobalEnvirIn::Instance()->__whichChessOnThere(PosX, PosY - 1)->chessName() == "BChariot") &&
       false == (PosY == 7 && GlobalEnvirIn::Instance()->__isThereHasChess(PosX, PosY + 1) &&
            GlobalEnvirIn::Instance()->__whichChessOnThere(PosX, PosY + 1)->chessName() == "BChariot")) return false;
    return true;
}

bool singleGame::isHorseCannonStep_black(const chessStep &curStep) {
    int num = curStep._chessNum;
    if(num != PARAM::globalEnvironment::CHESS_TABLE::BLACK_CANNON) return false;
    int kill = curStep._isKill;
    if(kill == false) return false;
    int PosX = curStep._deltaX;
    int PosY = curStep._deltaY;
    if(((PosX == 9 && PosY == 1) || (PosX == 9 && PosY == 7)) == false) return false;
    int killNum = curStep._chessKilledNum;
    if(killNum != PARAM::globalEnvironment::CHESS_TABLE::RED_HORSE) return false;
    if(false == (PosY == 1 && GlobalEnvirIn::Instance()->__isThereHasChess(PosX, PosY - 1) &&
            GlobalEnvirIn::Instance()->__whichChessOnThere(PosX, PosY - 1)->chessName() == "RChariot") &&
       false == (PosY == 7 && GlobalEnvirIn::Instance()->__isThereHasChess(PosX, PosY + 1) &&
            GlobalEnvirIn::Instance()->__whichChessOnThere(PosX, PosY + 1)->chessName() == "RChariot")) return false;
    return true;
}

bool singleGame::compareSteps(chessStep last, chessStep current) {
    if(last._chessNum == current._chessNum &&
            last._chessNumber == current._chessNumber &&
            last._chessCamp == current._chessCamp &&
            last._deltaX == current._deltaX &&
            last._deltaY == current._deltaY) {
        if(last._isKill == true && current._isKill == true) {
            if(last._chessKilledNum == current._chessKilledNum &&
                    last._chessKilledNumber == current._chessKilledNumber) return true;
        }
        if(last._isKill == false && current._isKill == false) return true;
    }
    return false;
}

void singleGame::realMove(chessStep step) {
    int Num    = step._chessNum;
    int Number = step._chessNumber;
    int PosX   = step._deltaX;
    int PosY   = step._deltaY;
    bool camp  = step._chessCamp;
    QString campString = camp ? "Red" : "Black";
    bool kill  = step._isKill;
    QString killString = kill ? "True" : "False";
    int killNum    = step._chessKilledNum;
    int killNumber = step._chessKilledNumber;
    std::cout << "Num   \t = " << Num << std::endl;
    std::cout << "Number\t = " << Number << std::endl;
    std::cout << "Name  \t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
    std::cout << "Camp  \t = " << campString.toStdString() << std::endl;
    std::cout << "PosX  \t = " << PosX << std::endl;
    std::cout << "PosY  \t = " << PosY << std::endl;
    std::cout << "kill  \t = " << killString.toStdString() << std::endl;
    if(kill) {
        std::cout << "k_Num   \t = " << killNum << std::endl;
        std::cout << "k_Number\t = " << killNumber << std::endl;
        std::cout << "k_Name  \t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
        GlobalEnvirIn::Instance()->__killThisChess(killNum, killNumber);
        QString camp_killer = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->chessCamp() ? "red_" : "black_";
        QString name_killer = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->chessName().remove(0, 1);
        QString image_killer = QString("../chess/") + camp_killer + name_killer + QString(".svg");
        std::cout << image_killer.toStdString() << std::endl;
        object->setProperty(QString("killer").toLatin1(), image_killer.toLatin1());
    }
    else {
        object->setProperty(QString("killedChessDisplay").toLatin1(), false);
    }
    QmlConnectIn::Instance()->changeChessPos(Num, Number, camp, PosX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosX(), PosY - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosY());
// 2022-05-09 disable depth change
//    if(camp == true) {
//        // current camp is red
//        // next is black's turn
//        updateSearchDepth_black();
//    }
//    else {
//        // current camp is black
//        // next is red's turn
//        updateSearchDepth_red();
//    }
}

void singleGame::fakeMove(chessStep step) {
    int Num    = step._chessNum;
    int Number = step._chessNumber;
    int PosX   = step._deltaX;
    int PosY   = step._deltaY;
    bool camp  = step._chessCamp;
    QString campString = camp ? "Red" : "Black";
    bool kill  = step._isKill;
    QString killString = kill ? "True" : "False";
    int killNum    = step._chessKilledNum;
    int killNumber = step._chessKilledNumber;
//    std::cout << "Num   \t = " << Num << std::endl;
//    std::cout << "Number\t = " << Number << std::endl;
//    std::cout << "Name  \t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
//    std::cout << "Camp  \t = " << campString.toStdString() << std::endl;
//    std::cout << "PosX  \t = " << PosX << std::endl;
//    std::cout << "PosY  \t = " << PosY << std::endl;
//    std::cout << "kill  \t = " << killString.toStdString() << std::endl;
    if(kill) {
//        std::cout << "k_Num   \t = " << killNum << std::endl;
//        std::cout << "k_Number\t = " << killNumber << std::endl;
//        std::cout << "k_Name  \t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
        GlobalEnvirIn::Instance()->__fakeKillThisChess(killNum, killNumber);
    }
    QmlConnectIn::Instance()->fakeChangeChessPos(Num, Number, camp, PosX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosX(), PosY - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosY());
}

void singleGame::realBackMove(chessStep step, int lastPosX, int lastPosY) {
    std::cout << "realBackMove() called" << std::endl;
}

void singleGame::fakeBackMove(chessStep step, int lastPosX, int lastPosY) {
    int Num    = step._chessNum;
    int Number = step._chessNumber;
    int PosX   = lastPosX;
    int PosY   = lastPosY;
    bool camp  = step._chessCamp;
    QString campString = camp ? "Red" : "Black";
    bool kill  = step._isKill;
    QString killString = kill ? "True" : "False";
    int killNum    = step._chessKilledNum;
    int killNumber = step._chessKilledNumber;
//    std::cout << "Num   \t = " << Num << std::endl;
//    std::cout << "Number\t = " << Number << std::endl;
//    std::cout << "Name  \t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
//    std::cout << "Camp  \t = " << campString.toStdString() << std::endl;
//    std::cout << "PosX  \t = " << PosX << std::endl;
//    std::cout << "PosY  \t = " << PosY << std::endl;
//    std::cout << "kill  \t = " << killString.toStdString() << std::endl;
//    if(kill) {
//        std::cout << "k_Num   \t = " << killNum << std::endl;
//        std::cout << "k_Number\t = " << killNumber << std::endl;
//        std::cout << "k_Name  \t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
//    }
    if(kill) GlobalEnvirIn::Instance()->__QStrOrInt2Chess(killNum, killNumber)->setAlive(true);
    QmlConnectIn::Instance()->fakeBackChangeChessPos(Num, Number, camp,
                                                 PosX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosX(),
                                                 PosY - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosY());
}

void singleGame::realMove(chessStep *step) {
    chessStep Step(step->_chessNum, step->_chessNumber, step->_chessCamp, step->_deltaX, step->_deltaY, step->_isKill, step->_chessKilledNum, step->_chessKilledNumber);
    realMove(Step);
}

void singleGame::fakeMove(chessStep *step) {
    chessStep Step(step->_chessNum, step->_chessNumber, step->_chessCamp, step->_deltaX, step->_deltaY, step->_isKill, step->_chessKilledNum, step->_chessKilledNumber);
    fakeMove(Step);
}

void singleGame::realBackMove(chessStep* step, int lastPosX, int lastPosY) {
    chessStep Step(step->_chessNum, step->_chessNumber, step->_chessCamp, step->_deltaX, step->_deltaY, step->_isKill, step->_chessKilledNum, step->_chessKilledNumber);
    realBackMove(Step, lastPosX, lastPosY);
}

void singleGame::fakeBackMove(chessStep *step, int lastPosX, int lastPosY) {
    chessStep Step(step->_chessNum, step->_chessNumber, step->_chessCamp, step->_deltaX, step->_deltaY, step->_isKill, step->_chessKilledNum, step->_chessKilledNumber);
    fakeBackMove(Step, lastPosX, lastPosY);
}

void singleGame::deleteStepList(QVector<chessStep *> &stepList) {
    int size = stepList.size();
    for(int index = 0; index < size; index++) delete stepList.at(index);
}

bool singleGame::humanMove() {
    // the first point
    // if isThereHasOurChess()
    // the second point
    // if isThereNoOurChess() generate move
    // else isThereHasOurChess() back to first point
    int lastPosX = -999; // must -1
    int lastPosY = -999;
    int curPosX = -1;
    int curPosY = -1;
    bool isHumanMoving = true;
    int Num = 0;
    int Number = 0;
    bool camp = true;
    int movePosX = -1;
    int movePosY = -1;
    bool kill = false;
    int kNum = 0;
    int kNumber = 0;
    while(isHumanMoving) {
        GlobalEnvirIn::Instance()->__delayMsec(10);
        QVariant x = object->property("lastMousePosX");
        QVariant y = object->property("lastMousePosY");
        curPosX = x.toInt();
        curPosY = y.toInt();
        if(!GlobalEnvirIn::Instance()->__isPosInBoard(coordinateIn::Instance()->transferPosX(curPosX),
                                                      coordinateIn::Instance()->transferPosY(curPosY))) continue;
        object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(curPosX)));
        object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(curPosY)));
//        std::cout << "X = " << curPosX << "    Y = " << curPosY << std::endl;
        if(lastPosX == -999 && lastPosY == -999 && curPosX != lastPosX && curPosY != lastPosY &&
                GlobalEnvirIn::Instance()->__isThereHasChess(coordinateIn::Instance()->transferPosX(curPosX),
                                                             coordinateIn::Instance()->transferPosY(curPosY)) &&
                GlobalEnvirIn::Instance()->__isThereHasOurChess(true,
                                                                coordinateIn::Instance()->transferPosX(curPosX),
                                                                coordinateIn::Instance()->transferPosY(curPosY))) {
            lastPosX = curPosX;
            lastPosY = curPosY;
            // object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(lastPosX)));
            // object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(lastPosY)));
            continue;
        }
        if(lastPosX != -999 && lastPosY != -999 &&
                (coordinateIn::Instance()->transferPosX(lastPosX) != coordinateIn::Instance()->transferPosX(curPosX) ||
                 coordinateIn::Instance()->transferPosY(lastPosY) != coordinateIn::Instance()->transferPosY(curPosY))) {
            // means there is a new point
            if(GlobalEnvirIn::Instance()->__isThereHasOurChess(true,
                                                               coordinateIn::Instance()->transferPosX(lastPosX),
                                                               coordinateIn::Instance()->transferPosY(lastPosY)) &&
                    !GlobalEnvirIn::Instance()->__isThereHasOurChess(true,
                                                                     coordinateIn::Instance()->transferPosX(curPosX),
                                                                     coordinateIn::Instance()->transferPosY(curPosY))) {
//                std::cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL " << coordinateIn::Instance()->transferPosX(curPosX) << " " << coordinateIn::Instance()->transferPosY(curPosY) << std::endl;
                // object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(curPosX)));
                // object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(curPosY)));
                Num = GlobalEnvirIn::Instance()->__QStr2intName(
                            GlobalEnvirIn::Instance()->__QString2SimpleName(
                                GlobalEnvirIn::Instance()->__whichChessOnThere(coordinateIn::Instance()->transferPosX(lastPosX),
                                                                               coordinateIn::Instance()->transferPosY(lastPosY))->chessName()));
                Number = GlobalEnvirIn::Instance()->__whichChessOnThere(coordinateIn::Instance()->transferPosX(lastPosX),
                                                                        coordinateIn::Instance()->transferPosY(lastPosY))->chessNumber();
                movePosX = coordinateIn::Instance()->transferPosX(curPosX);
                movePosY = coordinateIn::Instance()->transferPosY(curPosY);
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(movePosX, movePosY);
                if(kill) {
                    kNum = GlobalEnvirIn::Instance()->__QStr2intName(
                                GlobalEnvirIn::Instance()->__QString2SimpleName(
                                    GlobalEnvirIn::Instance()->__whichChessOnThere(movePosX, movePosY)->chessName()));
                    kNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(movePosX, movePosY)->chessNumber();
//                    std::cout  << " kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk " << Num << " " << Number << " " << kNum << " " << kNumber << std::endl;
                }
                break;
            }
            lastPosX = curPosX;
            lastPosY = curPosY;
            // std::cout << ";;;;;;;;;;;LLLLLLLLLLLLLLLLL;;;;;;;;;;;;;;;"  << " " << coordinateIn::Instance()->transferPosX(curPosX) << " " << coordinateIn::Instance()->transferPosX(curPosX) << std::endl;
            // if(GlobalEnvirIn::Instance()->__isThereHasOurChess(true,
            //                                                    coordinateIn::Instance()->transferPosX(curPosX),
            //                                                    coordinateIn::Instance()->transferPosY(curPosY))) {
            // object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(curPosX)));
            // object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(curPosY)));
            // }
        }
    }
    chessStep humanStep(Num, Number, camp, movePosX, movePosY, kill, kNum, kNumber);
    if(isHumanStepValid(humanStep)) {
        realMove(humanStep);
        return true;
    }
    return false;
}

bool singleGame::humanMove_black() {
    // the first point
    // if isThereHasOurChess()
    // the second point
    // if isThereNoOurChess() generate move
    // else isThereHasOurChess() back to first point
    int lastPosX = -999; // must -1
    int lastPosY = -999;
    int curPosX = -1;
    int curPosY = -1;
    bool isHumanMoving = true;
    int Num = 0;
    int Number = 0;
    bool camp = false; // true for red and false for black
    int movePosX = -1;
    int movePosY = -1;
    bool kill = false;
    int kNum = 0;
    int kNumber = 0;
    while(isHumanMoving) {
        GlobalEnvirIn::Instance()->__delayMsec(10);
        QVariant x = object->property("lastMousePosX");
        QVariant y = object->property("lastMousePosY");
        curPosX = x.toInt();
        curPosY = y.toInt();
        if(!GlobalEnvirIn::Instance()->__isPosInBoard(coordinateIn::Instance()->transferPosX(curPosX),
                                                      coordinateIn::Instance()->transferPosY(curPosY))) continue;
        object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(curPosX)));
        object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(curPosY)));
//        std::cout << "X = " << curPosX << "    Y = " << curPosY << std::endl;
        if(lastPosX == -999 && lastPosY == -999 && curPosX != lastPosX && curPosY != lastPosY &&
                GlobalEnvirIn::Instance()->__isThereHasChess(coordinateIn::Instance()->transferPosX(curPosX),
                                                             coordinateIn::Instance()->transferPosY(curPosY)) &&
                GlobalEnvirIn::Instance()->__isThereHasOurChess(false,
                                                                coordinateIn::Instance()->transferPosX(curPosX),
                                                                coordinateIn::Instance()->transferPosY(curPosY))) {
            lastPosX = curPosX;
            lastPosY = curPosY;
            // object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(lastPosX)));
            // object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(lastPosY)));
            continue;
        }
        if(lastPosX != -999 && lastPosY != -999 &&
                (coordinateIn::Instance()->transferPosX(lastPosX) != coordinateIn::Instance()->transferPosX(curPosX) ||
                 coordinateIn::Instance()->transferPosY(lastPosY) != coordinateIn::Instance()->transferPosY(curPosY))) {
            // means there is a new point
            if(GlobalEnvirIn::Instance()->__isThereHasOurChess(false,
                                                               coordinateIn::Instance()->transferPosX(lastPosX),
                                                               coordinateIn::Instance()->transferPosY(lastPosY)) &&
                    !GlobalEnvirIn::Instance()->__isThereHasOurChess(false,
                                                                     coordinateIn::Instance()->transferPosX(curPosX),
                                                                     coordinateIn::Instance()->transferPosY(curPosY))) {
//                std::cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL " << coordinateIn::Instance()->transferPosX(curPosX) << " " << coordinateIn::Instance()->transferPosY(curPosY) << std::endl;
                // object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(curPosX)));
                // object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(curPosY)));
                Num = GlobalEnvirIn::Instance()->__QStr2intName(
                            GlobalEnvirIn::Instance()->__QString2SimpleName(
                                GlobalEnvirIn::Instance()->__whichChessOnThere(coordinateIn::Instance()->transferPosX(lastPosX),
                                                                               coordinateIn::Instance()->transferPosY(lastPosY))->chessName()));
                Number = GlobalEnvirIn::Instance()->__whichChessOnThere(coordinateIn::Instance()->transferPosX(lastPosX),
                                                                        coordinateIn::Instance()->transferPosY(lastPosY))->chessNumber();
                movePosX = coordinateIn::Instance()->transferPosX(curPosX);
                movePosY = coordinateIn::Instance()->transferPosY(curPosY);
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(movePosX, movePosY);
                if(kill) {
                    kNum = GlobalEnvirIn::Instance()->__QStr2intName(
                                GlobalEnvirIn::Instance()->__QString2SimpleName(
                                    GlobalEnvirIn::Instance()->__whichChessOnThere(movePosX, movePosY)->chessName()));
                    kNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(movePosX, movePosY)->chessNumber();
//                    std::cout  << " kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk " << Num << " " << Number << " " << kNum << " " << kNumber << std::endl;
                }
                break;
            }
            lastPosX = curPosX;
            lastPosY = curPosY;
            // std::cout << ";;;;;;;;;;;LLLLLLLLLLLLLLLLL;;;;;;;;;;;;;;;"  << " " << coordinateIn::Instance()->transferPosX(curPosX) << " " << coordinateIn::Instance()->transferPosX(curPosX) << std::endl;
            // if(GlobalEnvirIn::Instance()->__isThereHasOurChess(true,
            //                                                    coordinateIn::Instance()->transferPosX(curPosX),
            //                                                    coordinateIn::Instance()->transferPosY(curPosY))) {
            // object->setProperty("selectChessX", coordinateIn::Instance()->tranRealPosX(coordinateIn::Instance()->transferPosX(curPosX)));
            // object->setProperty("selectChessY", coordinateIn::Instance()->tranRealPosY(coordinateIn::Instance()->transferPosY(curPosY)));
            // }
        }
    }
    chessStep humanStep(Num, Number, camp, movePosX, movePosY, kill, kNum, kNumber);
//    std::cout << Num << " " << Number << " " << (kill?"RR":"BB") << " " << movePosX << " " << movePosY << " " << (kill?"KK":"PP") << " " << kNum << " " << kNumber << std::endl;
    if(isHumanStepValid_black(humanStep)) {
        realMove(humanStep);
        return true;
    }
    return false;
}

bool singleGame::isHumanStepValid(chessStep step) {
    generateRedAllPossibleMoves();
    QVector<chessStep> allPossible;
    allPossible.clear();
    allPossible.append(originRedChessStepList);
    int size = allPossible.size();
    // displayRedAllPossibleMoves();
    for(int index = 0; index < size; index++) {
        if(compareSteps(allPossible.at(index), step)) return true;
    }
    qDebug() << "singleGame.cpp isHumanStepValid() line:2604 human move invalid!!!";
    return false;
}

bool singleGame::isHumanStepValid_black(chessStep step) {
    generateBlackAllPossibleMoves();
    QVector<chessStep> allPossible;
    allPossible.clear();
    allPossible.append(originBlackChessStepList);
    int size = allPossible.size();
//    displayBlackAllPossibleMoves();
    for(int index = 0; index < size; index++) {
        if(compareSteps(allPossible.at(index), step)) return true;
    }
    qDebug() << "singleGame.cpp isHumanStepValid_black() line:2937 human move invalid!!!";
    return false;
}

int singleGame::MonteCarloTree_black(int depth) {
    // 2021-07-31
    // depth = _level = 4
    std::cout << "In MonteCarloTree_black() depth = " << depth << std::endl;

    return 0;
}

int singleGame::QuiescentSearch_black(int depth) {
    // If someone eats your elephant with a horse, you'd better eat and return his horse.
    // Alpha-Beta search is not specifically aimed at this situation.
    // You pass the depth parameter to the function, and it's done when the depth reaches zero, even if one party is caught.
    // When Alpha-Beta runs out of depth, call static search instead of calling "Evaluate()".
    // This function also evaluates the situation, just to avoid misunderstanding the situation when there are obvious countermeasures.
    int retIndex = 0;

    // generateBlackAllPossibleMoves();
    QVector<chessStep> allBlack;
    allBlack.clear();
    allBlack.append(originBlackChessStepList);
    int sizeBlack = allBlack.size();

    int maxInMin = -987654321;

    for(int index = 0; index < sizeBlack; index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlack.at(index)._chessNum, allBlack.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlack.at(index)._chessNum, allBlack.at(index)._chessNumber)->getPosY();

        fakeMove(allBlack.at(index));
        int minScore = alpha_beta_getMin(depth - 1 - R_value, maxInMin);
        fakeBackMove(allBlack.at(index), lastPosX, lastPosY);

        if(minScore > maxInMin) {
            retIndex = index;
            maxInMin = minScore;
        }
    }

    return retIndex;
}

int singleGame::Quiescent_alpha_beta_getMin(int depth, int curMin) {
    if(depth <= 0) return GlobalEnvirIn::Instance()->__BoardEvaluate();

    int minInMax = 987654321;

//    MakeNullMove();
//    val = -AlphaBeta(depth - 1 - R, -beta, -beta + 1);
//    UnmakeNullMove();
//    if (val >= beta) {
//     return beta;
//    }

//    int R_tempMaxScore = Quiescent_alpha_beta_getMax(depth - 1 - R_value, minInMax);
//    if(R_tempMaxScore <= curMin) {
//        return R_tempMaxScore;
//    }

    generateRedAllPossibleMoves();
    QVector<chessStep> allRedMin;
    allRedMin.clear();
    allRedMin.append(originRedChessStepList);
    int sizeAllRed = allRedMin.size();

    for(int index = 0; index < sizeAllRed; index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedMin.at(index)._chessNum, allRedMin.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedMin.at(index)._chessNum, allRedMin.at(index)._chessNumber)->getPosY();

        fakeMove(allRedMin.at(index));
        int maxScore = alpha_beta_getMax(depth - 1 - R_value, minInMax);
        fakeBackMove(allRedMin.at(index), lastPosX, lastPosY);

        if(maxScore <= curMin) {
            return maxScore;
        }

        if(maxScore < minInMax) {
            minInMax = maxScore;
        }
    }

    return minInMax;

}

int singleGame::Quiescent_alpha_beta_getMax(int depth, int curMax) {
    if(depth <= 0) return GlobalEnvirIn::Instance()->__BoardEvaluate();

    int maxInMin = -987654321;

//    int R_tempMinScore = Quiescent_alpha_beta_getMin(depth - 1 - R_value, maxInMin);
//    if(R_tempMinScore >= curMax) {
//        return R_tempMinScore;
//    }

    generateBlackAllPossibleMoves();
    QVector<chessStep> allBlackMax;
    allBlackMax.clear();
    allBlackMax.append(originBlackChessStepList);
    int sizeAllBlack = allBlackMax.size();

    for(int index = 0; index < sizeAllBlack; index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlackMax.at(index)._chessNum, allBlackMax.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allBlackMax.at(index)._chessNum, allBlackMax.at(index)._chessNumber)->getPosY();

        fakeMove(allBlackMax.at(index));
        int minScore = alpha_beta_getMin(depth - 1 - R_value, maxInMin);
        fakeBackMove(allBlackMax.at(index), lastPosX, lastPosY);

        if(minScore >= curMax) {
            return minScore;
        }
        if(minScore > maxInMin) {
            maxInMin = minScore;
        }
    }

    return maxInMin;

}

void singleGame::updateSearchDepth_black() {
    generateBlackAllPossibleMoves();
//    int numberOfSteps = qMin<int>(originRedChessStepList.size(), originBlackChessStepList.size());
    int numberOfSteps = originBlackChessStepList.size();
    int basicLevel = BASIC_DEPTH;
    int maxNodes = MAX_SEARCH_NODES;
    int exponent = BEST_EXPONENT;
    int delta = 0;
    for(int i = 0; i < PARAM::MAX_LEVEL - basicLevel; i++) {
        if(pow(numberOfSteps, exponent + delta * 2) < maxNodes) delta++;
        else break;
    }
    delta--;
    if(currentSearchDepth_black() < basicLevel + delta && basicLevel + delta < PARAM::RL_DEPTH) {
        changeSearchDepth_black(basicLevel + delta);
    }
    changeSearchDepth(currentSearchDepth_black(), "black");
}

void singleGame::updateSearchDepth_red() {
    generateRedAllPossibleMoves();
    int numberOfSteps = originRedChessStepList.size();
    int basicLevel = BASIC_DEPTH;
    int maxNodes = MAX_SEARCH_NODES;
    int exponent = BEST_EXPONENT;
    int delta = 0;
    for(int i = 0; i < PARAM::MAX_LEVEL - basicLevel; i++) {
        if(pow(numberOfSteps, exponent + delta * 2) < maxNodes) delta++;
        else break;
    }
    delta--;
    if(currentSearchDepth_red() < basicLevel + delta && basicLevel + delta < PARAM::RL_DEPTH) {
        changeSearchDepth_red(basicLevel + delta);
    }
    changeSearchDepth(currentSearchDepth_red(), "Red");
}

int singleGame::currentSearchDepth_red() {
    return _redLevel;
}

int singleGame::currentSearchDepth_black() {
    return _blackLevel;
}

void singleGame::changeSearchDepth_red(int currentSearchDepth) {
    _redLevel = currentSearchDepth;
}

void singleGame::changeSearchDepth_black(int currentSearchDepth) {
    _blackLevel = currentSearchDepth;
}

int singleGame::currentSearchDepth() {
    return _level;
}

void singleGame::changeSearchDepth(int currentSearchDepth, QString camp) {
    std::cout << "-*-  Search Depth of " << camp.toStdString() << " Changed from " << _level << " to " << currentSearchDepth << " -*-" << std::endl;
    _level = currentSearchDepth;
}
