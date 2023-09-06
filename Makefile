# Makefile for Building STM32F103C8Tx Firmware
# Author: Moez Mefteh
# Date: 06/09/2023
# Description: This Makefile automates the compilation and linking of STM32F103C8Tx firmware.

# Define the toolchain
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
LD = $(PREFIX)ld
OBJCOPY = $(PREFIX)objcopy
SIZE = $(PREFIX)size

# Define the source files and object files
SRCS = Main.c stm32_startup_f103x.c
OBJS = $(SRCS:.c=.o)

# Define compiler and linker flags
CFLAGS = -c -mcpu=cortex-m4 -Wall -O0 -gdwarf
LDFLAGS = -T STM32F407VGTx_FLASH.ld -nostdlib -Map=main.map

# Define the target name
TARGET = main

# Default target to build the hex file
all: $(TARGET).hex

# Default target to build the hex file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# Link the object files into an ELF binary
$(TARGET).elf: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

# Compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean up generated files
clean:
	rm -rf *.o $(TARGET).elf $(TARGET).hex

# Calculate the size of the ELF binary
size:
	$(SIZE) $(TARGET).elf

# Copy files to a specific location (TRACE32 directory)
copy:
	cp C:\Users\mmefteh\Desktop\BareMetalApp\$(TARGET).elf C:\TRACE32_R_2023_02_000159199\files\demo\arm\hardware\stm32\stm32f4\stm32f4discovery\sieve
	cp C:\Users\mmefteh\Desktop\BareMetalApp\$(SRCS) C:\TRACE32_R_2023_02_000159199\files\demo\arm\hardware\stm32\stm32f4\stm32f4discovery\sieve