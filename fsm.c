/*
 * File:   fsm.c
 * Author: Phil
 *
 * Created on 19 May 2018, 20:44
 */


#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include "config.h"
#include "fsm.h"

void fsm(unsigned char state) 
{ 
    switch (state)
    {
        case START:
            
            if (CLK == HI && DT == HI)
            {
                current_state = START;
                START_LED = HI;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
                
            }
            else if (CLK == LO && DT == HI)
            {
                current_state = QCW;
                START_LED = LO;
                QUARTER_LED = HI;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
                
            }
            if (CLK == HI && DT == 0)
            {
                current_state = QACW;
                START_LED = LO;
                QUARTER_LED = HI;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
               
            }
            else if (CLK == LO && DT == LO)
            {
                current_state = START;
                START_LED = HI;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
               
            }
            break;
            
            case QCW:
            
            if (CLK == HI && DT == HI)
            {
                current_state = START;
                START_LED = HI;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
              
            }
            else if (CLK == LO && DT == LO)
            {
                current_state = HCW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = HI;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
                
            }
            break;
            
            case HCW:
            
            if (CLK == LO && DT == HI)
            {
                current_state = QCW;
                START_LED = LO;
                QUARTER_LED = HI;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
            }
            else if (CLK == HI && DT == LO)
            {
                current_state = TQCW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = HI;
                FINAL_LED = LO;
                CW_Flag = LO;
                
            }
            break;
            
            case TQCW:
            
            if (CLK == LO && DT == LO)
            {
                current_state = HCW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = HI;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
               
            }
            else if (CLK == HI && DT == HI)
            {
                current_state = FCW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = HI;
                CW_Flag = HI;
              
            }
            break;
            
            case FCW:
            
            if (CLK == HI && DT == HI)
            {
                current_state = START;
                START_LED = HI;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                CW_Flag = LO;
               
            }
            else if (CLK == HI && DT == LO)
            {
                current_state = TQCW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = HI;
                FINAL_LED = LO;
                CW_Flag = LO;
              
            }
            break;
            
            /*********************ANTI CLOCK WISE FSM*******************/
            
            case QACW:
            
            if (CLK == LO && DT == LO)
            {
                current_state = HACW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = HI;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                ACW_Flag = LO;
               
            }
            else if (CLK == HI && DT == LO)
            {
                current_state = QACW;
                START_LED = LO;
                QUARTER_LED = HI;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                ACW_Flag = LO;
                
            }
            break;
            
            case HACW:
            
            if (CLK == LO && DT == HI)
            {
                current_state = TQACW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = HI;
                FINAL_LED = LO;
                ACW_Flag = LO;
                
            }
            else if (CLK == LO && DT == LO)
            {
                current_state = HACW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = HI;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                ACW_Flag = LO;
                
            }
            break;
            
            case TQACW:
            
            if (CLK == HI && DT == HI)
            {
                current_state = FACW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = HI;
                ACW_Flag = HI;
               
            }
            else if (CLK == LO && DT == HI)
            {
                current_state = TQACW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = HI;
                FINAL_LED = LO;
                ACW_Flag = LO;
                
            }
            break;
            
            case FACW:
            
            if (CLK == HI && DT == HI)
            {
                current_state = START;
                START_LED = HI;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = LO;
                FINAL_LED = LO;
                ACW_Flag = LO;
               
            }
            else if (CLK == LO && DT == HI)
            {
                current_state = TQACW;
                START_LED = LO;
                QUARTER_LED = LO;
                HALF_LED = LO;
                THREE_QUARTER_LED = HI;
                FINAL_LED = LO;
                ACW_Flag = LO;
               
            }
            break;
            
           
           
    }
    
}
