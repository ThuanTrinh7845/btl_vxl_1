/*
 * global.c
 *
 *  Created on: Nov 1, 2024
 *      Author: THUAN
 */

#include "global.h"

// led7_segment
int time_buffer[2];
int time_buffer_idx = 0;
// fsm
int state = INIT;
// time
int red = 5, green = 3, yellow = 2;
int man_red = 0, man_green = 0, man_yellow = 0;
