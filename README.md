# STM32-Bare-Matel-Application
STM32 Discovery LED Blink Project (Bare Metal Application)

## Description
This project demonstrates a simple LED blink application on the STM32 Discovery board using a bare metal approach. The application controls four LEDs and adjusts the blinking rate using a button. The project showcases three different methods for implementing this functionality, each improving code organization and readability.

## Requirements
To successfully run this project, you'll need the following:

1. STM32 Discovery Board (e.g., STM32F4 Discovery)
2. GNU Arm Embedded Toolchain
3. TRACE32 Debugger (optional, for flashing)
4. USB Cable for board power

## Setup Instructions
1. Clone or download this repository to your local machine.
2. Install the GNU Arm Embedded Toolchain.
3. Build the project to generate the binary file.
5. Connect your STM32 Discovery board to your computer.
6. Flash the generated binary onto the board using your preferred method (TRACE32 Debugger or other flashing tools).
7. Reset the board.

## Usage
After flashing the binary onto the board, the LEDs should start blinking. Press the button to adjust the blinking rate.

## Methods

### Method 1: All in `main0.c`

In this method, all the code is contained within a single file, `main0.c`. This approach is straightforward but can become difficult to manage as the project grows.

**Key Points:**
- All code in one file.
- Direct manipulation of registers using hardcoded addresses.
- Simple but not modular or reusable.

### Method 2: Using `led.h` and `led.c`

This method separates the code into multiple files, `led.h` and `led.c`, to improve modularity and readability. The header file contains definitions and function prototypes, while the source file contains the implementation.

**Key Points:**
- Code is split into multiple files for better organization.
- Use of macros for register addresses and bit manipulation.
- More modular and reusable compared to Method 1.

### Method 3: Using Structs

In this method, the code is further improved by using structs to represent peripheral registers. This approach enhances code readability and maintainability by providing a clear and structured way to access registers. This method is similar to the CMSIS (Cortex Microcontroller Software Interface Standard) approach.

**Key Points:**
- Use of structs to represent peripheral registers.
- Improved code readability and maintainability.
- More abstract and easier to understand compared to direct register manipulation.
- Similar to the CMSIS approach.

## Author
Moez MEFTEH

For any questions or support, please contact moezmefteh85@gmail.com
