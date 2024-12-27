/*
 * software_timer.c
 *
 *  Created on: Nov 1, 2024
 *      Author: THUAN
 */

#include "software_timer.h"

int timerCounter[MAX_TIMER] = {0};
int timerFlag[MAX_TIMER] = {0};

void setTimer(int duration, int index)
{
	timerCounter[index] = duration;
	timerFlag[index] = 0;
}

void timerRun()
{
	for (int i = 0; i < MAX_TIMER; i++)
	{
		if (timerCounter[i] > 0)
		{
			timerCounter[i]--;
			if (timerCounter[i] <= 0)
			{
				timerFlag[i] = 1;
			}
		}
	}
}
