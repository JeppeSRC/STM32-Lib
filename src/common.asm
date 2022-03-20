/*
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

.syntax unified
.thumb

#if defined(STM32LIB_MEM_ASM)

.global memcpy
.global memset

#endif

#if defined(STM32LIB_REG_ASM)

.global reg_write
.global reg_writeh
.global reg_writeb
.global reg_read
.global reg_readh
.global reg_readb
.global reg_or
.global reg_orh
.global reg_orb

#endif

################################

.section .text.mem

.thumb_func
memcpy:
    push {r4, lr}
    movs r3, r2, lsr #2
    beq memcpy_odd

memcpy_word_loop:
    ldr r4, [r1], #4
    str r4, [r0], #4
    subs r3, #1
    bne memcpy_word_loop

memcpy_odd:
    ands r2, #3
    beq memcpy_end

memcpy_odd_loop:
    ldrb r4, [r1], #1
    strb r4, [r0], #1
    subs r2, #1
    bne memcpy_odd_loop

memcpy_end:
    pop {r4, pc}

################################

.thumb_func
memset:
    movs r3, r2, lsr #2
    beq memset_odd

    orr r1, r1, r1, lsl #8
    orr r1, r1, r1, lsl #16

memset_word_loop:
    str  r1, [r0], #4
    subs r3, #1
    bne memset_word_loop

memset_odd:
    ands r2, #3
    beq memset_end

memset_odd_loop:
    strb r1, [r0], #1
    subs r2, #1
    bne memset_odd_loop

memset_end:
    bx lr

##############################

.section .text.reg

.thumb_func
reg_write:
    str r1, [r0]
    bx lr

.thumb_func
reg_writeh:
    strh r1, [r0]
    bx lr

.thumb_func
reg_writeb:
    strb r1, [r0]
    bx lr

.thumb_func
reg_read:
    ldr r0, [r0]
    bx lr

.thumb_func
reg_readh:
    ldrh r0, [r0]
    bx lr

.thumb_func
reg_readb:
    ldrb r0, [r0]
    bx lr

.thumb_func
reg_or:
    ldr r2, [r0]
    orr r2, r1
    str r2, [r0]
    bx lr

.thumb_func
reg_orh:
    ldrh r2, [r0]
    orr  r2, r1
    strh r2, [r0]
    bx lr

.thumb_func
reg_orb:
    ldrb r2, [r0]
    orr  r2, r1
    strb r2, [r0]
    bx lr
