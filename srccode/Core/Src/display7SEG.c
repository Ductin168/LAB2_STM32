/*
 * display7SEG.c
 *
 *  Created on: Oct 3, 2024
 *      Author: DUC TIN
 */

#include "display7SEG.h"
void display7SEG(int num) {
    uint16_t segmentMap[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
    uint16_t segments = segmentMap[num];
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (segments & 0x01) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (segments & 0x02) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (segments & 0x04) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (segments & 0x08) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (segments & 0x10) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (segments & 0x20) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (segments & 0x40) ? SET : RESET);
}


