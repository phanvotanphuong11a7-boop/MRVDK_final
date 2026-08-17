#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdbool.h>

typedef enum {
    PORT_A = 0,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E
} gpio_port_t;


typedef enum {
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} gpio_pin_t;


typedef enum {
    GPIO_DIR_OUTPUT = 0, /*!< Configures pin as an Output (TRIS = 0) */
    GPIO_DIR_INPUT  = 1  /*!< Configures pin as an Input (TRIS = 1) */
} gpio_dir_t;


typedef enum {
    GPIO_LOW  = 0,       /*!< Logic Low (0V) */
    GPIO_HIGH = 1        /*!< Logic High (VDD) */
} gpio_state_t;

void HAL_GPIO_SetDirection(gpio_port_t port, gpio_pin_t pin, gpio_dir_t dir);

void HAL_GPIO_PullUpEnable(gpio_pin_t pin);

void HAL_GPIO_WritePin(gpio_port_t port, gpio_pin_t pin, gpio_state_t state);

gpio_state_t HAL_GPIO_ReadPin(gpio_port_t port, gpio_pin_t pin);

#endif /* HAL_GPIO_H */