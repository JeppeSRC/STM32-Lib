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

// AHB3

// AHB2
#define GPIOE_ADDR          0x48001000

// AHB1
#define DMA2_ADDR           0x40020400

// APB2
#define SDADC3_ADDR         0x40016800
#define SDADC2_ADDR         0x40016400
#define SDADC1_ADDR         0x40016000
#define TIM19_ADDR          0x40015C00
#define SPI1_ADDR           0x40013000
#define I2S1_ADDR           SPI1_ADDR
#define ADC_ADDR            0x40012400

// APB1
#define TIM18_ADDR          0x40009C00
#define DAC2_ADDR           0x40009800
#define CEC_ADDR            0x40007800
#define CAN_ADDR            0x40006400
#define USB_SRAM_ADDR       0x40006000
#define USB_ADDR            0x40005C00
#define I2C2_ADDR           0x40005800
#define SPI3_ADDR           0x40003C00
#define I2S3_ADDR           SPI3_ADDR
#define SPI2_ADDR           0x40003800
#define I2S2_ADDR           SPI2_ADDR
#define TIM14_ADDR          0x40002000
#define TIM13_ADDR          0x40001C00
#define TIM12_ADDR          0x40001800
#define TIM7_ADDR           0x40001400
#define TIM5_ADDR           0x40000C00
#define TIM4_ADDR           0x40000800
#define TIM3_ADDR           0x40000400