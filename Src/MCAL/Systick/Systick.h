/*================================================================
 *	Project Name: helmyOS
 * 	File Name: Systick.h
 * 	Created on: Sep 10, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 * This header file contains the interface for the SysTick driver
 * used in the helmyOS project. It defines functions and constants
 * for SysTick timer initialization, delay, interval timing, and
 * timer interrupt handling.
 */

#ifndef SYSTICK_SYSTICK_H_
#define SYSTICK_SYSTICK_H_
#include "../../helmyRTOS/helmyRTOS.h"
#include "STM32F103C8T6.h"

#define SYSTICK_INT_ENABLE   1
#define SYSTICK_INT_DISABLE  0

/* Bit positions in STK->CTRL register */
#define STK_CTRL_ENABLE_BIT    0
#define STK_CTRL_INT_ENABLE_BIT 1
#define STK_CTRL_COUNTFLAG_BIT 16


/*=============================================================================
 * Function: MCAL_Systick_SetCallBack
 * -----------------------------------
 * Description: Sets the user-defined callback function to be called when the
 *              SysTick timer reaches zero. This function allows the user to
 *              specify a custom action to be performed when the SysTick interrupt
 *              occurs.
 * Parameters:
 *    - ptr: Pointer to the callback function.
 * Returns: None.
 *===========================================================================*/
void MCAL_Systick_SetCallBack(void (*ptr)(void));

/*=============================================================================
 * Function: MCAL_Systick_Init
 * ---------------------------
 * Description: Initializes the SysTick timer with default settings. By default,
 *              the SysTick timer is configured to generate interrupts at a
 *              frequency equal to the core clock divided by 8.
 * Parameters: None.
 * Returns: None.
 *===========================================================================*/
void MCAL_Systick_Init(void);

/*=============================================================================
 * Function: MCAL_Systick_Start
 * ----------------------------
 * Description: Starts the SysTick timer with the given preload value. The preload
 *              value determines the number of clock cycles before the timer
 *              reaches zero and generates an interrupt.
 * Parameters:
 *    - PreloadValue: The preload value to load into the SysTick timer.
 * Returns: None.
 *===========================================================================*/
void MCAL_Systick_Start(uint32 PreloadValue);

/*=============================================================================
 * Function: MCAL_Systick_INTStatus
 * ---------------------------------
 * Description: Sets or clears the SysTick interrupt status bit. This function
 *              allows the user to enable or disable the SysTick timer interrupt
 *              as needed.
 * Parameters:
 *    - Status: 1 to enable the interrupt, 0 to disable it.
 * Returns: None.
 *===========================================================================*/
void MCAL_Systick_INTStatus(uint8 Status);

/*=============================================================================
 * Function: MCAL_Systick_ReadFlag
 * --------------------------------
 * Description: Reads the SysTick interrupt flag. This function allows the user to
 *              check whether the SysTick timer has reached zero and generated an
 *              interrupt.
 * Parameters: None.
 * Returns:
 *    - 1 if the interrupt flag is set, 0 otherwise.
 *===========================================================================*/
uint8 MCAL_Systick_ReadFlag(void);
#endif /* SYSTICK_SYSTICK_H_ */
