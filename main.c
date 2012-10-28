#include "start.h"
#include "registers.h"
#include "mem.h"

void main(void);

extern uint32_t _estack;

uint32_t V[] __attribute__ ((section(".vectors"))) =
	{(uint32_t)&_estack, (uint32_t)&reset};

int myGlobalInt = 2;
//0xDEADB33F;
int myUninit;
int anotherInt;
uint32_t *memPtr;

void main(void) {
	anotherInt = 2;
    
    memPtr = getMem(4);
    memPtr = getMem(4);
    memPtr = getMem(4);
    
	while(1){
		asm volatile("nop");
	}
}
