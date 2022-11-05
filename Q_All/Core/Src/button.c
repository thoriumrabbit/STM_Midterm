///*
// * button.c
// *
// *  Created on: Oct 12, 2022
// *      Author: binch
// */
//

#include "button.h"

uint16_t button_list[NO_OF_BUTTON] = {RESET_Pin, INC_Pin, DEC_Pin};


int KeyReg0[NO_OF_BUTTON] = {[0 ... NO_OF_BUTTON -1] = NORMAL_STATE};
int KeyReg1[NO_OF_BUTTON] = {[0 ... NO_OF_BUTTON -1] = NORMAL_STATE};
int KeyReg2[NO_OF_BUTTON] = {[0 ... NO_OF_BUTTON -1] = NORMAL_STATE};
int KeyReg3[NO_OF_BUTTON] = {[0 ... NO_OF_BUTTON -1] = NORMAL_STATE};

int TimeOutForKeyPress[NO_OF_BUTTON] =  { [0 ... NO_OF_BUTTON -1] = 300};
int button_flag[NO_OF_BUTTON] = { [0 ... NO_OF_BUTTON -1] = 0};
int button_flagLongPress[NO_OF_BUTTON] = { [0 ... NO_OF_BUTTON -1] = 0};

void singlePressProcess(int i){
	button_flag[i] = 1;
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

void longPressProcess(int i){
	button_flagLongPress[i] = 1;
}

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_flagLongPress[index] == 1){
		button_flagLongPress[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(uint16_t i){
  KeyReg2[i] = KeyReg1[i];
  KeyReg1[i] = KeyReg0[i];
  KeyReg0[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port, button_list[i]);


  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
    if (KeyReg2[i] != KeyReg3[i]){
      KeyReg3[i] = KeyReg2[i];

      if (KeyReg3[i] == PRESSED_STATE){
        singlePressProcess(i);
        TimeOutForKeyPress[i] = 300;
      }
    }else{
       TimeOutForKeyPress[i]--;
        if (TimeOutForKeyPress[i] == 0){
        	button_flag[i] = 0;
        	if(KeyReg3[i] == PRESSED_STATE){
        		longPressProcess(i);
        	}
        	TimeOutForKeyPress[i] = 100;
        }
    }
  }
}

