#ifndef HAL_MMIO_H
#define HAL_MMIO_H

#include <stdint.h>

#define TRUE       1
#define FALSE      0


#ifdef __cplusplus
extern "C" {
#endif

static uint32_t MMIO_BASE;

enum
{
    ERROR = -1,
    SUCCESS = 0,

    // Pulse value
    HIGH = 1,
    LOW = 0,

    // The offsets for reach register.
    IRQ_BASE = 0xB000,
 
    // The base address for UART.
    UART0_BASE = (0x200000 + 0x1000), // for raspi4 0xFE201000, raspi2 & 3 0x3F201000, and 0x20201000 for raspi1
 
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


	//INTERRUPT
	IRQ_PENDING_BASIC = (IRQ_BASE + 0x200),
	IRQ_PENDING1      = (IRQ_BASE + 0x204),
	IRQ_PENDING2      = (IRQ_BASE + 0x208),
	FIQ_CONTROL       = (IRQ_BASE + 0x20C),
	IRQ_ENABLE1       = (IRQ_BASE + 0x210),
	IRQ_ENABLE2       = (IRQ_BASE + 0x214),
	IRQ_ENABLE_BASIC  = (IRQ_BASE + 0x218),
	IRQ_DISABLE1      = (IRQ_BASE + 0x21C),
	IRQ_DISABLE2      = (IRQ_BASE + 0x220),
	IRQ_DISABLE_BASIC = (IRQ_BASE + 0x224)
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
