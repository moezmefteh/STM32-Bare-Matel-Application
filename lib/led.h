#ifndef __LED_H__
#define __LED_H__

#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIPH_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET            (0x0000UL)
#define GPIOD_OFFSET            (0x0C00UL)

#define GPIOA_BASE              (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define GPIOD_BASE              (AHB1PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET              (0x3800UL)
#define RCC_BASE                (AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET         (0x30UL)
#define RCC_AHB1EN_R            (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define GPIOA_MODE_R_OFFSET     (0x00UL)
#define GPIOA_MODE_R            (*(volatile unsigned int *)(GPIOA_BASE + GPIOA_MODE_R_OFFSET))
#define GPIOD_MODE_R_OFFSET     (0x0C00UL)
#define GPIOD_MODE_R            (*(volatile unsigned int *)(GPIOA_BASE + GPIOD_MODE_R_OFFSET))

#define GPIOA_ID_R_OFFSET       (0x10UL)
#define GPIOA_ID_R              (*(volatile unsigned int *)(GPIOA_BASE + GPIOA_ID_R_OFFSET))

#define GPIOD_OD_R_OFFSET       (0x0C14UL)
#define GPIOD_OD_R              (*(volatile unsigned int *)(GPIOA_BASE + GPIOD_OD_R_OFFSET))

#define GPIOAEN                 (1U<<0)
#define GPIODEN                 (1U<<3)

#define LED_PIN_1 12
#define LED_PIN_2 13
#define LED_PIN_3 14
#define LED_PIN_4 15
#define BUTTON 0

void init_led(void);
void init_button(void);
void led_toggle(void);
unsigned int read_button(void);
void nop_delay(unsigned int count);


#endif
