
#define LED_PIN_1 12
#define LED_PIN_2 13
#define LED_PIN_3 14
#define LED_PIN_4 15
#define BUTTON 0

void delay(unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}

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

void GPIO_TogglePin() {
    volatile unsigned int *GPIOD_ODR = (volatile unsigned int *)0x40020C14;
    *GPIOD_ODR ^= (1 << LED_PIN_1);
    *GPIOD_ODR ^= (1 << LED_PIN_2);
    *GPIOD_ODR ^= (1 << LED_PIN_3);
    *GPIOD_ODR ^= (1 << LED_PIN_4);
}

int main(void) {
    GPIO_Init();

    while (1) {

        volatile unsigned int *GPIOA_IDR = (volatile unsigned int*)0x40020010;
        if (!(*GPIOA_IDR & (1 << BUTTON))) {
            delay(0x3fffff);
        } else {
            delay(0xfffff);
        }
        // Toggle LED again
        GPIO_TogglePin();


    }
}
