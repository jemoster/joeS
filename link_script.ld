MEMORY {
	FLASH(rx)	: ORIGIN = 0x08000000, LENGTH = 1024k
	RAM (xrw)	: ORIGIN = 0x20000000, LENGTH = 122k
	ETHRAM (xrw)	: ORIGIN = 0x2001C000, LENGTH = 16k
	CCMRAM (xrw)	: ORIGIN = 0x10000000, LENGTH = 64k
}

/* Highest address of the kernel stack */
_estack = 0x10010000;	/*end of 64k CCM RAM */
/* Heap */
_sheap = 0x20000000;	/*beginning of 112K SRAM */
_eheap = 0x2001BFFC;	/**/

SECTIONS {
	flash :	{
		KEEP(*(.vectors))
		. = ALIGN(4);
		*(.text*)
		. = ALIGN(4);
		_srodata = .;
		*(.rodata*);
		_erodata = .;
		. = ALIGN(4);
	} > FLASH

	_sidata = .; 

	data :	AT (_sidata)
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data*)
		. = ALIGN(4);
		_edata = .;
		_sbss = .;
		*(.bss*)
		*(COMMON)
		_ebss = .;
	} > CCMRAM
}

PROVIDE(end = .);
_end = .;
