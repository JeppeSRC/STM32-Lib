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

#include <common.h>

void memcpy(volatile void* dstAddr, volatile void* srcAddr, uint32 size) {
    uint32 size4 = size >> 2;

    for (uint32 i = 0; i < size4; i++) {
        ((volatile uint32*)dstAddr)[i] = ((volatile uint32*)srcAddr)[i];
    }

    size &= 0x3;

    if (size) {
        for (uint32 i = 0; i < size; i++) {
            ((volatile uint8*)dstAddr)[i] = ((volatile uint8*)srcAddr)[i];
        }
    }
}

void memset(volatile void* dstAddr, uint8 value, uint32 size) {
    uint32 val = value | (value << 8) | (value << 16) | (value << 24);
    uint32 size4 = size >> 2;

    for (uint32 i = 0; i < size4; i++) {
        ((volatile uint32*)dstAddr)[i] = val;
    }

    size &= 0x3;

    if (size) {
        for (uint32 i = 0; i < size; i++) {
            ((volatile uint8*)dstAddr)[i] = (uint8)val;
        }
    }
}

#if defined(STM32LIB_REG_IMPL)

void reg_write (volatile void* registerAddr, uint32 data) {
    *((volatile uint32*)registerAddr) = data;
}

void reg_writeh(volatile void* registerAddr, uint16 data){
    *((volatile uint16*)registerAddr) = data;
}

void reg_writeb(volatile void* registerAddr, uint8  data) {
    *((volatile uint8*)registerAddr) = data;
}

uint32 reg_read (volatile void* registerAddr) {
    return *((volatile uint32*)registerAddr);
}

uint16 reg_readh(volatile void* registerAddr) {
    return *((volatile uint16*)registerAddr);
}

uint8 reg_readb(volatile void* registerAddr) {
    return *((volatile uint8*)registerAddr);
}

void reg_or (volatile void* registerAddr, uint32 data) {
    *((volatile uint32*)registerAddr) = *((volatile uint32*)registerAddr) | data;
}

void reg_orh(volatile void* registerAddr, uint16 data) {
    *((volatile uint16*)registerAddr) = *((volatile uint16*)registerAddr) | data;
}

void reg_orb(volatile void* registerAddr, uint8  data) {
    *((volatile uint8*)registerAddr) = *((volatile uint8*)registerAddr) | data;
}

#endif