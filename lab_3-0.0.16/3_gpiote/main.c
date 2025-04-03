#include "gpiote.h"
#include "ppi.h"
#include "gpio.h"

#define LED_PIN_START 17
#define LED_PIN_END 20

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
}

int main() {
    button_init();
    gpiote_init();

    ppi_init();

    for (int i = LED_PIN_START; i <= LED_PIN_END; i++) {
        GPIO->DIRSET = (1 << i);  
        GPIO->OUTSET = (1 << i);  
    }
    while (1) {
      
    }

    return 0;
}
