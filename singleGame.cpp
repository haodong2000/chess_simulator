#include "singleGame.h"

singleGame::singleGame()
{
    finalChessStep = new Step(-1, -1, false, 0, 0, false);
    chessBlackStepList.clear();
    originBlackChessStepList.clear();
    chessRedStepList.clear();
    originRedChessStepList.clear();

    _level = 4; // initialization
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
        chessBlackStepList.append(Step(Num, Number, camp, PosX, PosY, kill, killNum, killNumber));
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
        chessRedStepList.append(Step(Num, Number, camp, PosX, PosY, kill, killNum, killNumber));
    }
}
