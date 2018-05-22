/* 
 * File:   config.h
 * Author: Phil
 *
 * Created on 19 May 2018, 18:23
 */

#ifndef CONFIG_H
#define	CONFIG_H

// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = DISABLED // PLL Enable Bit (3x or 4x PLL Disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdbool.h>
#define _XTAL_FREQ 4000000
/*************SWITCH STATES********************/
#define LO 0
#define HI 1

/************MACHINE STATES********************/
#define START 1
#define QCW 2
#define HCW 3
#define TQCW 4
#define FCW 5
#define QACW 6
#define HACW 7
#define TQACW 8
#define FACW 9

/******MACHINE INPUTS & OUTPUTS*****************/
#define CLK PORTAbits.RA1               // CLK input for rotary encoder pin 18 yellow LED
#define DT PORTAbits.RA4                // DT input for rotary encoder pin 3 red LED 

/*******STATUS LEDS*******************************/
#define START_LED PORTCbits.RC5         // red LED indicating START state pin 5
#define QUARTER_LED PORTCbits.RC4       // green LED indicating QUARTER state pin 6
#define HALF_LED PORTCbits.RC3          // yellow LED indicating HALF state pin 7
#define THREE_QUARTER_LED PORTCbits.RC2 // blue LED indicating QUARTER state pin 14
#define DIAGNOSTIC_LED PORTBbits.RB4    // green diagnostic LED pin 13
#define FINAL_LED PORTBbits.RB5         // orange LED  indicating FINAL statepin 12
/******GLOBAL VARIABLES******************************/
unsigned char current_state = START;
bool CW_Flag = LO;      // CW_Flag is set when rotary encoder is turned clockwise
bool ACW_Flag = LO;     // ACW_Flag is set when rotary encoder is turned anti-clockwise

#endif	/* CONFIG_H */

