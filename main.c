#include "start.h"
#include "registers.h"
#include "mem.h"
#include "gpio.h"
#include "sys_tick.h"

void main(void);

extern uint32_t _estack;

uint32_t V[] __attribute__ ((section(".vectors"))) =
	{
    (uint32_t)&_estack, // Initial SP value
    (uint32_t)&reset,   // Reset
    (uint32_t)&hang,    // NMI
    (uint32_t)&hang,    // Hard fault
    (uint32_t)&hang,    // Memory management fault
    (uint32_t)&hang,    // Bus fault
    (uint32_t)&hang,    // Usage fault
    (uint32_t)&hang,    // Reserved
    (uint32_t)&hang,    // Reserved
    (uint32_t)&hang,    // Reserved
    (uint32_t)&hang,    // Rserved
    (uint32_t)&hang,    // SVCall
    (uint32_t)&hang,    // Reserved
    (uint32_t)&hang,    // Reserved
    (uint32_t)&hang,    // PendSV
    (uint32_t)&tick,    // Sys Tick
    (uint32_t)&hang     // Interrupt (IRD)
};

int myGlobalInt = 2;
//0xDEADB33F;
int myUninit;
int anotherInt;
uint32_t *memPtr;

void main(void) {
	anotherInt = 2;
    
    //Start SYSTICK 
    start_sys_tick();
        
    init_gpio_d();
    //Test LEDs by turning them all on
    LED_ODR |= (1<<LD3);
    LED_ODR |= (1<<LD4);
    LED_ODR |= (1<<LD5);
    LED_ODR |= (1<<LD6);
    
    
    memPtr = getMem(4);
    memPtr = getMem(4);
    memPtr = getMem(4);
        
	while(1){
        uint32_t i;
        for(i=1e7;i>1;i--){
            asm volatile("nop");
        }
        LED_ODR ^= (1<<LD3);
	}
}
