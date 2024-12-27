/*
 * global.h
 *
 *  Created on: Nov 1, 2024
 *      Author: THUAN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "traffic_light.h"
#include "software_timer.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
//#include "scheduler.h"
#include "i2c-lcd.h"

#define INIT			0
#define AUTO_RED_GREEN	1
#define AUTO_RED_YELLOW	2
#define AUTO_GREEN_RED 	3
#define AUTO_YELLOW_RED	4

#define MAN_INIT		10
#define MAN_RED			11
#define MAN_GREEN		12
#define MAN_YELLOW		13

#define SET_RED			21
#define SET_GREEN		22
#define SET_YELLOW		23

extern int time_buffer[2];
extern int time_buffer_idx;

extern int state;
extern int red, green, yellow;
int man_red, man_green, man_yellow;


#endif /* INC_GLOBAL_H_ */
