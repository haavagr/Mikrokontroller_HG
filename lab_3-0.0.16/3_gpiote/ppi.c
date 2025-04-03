#include "ppi.h"
#include "gpiote.h"


void ppi_init() {
    
    PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);  
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]); 

    
    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);  
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[2]); 

    
    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);  
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[3]); 

    
    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);  
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[4]); 


    PPI->PPI_CH[4].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);  
    PPI->PPI_CH[4].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[5]); 

    
    PPI->CHENSET = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
}
