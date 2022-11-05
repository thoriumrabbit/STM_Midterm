/*
 * led_processing.c
 *
 *  Created on: Oct 15, 2022
 *      Author: binch
 */

#include "led_processing.h"
#include "software_timer.h"

uint8_t SegmentNumber[10] = {
//Anode Common, A is MSB
	0x81,  //0
	0xCF,  //1
	0x92,  //2
	0x86,  //3
	0xCC,  //4
	0xA4,  //5
	0xA0,  //6
	0x8F,  //7
	0x00,  //8
	0x84   //9
};
void display7SEG(uint8_t num) {
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, (num >> 6) & 0x01);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, (num >> 5) & 0x01);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, (num >> 4) & 0x01);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, (num >> 3) & 0x01);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, (num >> 2) & 0x01);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, (num >> 1) & 0x01);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, (num >> 0) & 0x01);
}

void debugLED_blinky(){
	if(timer0_flag == 1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer0(1000);
	}
}
