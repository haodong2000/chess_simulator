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
    this->m_strEnd = "EndGame_Mode";
    this->m_intEnd = 1;
    this->m_strManual = "Mei Hua Pu";
    this->m_intManual = 1;
    this->m_strBack = "Picture_Mode";
    this->m_intBack = 1;
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

void StartGui::exitInfoFunc() {
    qDebug()<<"我已知晓 (I Understand)";
    object->setProperty(QString("infomationDone").toLatin1(), true);
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
        BASIC_DEPTH = 2;
        BEST_EXPONENT = BASIC_DEPTH * 2;
        MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
        if(Menu::IsInitTestMode) std::cout << "Difficulty Changed! Current Difficulty -> " << this->m_intDifficulty << std::endl;
        break;
    case 3:
        BASIC_DEPTH = 3;
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
    switch (this->m_intManual - 1) {
    case Menu::Manual::MeiHuaPu:
        STRATEGY_MODE = Menu::Manual::MeiHuaPu;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::JuZhongMi:
        STRATEGY_MODE = Menu::Manual::JuZhongMi;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::MengRuShenJi:
        STRATEGY_MODE = Menu::Manual::MengRuShenJi;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::HuYaJi:
        STRATEGY_MODE = Menu::Manual::HuYaJi;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::TaoLueYuanJi:
        STRATEGY_MODE = Menu::Manual::TaoLueYuanJi;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::YuanShenHaiKuo:
        STRATEGY_MODE = Menu::Manual::YuanShenHaiKuo;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::MiJinBaoLue:
        STRATEGY_MODE = Menu::Manual::MiJinBaoLue;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    case Menu::Manual::inValidHaHa:
        STRATEGY_MODE = Menu::Manual::inValidHaHa;
        if(Menu::IsInitTestMode) std::cout << "Manual Changed! Current Manual -> " << this->m_intManual << std::endl;
        break;
    default:
        qDebug() << "InValid Mode! 1~8 Wanted!";
    }
    switch (this->m_intBack) {
    case 1:
        BACKGROUND_MODE = Menu::Background::ChristmasTree;
        if(Menu::IsInitTestMode) std::cout << "Background Changed! Current Background -> " << this->m_intBack << std::endl;
        break;
    case 0:
        BACKGROUND_MODE = Menu::Background::NoBackGround;
        if(Menu::IsInitTestMode) std::cout << "Background Changed! Current Background -> " << this->m_intBack << std::endl;
        break;
    default:
        qDebug() << "InValid Mode! 0~1 Wanted!";
    }
}
