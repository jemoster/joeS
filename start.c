#include "registers.h"
#include "start.h"
#include "clock.h"
#include "gpio.h"

extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sidata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void c_start(void) {
	uint32_t* start_data = &_sdata;
	uint32_t* end_data = &_edata;
	uint32_t* data = &_sidata;

	while(start_data<end_data){
		*(start_data++) = *(data++);
	}

	uint32_t* start_bss = &_sbss;
	uint32_t* end_bss = &_ebss;
	while(start_bss<end_bss){
		*start_bss++ = 0;
	}
}

void reset(void) {
	c_start();
    clocks();
	main();
	while(1){}
}

void hang(void) {
    while(1){
       asm volatile("nop");
    }
}
void tick(void) {
//    asm volatile("nop");
        LED_ODR ^= (1<<LD3);
}
