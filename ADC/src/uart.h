#ifndef __UART_H__
#define __UART_H__

#include "stm32f401xe.h"

void debug_uart_init(void);
void uart_write(int ch);

#endif
