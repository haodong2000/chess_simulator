#ifndef DEFINITIONCHESSSET_H
#define DEFINITIONCHESSSET_H

/*****************************************************************
*   File:     definitionChessSet.h
*   Author:   Haodong LI
*   Usage:    definition of all chesses
*   Time:     2021-05-31 -> 21:01:43
*****************************************************************/

#include "allBRChessesInclude.h"

black_horse    *Ab_hor_1 = new black_horse   (0, 1);
black_cannon   *Ab_can_1 = new black_cannon  (2, 1);
black_advisor  *Ab_adv_1 = new black_advisor (0, 3);
black_chariot  *Ab_cha_1 = new black_chariot (0, 0);
black_elephant *Ab_ele_1 = new black_elephant(0, 2);
black_horse    *Ab_hor_2 = new black_horse   (0, 7, "BHorse",    false, 2);
black_cannon   *Ab_can_2 = new black_cannon  (2, 7, "BCannon",   false, 2);
black_advisor  *Ab_adv_2 = new black_advisor (0, 5, "BAdvisor",  false, 2);
black_chariot  *Ab_cha_2 = new black_chariot (0, 8, "BChariot",  false, 2);
black_elephant *Ab_ele_2 = new black_elephant(0, 6, "BElephant", false, 2);

black_soldier  *Ab_sol_1 = new black_soldier(3, 0, "BSoldier",  false, 1);
black_soldier  *Ab_sol_2 = new black_soldier(3, 2, "BSoldier",  false, 2);
black_soldier  *Ab_sol_3 = new black_soldier(3, 4, "BSoldier",  false, 3);
black_soldier  *Ab_sol_4 = new black_soldier(3, 6, "BSoldier",  false, 4);
black_soldier  *Ab_sol_5 = new black_soldier(3, 8, "BSoldier",  false, 5);

black_general  *Ab_gen_1 = new black_general(0, 4);

red_horse      *Ar_hor_1 = new red_horse   (9, 1);
red_cannon     *Ar_can_1 = new red_cannon  (7, 1);
red_advisor    *Ar_adv_1 = new red_advisor (9, 3);
red_chariot    *Ar_cha_1 = new red_chariot (9, 0);
red_elephant   *Ar_ele_1 = new red_elephant(9, 2);
red_horse      *Ar_hor_2 = new red_horse   (9, 7, "RHorse",    true, 2);
red_cannon     *Ar_can_2 = new red_cannon  (7, 7, "RCannon",   true, 2);
red_advisor    *Ar_adv_2 = new red_advisor (9, 5, "RAdvisor",  true, 2);
red_chariot    *Ar_cha_2 = new red_chariot (9, 8, "RChariot",  true, 2);
red_elephant   *Ar_ele_2 = new red_elephant(9, 6, "RElephant", true, 2);

red_soldier    *Ar_sol_1 = new red_soldier(6, 0, "RSoldier", true, 1);
red_soldier    *Ar_sol_2 = new red_soldier(6, 2, "RSoldier", true, 2);
red_soldier    *Ar_sol_3 = new red_soldier(6, 4, "RSoldier", true, 3);
red_soldier    *Ar_sol_4 = new red_soldier(6, 6, "RSoldier", true, 4);
red_soldier    *Ar_sol_5 = new red_soldier(6, 8, "RSoldier", true, 5);

red_general    *Ar_gen_1 = new red_general(9, 4);


// old version
//red_horse    r_hor_1(9, 1);
//red_cannon   r_can_1(7, 1);
//red_advisor  r_adv_1(9, 3);
//red_chariot  r_cha_1(9, 0);
//red_elephant r_ele_1(9, 2);
//red_horse    r_hor_2(9, 7, "RHorse",    true, 2);
//red_cannon   r_can_2(7, 7, "RCannon",   true, 2);
//red_advisor  r_adv_2(9, 5, "RAdvisor",  true, 2);
//red_chariot  r_cha_2(9, 8, "RChariot",  true, 2);
//red_elephant r_ele_2(9, 6, "RElephant", true, 2);

//red_soldier  r_sol_1(6, 0, "RSoldier", true, 1);
//red_soldier  r_sol_2(6, 2, "RSoldier", true, 2);
//red_soldier  r_sol_3(6, 4, "RSoldier", true, 3);
//red_soldier  r_sol_4(6, 6, "RSoldier", true, 4);
//red_soldier  r_sol_5(6, 8, "RSoldier", true, 5);

//red_general  r_gen_1(9, 4);

#endif // DEFINITIONCHESSSET_H
