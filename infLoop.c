#include "start.h"
#include "registers.h"

void main(void);

extern uint32_t _estack;

uint32_t V[] __attribute__ ((section(".vectors"))) =
	{(uint32_t)&_estack, (uint32_t)&reset};

int myGlobalInt = 2;
//0xDEADB33F;
int myUninit;
int anotherInt;

void main(void) {
	anotherInt = 2;
	while(1){
		asm volatile("nop");
	}
}
