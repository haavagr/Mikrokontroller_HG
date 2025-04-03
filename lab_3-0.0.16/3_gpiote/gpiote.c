#include "gpiote.h"
#define LED_PIN_START 17
#define LED_PIN_END 20



void gpiote_init() {
    GPIOTE->CONFIG[0]= (1 << 0) | (2 << 16) | (13 << 8);

    for (int i = LED_PIN_START; i <= LED_PIN_END; i++) {
        GPIOTE->CONFIG[i - LED_PIN_START + 1] = (3 << 16) |(3 << 0) | (i << 8);
    }

}