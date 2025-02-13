/*
 * main1.c
 *
 * author: Moez Mefteh
 * description:
 *    Blinks 4 on-board LED based on the button status.
 *    system clock is running from HSI which is 16 Mhz.
 *    Delay function is just a simple nop sequence.
 *
 * gpio setup steps:
 *   There are at least three steps associated with GPIO:
 *   1. enable GPIOx clock from RCC
 *   2. set the direction of the pins from MODER (input / output)
 *   3. (optional) set the speed of the pins from OSPEEDR
 *   4. (optional) set pins to pull-up or pull-down or
 *         leave them floating from PUPDR
 *   5. (optional) set output type register to push-pull or
 *         open-drain from OTYPER
 *   6. either read from IDR or write to ODR depending on
 *         input or output configuration
 */

#include "led1.h"

#define SLOWDELAY    0x3ffff
#define FASTDELAY    0xfffff

/*************************************************
* function declarations
*************************************************/
int main(void);

/*************************************************
* main code starts from here
*************************************************/
int main(void)
{
    // Initialize GPIO
    init_led();
    init_button();
    // the code should never leave its master loop, hence while(1) or for(;;)
    while(1)
    {
        // Set delay based on button state
        if(!read_button()) {
            nop_delay(SLOWDELAY);    // Delay when the button is released
        } else {
            nop_delay(FASTDELAY);     // Delay when the button is pressed
        }
        // Toggle LED pins
        led_toggle();
    }
    return 0;
}