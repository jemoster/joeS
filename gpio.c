#include "registers.h"

#define GPIODEN 3

void init_gpio_d(void)
{
    //Enable GPIO D clock
    RCC_AHB1ENR |= (1<<GPIODEN);

    //Set each of the LED Port mode registers to general purpose outputs
    GPIOD_MODER |= (1<<(2*LD3));
    GPIOD_MODER |= (1<<(2*LD4));
    GPIOD_MODER |= (1<<(2*LD5));
    GPIOD_MODER |= (1<<(2*LD6));
}

