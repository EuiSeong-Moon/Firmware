#ifndef HAL_UART_H
#define HAL_UART_H


#ifdef __cplusplus
extern "C" {
#endif

void uart_init(int raspi);
void uart_putc(unsigned char c);
unsigned char uart_getc();

#ifdef __cplusplus
}
#endif
#endif