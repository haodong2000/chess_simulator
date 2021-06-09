#ifndef SINGLEGAME_H
#define SINGLEGAME_H

/*****************************************************************
*   File:     singleGame.h
*   Author:   Haodong LI
*   Usage:    alpha-beta
*   Time:     2021-06-06 -> 14:25:53
*****************************************************************/

#include "Step.h"
#include "global.h"
#include "allBRChessesInclude.h"
#include "globalChesses.h"
#include <QVector>
#include <QtGlobal>

class singleGame
{
public:
    singleGame();
    virtual void setLevel(int level);
    virtual int getLevel();
    virtual void generateBlackAllPossibleMoves();
    virtual void displayBlackAllPossibleMoves();
    virtual void SdisplayBlackAllPossibleMoves();
    virtual void generateRedAllPossibleMoves();
    virtual void displayRedAllPossibleMoves();
    virtual void SdisplayRedAllPossibleMoves();
    virtual void tranStructToClass();
    virtual void testChessing(int maxCount = 5);
    virtual void testFakeChessing(int maxCount = 5);
    virtual void testStepClass();
    virtual void testFakeBackMove();
    virtual int generateRandomNumber(int maxInt);
    virtual bool compareSteps(chessStep last, chessStep current);

    // real play
    virtual void oneLevelChessing(int maxCount);
    virtual int oneLevelStepIndex(bool redOrBlack);
    virtual void twoLevelChessing(int maxCount);
    virtual int twoLevelStepIndex(bool redOrBlack);
    virtual void threeLevelChessing(int maxCount);
    virtual int threeLevelStepIndex(bool redOrBlack);
    virtual void normalPlay(int maxCount);
    virtual int normalPlayIndex(bool redOrBlack);
    virtual int alpha_beta(int depth, int alpha, int beta, bool redOfBlack);

    // interface
    virtual void realMove(chessStep step);
    virtual void fakeMove(chessStep step);
    virtual void realBackMove(chessStep step, int lastPosX, int lastPosY);
    virtual void fakeBackMove(chessStep step, int lastPosX, int lastPosY);
    virtual void realMove(chessStep* step);
    virtual void fakeMove(chessStep* step);
    virtual void realBackMove(chessStep* step, int lastPosX, int lastPosY);
    virtual void fakeBackMove(chessStep* step, int lastPosX, int lastPosY);

    Step* finalChessStep;
    QVector<Step*> chessBlackStepList;
    QVector<Step*> chessRedStepList;
    QVector<chessStep> originBlackChessStepList;
    QVector<chessStep> originRedChessStepList;
    QVector<chessStep*> SoriginBlackChessStepList;
    QVector<chessStep*> SoriginRedChessStepList;
//    QVector<chessStep> allRedAndBlackStepList;
    chessStep redCurStep;
    chessStep redLastStep;
    chessStep blackCurStep;
    chessStep blackLastStep;

private:
    int _level;
};

typedef NormalSingleton< singleGame > singleGameIn;

#endif // SINGLEGAME_H
