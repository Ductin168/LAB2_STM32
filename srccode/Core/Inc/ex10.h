/*
 * ex10.h
 *
 *  Created on: Oct 4, 2024
 *      Author: DUC TIN
 */

#ifndef INC_EX10_H_
#define INC_EX10_H_

#include "main.h"

extern const int MAX_LED_MATRIX ;
extern int index_led_matrix ;
extern uint8_t matrix_buffer[] ;
extern void sentToLEDMatrix(int value);
extern void updateLEDMatrix ();
void ex10_run();

#endif /* INC_EX10_H_ */
