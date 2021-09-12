#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "stdint.h"

enum {
    GPIO_MODE_INPUT              = 0,
    GPIO_MODE_OUTPUT             = 1,
    GPIO_MODE_FUNCTION0          = 2,
    GPIO_MODE_FUNCTION1          = 3,
    GPIO_MODE_FUNCTION2          = 4,
    GPIO_MODE_FUNCTION3          = 5,
    GPIO_MODE_FUNCTION4          = 6,
    GPIO_MODE_FUNCTION5          = 7,

    GPIO_EVENT_DETECT_MODE_HIGH  = 21,
    GPIO_EVENT_DETECT_MODE_LOW   = 22,
    GPIO_EVENT_DETECT_MODE_REDGE = 23,
    GPIO_EVENT_DETECT_MODE_FEDGE = 24,
};

void GPIO_Init();
void GPIO_Set (int pin);
void GPIO_Clear (int pin);
void GPIO_Select (int pin, int mode);
int32_t GPIO_GetEvent (int pin, int mode);
int32_t GPIO_Read (int pin);
void GPIO_Allclear();

#endif