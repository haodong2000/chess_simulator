#ifndef NAVIGATION_H
#define NAVIGATION_H

/*****************************************************************
*   File:     Navigation.h
*   Author:   Haodong LI
*   Usage:    Navigation of chess playing mode
*   Time:     2021-08-03 -> 21:53:11
*****************************************************************/

#include <unordered_map>
#include <QString>

namespace Menu {
    const bool IsInitTestMode = false;
    // play mode: AI-AI Human-AI Human-Human Human-AI(CIMC) Human-AI(EndGame&CIMC) Human-AI(EndGame) Human-Human(EndGame)
    enum Mode {
        AI_AI = 0,
        Human_AI,
        Human_Human,
        Human_AI_CIMC,
        Human_AI_CIMC_EndGame,
        AI_AI_EndGame,
        Human_AI_EndGame,
        Human_Human_EndGame,
        Test_Mode
    };
    // endGame mode: MeiHuaPu, JuZhongMi, MengRuShenJi, HuYaJi, TaoLueYuanJi, YuanShenHaiKuo
    enum Manual {
        MeiHuaPu = 0,
        JuZhongMi,
        MengRuShenJi,
        HuYaJi,
        TaoLueYuanJi,
        YuanShenHaiKuo,
        MiJinBaoLue,
        inValidHaHa
    };

    enum Background {
        NoBackGround = 0,
        ChristmasTree,
        GreenAurora,
        PurpleAurora,
        NaturalScenery,
        Kitty,
        Castle,
        Rome,
        Salzburg,
        Waterlicht,
        Terraces,
        Lion,
        Houses
    };
    const std::unordered_map<int, QString> BackgroundUrl{
        {0, "No Background"},
        {1, "../background/ChristmasTree.jpg"},
        {2, "../background/GreenAurora.jpg"},
        {3, "../background/PurpleAurora.jpg"},
        {4, "../background/NaturalScenery.jpg"},
        {5, "../background/Kitty.jpg"},
        {6, "../background/Castle.jpg"},
        {7, "../background/Rome.jpg"},
        {8, "../background/Salzburg.jpg"},
        {9, "../background/Waterlicht.jpg"},
        {10, "../background/Terraces.jpg"},
        {11, "../background/Lion.jpg"},
        {12, "../background/Houses.jpg"},
    };
}

#endif // NAVIGATION_H
