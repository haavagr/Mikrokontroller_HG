#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

#define __GPIO_BASE_ADDRESS__ 0x50000000
#define GPIO ((NRF_GPIO_REGS*)__GPIO_BASE_ADDRESS__)


typedef struct { 
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t RESERVED1[120];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

#endif
