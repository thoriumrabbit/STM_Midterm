/*
 * button.h
 *
 *  Created on: Oct 12, 2022
 *      Author: binch
 */



#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#define NO_OF_BUTTON 	3

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define RESET_BUTTON	0
#define INC_BUTTON		1
#define DEC_BUTTON		2

extern int button_flag[NO_OF_BUTTON];
extern int button_flagLongPress[NO_OF_BUTTON];

void getKeyInput(uint16_t);
int isButtonPressed(int index);
int isButtonLongPressed(int index);
#endif /* INC_BUTTON_H_ */
