/*================================================================
 *	Project Name: helmyOS
 * 	File Name: EXTI.h
 * 	Created on: Sep 12, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 *
 */

#ifndef EXI_EXTI_H_
#define EXI_EXTI_H_
#include "STM32F103C8T6.h"

/* Define the number of EXTI lines supported by your microcontroller */
#define NUMBER_OF_EXTI_LINES 16

/*=========================== EXTI MODES ===========================*/
#define RISING_EDGE    0
#define FALLING_EDGE   1
#define ON_CHANGE      2

#define ENABLE  1
#define DISABLE 0

/*=========================== PORTS ===========================*/
#define PORTA           0
#define PORTB           1
#define PORTC           2

/*=========================== EXTI LINES ===========================*/
#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3
#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7
#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11
#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15


/*=========================== EXTI NUMBERS ===========================*/
#define EXTI0IRQn     6
#define EXTI1IRQn     7
#define EXTI2IRQn     8
#define EXTI3IRQn     9
#define EXTI4IRQn     10

#define EXTI5IRQn     23
#define EXTI6IRQn     23
#define EXTI7IRQn     23
#define EXTI8IRQn     23
#define EXTI9IRQn     23

#define EXTI10IRQn    40
#define EXTI11IRQn    40
#define EXTI12IRQn    40
#define EXTI13IRQn    40
#define EXTI14IRQn    40
#define EXTI15IRQn    40





/*
 * Function: EXTI_Init
 * ----------------------------
 * Initialize EXTI for the specified EXTI line with the given trigger mode.
 *
 * EXTILine: The EXTI line to configure.
 * EXTIMode: The trigger mode (RISING_EDGE, FALLING_EDGE, or ON_CHANGE).
 */
void MCAL_EXTI_Init(uint8 EXTILine, uint8 EXTIMode);

/*
 * Function: EXTI_Enable
 * ----------------------------
 * Enable EXTI for the specified EXTI line.
 *
 * EXTILine: The EXTI line to enable.
 */
void MCAL_EXTI_Enable(uint8 EXTILine);

/*
 * Function: EXTI_Disable
 * ----------------------------
 * Disable EXTI for the specified EXTI line.
 *
 * EXTILine: The EXTI line to disable.
 */
void MCAL_EXTI_Disable(uint8 EXTILine);

/*
 * Function: EXTI_SoftWareTrigger
 * ----------------------------
 * Generate a software trigger for the specified EXTI line.
 *
 * EXTILine: The EXTI line to trigger.
 */
void MCAL_EXTI_SoftWareTrigger(uint8 EXTILine);

/*
 * Function: EXTI_SetCallBack
 * ----------------------------
 * Set a callback function for the specified EXTI line.
 *
 * EXTILine: The EXTI line to set the callback for.
 * ptr: Pointer to the callback function.
 */
void MCAL_EXTI_SetCallBack(uint8 EXTILine, void (*ptr)(void));





#endif /* EXI_EXTI_H_ */
