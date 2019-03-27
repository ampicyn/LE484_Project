#include "ctrler.h"
#include "bsp.h"
#include "timer.h"
#include "main.h"
#include <stdio.h>
// exported global variables
//int Button_Status = 0;
int x = 0;
	
/** @brief		Initialize I/O for Lamps
		@retval		None
*/
void BSP_Init(void){
}
/** @brief  Change lamps to GREEN
    @retval None
*/
void Signal_Pass(void){ 
	printf("x=%d \n",x);
	W_OFF();
	if(x == CONSTANT){
	int i;
	for(i=0;i<3;i++){
  W_ON();
	Delay(10);
	W_OFF();
	Delay(10);
	x = 0;
	}
	printf("dont walk\n");
}
	DW_ON();
	Delay(20);
	R_OFF();
	Delay(5);
	G_ON();	
}

/** @brief  Change lamps to RED
    @retval None
*/
void Signal_Block(void){	
		G_OFF();
		Delay(5);
		Y_ON();
		Delay(10);
		Y_OFF();
		Delay(5);
    R_ON();
		Delay(20);
		DW_OFF();
		Delay(5);
		
		W_ON();
	printf("walk\n");
static int WTime = 0;
			if(WALK_INTERVAL() == SET){
					WTime = 20;
			}
			else {
					WTime = 10;
			}
		Delay(WTime);
		x = CONSTANT;
}
/** @brief  Flash YELLOW lamp
    @retval None
*/
void Signal_Flash(void){
	R_OFF();
	G_OFF();
	W_OFF();
	DW_OFF();
	Y_OFF();
	Y_ON();
	Delay(5);
	Y_OFF();
	Delay(5);
}