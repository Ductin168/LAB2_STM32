/*
 * ex10.c
 *
 *  Created on: Oct 4, 2024
 *      Author: DUC TIN
 */

#include "ex10.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {0x00,0x00,0x20,0x7E,0xFE,0x7E,0x20,0x00};
uint8_t display_buffer[8] = {0};

void shiftLeft(uint8_t* buffer) {
    buffer[0] = (buffer[0] << 1) | ((buffer[0] & 0x80) >> 7);
    buffer[1] = (buffer[1] << 1) | ((buffer[1] & 0x80) >> 7);
    buffer[2] = (buffer[2] << 1) | ((buffer[2] & 0x80) >> 7);
    buffer[3] = (buffer[3] << 1) | ((buffer[3] & 0x80) >> 7);
    buffer[4] = (buffer[4] << 1) | ((buffer[4] & 0x80) >> 7);
    buffer[5] = (buffer[5] << 1) | ((buffer[5] & 0x80) >> 7);
    buffer[6] = (buffer[6] << 1) | ((buffer[6] & 0x80) >> 7);
    buffer[7] = (buffer[7] << 1) | ((buffer[7] & 0x80) >> 7);
}
void sendToLEDMatrix(int value){
    uint8_t Segments = matrix_buffer[value];
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin, (Segments & 0x01) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM1_Pin, (Segments & 0x02) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM2_Pin, (Segments & 0x04) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM3_Pin, (Segments & 0x08) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM4_Pin, (Segments & 0x10) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM5_Pin, (Segments & 0x20) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM6_Pin, (Segments & 0x40) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOA, ENM7_Pin, (Segments & 0x80) ? RESET : SET);
}

void updateLEDMatrix(int index) {
    switch (index) {
        case 0:
        	HAL_GPIO_WritePin(GPIOB, ROW0_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(0);

            break;
        case 1:
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(1);
            break;
        case 2:
        	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW0_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(2);
            break;
        case 3:
        	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW0_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(3);
            break;
        case 4:
        	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW0_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(4);
            break;
        case 5:
        	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW0_Pin|ROW6_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(5);
            break;
        case 6:
        	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW0_Pin|ROW7_Pin, SET);
            sendToLEDMatrix(6);
            break;
        case 7:
        	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, RESET);
        	HAL_GPIO_WritePin(GPIOB, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW0_Pin, SET);
            sendToLEDMatrix(7);
            break;
        default:
            break;
    }
}
void ex10_run(){

    updateLEDMatrix(index_led_matrix++);
    if(index_led_matrix == MAX_LED_MATRIX){
    	shiftLeft(matrix_buffer);
        index_led_matrix = 0;
    }
}
