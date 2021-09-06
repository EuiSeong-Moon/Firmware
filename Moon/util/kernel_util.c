#include <stdint.h>
#include <stddef.h>

#include "kernel_util.h"
#include "uart.h"

void uart_puts(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++)
		uart_putc((unsigned char)str[i]);
}