/*================================================================
 *	Project Name: helmyOS
 * 	File Name: LED.c
 * 	Created on: Sep 12, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 *
 */
#include "LED.h"

void LEDs_Init(void) {

    MCAL_GPIO_setupPinDirection(LED_PORT, LED_BLUE, OUTPUT_SPEED_2MHZ_PP);
    MCAL_GPIO_setupPinDirection(LED_PORT, LED_GREEN, OUTPUT_SPEED_2MHZ_PP);
    MCAL_GPIO_setupPinDirection(LED_PORT, LED_YELLOW, OUTPUT_SPEED_2MHZ_PP);
    MCAL_GPIO_setupPinDirection(RED_PORT, LED_RED1, OUTPUT_SPEED_2MHZ_PP);
    MCAL_GPIO_setupPinDirection(RED_PORT, LED_RED2, OUTPUT_SPEED_2MHZ_PP);

    /* Turn off all LEDs initially*/
    LED_Off(LED_BLUE);
    LED_Off(LED_GREEN);
    LED_Off(LED_YELLOW);
    LED_Off(LED_RED1);
    LED_Off(LED_RED2);
}

void LED_On(uint8 ledColor) {
    switch(ledColor) {
        case LED_BLUE:
        case LED_GREEN:
        case LED_YELLOW:
            MCAL_GPIO_WritePin(LED_PORT, ledColor, LOGIC_HIGH);
            break;
        case LED_RED1:
        case LED_RED2:
            MCAL_GPIO_WritePin(RED_PORT, ledColor, LOGIC_HIGH);
            break;
        default:
            break;
    }
}

void LED_Off(uint8 ledColor) {
    switch(ledColor) {
        case LED_BLUE:
        case LED_GREEN:
        case LED_YELLOW:
            MCAL_GPIO_WritePin(LED_PORT, ledColor, LOGIC_LOW);
            break;
        case LED_RED1:
        case LED_RED2:
            MCAL_GPIO_WritePin(RED_PORT, ledColor, LOGIC_LOW);
            break;
        default:
            break;
    }
}

void LED_Toggle(uint8 ledColor) {
    switch(ledColor) {
        case LED_BLUE:
        case LED_GREEN:
        case LED_YELLOW:
            if (MCAL_GPIO_ReadPin(LED_PORT, ledColor) == LOGIC_HIGH) {
                MCAL_GPIO_WritePin(LED_PORT, ledColor, LOGIC_LOW);
            } else {
                MCAL_GPIO_WritePin(LED_PORT, ledColor, LOGIC_HIGH);
            }
            break;
        case LED_RED1:
        case LED_RED2:
            if (MCAL_GPIO_ReadPin(RED_PORT, ledColor) == LOGIC_HIGH) {
                MCAL_GPIO_WritePin(RED_PORT, ledColor, LOGIC_LOW);
            } else {
                MCAL_GPIO_WritePin(RED_PORT, ledColor, LOGIC_HIGH);
            }
            break;
        default:
            break;
    }
}
