/****************************************************************
 * File: STM32F407VGTx_FLASH.ld
 * Author: Moez Mefteh
 * Date: 09/06/2023
 * Description: Linker script for STM32F103C8Tx microcontroller.
 ****************************************************************/

/* Define the entry point */
ENTRY(Reset_Handler)

/* Specify the memory layout of the target */
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
	/* .text section: contains code, vectors, and read-only data */
	.text :
	{
		*(.isr_vector)  /* Interrupt Vector Table */
		*(.text)        /* Code section */
		*(.rodata)      /* Read-only data section */
		. = ALIGN(4);
		_etext = .;      /* End of text section */
	}> FLASH
	
	/* _la_data: Load address of .data section for data copy */
      _la_data = LOADADDR(.data);

	/* .data section: initialized data */
	.data :
	{
		_sdata = .;      /* Start of initialized data in SRAM */
		*.(.data)        /* Initialized data section */
		. = ALIGN(4);
		_edata = .;      /* End of initialized data in SRAM */
	}> SRAM AT> FLASH

	/* .bss section: uninitialized data (zero-initialized) */
	.bss :
	{
		_sbss = .;       /* Start of uninitialized data in SRAM */
		*.(.bss)         /* Uninitialized data section */
		. = ALIGN(4);
		_ebss = .;       /* End of uninitialized data in SRAM */
	}> SRAM
}
