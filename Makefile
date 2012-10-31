CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib -c -g3
SOURCE= main.c start.c mem.c clock.c

make:
	arm-none-eabi-gcc $(SOURCE) $(CFLAGS)
	arm-none-eabi-ld $(SOURCE:.c=.o) -o a.elf -T ./link_script.ld
	arm-none-eabi-objcopy -O binary a.elf a.bin
burn: 
	st-flash write a.bin 0x08000000

clean :
	rm *.o a.elf a.bin

