MEMORY {
flash(rx): ORIGIN = 0x00000000, LENGTH = 32K
sram(rwx): ORIGIN = 0x10000000, LENGTH = 8K
}

sram_top = ORIGIN(sram) + LENGTH(sram);

SECTIONS
{
	s1 : {
		*(.irq_vectors)
		*(.text)
		*(.rodata)
	} > flash
	
	s2 : {
		*(.data)
		*(.bss)
	} > sram
	stack_entry = sram_top;
}
