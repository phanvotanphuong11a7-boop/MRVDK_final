// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "sys/sys_config.h"
#include "hal/hal_gpio.h"

#define _XTAL_FREQ 20000000
//YC1_1
//void main(void) {
//    sys_config();
//    while (1) {
//        if (HAL_GPIO_ReadPin(PORT_B,PIN_3)== GPIO_LOW) {
//            HAL_GPIO_WritePin(PORT_D,PIN_2,GPIO_HIGH);
//        }
//        else if (HAL_GPIO_ReadPin(PORT_B,PIN_3)== GPIO_HIGH) {
//            HAL_GPIO_WritePin(PORT_D,PIN_2,GPIO_LOW);
//        }
//    }
//    return;
//}

//YC1_2: co can thiep
//void main() {
//    sys_config();
//    while (1) { 
//         {
//             if (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
//                 HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
//                 
//                 /* Ch?ng d?i */
//                 __delay_ms(20);
//                 while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
//                 
//                 uint16_t time_cnt = 0;
//                 while (time_cnt < 500) {
//                     __delay_ms(10);
//                     time_cnt++;
//                     
//                     if (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
//                         time_cnt = 0; /* Reset timer ??m l?i t? ??u */
//                         
//                         __delay_ms(20);
//                         while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW); 
//                     }
//                 }
//                 HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
//             }
//         }
//    }
//}

//YC1_2: Khong can thiep
//void main() {
//    sys_config();
//    while(1)
//             {
//             if (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
//                 HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
//                 for (uint16_t i = 0; i < 500; i++) {
//                        __delay_ms(10);
//                 }
//
//                 HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
//                while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
//             }
//         }
//}

//YC2_1
//void main() {
//    sys_config();
//    while(1)
//    {
//             static uint8_t lock_state = 0; /* 0: NONE, 1: RED(RB3), 2: GREEN(RB4), 3: YELLOW(RB5) */
//         
//             bool bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
//             bool bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
//             bool bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
//         
//             switch (lock_state) {
//                 case 0: /* T? do */
//                     if (bt1) { 
//                          lock_state = 1; 
//                          HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH); 
//                      }
//                     else if (bt2) { 
//                          lock_state = 2; 
//                          HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH); 
//                      }
//                     else if (bt3) { 
//                          lock_state = 3; 
//                          HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_HIGH); }
//                     break;
//                 case 1: /* RB3 ?ang khóa */
//                     if (!bt1) { 
//                          HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW); 
//                          lock_state = 0; 
//                     }
//                     break;
//                 case 2: /* RB4 ?ang khóa */
//                     if (!bt2) { 
//                          HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW); 
//                          lock_state = 0; 
//                     }
//                     break;
//                 case 3: /* RB5 ?ang khóa */
//                     if (!bt3) { 
//                          HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW); 
//                          lock_state = 0; 
//                     }
//                     break;
//                 default:
//                     lock_state = 0;
//                     break;
//             }
//    }
//}


//YC2_2 co can thiep
//void main() {
//    sys_config();
//    while(1) {
//             bool bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
//             bool bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
//             bool bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
//         
//             if (bt1 || bt2 || bt3) {
//                 __delay_ms(20); 
//                 
//                 if (bt1 && HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
//                     HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
//                     while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
//                     
//                     uint16_t t1 = 0;
//                     while (t1 < 500) {
//                         __delay_ms(10);
//                         t1++;
//                         if (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
//                             t1 = 0; 
//                             while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
//                         }
//                     }
//                     HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
//                 }
//                 else if (bt2 && HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
//                     HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
//                     while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
//                     
//                     uint16_t t2 = 0;
//                     while (t2 < 500) {
//                         __delay_ms(10);
//                         t2++;
//                         if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
//                             t2 = 0; 
//                             while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
//                         }
//                     }
//                     HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
//                 }
//                 else if (bt3 && HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW) {
//                     HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_HIGH);
//                     while (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
//                     
//                     uint16_t t3 = 0;
//                     while (t3 < 500) {
//                         __delay_ms(10);
//                         t3++;
//                         if (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW) {
//                             t3 = 0; 
//                             while (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
//                         }
//                     }
//                     HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW);
//                 }
//             }
//    }
//}


//YC2_2 KHONG CAN THIEP
void main() {
    sys_config();
    while (1) {
              bool bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
             bool bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
             bool bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
         
             if (bt1 || bt2 || bt3) {
                 __delay_ms(20); 
                 
                 if (bt1 && HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
                     HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
                     for (uint16_t i = 0; i < 500; i++) { __delay_ms(10); } /* Ch? c?ng 5s */
                     HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
                     while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
                 }
                 else if (bt2 && HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
                     HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
                     for (uint16_t i = 0; i < 500; i++) { __delay_ms(10); } 
                     HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
                     while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
                 }
                 else if (bt3 && HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW) {
                     HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_HIGH);
                     for (uint16_t i = 0; i < 500; i++) { __delay_ms(10); } 
                     HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW);
                     while (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
                 }
             }
         }
 }