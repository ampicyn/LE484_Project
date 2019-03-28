#include "ctrler.h"
#include "bsp.h"
#include "timer.h"
#include "main.h"
#include <stdio.h>
volatile int32_t TimeCount = 0;


Ctrler_State_t Ctrler_State = RESTART;


void Ctrler_Init()
{
	
}

uint32_t Ctrler_Exec(Event_t evt)
{		if(evt == MODE_CHANGE){
		Ctrler_State = OUT_OF_SERVICE;
		}
		static int Status =0;
		static int Count=0;
    uint32_t timeout_value = 0; 
    switch(Ctrler_State) {
        case RESTART:
						if(evt == NO_EVT){
							Ctrler_State = THROUGH;							
							Signal_Flash();
							Status = 1;
						}
            break;
				case THROUGH:
						if(evt != BUTTON){
							printf("THROUGH STATE\n");
							Ctrler_State = THROUGH;

							Signal_Pass();
							Count++;
							printf("Count = %d\n",Count);
							int GTime= 0;
			if(MIN_G() == SET){
				GTime = 1200;
			}
			else {
				GTime = 600;
			}
								if(Status == 1){
									if(((Count*100)%GTime) == 0){
											Status = 2;
									}									
							printf("status = %d\n",Status);
								}
								
						}
						else if((Status == 2) && (Tick >= Timeout_Value)){
							Ctrler_State = BLOCKED;
							printf("Timeup\n");
							timeout_value = 20;
						}
						else if((Tick >= Timeout_Value)){
							Ctrler_State = WAIT;
							printf("go to WAIT\n");
														
						}												
						break;
						
				case BLOCKED:
						if(evt == TIMEOUT){
						printf("BLOCK STATE\n");
							Ctrler_State = THROUGH;
							Signal_Block();
						Status = 1;					
						Count = 0;
						}
						break;
				
				case WAIT:
							printf("WAIT STATE \n");
				int GTime= 0;
			if(MIN_G() == SET){
				GTime = 1200;
			}
			else {
				GTime = 600;
			}
							timeout_value = GTime - ((Count%GTime)*100);
							Ctrler_State = BLOCKED;
						break;
				
				default:
						if(evt == MODE_CHANGE){
						printf("OUT_OF_SERVICE \n");
            Ctrler_State = OUT_OF_SERVICE;
						while(1){
							Signal_Flash();
							}
						}
    }
    return timeout_value;
}