/*
 * software_timer.h
 *
 *  Created on: Nov 1, 2024
 *      Author: THUAN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define MAX_TIMER 10

extern int timerFlag[MAX_TIMER];

void setTimer(int duration, int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
