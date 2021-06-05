#include "Advisor.h"

namespace AdvisorPos {
    const int b_up_y = 3;
    const int b_down_y = 5;
    const int b_left_x = 0;
    const int b_right_x = 2;
    const int r_up_y = 3;
    const int r_down_y = 5;
    const int r_left_x = 0 + 7;
    const int r_right_x = 2 + 7;

    const int b_mid_x = 1;
    const int b_mid_y = 4;
    const int r_mid_x = 1 + 7;
    const int r_mid_y = 4;
}

Advisor::Advisor(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Advisor::space_value() {
    double countMoveModeNum = 0;
    if(!isAlive()) return 0;
    if(!canChessMove()) return 0;
    if(canChessMove()) countMoveModeNum = chessMoveNum();
    return countMoveModeNum/PARAM::globalEnvironment::maxAdvisorMove;
}

double Advisor::chessMoveNum() {
    bool camp = chessCamp();
    int count = 0;
    switch (camp) {
    case false: // black
        if((getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_down_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_down_y)) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_mid_x, AdvisorPos::b_mid_y)))
                count = 1;
        }
        else if(getPosX() == AdvisorPos::b_mid_x && getPosY() == AdvisorPos::b_mid_y) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_down_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_down_y))) count++;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of black Advisor!";
        break;
    case true: // red
        if((getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_down_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_down_y)) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_mid_x, AdvisorPos::r_mid_y)))
                count = 1;
        }
        else if(getPosX() == AdvisorPos::r_mid_x && getPosY() == AdvisorPos::r_mid_y) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_down_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_down_y))) count++;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of red Advisor!";
        break;
    default:
        qDebug() << "Advisor.cpp canChessMove() chessCamp() invalid!";
        break;
    }
    return count;
}

bool Advisor::canChessMove() {
    bool camp = chessCamp();
    switch (camp) {
    case false: // black
        if((getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_down_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_down_y))
            return !(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_mid_x, AdvisorPos::b_mid_y));
        else if(getPosX() == AdvisorPos::b_mid_x && getPosY() == AdvisorPos::b_mid_y) {
            bool retCanMove = (GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_down_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_down_y));
            return !retCanMove;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of black Advisor!";
        break;
    case true: // red
        if((getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_down_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_down_y))
            return !(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_mid_x, AdvisorPos::r_mid_y));
        else if(getPosX() == AdvisorPos::r_mid_x && getPosY() == AdvisorPos::r_mid_y) {
            bool retCanMove = (GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_down_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_down_y));
            return !retCanMove;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of red Advisor!";
        break;
    default:
        qDebug() << "Advisor.cpp canChessMove() chessCamp() invalid!";
        break;
    }
    return true;
}

void Advisor::generateMove() {

}
