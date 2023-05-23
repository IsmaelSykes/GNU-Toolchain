//Where is the led connected?
//Port:  A
//Pin:   5

#include <stdint.h>
#include "stm32f401xe.h"
#include "math_lib.h"
#define  GPIOAEN				(1U<<0) //   0b 0000 0000 0000 0000 0000 0000 0000 0001					
#define LED_PIN					 (1U<<5)


/*
 * (1U<<10)  // Set bit 10 to 1
 *  &=~(1U<<11) //  Set bit 11 to 0*/


int main(void)
{
	/*1. Enable clock access to GPIOA*/
	RCC-> AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER  |= (1U<<10);  // Set bit 10 to 1
	GPIOA->MODER  &=~(1U<<11); //  Set bit 11 to 0
    uint32_t v = 1000000;
    uint32_t p = 4;
	uint32_t x = Prescaler(v,p);
	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		for(int i=0;i<x;i++){}
		//HAL_Delay(100);
	}
}


/*
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 stm32F401RE_startup.c -o stm32F401RE_startup.o
arm-none-eabi-gcc -nostdlib -T stm32F401RE.ld main.o stm32F401RE_startup.o -o blink.elf -Wl,-Map=blink.map

blink.bin: blink.elf
    arm-none-eabi-objcopy blink.elf -O binary < blink.bin

openocd -f board/st_nucleo_f4.cfg

*/


