CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib -c -g3

infLoopmake: infLoop.c
	arm-none-eabi-gcc infLoop.c start.c $(CFLAGS)
	arm-none-eabi-ld infLoop.o start.o -o a.elf -T ./link_script.ld
	arm-none-eabi-objcopy -O binary a.elf a.bin
burn: 
	st-flash write a.bin 0x08000000
