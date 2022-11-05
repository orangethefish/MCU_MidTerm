/*
 * input_reading.h
 *
 *  Created on: Nov 5, 2022
 *      Author: DUY HOA
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
int check_button_flag(int index);
#endif /* INC_INPUT_READING_H_ */
