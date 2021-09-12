#include "mmio.h"
#include "uart.h"
#include "kernel_util.h"
#include "delay.h"
#include "gpio.h"
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
 
#ifdef AARCH64
// arguments for AArch64
void kernel_main(uint64_t dtb_ptr32, uint64_t x1, uint64_t x2, uint64_t x3)
#else
// arguments for AArch32
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
#endif
{
	// initialize UART for Raspi2
	uart_init(3);
	uart_puts("Hello, kernel World!\r\n");
	GPIO_Init();
	//mmio_write(GPFSEL0,0x11);
	//gpio_clear();
 
	while (1) {
		uart_putc(uart_getc());
	}
}

