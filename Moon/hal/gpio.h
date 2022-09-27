#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "stdint.h"

enum {
    // PIN Modes
    GPIO_MODE_INPUT              = 0,
    GPIO_MODE_OUTPUT             = 1,
    GPIO_MODE_FUNCTION0          = 2,
    GPIO_MODE_FUNCTION1          = 3,
    GPIO_MODE_FUNCTION2          = 4,
    GPIO_MODE_FUNCTION3          = 5,
    GPIO_MODE_FUNCTION4          = 6,
    GPIO_MODE_FUNCTION5          = 7,

    // Detect pulse
    GPIO_EVENT_DETECT_MODE_HIGH  = 21,
    GPIO_EVENT_DETECT_MODE_LOW   = 22,
    GPIO_EVENT_DETECT_MODE_REDGE = 23,
    GPIO_EVENT_DETECT_MODE_FEDGE = 24,

    // GPIO PINs
    GPIO_BASE    = 0x200000,
    // Select GPIO functions
    GPFSEL0      = (GPIO_BASE + 0x00),
    GPFSEL1      = (GPIO_BASE + 0x04),
    GPFSEL2      = (GPIO_BASE + 0x08),
    GPFSEL3      = (GPIO_BASE + 0x0C),
    GPFSEL4      = (GPIO_BASE + 0x10),
    GPFSEL5      = (GPIO_BASE + 0x14),
    // Set GPIO pins when pins are output mode.
    GPSET0       = (GPIO_BASE + 0x1C),
    GPSET1       = (GPIO_BASE + 0x20),
    // Clear GPIO pins when pins are output mode.
    GPCLR0       = (GPIO_BASE + 0x28),
    GPCLR1       = (GPIO_BASE + 0x2C),
    // Return GPIO pin value return 0 is Low, return 1 is High.
    GPLEV0       = (GPIO_BASE + 0x34),
    GPLEV1       = (GPIO_BASE + 0x38),
    // Detect GPIO pin events. 
    GPEDS0       = (GPIO_BASE + 0x40),
    GPEDS1       = (GPIO_BASE + 0x44),
    // Check the rising edge when we detect GPIO pin events at GPEDS
    GPREN0       = (GPIO_BASE + 0x4C),
    GPREN1       = (GPIO_BASE + 0x50),
    // Check the falling edge when we detect GPIO pin events at GPEDS
    GPFEN0       = (GPIO_BASE + 0x58),
    GPFEN1       = (GPIO_BASE + 0x5C),
    // Check the High when we detect GPIO pin events at GPEDS
    GPHEN0       = (GPIO_BASE + 0x64),
    GPHEN1       = (GPIO_BASE + 0x68),
    // Check the Low when we detect GPIO pin evets at GPEDS
    GPLEN0       = (GPIO_BASE + 0x70),
    GPLEN1       = (GPIO_BASE + 0x74),
    // Check the Asynchronize rising edge when we detect GPIO pin events at GPEDS
    GPAREN0      = (GPIO_BASE + 0x7C),
    GPAREN1      = (GPIO_BASE + 0x80),
    // Check the Asynchronize falling edge when we detect GPIO pin events at GPEDS
    GPAFEN0      = (GPIO_BASE + 0x88),
    GPAFEN1      = (GPIO_BASE + 0x8C),

    // Controls actuation of pull up/down to ALL GPIO pins.
    GPPUD = (GPIO_BASE + 0x94),
 
    // Controls actuation of pull up/down for specific GPIO pin.
    GPPUDCLK0 = (GPIO_BASE + 0x98),
    GPPUDCLK1    = (GPIO_BASE + 0x9C),
 
};

int32_t GPIO_Init ();
// How to use GPIO PIN such as in/out, function0~5
int32_t GPIO_Select (uint32_t pin, int32_t mode);
// GPIO set 1 or 0
int32_t GPIO_Set (uint32_t pin, int32_t level);
// Clear GPIO Pin
int32_t GPIO_Clear (uint32_t pin);
// Read GPIO pin. Low is 0, High is 1
int32_t GPIO_Read (uint32_t pin, int32_t* value);
// Detect event.
int32_t GPIO_Event (uint32_t pin, int32_t event);
// Clear all of the pins
int32_t GPIO_Allclear();

#endif