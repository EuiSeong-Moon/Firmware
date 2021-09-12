#include "gpio.h"
#include "mmio.h"

void GPIO_Init() {
    GPIO_Allclear();
}

void GPIO_Set (int pin) {
    if (pin < 32) {
        mmio_write(GPEDS0, mmio_read(GPEDS0) | (1 << pin));
    } else {
        mmio_write(GPEDS1, mmio_read(GPEDS1) | (1 << (pin-32)));
    }
}

void GPIO_Clear (int pin) {
    if (pin < 32) {
        mmio_write(GPEDS0, mmio_read(GPEDS0) & ~(1 << pin));
    } else {
        mmio_write(GPEDS1, mmio_read(GPEDS1) & ~(1 << (pin-32)));
    }
}


void GPIO_Select (int pin, int mode) {
    int stimulation = pin / 10;
    int base = (pin % 10)*3;

    switch (stimulation) {
        case 0:
            if (mode == GPIO_MODE_OUTPUT) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION0) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+2)));
            } else if (mode == GPIO_MODE_FUNCTION1) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+2)));
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION2) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+2)));
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+1)));
            } else if (mode == GPIO_MODE_FUNCTION3) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+2)));
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+1)));
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION4) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+1)));
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION5) {
                mmio_write(GPFSEL0, mmio_read(GPFSEL0) | (1 << (base+1)));
            }
            break;
        case 1:
            if (mode == GPIO_MODE_OUTPUT) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION0) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+2)));
            } else if (mode == GPIO_MODE_FUNCTION1) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+2)));
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION2) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+2)));
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+1)));
            } else if (mode == GPIO_MODE_FUNCTION3) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+2)));
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+1)));
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION4) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+1)));
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION5) {
                mmio_write(GPFSEL1, mmio_read(GPFSEL1) | (1 << (base+1)));
            }
            break;
        case 2:
            if (mode == GPIO_MODE_OUTPUT) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION0) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+2)));
            } else if (mode == GPIO_MODE_FUNCTION1) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+2)));
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION2) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+2)));
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+1)));
            } else if (mode == GPIO_MODE_FUNCTION3) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+2)));
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+1)));
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION4) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+1)));
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION5) {
                mmio_write(GPFSEL2, mmio_read(GPFSEL2) | (1 << (base+1)));
            }
            break;
        case 3:
            if (mode == GPIO_MODE_OUTPUT) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION0) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+2)));
            } else if (mode == GPIO_MODE_FUNCTION1) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+2)));
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION2) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+2)));
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+1)));
            } else if (mode == GPIO_MODE_FUNCTION3) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+2)));
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+1)));
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION4) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+1)));
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION5) {
                mmio_write(GPFSEL3, mmio_read(GPFSEL3) | (1 << (base+1)));
            }
            break;
        case 4:
            if (mode == GPIO_MODE_OUTPUT) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION0) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+2)));
            } else if (mode == GPIO_MODE_FUNCTION1) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+2)));
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION2) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+2)));
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+1)));
            } else if (mode == GPIO_MODE_FUNCTION3) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+2)));
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+1)));
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION4) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+1)));
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION5) {
                mmio_write(GPFSEL4, mmio_read(GPFSEL4) | (1 << (base+1)));
            }
            break;
        case 5:
            if (mode == GPIO_MODE_OUTPUT) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION0) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+2)));
            } else if (mode == GPIO_MODE_FUNCTION1) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+2)));
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION2) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+2)));
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+1)));
            } else if (mode == GPIO_MODE_FUNCTION3) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+2)));
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+1)));
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION4) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+1)));
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << base));
            } else if (mode == GPIO_MODE_FUNCTION5) {
                mmio_write(GPFSEL5, mmio_read(GPFSEL5) | (1 << (base+1)));
            }
            break;
    }
}

int32_t GPIO_GetEvent (int pin, int mode) {
    if (pin < 32) {
        if (GPIO_EVENT_DETECT_MODE_HIGH == mode) {
            mmio_write(GPREN0, mmio_read(GPREN0) & ~(1 << pin));
            mmio_write(GPFEN0, mmio_read(GPFEN0) & ~(1 << pin));
            mmio_write(GPHEN0, mmio_read(GPHEN0) | (1 << pin));
            mmio_write(GPLEN0, mmio_read(GPLEN0) & ~(1 << pin));
        } else if (GPIO_EVENT_DETECT_MODE_LOW == mode) {
            mmio_write(GPREN0, mmio_read(GPREN0) & ~(1 << pin));
            mmio_write(GPFEN0, mmio_read(GPFEN0) & ~(1 << pin));
            mmio_write(GPHEN0, mmio_read(GPHEN0) & ~(1 << pin));
            mmio_write(GPLEN0, mmio_read(GPLEN0) | (1 << pin));
        } else if (GPIO_EVENT_DETECT_MODE_REDGE == mode) {
            mmio_write(GPREN0, mmio_read(GPREN0) | (1 << pin));
            mmio_write(GPFEN0, mmio_read(GPFEN0) & ~(1 << pin));
            mmio_write(GPHEN0, mmio_read(GPHEN0) & ~(1 << pin));
            mmio_write(GPLEN0, mmio_read(GPLEN0) & ~(1 << pin));
        } else if (GPIO_EVENT_DETECT_MODE_FEDGE == mode) {
            mmio_write(GPREN0, mmio_read(GPREN0) & ~(1 << pin));
            mmio_write(GPFEN0, mmio_read(GPFEN0) | (1 << pin));
            mmio_write(GPHEN0, mmio_read(GPHEN0) & ~(1 << pin));
            mmio_write(GPLEN0, mmio_read(GPLEN0) & ~(1 << pin));
        }
        while ((mmio_read(GPEDS0) & (1 << pin)) == 0);
    } else {
       if (GPIO_EVENT_DETECT_MODE_HIGH == mode) {
            mmio_write(GPREN1, mmio_read(GPREN1) & ~(1 << pin));
            mmio_write(GPFEN1, mmio_read(GPFEN1) & ~(1 << pin));
            mmio_write(GPHEN1, mmio_read(GPHEN1) | (1 << pin));
            mmio_write(GPLEN1, mmio_read(GPLEN1) & ~(1 << pin));
        } else if (GPIO_EVENT_DETECT_MODE_LOW == mode) {
            mmio_write(GPREN1, mmio_read(GPREN1) & ~(1 << pin));
            mmio_write(GPFEN1, mmio_read(GPFEN1) & ~(1 << pin));
            mmio_write(GPHEN1, mmio_read(GPHEN1) & ~(1 << pin));
            mmio_write(GPLEN1, mmio_read(GPLEN1) | (1 << pin));
        } else if (GPIO_EVENT_DETECT_MODE_REDGE == mode) {
            mmio_write(GPREN1, mmio_read(GPREN1) | (1 << pin));
            mmio_write(GPFEN1, mmio_read(GPFEN1) & ~(1 << pin));
            mmio_write(GPHEN1, mmio_read(GPHEN1) & ~(1 << pin));
            mmio_write(GPLEN1, mmio_read(GPLEN1) & ~(1 << pin));
        } else if (GPIO_EVENT_DETECT_MODE_FEDGE == mode) {
            mmio_write(GPREN1, mmio_read(GPREN1) & ~(1 << pin));
            mmio_write(GPFEN1, mmio_read(GPFEN1) | (1 << pin));
            mmio_write(GPHEN1, mmio_read(GPHEN1) & ~(1 << pin));
            mmio_write(GPLEN1, mmio_read(GPLEN1) & ~(1 << pin));
        }
        while ((mmio_read(GPEDS1) & (1 << pin)) == 0);
    }
    return TRUE;
}

int32_t GPIO_Read (int pin) {
    if (pin < 32) {
        if (mmio_read(GPLEV0) & (1 << pin) == 0) {
            return FALSE;
        }
    } else {
        if (mmio_read(GPLEV1) & (1 << pin) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void GPIO_Allclear() {
    mmio_write(GPCLR0,0x0FFFFFFFF);
    //31~22 bits reserved
    mmio_write(GPCLR1,0x3FFFFF);
}