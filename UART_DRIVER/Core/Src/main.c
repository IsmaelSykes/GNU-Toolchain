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
	char measure[10];
	float n1 = 27.2512;
	float n2 = 25.2517;
	float n3 = n1*n2;//637.62310144
	
	char m[] = "\r Hola STM32F401RE \r\n"; 
	message(m,sizeof(m));

	//for(int i = 0; i<sizeof(m);i++)
	//	uart_write(m[i]);
	
	
	get_number(measure,sizeof(measure), "%.6f", n3);
    message("\r measure: ",sizeof("\r measure: "));
    message(measure,10);
    message("\r\n",sizeof("\r\n"));

    float e1 = 12.231;
    float e2 = 12.231;
    float e3 = e1+e2 ;

    get_number(measure,sizeof(measure), "%.6f", e3);
    message("\r edad : ",sizeof("\r edad : "));
    message(measure,10);
    message("\r\n",sizeof("\r\n"));
    float j = 0;
	
	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		sensor_value =  adc_read();
		j += 0.002;
		get_number(measure,sizeof(measure), "%.6f", j);
		message("\r j : ",sizeof("\r j : "));
		message(measure,10);
		message("\r\n",sizeof("\r\n"));
		for(int i =0;i<1500000;i++)
		{

		}

	}

}

//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





