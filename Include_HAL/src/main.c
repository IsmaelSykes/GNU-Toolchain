//Where is the led connected?
//Port:  A
//Pin:   5
#include <stdio.h>
#include <stdint.h>
#include "stm32f401xe.h"
#include "math_lib.h"
#include "uart.h"
/*
FPU
UART
GPIO
TIMEBASE
*/
#define  GPIOAEN				(1U<<0) //   0b 0000 0000 0000 0000 0000 0000 0000 0001					
#define LED_PIN					 (1U<<5)


/*
 * (1U<<10)  //  Set bit 10 to 1
 *  &=~(1U<<11) //  Set bit 11 to 0*/
void fpu_enable(void)
{
	SCB->CPACR |= (1U<<20);
	SCB->CPACR |= (1U<<21);
	SCB->CPACR |= (1U<<22);
	SCB->CPACR |= (1U<<23);
}



int main(void)
{
	/*1. Enable clock access to GPIOA*/
	//RCC-> AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	//GPIOA->MODER  |= (1U<<10);  // Set bit 10 to 1
	//GPIOA->MODER  &=~(1U<<11); //  Set bit 11 to 0
    //uint32_t v = 1000000;
    //uint32_t p = 100;
	//uint32_t x = Prescaler(v,p);
	fpu_enable();
	debug_uart_init();
	while(1)
	{
		//GPIOA->ODR ^= LED_PIN;
		for(int i=0;i<x;i++)
		{

		}

		printf("Hello from Bare Metal\r\n")
	}
}


/*
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 stm32F401RE_startup.c -o stm32F401RE_startup.o
arm-none-eabi-gcc -nostdlib -T stm32F401RE.ld main.o stm32F401RE_startup.o -o blink.elf -Wl,-Map=blink.map

blink.bin: blink.elf
    arm-none-eabi-objcopy blink.elf -O binary < blink.bin

openocd -f board/st_nucleo_f4.cfg


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

*/




