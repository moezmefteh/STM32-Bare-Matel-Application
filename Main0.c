/*******************************************************
 * File: main.c
 * Author: Moez Mefteh
 * Date: 09/06/2023
 * Description: C code for controlling LEDs using GPIO pins
 *              and reading input from a button using GPIO.
 ********************************************************/

// Include necessary header files
#define LED_PIN_1 12
#define LED_PIN_2 13
#define LED_PIN_3 14
#define LED_PIN_4 15
#define BUTTON 0

// Function to introduce a delay
void delay(unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}

// Function to initialize GPIO pins
void GPIO_Init(void) {

    volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;
    // Enable clock for GPIO D
    *RCC_AHB1ENR |= (1 << 3);

    // Enable clock for GPIO A
    *RCC_AHB1ENR |= (1 << 0);

    // Configure LED pin as output
    volatile unsigned int *GPIOD_MODER = (volatile unsigned int *)0x40020C00;
    *GPIOD_MODER |= (1 << (LED_PIN_1 * 2));
    *GPIOD_MODER |= (1 << (LED_PIN_2 * 2));
    *GPIOD_MODER |= (1 << (LED_PIN_3 * 2));
    *GPIOD_MODER |= (1 << (LED_PIN_4 * 2));

    // Configure BUTTON pin as input
    volatile unsigned int *GPIOA_MODER = (volatile unsigned int*)0x40020000;
    *GPIOA_MODER &= ~BUTTON;
}

// Function to initialize GPIO pins
void GPIO_TogglePin() {
    volatile unsigned int *GPIOD_ODR = (volatile unsigned int *)0x40020C14;
    *GPIOD_ODR ^= (1 << LED_PIN_1);
    *GPIOD_ODR ^= (1 << LED_PIN_2);
    *GPIOD_ODR ^= (1 << LED_PIN_3);
    *GPIOD_ODR ^= (1 << LED_PIN_4);
}

int main(void) {
    // Initialize GPIO
    GPIO_Init();

    while (1) {
        // Read button input
        volatile unsigned int *GPIOA_IDR = (volatile unsigned int*)0x40020010;
        // Implement delay based on button state
        if (!(*GPIOA_IDR & (1 << BUTTON))) {
            delay(0x3fffff);    // Delay when the button is released
        } else {
            delay(0xfffff);     // Delay when the button is pressed
        }
        // Toggle LED pins
        GPIO_TogglePin();


    }
}
