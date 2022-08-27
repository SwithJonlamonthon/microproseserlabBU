/* Program 1_1.c Toggling LED in C using Keil header file * register definitions(MK64F12.h).* This program toggles green LED for 2second ON and 2second OFF.* The green LED is connected to PTB26.* The LEDs are low active (a '0' turns ON the LED).*/ 

#include"MK64F12.h"

void delayMs(int n);
void ledpin(int a , int b);
int main(void) {
       
        while (1) {
								ledpin(1,3);
               
                delayMs(500); /* Step-5: delay function*/
								ledpin(0,3);
                delayMs(500); /* Step-7: delay function*/
        }
        
} /* Delay n milliseconds* The CPU core clock is set to MCGFLLCLK at 41.94 MHz ??? in SystemInit().*/
void delayMs(int n){
				int i;
        int j; /* This for-loop takes about 2 seconds */
        for (i = 0; i < n/2; i++){
                for (j = 0; j < 7000; j++) {}
        }
}

void ledpin(int a , int b){
			switch(b){
				case 1:  /*For red led*/
							SIM -> SCGC5 |= 0x400; /* Step-1: enable clock to Port B */
							PORTB -> PCR[22] = 0x0100; /* Step-2: make PTE22 pin as GPIO */
							PTB -> PDDR |= 0x0400000; /* Step-3: make PTE22 as output pin */
								if (a == 1){
								PTB -> PDOR &= !0x0400000;
								}
								else{
								PTB -> PDOR |= 0x0400000; /* Step-4: turn on red LED */
								}
							break;
				case 2:
							SIM -> SCGC5 |= 0x2000; /* Step-1: enable clock to Port B */
							PORTE -> PCR[26] = 0x0100; /* Step-2: make PTE26 pin as GPIO */
							PTE -> PDDR |= 0x04000000; /* Step-3: make PTE26 as output pin */
								if (a == 1){
									PTE -> PDOR &= !0x04000000;
								}
								else{
									PTE -> PDOR |= 0x04000000; /* Step-4: turn on red LED */
								}
							break;
				case 3:
							SIM -> SCGC5 |= 0x400; /* Step-1: enable clock to Port B */
							PORTB -> PCR[21] = 0x0100; /* Step-2: make PTE21 pin as GPIO */
							PTB -> PDDR |= 0x0200000; /* Step-3: make PTE21 as output pin */
								if (a == 1){
									PTB -> PDOR &= !0x0200000;
								}
								else{
									PTB -> PDOR |= 0x0200000; /* Step-4: turn on red LED */
								}
					
					
		
			
			
			
			
			}
		
}


