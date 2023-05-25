#include <stdio.h>
#include <stdint.h>
#include "stm32f401xe.h"
#include "adc.h"
#include "fpu.h"
#include "uart.h"

#define  GPIOAEN				(1U<<0) 
#define LED_PIN					 (1U<<5)

uint32_t sensor_value;



int main(void)
{

    RCC-> AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER  |= (1U<<10);  // Set bit 10 to 1
	GPIOA->MODER  &=~(1U<<11); //  Set bit 11 to 0
	//initialise_monitor_handles();

	/*Enable FPU*/
	fpu_enable();

	/*Initialize debug UART*/
	debug_uart_init();
	pa1_adc_init();
	start_converstion();
	char measure[8];
	char message[] = "\r Hola STM32F401RE \r\n"; 
	for(int i = 0; i<sizeof(message);i++)
		uart_write(message[i]);
	
	get_number(measure,sizeof(measure), "%.3f", 516.123);
    message("\r measure: \r\n",9);
    message(measure,8);
	
	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		sensor_value =  adc_read();
		
		//printf("\r Sensor value : %d \r\n",(int)sensor_value);
		for(int i =0;i<100000;i++){}

	}

}

//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





