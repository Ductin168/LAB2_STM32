/*
 * ex9.c
 *
 *  Created on: Oct 3, 2024
 *      Author: DUC TIN
 */

#include "ex9.h"

const int MAX_LED_MATRIX_1 = 8;
int index_led_matrix_1 = 0;
uint8_t matrix_buffer_1 [8] = {0x18,0x3C,0x66,0x66,0x7E,0x7E,0x66,0x66};
void sendToLEDMatrix_1(int value){
    uint8_t Segments = matrix_buffer_1[value];
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin, (Segments & 0x01) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM1_Pin, (Segments & 0x02) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM2_Pin, (Segments & 0x04) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM3_Pin, (Segments & 0x08) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM4_Pin, (Segments & 0x10) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM5_Pin, (Segments & 0x20) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM6_Pin, (Segments & 0x40) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM7_Pin, (Segments & 0x80) ? RESET : SET);
}
void updateLEDMatrix_1(int index) {
    switch (index) {
        case 0:
        	HAL_GPIO_WritePin(GPIOB, ROW0_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(0);

            break;
        case 1:
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(1);
            break;
        case 2:
        	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW0_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(2);
            break;
        case 3:
        	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW0_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(3);
            break;
        case 4:
        	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW0_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(4);
            break;
        case 5:
        	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW0_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(5);
            break;
        case 6:
        	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW0_Pin|ROW7_Pin, SET);
            sendToLEDMatrix_1(6);
            break;
        case 7:
        	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW0_Pin, SET);
            sendToLEDMatrix_1(7);
            break;
        default:
            break;
    }
}
void ex9_run(){
    updateLEDMatrix_1(index_led_matrix_1++);
    if(index_led_matrix_1 == MAX_LED_MATRIX_1){
        index_led_matrix_1 = 0;
    }
}


