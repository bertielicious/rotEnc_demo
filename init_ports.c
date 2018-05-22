
#include <pic16f1459.h>
#include "config.h"
#include "init_ports.h"
void init_ports (void)
{
    //********TURN OFF ANALOGUE INPUTS**********************
    ANSELA = 0x00;                  // turn off all ADC inputs on PORTA
    ANSELB = 0x00;                  // turn off all ADC inputs on PORTB
    ANSELC = 0x00;                  // turn off all ADC inputs on PORTC
    /***************LED OUTPUT PINS***********************/
    TRISCbits.TRISC5 = 0;       // start_LED pin 5
    TRISCbits.TRISC4 = 0;       // quarter_LED pin 6
    TRISCbits.TRISC3 = 0;       // half_LED pin 7
    TRISCbits.TRISC2 = 0;       // three_quarter_LED pin 14
    TRISBbits.TRISB4 = 0;       // diagnostic_LED pin 13
    TRISBbits.TRISB5 = 0;       // final_LED pin 12
    
    /*SET DATA DIRECTION FOR ROTARY ENCODER AND SWITCH*******/
    /*RA0, RA1 no TRIS needed as these pins only function as inputs*/
    /* RA0 = SWIP pin 19*/
    /* RA1 = CLK pin 18*/
    TRISAbits.TRISA4 = 1;           // DT pin 3
    
    /*SET DATA DIRECTION FOR UART*******************/
    PORTBbits.RB7 = 0;              // TX pin 10
    
}
