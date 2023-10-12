/**
  ==============================================================================
 * @file           : main.c
 * @author         : Mahmoud-Helmy
 * @brief          : Main program body
 ==============================================================================
 */
#include "helmyRTOS/helmyRTOS.h" /* Include my RTOS library header */
#include "MCAL/GPIO/GPIO.h"    /* Include  GPIO library header */
#include "MCAL/RCC/RCC.h"      /* Include RCC library header */
#include "HAL/LED/LED.h"
#include "MCAL/Systick/Systick.h"


void LED1(void);
void LED2(void);
void LED3(void);

int main(void)
{

	MCAL_RCC_Init();
	MCAL_RCC_EnablePeripheralClock(APB2_BUS,GPIOC_RCC);
	LEDs_Init();
	MCAL_GPIO_setupPinDirection(PORTC_ID,LED_GREEN,OUTPUT_SPEED_2MHZ_PP);
	MCAL_GPIO_setupPinDirection(PORTC_ID,LED_BLUE,OUTPUT_SPEED_2MHZ_PP);
	MCAL_GPIO_setupPinDirection(PORTC_ID,LED_YELLOW,OUTPUT_SPEED_2MHZ_PP);

	helmyRTOS_CreateTask(0,1000,LED1,0);
	helmyRTOS_CreateTask(1,2000,LED2,0);
	helmyRTOS_CreateTask(2,3000,LED3,0);

	helmyRTOS_Start();

	while(1){
	}
}



void LED1( void ){

	MCAL_GPIO_TogglePin(PORTC_ID,LED_GREEN);


}

void LED2 ( void ){

	MCAL_GPIO_TogglePin(PORTC_ID,LED_YELLOW);

}

void LED3 ( void ){

	MCAL_GPIO_TogglePin(PORTC_ID,LED_BLUE);

}

