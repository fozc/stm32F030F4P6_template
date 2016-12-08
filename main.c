/**
  ******************************************************************************
  * @file    main.c 
  * @author  Fatih OZCAN
  * @version V1.0.0
  * @date    28-Haziran-2016
  * @brief   Main program body
  ******************************************************************************
  */
#include "main.h"

#define LED_GPIO_CLK   RCC_AHBPeriph_GPIOA 
#define LED_PORT   	   GPIOA
#define LED_PIN        GPIO_Pin_4

extern volatile uint32_t milli_sec;

void delay_ms(uint32_t ms)
{
	 uint32_t current_time = milli_sec;
	
  while( ms > (milli_sec - current_time) ) 
	{
		;
	}		
}


int main(void)
{
		/* Set systick timer for 1ms. 1ms için Systicktimer kurulumu yapiliyor.*/
		if (SysTick_Config(SystemCoreClock / 1000))
				while (1);
	
	  GPIO_InitTypeDef GPIO_InitStructure;

	  RCC_AHBPeriphClockCmd(LED_GPIO_CLK, ENABLE);
    GPIO_DeInit(LED_PORT);
    GPIO_InitStructure.GPIO_Pin    = LED_PIN;
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;	
    GPIO_Init(LED_PORT, &GPIO_InitStructure);

  while (1)
  {
		GPIO_SetBits(LED_PORT, LED_PIN);
    delay_ms(100);
		GPIO_ResetBits(LED_PORT, LED_PIN);
		delay_ms(350);
	}
}

 
