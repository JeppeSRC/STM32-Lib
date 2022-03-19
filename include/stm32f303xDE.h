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

#include "stm32f3xx.h"

// AHB4
#define FMC_CTRL_ADDR       0xA0000000
#define FMC_BANK34_ADDR     0x80000000
#define FMC_BANK12_ADDR     0x60000000

// AHB3
#define ADC1_ADDR           0x50000000
#define ADC2_ADDR           0x50000100
#define ADC12_ADDR          0x50000300
#define ADC3_ADDR           0x50000400
#define ADC4_ADDR           0x50000500
#define ADC34_ADDR          0x50000700

// AHB2
#define GPIOH_ADDR          0x48001C00
#define GPIOG_ADDR          0x48001800
#define GPIOE_ADDR          0x48001000

// AHB1         
#define DMA2_ADDR           0x40020400

// APB2
#define TIM20_ADDR          0x40015000
#define SPI4_ADDR           0x40013C00
#define TIM8_ADDR           0x40013400
#define SPI1_ADDR           0x40013000
#define OPAMP_ADDR          0x40010000
#define TIM1_ADDR           0x40012C00

// APB1
#define I2C3_ADDR           0x40007800
#define CAN_ADDR            0x40006400
#define USB_SRAM_ADDR       0x40006000
#define USB_ADDR            0x40005C00
#define I2C2_ADDR           0x40005800
#define USART5              0x40005000
#define USART4              0x40004C00
#define I2S3EXT_ADDR        0x40004000
#define SPI3_ADDR           0x40003C00
#define I2S3_ADDR           SPI3_ADDR
#define SPI2_ADDR           0x40003800
#define I2S2_ADDR           SPI2_ADDR
#define I2S3EXT_ADDR        0x40003400
#define TIM7_ADDR           0x40001400
#define TIM4_ADDR           0x40000800
#define TIM3_ADDR           0x40000400

#define CCM_SRAM_ADDR       0x10000000