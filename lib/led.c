#include "led.h"

void init_led(void)
{
    /* Each module is powered separately. In order to turn on a module
     * its relevant clock needs to be enabled first.
     * The clock enables are located at RCC module in the relevant bus registers
     * STM32F4-Discovery board LEDs are connected to GPIOD pins 12, 13, 14, 15.
     * All the GPIO are connected to AHB1 bus, so the relevant register for the
     * clocks is AHB1ENR.
     * More info in Chapter 7 - RCC in RM0090
     */

    /* Enable GPIOD clock (AHB1ENR: bit 3) */
    // AHB1ENR: XXXX XXXX XXXX XXXX XXXX XXXX XXXX 1XXX
	RCC_AHB1EN_R |= GPIODEN;//GPIODEN;

    /* Make Pin 12 output (MODER: bits 25:24) */
    // Each pin is represented with two bits on the MODER register
    // 00 - input (reset state)
    // 01 - output
    // 10 - alternate function
    // 11 - analog mode

    // We can leave the pin at default value to make it an input pin.
    // In order to make a pin output, we need to write 01 to the relevant
    // section in MODER register
    //                     bit31                                         bit0
    // MODER register bits : xx xx xx 01 XX XX XX XX XX XX XX XX XX XX XX XX
    //                      p15      p12                                  p0
	GPIOD_MODE_R |= (1U<<24);
	GPIOD_MODE_R &= ~(1U<<25);
	GPIOD_MODE_R |= (1U<<26);
	GPIOD_MODE_R &= ~(1U<<27);
    GPIOD_MODE_R |= (1U<<28);
	GPIOD_MODE_R &= ~(1U<<29);
	GPIOD_MODE_R |= (1U<<30);
	GPIOD_MODE_R &= ~(1U<<31);
}

void init_button(void)
{
    RCC_AHB1EN_R |= GPIOAEN;//GPIOAEN;
    GPIOA_MODE_R |= (1U<<30);
	GPIOA_MODE_R &= ~(1U<<31);
}

void led_toggle(void)
{
	GPIOD_OD_R ^= (1 << LED_PIN_1);
    GPIOD_OD_R ^= (1 << LED_PIN_2);
    GPIOD_OD_R ^= (1 << LED_PIN_3);
    GPIOD_OD_R ^= (1 << LED_PIN_4);
}

unsigned int read_button(void)
{
    return (GPIOA_ID_R & (1 << BUTTON));
}
// Function to introduce a delay
void nop_delay(unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}
