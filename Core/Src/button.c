/*
 * button.c
 *
 *  Created on: Oct 29, 2024
 *      Author: THUAN
 */

#include "button.h"


int keyReg0[MAX_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[MAX_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[MAX_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg3[MAX_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};


int TimerPress[MAX_BUTTON] = {100, 100, 100};

int buttonFlag[MAX_BUTTON] = {0, 0, 0};

int buttonIsPressed(int index)
{
	if (buttonFlag[index] == 1)
	{
		buttonFlag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index)
{
	buttonFlag[index] = 1;
}

void getKeyInput()
{

	for (int i = 0; i < MAX_BUTTON; i++)
	{
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];

		keyReg2[0] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
		keyReg2[1] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		keyReg2[2] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

		if ((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
		{
			if (keyReg2[i] != keyReg3[i])
			{
				keyReg3[i] = keyReg2[i];
				if (keyReg2[i] == PRESSED_STATE)
				{
					subKeyProcess(i);
					TimerPress[i] = 100;
				}
			}
			else
			{
				TimerPress[i]--;
				if (TimerPress[i] <= 0)
				{
					keyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
