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

#include <stm32f3xx.h>

void write(volatile void* addr, uint32 offset, uint32 data) {
    reg_write(REG_ADDR(addr, offset), data);
}

uint32 read(volatile void* addr, uint32 offset) {
    return reg_read(REG_ADDR(addr, offset)); 
}

///////////////////////////////////////////////////////////////////////

//MODER

void GPIO_SetModes(volatile void* addr, uint32 portModes) {
    write(addr, GPIO_MODER_ADDR, portModes);
}

void GPIO_SetPortMode(volatile void* addr, uint8 port, uint8 mode) {
    uint32 v = read(addr, GPIO_MODER_ADDR);

    write(addr, GPIO_MODER_ADDR, (v & ~GPIO_MODER(port, 0xFF)) | GPIO_MODER(port, mode));
}

uint32 GPIO_ReadModes(volatile void* addr) {
    return read(addr, GPIO_MODER_ADDR);
}

uint8 GPIO_ReadPortMode(volatile void* addr, uint8 port) {
    return GPIO_MODER_READ(port, read(addr, GPIO_MODER_ADDR));
}

///////////////////////////////////////////////////////////////////////

//OTYPER

void GPIO_SetOutputModes(volatile void* addr, uint32 portModes) {
    write(addr, GPIO_OTYPER_ADDR, portModes);
}

void GPIO_SetPortOutputMode(volatile void* addr, uint8 port, uint8 mode) {
    uint32 v = read(addr, GPIO_OTYPER_ADDR);

    write(addr, GPIO_OTYPER_ADDR, (v & ~GPIO_OTYPER(port, 0xFF)) | GPIO_OTYPER(port, mode));
}

uint32 GPIO_ReadOutputModes(volatile void* addr) {
    return read(addr, GPIO_OTYPER_ADDR);
}

uint8 GPIO_ReadPortOutputMode(volatile void* addr, uint8 port) {
    return GPIO_OTYPER_READ(port, read(addr, GPIO_OTYPER_ADDR));
}

///////////////////////////////////////////////////////////////////////

//OSPEEDR

void GPIO_SetSpeeds(volatile void* addr, uint32 portSpeeds) {
    write(addr, GPIO_OSPEEDR_ADDR, portSpeeds);
}

void GPIO_SetPortSpeed(volatile void* addr, uint8 port, uint8 mode) {
    uint32 v = read(addr, GPIO_OSPEEDR_ADDR);

    write(addr, GPIO_OSPEEDR_ADDR, (v & ~GPIO_OSPEEDR(port, 0xFF)) | GPIO_OSPEEDR(port, mode));
}

uint32 GPIO_ReadSpeeds(volatile void* addr) {
    return read(addr, GPIO_OSPEEDR_ADDR);
}

uint8 GPIO_ReadPortSpeed(volatile void* addr, uint8 port) {
    return GPIO_OSPEEDR_READ(port, read(addr, GPIO_OSPEEDR_ADDR));
}

///////////////////////////////////////////////////////////////////////

//PUPDR

void GPIO_SetPUPD(volatile void* addr, uint32 portModes) {
    write(addr, GPIO_PUPDR_ADDR, portModes);
}

void GPIO_SetPortPUPD(volatile void* addr, uint8 port, uint8 mode) {
    uint32 v = read(addr, GPIO_PUPDR_ADDR);

    write(addr, GPIO_PUPDR_ADDR, (v & ~GPIO_PUPDR(port, 0xFF)) | GPIO_PUPDR(port, mode));
}

uint32 GPIO_ReadPUPD(volatile void* addr) {
    return read(addr, GPIO_PUPDR_ADDR);
}

uint8 GPIO_ReadPortPUPD(volatile void* addr, uint8 port) {
    return GPIO_PUPDR_READ(port, read(addr, GPIO_PUPDR_ADDR));
}

///////////////////////////////////////////////////////////////////////

//IDR

uint32 GPIO_Read(volatile void* addr) {
    return read(addr, GPIO_IDR_ADDR);
}

uint8 GPIO_ReadPort(volatile void* addr, uint8 port) {
    return GPIO_IDR_READ(port, read(addr, GPIO_IDR_ADDR));
}

///////////////////////////////////////////////////////////////////////

//ODR

void GPIO_Write(volatile void* addr, uint32 state) {
    write(addr, GPIO_ODR_ADDR, state);
}

void GPIO_WritePort(volatile void* addr, uint8 port, uint8 state) {
    uint32 v = read(addr, GPIO_ODR_ADDR);

    write(addr, GPIO_ODR_ADDR, (v & ~GPIO_ODR(port, 0xFF)) | GPIO_ODR(port, state));
}

uint32 GPIO_ReadOutputs(volatile void* addr) {
    return read(addr, GPIO_ODR_ADDR);
}

uint8 GPIO_ReadPortOutput(volatile void* addr, uint8 port) {
    return GPIO_ODR_READ(port, read(addr, GPIO_ODR_ADDR));
}

///////////////////////////////////////////////////////////////////////

//BSRR

void GPIO_Set(volatile void* addr, uint32 data) {
    write(addr, GPIO_BSRR_ADDR, data & 0xFFFF);
}

void GPIO_SetPort(volatile void* addr, uint8 port) {
    write(addr, GPIO_BSRR_ADDR, GPIO_BSRR(port));
}

void GPIO_Reset(volatile void* addr, uint32 data) {
    write(addr, GPIO_BSRR_ADDR, (data & 0xFFFF) << 16);
}

void GPIO_ResetPort(volatile void* addr, uint8 port) {
    write(addr, GPIO_BSRR_ADDR, GPIO_BSRR(port + 16));
}

///////////////////////////////////////////////////////////////////////

//LCKR

void GPIO_Lock(volatile void* addr) {
    write(addr, GPIO_LCKR_ADDR, 0x10000);
}

void GPIO_SetLocks(volatile void* addr, uint32 data) {
    write(addr, GPIO_LCKR_ADDR, data & 0xFFFF);
}

void GPIO_SetPortLock(volatile void* addr, uint8 port) {
    write(addr, GPIO_LCKR_ADDR, GPIO_LCKR(port));
}

uint8 GPIO_Locked(volatile void* addr) {
    return GPIO_LCKR_READ(16, read(addr, GPIO_LCKR_ADDR));
}

uint32 GPIO_ReadLocks(volatile void* addr) {
    return read(addr, GPIO_LCKR_ADDR);
}

uint8 GPIO_ReadPortPort(volatile void* addr, uint8 port) {
    return GPIO_LCKR_READ(port, read(addr, GPIO_LCKR_ADDR));
}

///////////////////////////////////////////////////////////////////////

//ADR

void GPIO_SetAlternateModes(volatile void* addr, uint64 portModes) {
    write(addr, GPIO_AFRL_ADDR, (uint32)(portModes & 0xFFFFFFFF));
    write(addr, GPIO_AFRH_ADDR, (uint32)((portModes >> 32) & 0xFFFFFFFF));
}

void GPIO_SetPortAlternateMode(volatile void* addr, uint8 port, uint8 mode) {
    if (port >= 8) {
        write(addr, GPIO_AFRH_ADDR, GPIO_AFR(port - 8, mode));
    } else {
        write(addr, GPIO_AFRL_ADDR, GPIO_AFR(port, mode));
    }
}

uint64 GPIO_ReadAlternateModes(volatile void* addr) {
    uint32 vl = read(addr, GPIO_AFRL_ADDR);
    uint32 vh = read(addr, GPIO_AFRH_ADDR);
    
    return ((uint64)vh << 32) | vl;
}

uint8 GPIO_ReadPortAlternateMode(volatile void* addr, uint8 port) {
    if (port >= 8) {
        return GPIO_AFR_READ(port, read(addr, GPIO_AFRH_ADDR));
    } else {
        return GPIO_AFR_READ(port, read(addr, GPIO_AFRL_ADDR));
    }
}

///////////////////////////////////////////////////////////////////////