#include "sys_config.h"
#include <xc.h> 
#include "../hal/hal_gpio.h"

static void System_GPIO_Config(void);

void sys_config(void) {
    /* 1. CRITICAL SECTION: DISABLE INTERRUPTS */
    INTCONbits.GIE = 0;  
    INTCONbits.PEIE = 0; 

    /* 2. HARDWARE AND MIDDLEWARE INITIALIZATION SEQUENCE */
    System_GPIO_Config();


    /* 3. END OF CRITICAL SECTION: ENABLE INTERRUPTS */
    INTCONbits.PEIE = 1; 
    INTCONbits.GIE = 1;  
}

static void System_GPIO_Config(void) {
    /* OUTPUT: LED (RD4: ??, RD5: Xanh, RD6: Vàng) */
    HAL_GPIO_SetDirection(PORT_D, PIN_2, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(PORT_D, PIN_3, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(PORT_D, PIN_7, GPIO_DIR_OUTPUT);

    HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW);

    /* INPUT: BUTTON (RB3: BT1, RB4: BT2, RB5: BT3) */
    HAL_GPIO_SetDirection(PORT_B, PIN_3, GPIO_DIR_INPUT);
    HAL_GPIO_PullUpEnable(PIN_3);

    HAL_GPIO_SetDirection(PORT_B, PIN_4, GPIO_DIR_INPUT);
    HAL_GPIO_PullUpEnable(PIN_4);

    HAL_GPIO_SetDirection(PORT_B, PIN_5, GPIO_DIR_INPUT);
    HAL_GPIO_PullUpEnable(PIN_5);
}