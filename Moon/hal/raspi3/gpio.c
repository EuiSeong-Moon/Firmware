#include "gpio.h"
#include "mmio.h"
#include <stdlib.h>
#include <stdio.h>

int32_t GPIO_Init() {
    // Empty
    return SUCCESS;
}

//How to use GPIO pins. Set modes and functions.
int32_t GPIO_Select (uint32_t pin, int32_t mode) {
    char buf = 0;
    int32_t curGPFSEL = 0;
    switch (mode) {
        case GPIO_MODE_INPUT:
            buf = buf | 0b000;
            break;
        case GPIO_MODE_OUTPUT:
            buf |= 0b001;
            break;
        case GPIO_MODE_FUNCTION0:
            buf |= 0b100;
            break;
        case GPIO_MODE_FUNCTION1:
            buf |= 0b101;
            break;
        case GPIO_MODE_FUNCTION2:
            buf |= 0b110;
            break;
        case GPIO_MODE_FUNCTION3:
            buf |= 0b111;
            break;
        case GPIO_MODE_FUNCTION4:
            buf |= 0b011;
            break;
        case GPIO_MODE_FUNCTION5:
            buf |= 0b010;
            break;
    }

    //overwrite 문제 해결필요 재작성필요
    if (pin < 0 || pin > 53) {
        //Wrong pin numbers
        //exit(1);
    } else if (pin <= 9) {
        curGPFSEL = mmio_read(GPFSEL0);
        curGPFSEL &= ~(0b111 << pin*3);
        curGPFSEL |= (buf << pin*3);
        mmio_write(GPFSEL0, curGPFSEL);
    } else if (pin <=19) {
        curGPFSEL = mmio_read(GPFSEL1);
        curGPFSEL &= ~(0b111 << (pin-10)*3);
        curGPFSEL |= (buf << (pin-10)*3);
        mmio_write(GPFSEL1, curGPFSEL);
    } else if (pin <= 29) {
        curGPFSEL = mmio_read(GPFSEL2);
        curGPFSEL &= ~(0b111 << (pin-20)*3);
        curGPFSEL |= (buf << (pin-20)*3);
        mmio_write(GPFSEL2, curGPFSEL);
    } else if (pin <= 39) {
        curGPFSEL = mmio_read(GPFSEL3);
        curGPFSEL &= ~(0b111 << (pin-30)*3);
        curGPFSEL |= (buf << (pin-30)*3);
        mmio_write(GPFSEL3, curGPFSEL);
    } else if (pin <= 49) {
        curGPFSEL = mmio_read(GPFSEL4);
        curGPFSEL &= ~(0b111 << (pin-40)*3);
        curGPFSEL |= (buf << (pin-40)*3);
        mmio_write(GPFSEL4, curGPFSEL);
    }
    return SUCCESS;
}

//GPIO SET when GPIO is output mode.
int32_t GPIO_Set (uint32_t pin, int32_t level) {
    if (pin < 32) {
        mmio_write(GPSET0, (mmio_read(GPLEV0) | (1 << pin)));
    } else {
        mmio_write(GPSET1, (mmio_read(GPLEV1) | (1 << (pin-32))));
    }
    return SUCCESS;
}

int32_t GPIO_Clear (uint32_t pin) {
    if (pin < 32) {
        mmio_write(GPEDS0, (~mmio_read(GPLEV0) | (1 << pin)));
    } else {
        mmio_write(GPEDS1, (~mmio_read(GPLEV1) | (1 << (pin-32))));
    }
    return SUCCESS;
}

int32_t GPIO_Read (uint32_t pin, int32_t* value) {
    uint32_t curData = 0;
    if (pin < 32) {
        curData = (mmio_read(GPLEV0) & (1 << pin));
    } else {
        curData = (mmio_read(GPLEV1) & (1 << pin-32));
    }
    if (curData == 0) {
        *value = 0;
    } else {
        *value = 1;
    }
    return SUCCESS;
}

int32_t GPIO_Allclear() {
    mmio_write(GPCLR0,0x0FFFFFFFF);
    //31~22 bits reserved
    mmio_write(GPCLR1,0x3FFFFF);
    return SUCCESS;
}

int32_t GPIO_Event (uint32_t pin, int32_t event) {
    // Empty
    return SUCCESS;
}
