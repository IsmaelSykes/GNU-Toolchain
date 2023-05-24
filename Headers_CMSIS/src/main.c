//Where is the led connected?
//Port:  A
//Pin:   5

#include <stdint.h>
#include <stdio.h>
#include "stm32f401xe.h"
#include "math_lib.h"
#define  GPIOAEN				(1U<<0) //   0b 0000 0000 0000 0000 0000 0000 0000 0001					
#define LED_PIN					 (1U<<5)


/*
 * (1U<<10)  // Set bit 10 to 1
 *  &=~(1U<<11) //  Set bit 11 to 0*/
void uart2_init(void);
int uart2_write(int c);
int uart2_read(void)


int main(void)
{
	/*1. Enable clock access to GPIOA*/
	RCC-> AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER  |= (1U<<10);  // Set bit 10 to 1
	GPIOA->MODER  &=~(1U<<11); //  Set bit 11 to 0
    uint32_t v = 1000000;
    uint32_t p = 20;
	uint32_t x = Prescaler(v,p);

	int number;
	char sentence[100];
	uart2_init();

	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		for(int i=0;i<x;i++){}
		//HAL_Delay(100);

			printf("Please enter a number: ");
		    scanf("%d",&number);
		    printf("Th numberentered is %d \r\n",number);
		    printf("Please type a character string:");
		    gets(sentence);
		    printf("The character string entered is: ");
		    puts(sentence);
		    printf("\r\n");
	}
}


void uart2_init(void)
{
	RCC->AHB1ENR |= (1U<<0);
	RCC->APB1ENR |= (1U<<17)
	RCC->AFR[0] |= 0x7700;
	GPIOA->MODER  |= 0x00A0;
	USART2->BRR = 0x0683;
	USART2->CR1 = 0x000C;
	USART2->CR2 = 0;
	USART2->CR3 =0;
	USART2->CR1 |= 0x2000;
}
int uart2_write(int ch)
{
	while(!(USART2->SR & 0x0080))
	{

	}
	USART2->DR = ch & 0xFF;
	return ch;
}
int uart2_read(void)
{
	while(!(USART2->SR & 0x0020))
	{

	}
	return USART2->DR;
}

struct __FILE {int handle;};
FILE_stdin ={0};
FILE_stdout = {1};
FILE_stderr = {2};

int fgetc(FILE *f)
{
	int c;
	if(c == '\r')
	{
		uart2_write(c);
		c= '\n';
	}
	uart2_write(c)
	return c;
}

int fputc(int c, FILE *f)
{
	return uart2_write(c);
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


