/*
 * software-timer.c
 *
 *  Created on: Oct 3, 2024
 *      Author: DUC TIN
 */
#include "software-timer.h"
int timerCouter[10];
int timerFlag[10];
void settimer1( int index , int counter){
	 timerCouter[index]= counter/TICK;
	 timerFlag[index]=0;
}
void settimer2(int index, int counter){
	 timerCouter[index]= counter/TICK;
	 timerFlag[index]=0;
}
void timerRun(){
	for( int i=0 ; i < 10 ; i++){
		if(timerCouter[i]>0){
			timerCouter[i]--;
		if(timerCouter[i]<=0){
			timerFlag[i]=1;
		}
	}
	}
}

