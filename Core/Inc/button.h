/*
 * button.h
 *
 *  Created on: Oct 29, 2024
 *      Author: THUAN
 */

#include "main.h"

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_RESET
#define PRESSED_STATE GPIO_PIN_SET

#define MAX_BUTTON 3

int buttonIsPressed(int index);
void subKeyProcess(int index);
void getKeyInput();

/*int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
void subKeyProcess(int i);
void getKeyinput();*/

#endif /* INC_BUTTON_H_ */
