/*
 * software_timer.h
 *
 *  Created on: Sep 25, 2022
 *      Author: binch
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

extern int timer0_counter;
extern int timer1_counter;

extern int Hz;
extern int TIMER_CYCLE;

void setTimer0(int);
void setTimer1(int);
void setTimer2(int);
void setTimer3(int);
void timerRun(void);
int Hz_to_mSec(int);

#endif /* INC_SOFTWARE_TIMER_H_ */
