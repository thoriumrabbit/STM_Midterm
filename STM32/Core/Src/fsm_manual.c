/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: binch
 */

#include "fsm_manual.h"
#include "global.h"
#include "software_timer.h"
#include "led_processing.h"


void fsm_simple_buttons_run() {
	switch (number_state){
		case INIT: 
			number_state = NUM0;
			setTimer1(10000);
			break;
		case NUM0:
			display7SEG(SegmentNumber[0]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM1;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM9;
				setTimer1(10000);
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM0;
				setTimer1(1000);
			}
			break;
		case NUM1:
			display7SEG(SegmentNumber[1]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM2;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM0;
				setTimer1(10000);
				button_flag[2] = 0;
				button_flagLongPress[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM0;
				setTimer1(1000);
			}
			break;
		case NUM2:
			display7SEG(SegmentNumber[2]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM3;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM1;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM1;
				setTimer1(1000);
			}
			break;
		case NUM3:
			display7SEG(SegmentNumber[3]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM4;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM2;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM2;
				setTimer1(1000);
			}
			break;
		case NUM4:
			display7SEG(SegmentNumber[4]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM5;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM3;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM3;
				setTimer1(1000);
			}
			break;
		case NUM5:
			display7SEG(SegmentNumber[5]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM6;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM4;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM4;
				setTimer1(1000);
			}
			break;
		case NUM6:
			display7SEG(SegmentNumber[6]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM7;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM5;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM5;
				setTimer1(1000);
			}
			break;
		case NUM7:
			display7SEG(SegmentNumber[7]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM8;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM6;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM6;
				setTimer1(1000);
			}
			break;
		case NUM8:
			display7SEG(SegmentNumber[8]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM9;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM7;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM7;
				setTimer1(1000);
			}
			break;
		case NUM9:
			display7SEG(SegmentNumber[9]);
			if (isButtonPressed(RESET_BUTTON)){
				number_state = INIT;
				button_flag[0] = 0;
			}
			if (isButtonPressed(INC_BUTTON)||isButtonLongPressed(INC_BUTTON)){
				number_state =	NUM0;
				setTimer1(10000);
				button_flag[1] = 0;
				button_flagLongPress[1] = 0;
			}
			if (isButtonPressed(DEC_BUTTON)||isButtonLongPressed(DEC_BUTTON)){
				number_state =	NUM8;
				setTimer1(10000);
				button_flagLongPress[2] = 0;
				button_flag[2] = 0;
			}
			if (timer1_flag == 1){
				number_state =	NUM8;
				setTimer1(1000);
			}
			break;
	}
}

