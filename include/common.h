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

#define SRAM_ADDR           0x20000000
#define OPTIONS_ADDR        0x1FFFF800
#define SYSMEMORY_ADDR      0x1FFFD800
#define FLASHMEMORY_ADDR    0x08000000

#define SYSTIMER_ADDR       0xE000E010
#define NVIC_ADDR           0xE000E100
#define SCB_ADDR            0xE000ED00
#define MPU_ADDR            0xE000ED90
#define FPU_ADDR            0xE000EF30

typedef unsigned char uint8;
typedef unsigned char byte;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned long long uint64;
typedef signed long long int64;

#if defined(STM32LIB_MEM_ASM) && defined(__cplusplus)

extern "C" void memcpy(volatile void* dstAddr, volatile void* srcAddr, uint32 size);
extern "C" void memset(volatile void* dstAddr, uint8 value, uint32 size);

#else

void memcpy(volatile void* dstAddr, volatile void* srcAddr, uint32 size);
void memset(volatile void* dstAddr, uint8 value, uint32 size);

#endif

#define REG_ADDR(base, offset) ((volatile uint32*)(base + offset))

#if defined(STM32LIB_REG_ASM) && defined(__cplusplus)

extern "C" void reg_write (volatile void* registerAddr, uint32 data);
extern "C" void reg_writeh(volatile void* registerAddr, uint16 data);
extern "C" void reg_writeb(volatile void* registerAddr, uint8  data);

extern "C" void reg_read (volatile void* registerAddr, uint32 data);
extern "C" void reg_readh(volatile void* registerAddr, uint16 data);
extern "C" void reg_readb(volatile void* registerAddr, uint8  data);

extern "C" void reg_or (volatile void* registerAddr, uint32 data);
extern "C" void reg_orh(volatile void* registerAddr, uint16 data);
extern "C" void reg_orb(volatile void* registerAddr, uint8  data);

#elif defined(STM32LIB_REG_IMPL)

void reg_write (volatile void* registerAddr, uint32 data);
void reg_writeh(volatile void* registerAddr, uint16 data);
void reg_writeb(volatile void* registerAddr, uint8  data);

uint32 reg_read (volatile void* registerAddr);
uint16 reg_readh(volatile void* registerAddr);
uint8  reg_readb(volatile void* registerAddr);

void reg_or (volatile void* registerAddr, uint32 data);
void reg_orh(volatile void* registerAddr, uint16 data);
void reg_orb(volatile void* registerAddr, uint8  data);

#else


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"


static void reg_write (volatile void* registerAddr, uint32 data) {
    *((volatile uint32*)registerAddr) = data;
}

static void reg_writeh(volatile void* registerAddr, uint16 data){
    *((volatile uint16*)registerAddr) = data;
}

static void reg_writeb(volatile void* registerAddr, uint8  data) {
    *((volatile uint8*)registerAddr) = data;
}

static uint32 reg_read (volatile void* registerAddr) {
    return *((volatile uint32*)registerAddr);
}

static uint16 reg_readh(volatile void* registerAddr) {
    return *((volatile uint16*)registerAddr);
}

static uint8 reg_readb(volatile void* registerAddr) {
    return *((volatile uint8*)registerAddr);
}

static void reg_or (volatile void* registerAddr, uint32 data) {
    *((volatile uint32*)registerAddr) = *((volatile uint32*)registerAddr) | data;
}

static void reg_orh(volatile void* registerAddr, uint16 data) {
    *((volatile uint16*)registerAddr) = *((volatile uint16*)registerAddr) | data;
}

static void reg_orb(volatile void* registerAddr, uint8  data) {
    *((volatile uint8*)registerAddr) = *((volatile uint8*)registerAddr) | data;
}

#pragma GCC diagnostic pop

#endif

