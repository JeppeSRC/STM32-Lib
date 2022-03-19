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
#define ADC1_ADDR           0x50000000
    
// AHB2 
    
// AHB1 
    
// APB2 
#define OPAMP_ADDR          0x40010000
#define TIM1_ADDR           0x40012C00
    
// APB1 
#define I2C3_ADDR           0x40007800
#define I2C2_ADDR           0x40005800
#define I2S3EXT_ADDR        0x40004000
#define SPI3_ADDR           0x40003C00
#define I2S3_ADDR           SPI3_ADDR
#define SPI2_ADDR           0x40003800
#define I2S2_ADDR           SPI2_ADDR
#define I2S3EXT_ADDR        0x40003400