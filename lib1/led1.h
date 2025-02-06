#ifndef __LED1_H__
#define __LED1_H__

#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIPH_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET            (0x0000UL)
#define GPIOD_OFFSET            (0x0C00UL)

#define GPIOA_BASE              (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define GPIOD_BASE              (AHB1PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET              (0x3800UL)
#define RCC_BASE                (AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN                 (1U<<0)
#define GPIODEN                 (1U<<3)

#define LED_PIN_1 12
#define LED_PIN_2 13
#define LED_PIN_3 14
#define LED_PIN_4 15
#define BUTTON 0

typedef struct
{
    volatile uint32_t DUMMY[12];
    volatile uint32_t AHB1ENR;
} RCC_TypeDef;

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t DUMMY[3];
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO_TypeDef;

#define RCC         ((RCC_TypeDef*) RCC_BASE)
#define GPIOA       ((GPIO_TypeDef*) GPIOA_BASE)
#define GPIOD       ((GPIO_TypeDef*) GPIOD_BASE)

void init_led(void);
void init_button(void);
void led_toggle(void);
unsigned int read_button(void);
void nop_delay(unsigned int count);


#endif
