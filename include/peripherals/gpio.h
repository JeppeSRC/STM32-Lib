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

#include <common.h>

///////////////////////////////////////////////////////////////////////

//MODER

#define GPIO_MODE_INPUT     0x00
#define GPIO_MODE_OUTPUT    0x01
#define GPIO_MODE_ALTERNATE 0x02
#define GPIO_MODE_ANALOG    0x03


/**
* GPIO_SetMode:         Writes portModes to the entire mode register
* GPIO_SetPortMode:     Sets the specific port to the specified mode    
* GPIO_ReadMode:        Reads the entire mode register
* GPIO_ReadPortMode:    Reads the specific port mode
*/

#define GPIO_MODER(port, mode) ((mode & 0x03) << ((port) << 1))
#define GPIO_MODER_READ(port, data) ((data >> ((port) << 1)) & 0x3)

void    GPIO_SetMode(volatile void* addr, uint32 portModes);
void    GPIO_SetPortMode(volatile void* addr, uint8 port, uint8 mode);
uint32  GPIO_ReadMode(volatile void* addr);
uint8   GPIO_ReadPortMode(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//OTYPER

#define GPIO_MODE_PUSHPULL  0x00
#define GPIO_MODE_OPENDRAIN 0x01

/**
* GPIO_SetOutputMode:         Writes portModes to the entire output mode register
* GPIO_SetPortOutputMode:     Sets the specific port to the specified mode    
* GPIO_ReadOutputMode:        Reads the entire output mode register
* GPIO_ReadPortOutputMode:    Reads the specific port output mode
*/

#define GPIO_OTYPER(port, mode) ((mode & 0x01) << (port))
#define GPIO_OTYPER_READ(port, data) ((data >> (port)) & 0x1)

void    GPIO_SetOutputMode(volatile void* addr, uint32 portModes);
void    GPIO_SetPortOutputMode(volatile void* addr, uint8 port, uint8 mode);
uint32  GPIO_ReadOutputMode(volatile void* addr);
uint8   GPIO_ReadPortOutputMode(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//OSPEEDR

#define GPIO_SPEED_LOW      0x00
#define GPIO_SPEED_MEDIUM   0x01
#define GPIO_SPEED_HIGH     0x03


/**
* GPIO_SetSpeed:         Writes portSpeeds to the entire output speed register
* GPIO_SetPortSpeed:     Sets the specific port to the specified speed    
* GPIO_ReadSpeed:        Reads the entire output speed register
* GPIO_ReadPortSpeed:    Reads the specific port spped
*/

#define GPIO_OSPEEDR(port, mode) GPIO_MODER(port, mode)
#define GPIO_OSPEEDR_READ(port, data) GPIO_MODER_READ(port, data)

void    GPIO_SetSpeed(volatile void* addr, uint32 portSpeeds);
void    GPIO_SetPortSpeed(volatile void* addr, uint8 port, uint8 speed);
uint32  GPIO_ReadSpeed(volatile void* addr);
uint8   GPIO_ReadPortSpeed(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//PUPDR

#define GPIO_PUPD_NONE      0x00
#define GPIO_PUPD_PULLUP    0x01
#define GPIO_PUPD_PULLDOWN  0x02

/**
* GPIO_SetPUPD:         Writes portModes to the entire pullup/pulldown register
* GPIO_SetPortPUPD:     Sets the specific port to the specified mode    
* GPIO_ReadPUPD:        Reads the entire pullup/pulldown register
* GPIO_ReadPortPUPD:    Reads the specific port mode
*/

#define GPIO_PUPDR(port, mode) GPIO_MODER(port, mode)
#define GPIO_PUPDR_READ(port, data) GPIO_MODER_READ(port, data)

void    GPIO_SetPUPD(volatile void* addr, uint32 portModes);
void    GPIO_SetPortPUPD(volatile void* addr, uint8 port, uint8 mode);
uint32  GPIO_ReadPUPD(volatile void* addr);
uint8   GPIO_ReadPortPUPD(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//IDR

/**
* GPIO_Read:       Reads the entire input data register
* GPIO_ReadPort:   Reads the specific port input state
*/

#define GPIO_IDR_READ(port, data) GPIO_OTYPER_READ(port, data)

uint32  GPIO_Read(volatile void* addr);
uint8   GPIO_ReadPort(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//ODR

#define GPIO_OUTPUT_SET     0x01
#define GPIO_OUTPUT_RESET   0x00

/**
* GPIO_Write:           Sets the entire output data register
* GPIO_WritePort:       Sets the specific port ouput state
* GPIO_ReadOutput:      Reads the entire output data register
* GPIO_ReadPortOutput:  Reads the specific port output state
*/

#define GPIO_ODR(port, mode) GPIO_OTYPER(port, mode)
#define GPIO_ODR_READ(port, data) GPIO_OTYPER_READ(port, data)

void    GPIO_Write(volatile void* addr, uint32 state);
void    GPIO_WritePort(volatile void* addr, uint8 port, uint8 state);
uint32  GPIO_ReadOutput(volatile void* addr);
uint8   GPIO_ReadPortOutput(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//BSRR

/**
* GPIO_Set:             Writes state into the port bit set register
* GPIO_SetPort:         Sets the specific port
* GPIO_ReadOutput:      Writes the state inpot port bit reset register
* GPIO_ReadPortOutput:  Reads the specific port output state
*/

#define GPIO_BSRR(port) (1 << (port))

void    GPIO_Set(volatile void* addr, uint32 data);
void    GPIO_SetPort(volatile void* addr, uint8 port);
void    GPIO_Reset(volatile void* addr, uint32 data);
void    GPIO_ResetPort(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//LCKR

/**
* GPIO_Lock:            Locks the port for whos bits are set in the lock register
* GPIO_SetLock:         Writes data into the port lock register
* GPIO_SetPortLock:     Sets the port bit in lock register
* GPIO_Locked:          Returns 1 if the port is locked otherwize 0
* GPIO_ReadLock:        Writes the state inpot port bit reset register
* GPIO_ReadPortPort:    Reads the specific port output state
*/

#define GPIO_LCKR(port) (1 << port)
#define GPIO_LCKR_READ(port, data) ((data >> (port)) & 0x01)

void    GPIO_Lock(volatile void* addr);
void    GPIO_SetLock(volatile void* addr, uint32 data);
void    GPIO_SetPortLock(volatile void* addr, uint8 port);
uint8   GPIO_Locked(volatile void* addr);
uint32  GPIO_ReadLock(volatile void* addr);
uint8   GPIO_ReadPortPort(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////

//AFR

/**
* GPIO_SetAlternateMode:         Writes portModes to the entire alternate mode register
* GPIO_SetPortAlternateMode:     Sets the specific port to the specified alternate mode    
* GPIO_ReadAlternateMode:        Reads the entire alternate mode register
* GPIO_ReadPortAlternateMode:    Reads the specific port alternate mode
*/

#define GPIO_AFR(port, mode) ((mode & 0x0F) << ((port) << 2))
#define GPIO_AFR_READ(port, data) ((data >> ((port) << 2)) & 0x0F)

void    GPIO_SetAlternateMode(volatile void* addr, uint64 portModes);
void    GPIO_SetPortAlternateMode(volatile void* addr, uint8 port, uint8 mode);
uint64  GPIO_ReadAlternateMode(volatile void* addr);
uint8   GPIO_ReadPortAlternateMode(volatile void* addr, uint8 port);

///////////////////////////////////////////////////////////////////////