/*
 * ex1.c
 *
 *  Created on: Oct 3, 2024
 *      Author: DUC TIN
 */

#include "ex1.h"
void init_ex1(){
	HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
			|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, EN2_Pin|EN3_Pin, SET);
}
int currentDisplay=0;
void ex1_run(){
	switch(currentDisplay){
	case 0:
		display7SEG(1);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
		currentDisplay=1;
		break;
	case 1:
		display7SEG(2);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		currentDisplay=0;
		break;
	default:
		break;
	}
}
