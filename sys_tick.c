#include "registers.h"
#include "sys_tick.h"

void start_sys_tick(void){

    //Set the reload value for a 0.01 second tick
    SYSTICK_RELOAD = 0x0019A280;
    
    //Clear the current value
    SYSTICK_VAL = 0x00000000;

    //Enable the sys tick counter
    SYSTICK_CTL |= 1;
    
    //Enable the sys tick exception
    SYSTICK_CTL |= 1<<1;
}
