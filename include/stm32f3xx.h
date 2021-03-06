/**
MIT License

Copyright (c) 2022 Jesper

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "common.h"
#include "peripherals/gpio.h"
#include "peripherals/flash.h"

// AHB3

// AHB2
#define GPIOF_ADDR          0x48001400
#define GPIOD_ADDR          0x48000C00
#define GPIOC_ADDR          0x48000800
#define GPIOB_ADDR          0x48000400
#define GPIOA_ADDR          0x48000000

//AHB1  
#define TSC_ADDR            0x40024000
#define CRC_ADDR            0x40023000
#define FLASH_ADDR          0x40022000
#define RCC_ADDR            0x40021000
#define DMA1_ADDR           0x40020000

//APB2  
#define TIM17_ADDR          0x40014800
#define TIM16_ADDR          0x40014400
#define TIM15_ADDR          0x40014000
#define USART1_ADDR         0x40013800
#define EXTI_ADDR           0x40010400
#define SYSCFG_ADDR         0x40010000
#define COMP_ADDR           0x40010000
#define OPAMP_ADDR          0x40010000

//APB1  
#define DAC1_ADDR           0x40007400
#define PWR_ADDR            0x40007000
#define I2C1_ADDR           0x40005400
#define USART3_ADDR         0x40004800
#define USART2_ADDR         0x40004400
#define IWDG_ADDR           0x40003000
#define WWDG_ADDR           0x40002C00
#define RTC_ADDR            0x40002800
#define TIM6_ADDR           0x40001000
#define TIM2_ADDR           0x40000000

//GPIO registers
#define GPIO_MODER_ADDR     0x00
#define GPIO_OTYPER_ADDR    0x04
#define GPIO_OSPEEDR_ADDR   0x08
#define GPIO_PUPDR_ADDR     0x0C
#define GPIO_IDR_ADDR       0x10
#define GPIO_ODR_ADDR       0x14
#define GPIO_BSRR_ADDR      0x18
#define GPIO_LCKR_ADDR      0x1C
#define GPIO_AFRL_ADDR      0x20
#define GPIO_AFRH_ADDR      0x24

//TODO: TSC
//TODO: CRC

//FLASH registers
#define FLASH_ACR_ADDR      0x00
#define FLASH_KEYR_ADDR     0x04
#define FLASH_OPTKEYR_ADDR  0x08
#define FLASH_SR_ADDR       0x0C
#define FLASH_CR_ADDR       0x10
#define FLASH_AR_ADDR       0x14
#define FLASH_OBR_ADDR      0x1C
#define FLASH_WRPR_ADDR     0x20