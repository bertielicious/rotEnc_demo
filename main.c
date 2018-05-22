/*
 * File:   main.c
 * Author: Phil
 *
 * Created on 19 May 2018, 18:24
 */


#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "main.h"
#include "config_osc.h"
#include "init_ports.h"
#include "set_usart.h"
#include "fsm.h"

void main(void) 
{
    config_osc();
    init_ports();
    set_usart();

   
    START_LED = LO;
    QUARTER_LED = LO;
    HALF_LED = LO;
    THREE_QUARTER_LED = LO;
    FINAL_LED = LO;
    DIAGNOSTIC_LED = 0;
   
    TRISAbits.TRISA5 = 0;   // ACW_Flag pin 2
    
    
    printf("hello world xxx\n");
    
    while(1)
    {
       fsm(current_state);
       
       DIAGNOSTIC_LED = CW_Flag;
       PORTAbits.RA5 = ACW_Flag;
       DIAGNOSTIC_LED = 0;
       PORTAbits.RA5 = 0;
       if(CW_Flag)
       
       {
           printf("CW_Flag = %d, ACW_Flag = %d\n",CW_Flag, ACW_Flag);
           printf("right\n");
       }
       else if(ACW_Flag)
       
       {
           printf("CW_Flag = %d, ACW_Flag = %d\n",CW_Flag, ACW_Flag);
           printf("left\n");
       }
       ACW_Flag = LO;
       CW_Flag = LO;
       
    }
}
