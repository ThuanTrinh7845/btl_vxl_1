/*
 * traffic_light.c
 *
 *  Created on: Nov 1, 2024
 *      Author: THUAN
 */

#include "traffic_light.h"

void red_green()
{
	HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 1);
	HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 1);

	HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 1);
	HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 0);
}

void red_yellow()
{
	HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 1);
	HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 1);

	HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 0);
	HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 1);
}

void green_red()
{
	HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 1);
	HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 0);

	HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 1);
	HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 1);
}

void yellow_red()
{
	HAL_GPIO_WritePin(MSB1_GPIO_Port, MSB1_Pin, 0);
	HAL_GPIO_WritePin(LSB1_GPIO_Port, LSB1_Pin, 1);

	HAL_GPIO_WritePin(MSB2_GPIO_Port, MSB2_Pin, 1);
	HAL_GPIO_WritePin(LSB2_GPIO_Port, LSB2_Pin, 1);
}
