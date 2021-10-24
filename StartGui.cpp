#include "StartGui.h"
#include <QDateTime>
#include <QString>
#include <QDebug>
#include "Navigation.h"

/* * * * * * * * * * * * * * * * * * * * *
*   File:     StartGui.cpp
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-10-23
* * * * * * * * * * * * * * * * * * * * * */

StartGui::StartGui(QObject *parent) : QObject(parent){
    this->m_strMode = "Human_AI_CIMC_EndGame";
    this->m_intMode = 5;
    this->m_strDifficulty = "Hard-Level";
    this->m_intDifficulty = 3;
    this->m_nAge = 18;
    this->m_strEnd = "TestEnd";
    this->m_strManual = "TestManual";
    this->m_strBack = "TestBack";
    connect(&m_timer, &QTimer::timeout, this, &StartGui::getCurrentTime);
    this->m_timer.start(1000);
}

void StartGui::exitGameFunc(){
    qDebug()<<"退出游戏 (Exit the Game) ...";
    Is_Game_No_Play = true;
}

void StartGui::startGameFunc(){
    qDebug()<<"开始游戏 (Start the Game) ...";
    Is_Game_Start = true;
}

void StartGui::testFunc(){
    qDebug()<<"testFunc ...";
}

void StartGui::getCurrentTime(){
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    currentTime = QString("Time: ") + currentTime;
    this->refreshTime(currentTime);
//    int BASIC_DEPTH = 3;
//    int BEST_EXPONENT = BASIC_DEPTH * 2;
//    int MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
    switch (this->m_intDifficulty) {
    case 1:
        BASIC_DEPTH = 1;
        BEST_EXPONENT = BASIC_DEPTH * 2;
        MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
        if(Menu::IsInitTestMode) std::cout << "Difficulty Changed! Current Difficulty -> " << this->m_intDifficulty << std::endl;
        break;
    case 2:
        BASIC_DEPTH = 1;
        BEST_EXPONENT = BASIC_DEPTH * 2;
        MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
        if(Menu::IsInitTestMode) std::cout << "Difficulty Changed! Current Difficulty -> " << this->m_intDifficulty << std::endl;
        break;
    case 3:
        BASIC_DEPTH = 1;
        BEST_EXPONENT = BASIC_DEPTH * 2;
        MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
        if(Menu::IsInitTestMode) std::cout << "Difficulty Changed! Current Difficulty -> " << this->m_intDifficulty << std::endl;
        break;
    default:
        qDebug() << "InValid Difficulty! 1~3 Wanted!";
    }
    switch (this->m_intMode - 1) {
    case Menu::Mode::AI_AI:
        CHESS_PLAY_MODE = Menu::Mode::AI_AI;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::Human_AI:
        CHESS_PLAY_MODE = Menu::Mode::Human_AI;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::Human_Human:
        CHESS_PLAY_MODE = Menu::Mode::Human_Human;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::Human_AI_CIMC:
        CHESS_PLAY_MODE = Menu::Mode::Human_AI_CIMC;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::Human_AI_CIMC_EndGame:
        CHESS_PLAY_MODE = Menu::Mode::Human_AI_CIMC_EndGame;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::AI_AI_EndGame:
        CHESS_PLAY_MODE = Menu::Mode::AI_AI_EndGame;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::Human_AI_EndGame:
        CHESS_PLAY_MODE = Menu::Mode::Human_AI_EndGame;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    case Menu::Mode::Human_Human_EndGame:
        CHESS_PLAY_MODE = Menu::Mode::Human_Human_EndGame;
        if(Menu::IsInitTestMode) std::cout << "CHESS_PLAY_MODE Changed! Current CHESS_PLAY_MODE -> " << this->m_intMode << std::endl;
        break;
    default:
        qDebug() << "InValid Mode! 1~8 Wanted!";
    }
}
