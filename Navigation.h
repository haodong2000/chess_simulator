#ifndef NAVIGATION_H
#define NAVIGATION_H

/*****************************************************************
*   File:     Navigation.h
*   Author:   Haodong LI
*   Usage:    Navigation of chess playing mode
*   Time:     2021-08-03 -> 21:53:11
*****************************************************************/

namespace Menu {
    // play mode: AI-AI Human-AI Human-Human Human-AI(CIMC) Human-AI(EndGame&CIMC) Human-AI(EndGame) Human-Human(EndGame)
    enum Mode {
        AI_AI = 0,
        Human_AI,
        Human_Human,
        Human_AI_CIMC,
        Human_AI_CIMC_EndGame,
        Human_AI_EndGame,
        Human_Human_EndGame
    };
    // endGame mode: MeiHuaPu, JuZhongMi, MengRuShenJi, HuYaJi, TaoLueYuanJi, YuanShenHaiKuo
    enum Manual {
        MeiHuaPu = 0,
        JuZhongMi,
        MengRuShenJi,
        HuYaJi,
        TaoLueYuanJi,
        YuanShenHaiKuo,
        Mijinbaolue
    };
}

#endif // NAVIGATION_H
