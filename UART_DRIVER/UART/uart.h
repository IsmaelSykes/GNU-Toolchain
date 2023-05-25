#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include "stm32f401xe.h"


void debug_uart_init(void);
void uart_write(int ch);
void get_number(char *string,uint32_t len, char *fmt, ...);
void message(char *buff, uint32_t length);

#endif
