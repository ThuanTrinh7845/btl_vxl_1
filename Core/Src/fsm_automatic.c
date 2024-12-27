/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2024
 *      Author: THUAN
 */

#include "fsm_automatic.h"

void update_buffer()
{
	time_buffer[0]--;
	time_buffer[1]--;
}

void fsm_automatic_run()
{

	switch(state)
	{
		case INIT:
			HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
			HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

			HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
			HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);


			if (red - (yellow + green) > 0)
			{
				green += red - (yellow + green);
			}
			if (red - (yellow + green) < 0)
			{
				red += (yellow + green) - red;
			}

			if (1)
			{
				setTimer(100, 1);
				state = AUTO_RED_GREEN;

				time_buffer[0] = red;
				time_buffer[1] = green;
			}
			break;
		case AUTO_RED_GREEN:
			red_green();

			if (timerFlag[1] == 1)
			{
				setTimer(100, 1);
				time_buffer[0]--;
				time_buffer[1]--;
			}

			if (time_buffer[1] <= 0)
			{
				setTimer(100, 1);
				state = AUTO_RED_YELLOW;
				time_buffer[1] = yellow;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		case AUTO_RED_YELLOW:
			red_yellow();

			if (timerFlag[1] == 1)
			{
				setTimer(100, 1);
				time_buffer[0]--;
				time_buffer[1]--;
			}
			if (time_buffer[0] <= 0)
			{
				setTimer(100, 1);
				state = AUTO_GREEN_RED;


				time_buffer[0] = green;
				time_buffer[1] = red;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		case AUTO_GREEN_RED:
			green_red();

			if (timerFlag[1] == 1)
			{
				setTimer(100, 1);
				time_buffer[0]--;
				time_buffer[1]--;
			}


			if (time_buffer[0] <= 0)
			{
				state = AUTO_YELLOW_RED;
				setTimer(100, 1);

				time_buffer[0] = yellow;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		case AUTO_YELLOW_RED:
			yellow_red();

			if (timerFlag[1] == 1)
			{
				setTimer(100, 1);
				time_buffer[0]--;
				time_buffer[1]--;
			}


			if (time_buffer[0] <= 0)
			{
				state = AUTO_RED_GREEN;
				setTimer(100, 1);

				time_buffer[0] = red;
				time_buffer[1] = green;

			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		default:
			break;
	}

}
