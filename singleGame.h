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

#include <QTcpSocket>
#include <QTcpServer>

#include <vision_thread.h>

extern vision_thread *vision;

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
    virtual void oneLevelChessing_HumanVSAI(int maxCount);
    virtual void S_oneLevelChessing(int maxCount);
    virtual int oneLevelStepIndex(bool redOrBlack);
    virtual int S_oneLevelStepIndex(bool redOrBlack);
    virtual void twoLevelChessing(int maxCount);
    virtual void twoLevelChessing_HumanVSAI(int maxCount);
    virtual void S_twoLevelChessing(int maxCount);
    virtual int twoLevelStepIndex(bool redOrBlack);
    virtual int S_twoLevelStepIndex(bool redOrBlack);
    virtual void threeLevelChessing(int maxCount);
    virtual void threeLevelChessing_HumanVSAI(int maxCount);
    virtual int threeLevelStepIndex(bool redOrBlack);
    virtual void S_threeLevelChessing(int maxCount);
    virtual int S_threeLevelStepIndex(bool redOrBlack);
    virtual void normalPlay(int maxCount);
    virtual void normalPlay_HumanVSAI(int maxCount);
    virtual void normalPlay_HumanVSHuman(int maxCount);
    virtual void normalPlay_HumanVSAI_CIMC(int maxCount);
    virtual void normalPlay_HumanVSAI_CIMC_EndGame(int maxCount);
    virtual int MonteCarloTree_black(int depth);
    virtual int QuiescentSearch_black(int depth);
    virtual int Quiescent_alpha_beta_getMin(int depth, int curMin);
    virtual int Quiescent_alpha_beta_getMax(int depth, int curMax);
    virtual int alpha_beta_black(int depth);
    virtual int alpha_beta_red(int depth);
    virtual int alpha_beta_getMin(int depth, int curMin);
    virtual int alpha_beta_getMax(int depth, int curMax);
    virtual int alpha_beta_try(int depth, int alpha, int beta, bool redOrBlack);
    virtual int normalPlayIndex_old(bool redOrBlack);
    virtual int alpha_beta_old(int depth, int alpha, int beta, bool redOfBlack);

    // interface
    virtual void realMove(chessStep step);
    virtual void fakeMove(chessStep step);
    virtual void realBackMove(chessStep step, int lastPosX, int lastPosY);
    virtual void fakeBackMove(chessStep step, int lastPosX, int lastPosY);
    virtual void realMove(chessStep* step);
    virtual void fakeMove(chessStep* step);
    virtual void realBackMove(chessStep* step, int lastPosX, int lastPosY);
    virtual void fakeBackMove(chessStep* step, int lastPosX, int lastPosY);
    virtual bool humanMove();
    virtual bool humanMove_black();
    virtual bool isHumanStepValid(chessStep step);
    virtual bool isHumanStepValid_black(chessStep step);

    virtual void deleteStepList(QVector<chessStep*>& stepList);

    int VisionHumanStepIndex(const QVector<chessStep>& curStepList);

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

//private slots:
//    void M1_client_disconnect();

private:
    int _level;
    int R_value;
    QTcpSocket* M1_client = new QTcpSocket();
};

typedef NormalSingleton< singleGame > singleGameIn;

#endif // SINGLEGAME_H
