
#include "uart.h"
#include "gpio.h"
#define __UART_BASE_ADDRESS__ 0x40002000
#define UART ((NRF_UART_REG*)__UART_BASE_ADDRESS__)

#define UART_TX 6
#define UART_RX 8

typedef struct
{
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASKS_STOPTX;
    volatile uint32_t RESERVED0[3];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESERVED1[56];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESERVED2[4];
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESERVED3;
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVED4[7];
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESERVED5[46];
    volatile uint32_t SHORTS;
    volatile uint32_t RESERVED6[64];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED7[93];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED8[31];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED9;
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED10;
    volatile uint32_t BAUDRATE;
    volatile uint32_t RESERVED11[17];
    volatile uint32_t CONFIG;
} NRF_UART_REG;

void uart_init(){ 
    //Brukes av GPIO
	GPIO->PIN_CNF[UART_TX] = (1 << 0);
    GPIO->PIN_CNF[UART_RX] = (0 << 0);
    //Brukes av UART
    UART->PSELTXD = UART_TX;
    UART->PSELRXD = UART_RX;
    UART->BAUDRATE = 0x00275000;
    UART->PSELRTS = ~0;
    UART->PSELCTS = ~0;
    UART->ENABLE = 8;
    UART->TASKS_STARTRX = 1;
}
void uart_send(char letter) {
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while(!(UART->EVENTS_TXDRDY));
    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX =1 ;
}

char uart_read(){
    /*
    char letter;
    UART->EVENTS_RXDRDY = 0;
    UART->TASKS_STARTRX = 1;

    if (UART->EVENTS_RXDRDY){
        letter = UART->RXD;
        UART->EVENTS_RXDRDY = 0;
    }
    else
    {
        letter = '\0';
    }
    return letter;
    */
    UART->EVENTS_RXDRDY = 0;
    UART->TASKS_STARTRX = 1;
    char letter = '\0';

    // Vent på at data skal være tilgjengelig
    while (!(UART->EVENTS_RXDRDY)) {
        // Kan ha en liten pause her hvis nødvendig
    }

    // Les data hvis tilgjengelig
    letter = UART->RXD;

    // Nullstill hendelsen
    UART->EVENTS_RXDRDY = 0;

    return letter;

}