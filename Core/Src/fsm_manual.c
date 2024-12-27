/*
 * fsm_manual.c
 *
 *  Created on: Nov 3, 2024
 *      Author: THUAN
 */

#include "fsm_manual.h"

int switch_led;

void fsm_manual_run()
{
	switch(state)
	{
		case MAN_INIT:
			HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
			HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

			HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
			HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);

			switch_led = 0;

			if (1)
			{
				state = MAN_RED;
			}
			break;
		case MAN_RED:
			time_buffer[0] = man_red;
			time_buffer[1] = MAN_RED - 10;


			if (switch_led == 0)
			{
				HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
				HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

				HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
				HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);
				switch_led = 1;
			}
			else if (switch_led == 1)
			{
				HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 1);
				HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 1);

				HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 1);
				HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 1);
				switch_led = 0;
			}

			if (man_red > 99)
			{
				man_red = 0;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_GREEN;
			}

			if (buttonIsPressed(1))
			{
				man_red++;
			}
			if (buttonIsPressed(2))
			{
				red = man_red;
				man_red = 0;
			}

			break;
		case MAN_GREEN:
			time_buffer[0] = man_green;
			time_buffer[1] = MAN_GREEN - 10;

			if (switch_led == 0)
			{
				HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
				HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

				HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
				HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);
				switch_led = 1;
			}
			else if (switch_led == 1)
			{
				HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 1);
				HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

				HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 1);
				HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);
				switch_led = 0;
			}

			if (man_green > 99)
			{
				man_green = 0;
			}

			if (buttonIsPressed(0))
			{
				state = MAN_YELLOW;
			}

			if (buttonIsPressed(1))
			{
				man_green++;
			}
			if (buttonIsPressed(2))
			{
				green = man_green;
				man_green = 0;
			}

			break;
		case MAN_YELLOW:
			time_buffer[0] = man_yellow;
			time_buffer[1] = MAN_YELLOW - 10;

			if (switch_led == 0)
			{
				HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
				HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

				HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
				HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);
				switch_led = 1;
			}
			else if (switch_led == 1)
			{
				HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
				HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 1);

				HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
				HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 1);
				switch_led = 0;
			}

			if (man_yellow > 99)
			{
				man_yellow = 0;
			}
			if (buttonIsPressed(0))
			{
				state = INIT;
			}

			if (buttonIsPressed(1))
			{
				man_yellow++;
			}
			if (buttonIsPressed(2))
			{
				yellow = man_yellow;
				man_yellow = 0;
			}

			break;
		default:
			break;
	}
}
