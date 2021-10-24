#include "StartGui.h"
#include <QDateTime>
#include <QString>
#include <QDebug>

StartGui::StartGui(QObject *parent) : QObject(parent){
    this->m_strName = "悟空";
    this->m_nAge = 18;
    connect(&m_timer, &QTimer::timeout, this, &StartGui::getCurrentTime);
    this->m_timer.start(1000);  //启动定时器
}

void StartGui::exitGameFunc(){
    qDebug()<<"退出游戏 (Exit the Game) ...";
    Is_Game_No_Play = true;
}

void StartGui::startGameFunc(){
    qDebug()<<"开始游戏 (Start the Game) ...";
    Is_Game_Start = true;
}

void StartGui::testFunc03(){
    qDebug()<<"普通公有方法 ...";
}

void StartGui::getCurrentTime(){
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    this->refreshTime(currentTime);
}
