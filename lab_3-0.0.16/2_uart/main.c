#include "uart.h"
#include "gpio.h"
#include <stdio.h>
#include <sys/types.h>

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
	uart_send(*letter);
	letter++;
	}
	return count;
	}


#define __BUTTON_1_PIN__ 14
#define __BUTTON_2_PIN__ 13

#define LED_PIN_START 17
#define LED_PIN_END 20


void button_init(){ 
	GPIO->PIN_CNF[__BUTTON_1_PIN__] = (3 << 2);
	GPIO->PIN_CNF[__BUTTON_2_PIN__] = (3 << 2);
	// Fill inn the configuration for the remaining buttons 
}


int main () {
	uart_init();
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i);
	}
	// Configure buttons -> see button_init()
	button_init();
	int sleep = 0;
	int leds_on = 0;

	int course = 4235;
    int year = 2022;
    char grade = 'B';
	

	while(1){

			char letter = uart_read();
			if (letter != '\0'){		
					if (leds_on == 0) {
							for (int i = LED_PIN_START; i <= LED_PIN_END; i++) {
								GPIO->OUTCLR = (1 << i);
							}
							leds_on = 1;
							iprintf("The average grade in TTK%d was in %d was: %c\n\r", course, year, grade);
						}
					else if (leds_on == 1) {
								for (int i = LED_PIN_START; i <= LED_PIN_END; i++) {
									GPIO->OUTSET = (1 << i);
								}
								leds_on = 0;
		
					}
				}
			//}
		
		
		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */
		
			//if (!(GPIO->IN & (1 << __BUTTON_2_PIN__))){
             //   for (int i = LED_PIN_START; i <= LED_PIN_END; i++) {
				//	GPIO->OUTCLR = (1 << i);  // Slå av LED ved å sette pinne til lav
		//}
			//	uart_send('B');
			//}
			
		sleep = 10000;
		while(--sleep); // Delay
	}



	return 0;



}