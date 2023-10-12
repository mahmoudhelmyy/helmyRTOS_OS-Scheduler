/*================================================================
 *	Project Name: helmyOS
 * 	File Name: Systick.c
 * 	Created on: Sep 10, 2023
 * 	Author: HELMY-PC
 *================================================================
 *
 */
#include "Systick.h"  /* Include the appropriate Systick.h header file */
#include "../../HAL/LED/LED.h"

/* Private Global Variables */
 void (*MCAL_Systick_Callback)(void);  /* Callback function pointer */

/*
 * Function: SysTick_Handler
 * -------------------------
 * SysTick interrupt handler. This function is automatically called when the SysTick
 * timer reaches zero. It, in turn, calls the user-defined callback function if one
 * has been registered.
 */
void SysTick_Handler(void){

	MCAL_Systick_Callback();  /* Call the user-defined callback function */
}

/*
 * Function: MCAL_Systick_SetCallBack
 * -----------------------------------
 * Sets the user-defined callback function to be called when the SysTick timer
 * reaches zero. This function allows the user to specify a custom action to be
 * performed when the SysTick interrupt occurs.
 *
 * Parameters:
 * ptr: Pointer to the callback function.
 */
void MCAL_Systick_SetCallBack(void (*ptr)(void)){
    MCAL_Systick_Callback = ptr;  /* Store the callback function pointer */
}

/*
 * Function: MCAL_Systick_Init
 * ---------------------------
 * Initializes the SysTick timer with default settings. By default, the SysTick
 * timer is configured to generate interrupts at a frequency equal to the core
 * clock divided by 8.
 */
void MCAL_Systick_Init(void){
    /* Enable SysTick Interrupt, Clock = AHB / 8, Stop SysTick */
    STK->CTRL = (1 << STK_CTRL_ENABLE_BIT);
}

/*
 * Function: MCAL_Systick_Start
 * ----------------------------
 * Starts the SysTick timer with the given preload value. The preload value
 * determines the number of clock cycles before the timer reaches zero and
 * generates an interrupt.
 *
 * Parameters:
 * PreloadValue: The preload value to load into the SysTick timer.
 */
void MCAL_Systick_Start(uint32 PreloadValue){
    /* AHB = EXT = 8MHz & CLOCK OF STK = AHB / 8 = 8MHz / 8 = 1MHz = 1 Micro For Each Count */
    /* Load Reload Value */
    STK->LOAD = PreloadValue - 1;
    /* Clear Value Register */
    STK->VAL = 0;
    /* Enable SysTick */
    SET_BIT(STK->CTRL, STK_CTRL_ENABLE_BIT);
}

/*
 * Function: MCAL_Systick_INTStatus
 * ---------------------------------
 * Sets or clears the SysTick interrupt status bit. This function allows the user
 * to enable or disable the SysTick timer interrupt as needed.
 *
 * Parameters:
 * Status: 1 to enable the interrupt, 0 to disable it.
 */
void MCAL_Systick_INTStatus(uint8 Status){
	CLEAR_BIT(STK->CTRL,STK_CTRL_INT_ENABLE_BIT); /* Clear the SysTick interrupt status bit */
	SET_BIT(STK->CTRL,Status);   /* Set the SysTick interrupt status bit as specified */
}

/*
 * Function: MCAL_Systick_ReadFlag
 * --------------------------------
 * Reads the SysTick interrupt flag. This function allows the user to check whether
 * the SysTick timer has reached zero and generated an interrupt.
 *
 * Returns:
 * 1 if the interrupt flag is set, 0 otherwise.
 */
uint8 MCAL_Systick_ReadFlag(void){
    return (GET_BIT(STK->CTRL, STK_CTRL_COUNTFLAG_BIT));
}

/* End of MCAL_Systick.c */
