/*
 * simple_run.h
 *
 *  Created on: Nov 5, 2022
 *      Author: DUY HOA
 */

#ifndef INC_SIMPLE_RUN_H_
#define INC_SIMPLE_RUN_H_

#include "main.h"
#include "input_reading.h"
#include "7SEG_display.h"
#include "global.h"
void fsm_simple_button_run(){
	switch(status){
	case INIT:
		display7SEG(current_number);
		if(check_button_flag(0)) status=RESET;
		if(check_button_flag(1)) status=INC;
		if(check_button_flag(2)) status=DEC;
		if(check_button_flag_1s(1)){
			status=INC_LONG;
			setTimer1(1000);
		}
		if(check_button_flag_1s(2)){
			status=DEC_LONG;
			setTimer1(1000);
		}
		break;
	case INC:
		display7SEG(++current_number%10);
//		if(check_button_flag_1s(1)){
//			display7SEG(8);
////			status=INC_LONG;
////			setTimer1(1000);
//		}else{
//			status=INIT;
//		}
		status=INIT;
		break;
	case RESET:
		display7SEG(0);
		status=INIT;
		break;
	case DEC:
		if(current_number<=0){
			current_number=9;
		}else{
			current_number--;
		}
		display7SEG(current_number);
		status=INIT;
		break;
	case INC_LONG:
//		display7SEG(6);
//		status=INIT;
//		if(check_button_flag(1)){
//			if(timer1_flag==1){
//				display7SEG(++current_number%10);
//				setTimer1(1000);
//			}
//		}else{
//			status=INIT;
//		}
		if(timer1_flag==1){
			display7SEG(++current_number%10);
			setTimer1(1000);
		}
		if(!is_button_pressed(1)) status=INIT;
		break;
	case DEC_LONG:
		if(timer1_flag==1){
			if(current_number<=0){
				current_number=9;
			}else{
				current_number--;
			}
			display7SEG(current_number);
			setTimer1(1000);
		}
		if(!is_button_pressed(2)) status=INIT;
		break;
	}
}
#endif /* INC_SIMPLE_RUN_H_ */
