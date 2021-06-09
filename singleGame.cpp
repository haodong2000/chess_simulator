#include "singleGame.h"

singleGame::singleGame():
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
//    allRedAndBlackStepList.clear();

    _level = 3; // initialization, actuall level is 4
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

void singleGame::oneLevelChessing(int maxCount) {
    // one level test, AI is black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 500;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        generateRedAllPossibleMoves();
        generateBlackAllPossibleMoves();
        if(redOrBlack && (!originRedChessStepList.empty())) {
            int sizeIndex = oneLevelStepIndex(redOrBlack);
            realMove(originRedChessStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!originBlackChessStepList.empty())) {
            int sizeIndex = oneLevelStepIndex(redOrBlack);
            realMove(originBlackChessStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:399 oneLevelChessing() error: originRedChessStepList or originBlackChessStepList is EMPTY!!!!!";
            return;
        }

        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
        }
        redOrBlack = !redOrBlack;
    }
}

int singleGame::oneLevelStepIndex(bool redOrBlack) {
    // 1. fakeMove()
    //      1. if level = L, then L numbers could represent all possible moves
    //      2. a state tree
    //          1. root
    //          2.
    // 2. selectBest()
    // https://blog.csdn.net/weixin_43867940/article/details/111881002?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
    int size = 0;
    int maxValue = -99999;
    int minValue = 99999;
    int sizeIndex = 0;
    int currentValue = 0;
    if(redOrBlack) {
        size = originRedChessStepList.size();
        for(int index = 0; index < size; index++) {
            // init
            currentValue = 0;
            // fakemove
            int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(originRedChessStepList.at(index)._chessNum, originRedChessStepList.at(index)._chessNumber)->getPosX();
            int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(originRedChessStepList.at(index)._chessNum, originRedChessStepList.at(index)._chessNumber)->getPosY();
            fakeMove(originRedChessStepList.at(index));
            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue < minValue) {
                minValue = currentValue;
                sizeIndex = index;
            }
//            GlobalEnvirIn::Instance()->__printBoard();
//            std::cout << index << " " << currentValue << " " << maxValue << " " << sizeIndex << std::endl;
            // restore
            fakeBackMove(originRedChessStepList.at(index), lastPosX, lastPosY);
        }
        // return the best
        return sizeIndex;
    }
    else {
        size = originBlackChessStepList.size();
        for(int index = 0; index < size; index++) {
            // init
            currentValue = 0;
            // fakemove
            int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(originBlackChessStepList.at(index)._chessNum, originBlackChessStepList.at(index)._chessNumber)->getPosX();
            int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(originBlackChessStepList.at(index)._chessNum, originBlackChessStepList.at(index)._chessNumber)->getPosY();
            fakeMove(originBlackChessStepList.at(index));
            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue > maxValue) {
                maxValue = currentValue;
                sizeIndex = index;
            }
//            GlobalEnvirIn::Instance()->__printBoard();
//            std::cout << index << " " << currentValue << " " << maxValue << " " << sizeIndex << std::endl;
            // restore
            fakeBackMove(originBlackChessStepList.at(index), lastPosX, lastPosY);
        }
        // return the best
        return sizeIndex;
    }
    qDebug() << "singleGame.cpp oneLevelStepIndex() line:456";
    return 0;
}

void singleGame::twoLevelChessing(int maxCount) {
    // two level test, AI is black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 500;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        int value = GlobalEnvirIn::Instance()->__BoardEvaluate();
        std::cout << "current value     -> " << value << std::endl;
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
            int sizeIndex = twoLevelStepIndex(redOrBlack);
            realMove(curStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = twoLevelStepIndex(redOrBlack);
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:499 twoLevelChessing() error: originRedChessStepList or originBlackChessStepList is EMPTY!!!!!";
            return;
        }

        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
        }
        redOrBlack = !redOrBlack;
    }
}

int singleGame::twoLevelStepIndex(bool redOrBlack) {
    int size = 0;
    int maxValue = -99999;
    int minValue = 99999;
    int sizeIndex = 0;
    int currentValue = 0;
    QVector<chessStep> levelOneStepList;
    levelOneStepList.clear();
    if(redOrBlack) {
        levelOneStepList.clear();
        levelOneStepList.append(originRedChessStepList);
        size = levelOneStepList.size();
        for(int index = 0; index < size; index++) {
            // init
            currentValue = 0;
            // fakemove
            int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosX();
            int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosY();
            fakeMove(levelOneStepList.at(index));
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(1000);

            // into level 2
            generateBlackAllPossibleMoves();
            QVector<chessStep> levelTwoList;
            levelTwoList.clear();
            levelTwoList.append(originBlackChessStepList);
            // execute black
            int blackIndex = oneLevelStepIndex(false);
            int lastBlackX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoList.at(blackIndex)._chessNum, levelTwoList.at(blackIndex)._chessNumber)->getPosX();
            int lastBlackY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoList.at(blackIndex)._chessNum, levelTwoList.at(blackIndex)._chessNumber)->getPosY();
            fakeMove(levelTwoList.at(blackIndex));
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(1000);
            generateRedAllPossibleMoves(); // generate red step list after black fakeMove!!!!!
            QVector<chessStep> levelTwoEnemy;
            levelTwoEnemy.clear();
            levelTwoEnemy.append(originRedChessStepList);
            int sizeTwo = levelTwoEnemy.size();
            for(int indexTwo = 0; indexTwo < sizeTwo; indexTwo++) {
                // init
                currentValue = 0;
                // fakemove
                int lastPosXTwo = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoEnemy.at(indexTwo)._chessNum, levelTwoEnemy.at(indexTwo)._chessNumber)->getPosX();
                int lastPosYTwo = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoEnemy.at(indexTwo)._chessNum, levelTwoEnemy.at(indexTwo)._chessNumber)->getPosY();
                fakeMove(levelTwoEnemy.at(indexTwo));
//                GlobalEnvirIn::Instance()->__printBoard();
//                std::cout << originRedChessStepList.at(indexTwo)._chessNum << " " << originRedChessStepList.at(indexTwo)._chessNumber << " " << lastPosX << " " << lastPosY << std::endl;
//                GlobalEnvirIn::Instance()->__delayMsec(1000);
                // evaluate
                currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                // compare
                if(currentValue < minValue) {
                    minValue = currentValue;
                    sizeIndex = index;
                }
                // restore
                fakeBackMove(levelTwoEnemy.at(indexTwo), lastPosXTwo, lastPosYTwo);
//                GlobalEnvirIn::Instance()->__printBoard();
//                GlobalEnvirIn::Instance()->__delayMsec(1000);
            }
            // restore black
            fakeBackMove(levelTwoList.at(blackIndex), lastBlackX, lastBlackY);
//            GlobalEnvirIn::Instance()->__printBoard();

            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue < minValue) {
                minValue = currentValue;
                sizeIndex = index;
            }
            // restore
            fakeBackMove(levelOneStepList.at(index), lastPosX, lastPosY);
//            GlobalEnvirIn::Instance()->__printBoard();
        }
        // return the best
        return sizeIndex;
    }
    else {
        levelOneStepList.clear();
        levelOneStepList.append(originBlackChessStepList);
        size = levelOneStepList.size();
        for(int index = 0; index < size; index++) {
            // init
            currentValue = 0;
            // fakemove
            int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosX();
            int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosY();
            fakeMove(levelOneStepList.at(index));

            // into level 2
            generateRedAllPossibleMoves();
            QVector<chessStep> levelTwoList;
            levelTwoList.clear();
            levelTwoList.append(originRedChessStepList);
            // execute red
            int redIndex = oneLevelStepIndex(true);
            int lastRedX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoList.at(redIndex)._chessNum, levelTwoList.at(redIndex)._chessNumber)->getPosX();
            int lastRedY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoList.at(redIndex)._chessNum, levelTwoList.at(redIndex)._chessNumber)->getPosY();
            fakeMove(levelTwoList.at(redIndex));
            generateBlackAllPossibleMoves(); // generate black after red fakeMove!!!!
            QVector<chessStep> levelTwoEnemy;
            levelTwoEnemy.clear();
            levelTwoEnemy.append(originBlackChessStepList);
            int sizeTwo = levelTwoEnemy.size();
            for(int indexTwo = 0; indexTwo < sizeTwo; indexTwo++) {
                // init
                currentValue = 0;
                // fakemove
                int lastPosXTwo = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoEnemy.at(indexTwo)._chessNum, levelTwoEnemy.at(indexTwo)._chessNumber)->getPosX();
                int lastPosYTwo = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoEnemy.at(indexTwo)._chessNum, levelTwoEnemy.at(indexTwo)._chessNumber)->getPosY();
                fakeMove(levelTwoEnemy.at(indexTwo));
                // evaluate
                currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                // compare
                if(currentValue > maxValue) {
                    maxValue = currentValue;
                    sizeIndex = index;
                }
                // restore
                fakeBackMove(levelTwoEnemy.at(indexTwo), lastPosXTwo, lastPosYTwo);
            }
            // restore red
            fakeBackMove(levelTwoList.at(redIndex), lastRedX, lastRedY);

            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue > maxValue) {
                maxValue = currentValue;
                sizeIndex = index;
            }
            // restore
            fakeBackMove(levelOneStepList.at(index), lastPosX, lastPosY);
        }
        // return the best
        return sizeIndex;
    }
    qDebug() << "singleGame.cpp twoLevelStepIndex() line:582";
    return 0;
}

void singleGame::threeLevelChessing(int maxCount) {
    // three level test, AI is black
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 50;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
        GlobalEnvirIn::Instance()->__printBoard();
        int value = GlobalEnvirIn::Instance()->__BoardEvaluate();
        std::cout << "current value     -> " << value << std::endl;
        GlobalEnvirIn::Instance()->__delayMsec(delayMs);

        if(redOrBlack) GlobalEnvirIn::Instance()->__setGameTurn(false);
        else GlobalEnvirIn::Instance()->__setGameTurn(true);

        GlobalEnvirIn::Instance()->__delayMsec(delayMs);
        QVector<chessStep> curStepList; // memory
        curStepList.clear();
        if(redOrBlack) {
            generateRedAllPossibleMoves();
            curStepList.append(originRedChessStepList);
        }
        else {
            generateBlackAllPossibleMoves();
            curStepList.append(originBlackChessStepList);
        }
        if(redOrBlack && (!curStepList.empty())) {
            int sizeIndex = threeLevelStepIndex(redOrBlack);
            realMove(curStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            int sizeIndex = threeLevelStepIndex(redOrBlack);
            realMove(curStepList.at(sizeIndex));
        }
        else {
            qDebug() << "singleGame.cpp line:499 threeLevelChessing() error: originRedChessStepList or originBlackChessStepList is EMPTY!!!!!";
            return;
        }

        gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive();
        if(gameIsOn == false) {
            if(Ab_gen_1->isAlive()) std::cout << "Black Win!" << std::endl;
            else std::cout << "Red Win!" << std::endl;
        }
        redOrBlack = !redOrBlack;
    }
}

int singleGame::threeLevelStepIndex(bool redOrBlack) {
    int size = 0;
    int maxValue = -99999;
    int minValue = 99999;
    int sizeIndex = 0;
    int currentValue = 0;
    QVector<chessStep> levelOneStepList;
    levelOneStepList.clear();
    if(redOrBlack) {
        levelOneStepList.clear();
        levelOneStepList.append(originRedChessStepList);
        size = levelOneStepList.size();
        for(int index = 0; index < size; index++) {
            // init
            currentValue = 0;
            // fakemove
            int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosX();
            int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosY();
            fakeMove(levelOneStepList.at(index));
            std::cout << "level = " << 1 << "  index = " << index << "  camp: red" << std::endl;
            GlobalEnvirIn::Instance()->__delayMsec(1);
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(500);

            // into level 2
            generateBlackAllPossibleMoves();
            QVector<chessStep> levelTwoStepList;
            levelTwoStepList.clear();
            levelTwoStepList.append(originBlackChessStepList);
            int indexTwo = twoLevelStepIndex(false);

            int lastTwoPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoStepList.at(indexTwo)._chessNum, levelTwoStepList.at(indexTwo)._chessNumber)->getPosX();
            int lastTwoPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoStepList.at(indexTwo)._chessNum, levelTwoStepList.at(indexTwo)._chessNumber)->getPosY();
            fakeMove(levelTwoStepList.at(indexTwo));

//            std::cout << "level = " << 2 << std::endl;
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(500);


            // into level 3
            generateRedAllPossibleMoves();
            QVector<chessStep> levelThreeStepList;
            levelThreeStepList.clear();
            levelThreeStepList.append(originRedChessStepList);
            int levelThreeeSize = levelThreeStepList.size();
            for(int indexThree = 0; indexThree < levelThreeeSize; indexThree++) {
                // init
                currentValue = 0;
                // fakemove
                int lastThreePosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelThreeStepList.at(indexThree)._chessNum, levelThreeStepList.at(indexThree)._chessNumber)->getPosX();
                int lastThreePosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelThreeStepList.at(indexThree)._chessNum, levelThreeStepList.at(indexThree)._chessNumber)->getPosY();
                fakeMove(levelThreeStepList.at(indexThree));
//                    std::cout << "level = " << 3 << std::endl;
//                    GlobalEnvirIn::Instance()->__printBoard();
//                    GlobalEnvirIn::Instance()->__delayMsec(500);

                // into level 4
                generateBlackAllPossibleMoves();
                QVector<chessStep> levelFourStepList;
                levelFourStepList.clear();
                levelFourStepList.append(originBlackChessStepList);
                int indexFour = oneLevelStepIndex(false);
                int lastFourPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFourStepList.at(indexFour)._chessNum, levelFourStepList.at(indexFour)._chessNumber)->getPosX();
                int lastFourPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFourStepList.at(indexFour)._chessNum, levelFourStepList.at(indexFour)._chessNumber)->getPosY();
                fakeMove(levelFourStepList.at(indexFour));

                // into level 5
                generateRedAllPossibleMoves();
                QVector<chessStep> levelFiveStepList;
                levelFiveStepList.clear();
                levelFiveStepList.append(originRedChessStepList);
                int levelFiveSize = levelFiveStepList.size();
                for(int indexFive = 0; indexFive < levelFiveSize; indexFive++) {
                    // init
                    currentValue = 0;
                    // fakemove
                    int lastFivePosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFiveStepList.at(indexFive)._chessNum, levelFiveStepList.at(indexFive)._chessNumber)->getPosX();
                    int lastFivePosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFiveStepList.at(indexFive)._chessNum, levelFiveStepList.at(indexFive)._chessNumber)->getPosY();
                    fakeMove(levelFiveStepList.at(indexFive));
//                            std::cout << "level = " << 5 << std::endl;
//                            GlobalEnvirIn::Instance()->__printBoard();
//                            GlobalEnvirIn::Instance()->__delayMsec(500);

                    // evaluate
                    currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                    // compare
                    if(currentValue < minValue) {
                        minValue = currentValue;
                        sizeIndex = index;
                    }
                    // restore
                    fakeBackMove(levelFiveStepList.at(indexFive), lastFivePosX, lastFivePosY);
//                            GlobalEnvirIn::Instance()->__printBoard();
//                            GlobalEnvirIn::Instance()->__delayMsec(500);
                }

                // evaluate
                currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                // compare
                if(currentValue < minValue) {
                    minValue = currentValue;
                    sizeIndex = index;
                }
                // restore
                fakeBackMove(levelFourStepList.at(indexFour), lastFourPosX, lastFourPosY);

                // evaluate
                currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                // compare
                if(currentValue < minValue) {
                    minValue = currentValue;
                    sizeIndex = index;
                }
                // restore
                fakeBackMove(levelThreeStepList.at(indexThree), lastThreePosX, lastThreePosY);
//                    GlobalEnvirIn::Instance()->__printBoard();
//                    GlobalEnvirIn::Instance()->__delayMsec(500);
            }


            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue < minValue) {
                minValue = currentValue;
                sizeIndex = index;
            }
            // restore
            fakeBackMove(levelTwoStepList.at(indexTwo), lastTwoPosX, lastTwoPosY);
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(500);

            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue < minValue) {
                minValue = currentValue;
                sizeIndex = index;
            }
            // restore
            fakeBackMove(levelOneStepList.at(index), lastPosX, lastPosY);
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(500);
        }
        // return the best
        return sizeIndex;
    }
    else {
        levelOneStepList.clear();
        levelOneStepList.append(originBlackChessStepList);
        size = levelOneStepList.size();
        for(int index = 0; index < size; index++) {
            // init
            currentValue = 0;
            // fakemove
            int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosX();
            int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelOneStepList.at(index)._chessNum, levelOneStepList.at(index)._chessNumber)->getPosY();
            fakeMove(levelOneStepList.at(index));

            std::cout << "level = " << 1 << "  index = " << index << "  camp: black" << std::endl;
            GlobalEnvirIn::Instance()->__delayMsec(1);
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(500);

            // into level 2
            generateRedAllPossibleMoves();
            QVector<chessStep> levelTwoStepList;
            levelTwoStepList.clear();
            levelTwoStepList.append(originRedChessStepList);
            int indexTwo = twoLevelStepIndex(true);

            int lastTwoPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoStepList.at(indexTwo)._chessNum, levelTwoStepList.at(indexTwo)._chessNumber)->getPosX();
            int lastTwoPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelTwoStepList.at(indexTwo)._chessNum, levelTwoStepList.at(indexTwo)._chessNumber)->getPosY();
            fakeMove(levelTwoStepList.at(indexTwo));


            // into level 3
            generateBlackAllPossibleMoves();
            QVector<chessStep> levelThreeStepList;
            levelThreeStepList.clear();
            levelThreeStepList.append(originBlackChessStepList);
            int levelThreeeSize = levelThreeStepList.size();
            for(int indexThree = 0; indexThree < levelThreeeSize; indexThree++) {
                // init
                currentValue = 0;
                // fakemove
                int lastThreePosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelThreeStepList.at(indexThree)._chessNum, levelThreeStepList.at(indexThree)._chessNumber)->getPosX();
                int lastThreePosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelThreeStepList.at(indexThree)._chessNum, levelThreeStepList.at(indexThree)._chessNumber)->getPosY();
                fakeMove(levelThreeStepList.at(indexThree));

                // into level 4
                generateRedAllPossibleMoves();
                QVector<chessStep> levelFourStepList;
                levelFourStepList.clear();
                levelFourStepList.append(originRedChessStepList);
                int indexFour = oneLevelStepIndex(true);
                int lastFourPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFourStepList.at(indexFour)._chessNum, levelFourStepList.at(indexFour)._chessNumber)->getPosX();
                int lastFourPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFourStepList.at(indexFour)._chessNum, levelFourStepList.at(indexFour)._chessNumber)->getPosY();
                fakeMove(levelFourStepList.at(indexFour));

                // into level 5
                generateBlackAllPossibleMoves();
                QVector<chessStep> levelFiveStepList;
                levelFiveStepList.clear();
                levelFiveStepList.append(originBlackChessStepList);
                int levelFiveSize = levelFiveStepList.size();
                for(int indexFive = 0; indexFive < levelFiveSize; indexFive++) {
                    // init
                    currentValue = 0;

                    // fakemove
                    int lastFivePosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFiveStepList.at(indexFive)._chessNum, levelFiveStepList.at(indexFive)._chessNumber)->getPosX();
                    int lastFivePosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(levelFiveStepList.at(indexFive)._chessNum, levelFiveStepList.at(indexFive)._chessNumber)->getPosY();
                    fakeMove(levelFiveStepList.at(indexFive));
                    // evaluate
                    currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                    // compare
                    if(currentValue > maxValue) {
                        maxValue = currentValue;
                        sizeIndex = index;
                    }
                    // restore
                    fakeBackMove(levelFiveStepList.at(indexFive), lastFivePosX, lastFivePosY);
                }

                // evaluate
                currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                // compare
                if(currentValue > maxValue) {
                    maxValue = currentValue;
                    sizeIndex = index;
                }
                // restore
                fakeBackMove(levelFourStepList.at(indexFour), lastFourPosX, lastFourPosY);

                // evaluate
                currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
                // compare
                if(currentValue > maxValue) {
                    maxValue = currentValue;
                    sizeIndex = index;
                }
                // restore
                fakeBackMove(levelThreeStepList.at(indexThree), lastThreePosX, lastThreePosY);
            }


            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue > maxValue) {
                maxValue = currentValue;
                sizeIndex = index;
            }
            // restore
            fakeBackMove(levelTwoStepList.at(indexTwo), lastTwoPosX, lastTwoPosY);


            // evaluate
            currentValue += GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
            // compare
            if(currentValue > maxValue) {
                maxValue = currentValue;
                sizeIndex = index;
            }
            // restore
            fakeBackMove(levelOneStepList.at(index), lastPosX, lastPosY);
//            std::cout << "level = " << 1 << "=====================BACK" << std::endl;
//            GlobalEnvirIn::Instance()->__printBoard();
//            GlobalEnvirIn::Instance()->__delayMsec(500);
        }
        // return the best
        return sizeIndex;
    }
    qDebug() << "singleGame.cpp threeLevelStepIndex() line:822";
    return 0;
}

void singleGame::normalPlay(int maxCount) {
    // alpha-beta
    bool gameIsOn = true;
    bool redOrBlack = true;
    int count = 0;
    const int delayMs = 250;
    while(gameIsOn && (count++) < maxCount) {
        std::cout << "count chess moves -> " << count << std::endl;
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
            int sizeIndex = normalPlayIndex(redOrBlack);
            realMove(curStepList.at(sizeIndex));
        }
        else if(!redOrBlack && (!curStepList.empty())) {
            curStepList.append(originBlackChessStepList);
            int sizeIndex = normalPlayIndex(redOrBlack);
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
        }
        redOrBlack = !redOrBlack;
    }
}

int singleGame::normalPlayIndex(bool redOrBlack) {
    QVector<chessStep> allRedAndBlackStepList;
    generateRedAllPossibleMoves(); // refresh
    generateBlackAllPossibleMoves();
    allRedAndBlackStepList.clear();
    allRedAndBlackStepList.append(originRedChessStepList);
    allRedAndBlackStepList.append(originBlackChessStepList);

    int redSize = originRedChessStepList.size();
    int blackSize = originBlackChessStepList.size();
    int allSize = allRedAndBlackStepList.size();

    int curValue = 0;
    int bestValueRed = 999;
    int bestValueBlack = -999;
    int retIndex = 0;
    int initAlpha = -99999;
    int initBeta = 99999;

    for(int index = (redOrBlack ? 0 : redSize); index < (redOrBlack ? redSize : allSize); index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedAndBlackStepList.at(index)._chessNum, allRedAndBlackStepList.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedAndBlackStepList.at(index)._chessNum, allRedAndBlackStepList.at(index)._chessNumber)->getPosY();
        fakeMove(allRedAndBlackStepList.at(index));
//        std::cout << "INDEX ***********************************************************" << std::endl;
//        GlobalEnvirIn::Instance()->__printBoard();
//        GlobalEnvirIn::Instance()->__delayMsec(1000);
        // alpha-beta
        // curValue = alpha_beta(_level, initAlpha, initBeta, redOrBlack);
        curValue = alpha_beta(2, initAlpha, initBeta, redOrBlack);
        fakeBackMove(allRedAndBlackStepList.at(index), lastPosX, lastPosY);
//        std::cout << "BACK ***********************************************************" << std::endl;
//        GlobalEnvirIn::Instance()->__printBoard();
//        GlobalEnvirIn::Instance()->__delayMsec(1000);
        // compare
        if(redOrBlack) { // MIN
            retIndex = (curValue < bestValueRed) ?  index : retIndex;
            bestValueRed = (curValue < bestValueRed) ? curValue : bestValueRed;
        }
        else {
            retIndex = (curValue > bestValueBlack) ?  (index - redSize) : retIndex;
            bestValueBlack = (curValue > bestValueBlack) ? curValue : bestValueBlack;
        }
    }
    // return best
    return retIndex;
    qDebug() << "singleGame.cpp normalPlayIndex() line:691";
    return 0;
}

int singleGame::alpha_beta(int depth, int alpha, int beta, bool redOrBlack) {
    /*function alpha-beta(depth, alpha, beta) {
        for every moves:
            fakeMove();
            ret = alpha-beta(depth + 1, alpha, beta)
            fakeBackMove();
            if MAX, alpha = max(alpha, ret)
            else if MIN, beta = min(beta, ret)
            if beta <= alpha return (MAX ? alpha : beta)
        return (MAX ? alpha : beta)
    }*/
    if(depth == 1) return GlobalEnvirIn::Instance()->__BoardEvaluate(); // black - red
    // black -> MAX
    // red   -> MIN
    bool MIN = redOrBlack;
    bool MAX = !MIN;
    int retValue = 0;

    QVector<chessStep> allRedAndBlackStepList;
    generateRedAllPossibleMoves(); // refresh
    generateBlackAllPossibleMoves();
    allRedAndBlackStepList.clear();
    allRedAndBlackStepList.append(originRedChessStepList);
    allRedAndBlackStepList.append(originBlackChessStepList);

    int redSize = originRedChessStepList.size();
    int blackSize = originBlackChessStepList.size();
    int allSize = allRedAndBlackStepList.size();

    for(int index = (redOrBlack ? 0 : redSize); index < (redOrBlack ? redSize : allSize); index++) {
        int lastPosX = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedAndBlackStepList.at(index)._chessNum, allRedAndBlackStepList.at(index)._chessNumber)->getPosX();
        int lastPosY = GlobalEnvirIn::Instance()->__QStrOrInt2Chess(allRedAndBlackStepList.at(index)._chessNum, allRedAndBlackStepList.at(index)._chessNumber)->getPosY();
        fakeMove(allRedAndBlackStepList.at(index));
//        GlobalEnvirIn::Instance()->__printBoard();
//        GlobalEnvirIn::Instance()->__delayMsec(1000);
        retValue = alpha_beta(depth - 1, alpha, beta, !redOrBlack);
        fakeBackMove(allRedAndBlackStepList.at(index), lastPosX, lastPosY);
//        GlobalEnvirIn::Instance()->__printBoard();
//        GlobalEnvirIn::Instance()->__delayMsec(1000);
        if(MAX) alpha = qMax(alpha, retValue);
        if(MIN) beta = qMin(beta, retValue);
//        std::cout << alpha << " " << beta << std::endl;
//        if(alpha >= beta) return (MAX ? alpha : beta);
//        if(MAX && (beta >= alpha)) return ((MAX) ? alpha : beta);
//        if(MIN && (beta <= alpha)) return ((MAX) ? alpha : beta);
    }

    return ((MAX) ? alpha : beta);
}

bool singleGame::compareSteps(chessStep last, chessStep current) {
    if(last._chessNum == current._chessNum &&
            last._chessNumber == current._chessNumber &&
            last._chessCamp == current._chessCamp &&
            last._deltaX == current._deltaX) {
        if(last._isKill == true && current._isKill == true) {
            if(last._chessKilledNum == current._chessKilledNumber &&
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
    }
    QmlConnectIn::Instance()->changeChessPos(Num, Number, camp, PosX - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosX(), PosY - GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, Number)->getPosY());
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

void singleGame::realBackMove(chessStep step) {
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
