// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected 
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO)
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground
#include <stdio.h>
#include <stdint.h>
#include "string.h"
#include "ST7735.h"
#include "SysTick.h"
#include "PLL.h"
#include "tm4c123gh6pm.h"

void DelayWait10ms(uint32_t n);

volatile int x = 63;
volatile int y = 79;
volatile int r = 20;

int main(void){
	//Initialization
	PLL_Init(Bus80MHz);
	SysTick_Init();
	ST7735_InitR(INITR_REDTAB);
	
	//Background
	ST7735_FillScreen(ST7735_BROWN);
	ST7735_FillRect(0, 20, 128, 35,ST7735_YELLOW);
	
	//Initial Frame
	ST7735_FillCircle(x, y, r, ST7735_PURPLE);
	ST7735_DrawLine(60, 150, 120, 150, ST7735_CYAN);	//Horizontal
	ST7735_DrawLine(110, 80, 110, 127, ST7735_CYAN);	//Vertical
	ST7735_DrawLine(110, 100, 125, 159, ST7735_CYAN);	//Diagonal
	
	//Characters with Different Font, Size, Color
	ST7735_DrawChar(7, 140, 'I', ST7735_BLUE, ST7735_GREEN, 2);
	ST7735_DrawChar(25, 135, 'D', ST7735_MAGENTA, ST7735_BLUE, 3);
	ST7735_DrawChar(50, 110, '8', ST7735_YELLOW, ST7735_RED, 5);
	
	SysTick_Start();
	while(1){
	}
}

void DelayWait10ms(uint32_t n){uint32_t volatile time;
  while(n){
//    time = 727240*2/91;  // 10msec for launchpad
    time = 727240/91;  // for simulation
    while(time){
	  	time--;
    }
    n--;
  }
}

void SysTick_Handler(){
	SysTick_Stop();
	ST7735_FillCircle(x, y, r, ST7735_PURPLE);
	ST7735_FillCircle(x, y, r, ST7735_WHITE);
	x--;
	SysTick_Start();
}