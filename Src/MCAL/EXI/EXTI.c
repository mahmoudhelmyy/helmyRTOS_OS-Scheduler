/*================================================================
 *  Project Name: helmyOS
 *  File Name: EXTI.c
 *  Created on: Sep 12, 2023
 *  Author: HELMY-PC
 *================================================================
 *                      File Description
 *================================================================
 *  This file contains the implementation of the EXTI (External
 *  Interrupt) driver for helmyOS.
 *================================================================*/

#include "EXTI.h"

/* Function pointer array to store callback functions for each EXTI line */
void (*EXTI_CallBack[NUMBER_OF_EXTI_LINES]) (void);

/* Initialize EXTI for the specified EXTI line with the given trigger mode */
void MCAL_EXTI_Init(uint8 EXTILine, uint8 EXTIMode) {
    switch (EXTIMode) {
        case RISING_EDGE:
            /* Enable rising edge trigger */
            SET_BIT(EXTI->RTSR, EXTILine);
            break;
        case FALLING_EDGE:
            /* Enable falling edge trigger */
            SET_BIT(EXTI->FTSR, EXTILine);
            break;
        case ON_CHANGE:
            /* Enable both rising and falling edge triggers for level changes */
            SET_BIT(EXTI->RTSR, EXTILine);
            SET_BIT(EXTI->FTSR, EXTILine);
            break;
    }
    /* Enable the EXTI interrupt for the selected line */
    SET_BIT(EXTI->IMR, EXTILine);
}

/* Enable EXTI for the specified EXTI line */
void MCAL_EXTI_Enable(uint8 EXTILine) {
    SET_BIT(EXTI->IMR, EXTILine);
}

/* Disable EXTI for the specified EXTI line */
void MCAL_EXTI_Disable(uint8 EXTILine) {
    CLR_BIT(EXTI->IMR, EXTILine);
}

/* Generate a software trigger for the specified EXTI line */
void MCAL_EXTI_SoftWareTrigger(uint8 EXTILine) {
    SET_BIT(EXTI->SWIER, EXTILine);
}

/* Set a callback function for the specified EXTI line */
void MCAL_EXTI_SetCallBack(uint8 EXTILine, void (*ptr)(void)) {
    if (EXTILine < NUMBER_OF_EXTI_LINES) {
        EXTI_CallBack[EXTILine] = ptr;
    }
}

/* EXTI0 interrupt handler */
void EXTI0_IRQHandler(void) {
    if (EXTI_CallBack[EXTI_LINE0] != NULL) {
        /* Call the callback function associated with EXTI_LINE0 */
        EXTI_CallBack[EXTI_LINE0]();
    }
    /* Clear the EXTI interrupt flag for EXTI_LINE0 */
    SET_BIT(EXTI->PR, EXTI_LINE0);
}

/* EXTI1 interrupt handler */
void EXTI1_IRQHandler(void) {
    if (EXTI_CallBack[EXTI_LINE1] != NULL) {
        /* Call the callback function associated with EXTI_LINE1 */
        EXTI_CallBack[EXTI_LINE1]();
    }
    /* Clear the EXTI interrupt flag for EXTI_LINE1 */
    SET_BIT(EXTI->PR, EXTI_LINE1);
}

/* EXTI2 interrupt handler */
void EXTI2_IRQHandler(void) {
    if (EXTI_CallBack[EXTI_LINE2] != NULL) {
        /* Call the callback function associated with EXTI_LINE2 */
        EXTI_CallBack[EXTI_LINE2]();
    }
    /* Clear the EXTI interrupt flag for EXTI_LINE2 */
    SET_BIT(EXTI->PR, EXTI_LINE2);
}

/* EXTI3 interrupt handler */
void EXTI3_IRQHandler(void) {
    if (EXTI_CallBack[EXTI_LINE3] != NULL) {
        /* Call the callback function associated with EXTI_LINE3 */
        EXTI_CallBack[EXTI_LINE3]();
    }
    /* Clear the EXTI interrupt flag for EXTI_LINE3 */
    SET_BIT(EXTI->PR, EXTI_LINE3);
}

/* EXTI4 interrupt handler */
void EXTI4_IRQHandler(void) {
    if (EXTI_CallBack[EXTI_LINE4] != NULL) {
        /* Call the callback function associated with EXTI_LINE4 */
        EXTI_CallBack[EXTI_LINE4]();
    }
    /* Clear the EXTI interrupt flag for EXTI_LINE4 */
    SET_BIT(EXTI->PR, EXTI_LINE4);
}

/* EXTI9_5 interrupt handler */
void EXTI9_5_IRQHandler(void) {
    for (uint8 line = EXTI_LINE5; line <= EXTI_LINE9; line++) {
        if (GET_BIT(EXTI->PR, line) == ENABLE) {
            if (EXTI_CallBack[line] != NULL) {
                /* Call the callback function associated with the EXTI line */
                EXTI_CallBack[line]();
            }
            /* Clear the EXTI interrupt flag for the EXTI line */
            SET_BIT(EXTI->PR, line);
        }
    }
}

/* EXTI15_10 interrupt handler */
void EXTI15_10_IRQHandler(void) {
    for (uint8 line = EXTI_LINE10; line <= EXTI_LINE15; line++) {
        if (GET_BIT(EXTI->PR, line) == ENABLE) {
            if (EXTI_CallBack[line] != NULL) {
                /* Call the callback function associated with the EXTI line */
                EXTI_CallBack[line]();
            }
            /* Clear the EXTI interrupt flag for the EXTI line */
            SET_BIT(EXTI->PR, line);
        }
    }
}
