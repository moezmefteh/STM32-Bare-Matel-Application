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

# Define the source directory
SRC_DIR = .

# Define the lib directory
LIB_DIR = $(SRC_DIR)/lib
#LIB_DIR = $(SRC_DIR)/lib1

# Define the source files and object files
#SRCS = Main0.c stm32_startup_f103x.c
SRCS = Main.c stm32_startup_f103x.c
#SRCS = Main1.c stm32_startup_f103x.c

LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Define the target name
TARGET = main
#TARGET = main1

# Default target to build the hex file
all: $(TARGET).hex

# Convert ELF binary to Intel HEX format
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# Link the object files into an ELF binary
$(TARGET).elf: $(OBJS) $(LIB_SRCS:.c=.o)
	$(LD) -T STM32F407VGTx_FLASH.ld -nostdlib -Map=main.map $^ -o $@

# Compile C source files into object files
%.o: %.c
	$(CC) -c -mcpu=cortex-m4 -Wall -O0 -gdwarf -I$(SRC_DIR) -I$(LIB_DIR) $< -o $@

# Clean up generated files
clean:
	rm -rf *.o $(TARGET).elf $(TARGET).hex

# Calculate the size of the ELF binary
size:
	$(SIZE) $(TARGET).elf

# Copy files to a specific location (TRACE32 directory)
copy:
	cp $(TARGET).elf /path/to/destination/$(TARGET).elf
	cp $(SRCS) $(LIB_SRCS) /path/to/destination/
