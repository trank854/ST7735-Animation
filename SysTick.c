#include "SysTick.h"
#include "tm4c123gh6pm.h"

void SysTick_Init(){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_RELOAD_R = 800000 - 1;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x1FFFFFFF) | 0x40000000;
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_INTEN;
}

void SysTick_Start(){
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
}

void SysTick_Stop(){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
	NVIC_ST_CURRENT_R = 0;
}
