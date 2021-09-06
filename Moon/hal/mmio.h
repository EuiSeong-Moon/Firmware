#ifndef HAL_MMIO_H
#define HAL_MMIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

static uint32_t MMIO_BASE;

enum
{
    // The offsets for reach register.
    GPIO_BASE = 0x200000,
 
    // Controls actuation of pull up/down to ALL GPIO pins.
    GPPUD = (GPIO_BASE + 0x94),
 
    // Controls actuation of pull up/down for specific GPIO pin.
    GPPUDCLK0 = (GPIO_BASE + 0x98),
 
    // The base address for UART.
    UART0_BASE = (GPIO_BASE + 0x1000), // for raspi4 0xFE201000, raspi2 & 3 0x3F201000, and 0x20201000 for raspi1
 
    // The offsets for reach register for the UART.
    UART0_DR     = (UART0_BASE + 0x00),
    UART0_RSRECR = (UART0_BASE + 0x04),
    UART0_FR     = (UART0_BASE + 0x18),
    UART0_ILPR   = (UART0_BASE + 0x20),
    UART0_IBRD   = (UART0_BASE + 0x24),
    UART0_FBRD   = (UART0_BASE + 0x28),
    UART0_LCRH   = (UART0_BASE + 0x2C),
    UART0_CR     = (UART0_BASE + 0x30),
    UART0_IFLS   = (UART0_BASE + 0x34),
    UART0_IMSC   = (UART0_BASE + 0x38),
    UART0_RIS    = (UART0_BASE + 0x3C),
    UART0_MIS    = (UART0_BASE + 0x40),
    UART0_ICR    = (UART0_BASE + 0x44),
    UART0_DMACR  = (UART0_BASE + 0x48),
    UART0_ITCR   = (UART0_BASE + 0x80),
    UART0_ITIP   = (UART0_BASE + 0x84),
    UART0_ITOP   = (UART0_BASE + 0x88),
    UART0_TDR    = (UART0_BASE + 0x8C),
 
    // The offsets for Mailbox registers
    MBOX_BASE    = 0xB880,
    MBOX_READ    = (MBOX_BASE + 0x00),
    MBOX_STATUS  = (MBOX_BASE + 0x18),
    MBOX_WRITE   = (MBOX_BASE + 0x20),

    //GPIO
    GPFSEL0      = (GPIO_BASE + 0x00),
    GPFSEL1      = (GPIO_BASE + 0x04),
    GPFSEL2      = (GPIO_BASE + 0x08),
    GPFSEL3      = (GPIO_BASE + 0x0C),
    GPFSEL4      = (GPIO_BASE + 0x10),
    GPFSEL5      = (GPIO_BASE + 0x14),
    GPSET0       = (GPIO_BASE + 0x1C),
    GPSET1       = (GPIO_BASE + 0x20),
    GPCLR0       = (GPIO_BASE + 0x28),
    GPCLR1       = (GPIO_BASE + 0x2C),
    GPLEV0       = (GPIO_BASE + 0x34),
    GPLEV1       = (GPIO_BASE + 0x38),
    GPEDS0       = (GPIO_BASE + 0x40),
    GPEDS1       = (GPIO_BASE + 0x44),
    GPREN0       = (GPIO_BASE + 0x4C),
    GPREN1       = (GPIO_BASE + 0x50),
    GPFEN0       = (GPIO_BASE + 0x58),
    GPFEN1       = (GPIO_BASE + 0x5C),
    GPHEN0       = (GPIO_BASE + 0x64),
    GPHEN1       = (GPIO_BASE + 0x68),
    GPLEN0       = (GPIO_BASE + 0x70),
    GPLEN1       = (GPIO_BASE + 0x74),
    GPAREN0      = (GPIO_BASE + 0x7C),
    GPAREN1      = (GPIO_BASE + 0x80),
    GPAFEN0      = (GPIO_BASE + 0x88),
    GPAFEN1      = (GPIO_BASE + 0x8C),
    GPPUDCLK1    = (GPIO_BASE + 0x9C)
};

// The MMIO area base address, depends on board type
void mmio_init(int raspi);

// Memory-Mapped I/O output
void mmio_write(uint32_t reg, uint32_t data);
 
// Memory-Mapped I/O input
uint32_t mmio_read(uint32_t reg);

#ifdef __cplusplus
}
#endif
#endif