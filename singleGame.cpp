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

    originBlackChessStepList.clear();

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

    originRedChessStepList.clear();

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
//        if(redOrBlack) displayRedAllPossibleMoves();
//        else displayBlackAllPossibleMoves();
        std::cout << "count = " << count << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();

        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        if(redOrBlack && (!originRedChessStepList.empty())) {
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
        }
        if(!redOrBlack && (!originBlackChessStepList.empty())) {
            int Num = originBlackChessStepList.at(0)._chessNum;
            int Number = originBlackChessStepList.at(0)._chessNumber;
            int PosX = originBlackChessStepList.at(0)._deltaX;
            int PosY = originBlackChessStepList.at(0)._deltaY;
            bool camp = originBlackChessStepList.at(0)._chessCamp;
            QString campString = camp ? "Red" : "Black";
            bool kill = originBlackChessStepList.at(0)._isKill;
            QString killString = kill ? "True" : "False";
            int killNum = originBlackChessStepList.at(0)._chessKilledNum;
            int killNumber = originBlackChessStepList.at(0)._chessKilledNumber;
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
        }

        GlobalEnvirIn::Instance()->__delayMsec(250);

        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        redOrBlack = !redOrBlack;
    }
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
