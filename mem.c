//Joe's malloc function
#include "registers.h"
#include "mem.h"

extern uint32_t _sheap;
extern uint32_t _eheap;

void* getMem(uint32_t size) {
	static uint32_t* start_data = &_sheap;
	uint32_t* end_data = &_eheap;
    
    uint32_t* start_addr = start_data;
    if(start_data+size<end_data){
        start_data = (uint32_t*)((uint32_t)start_data+size);
    }
    else {
        start_addr = NULL;
    }
    return start_addr;
}
