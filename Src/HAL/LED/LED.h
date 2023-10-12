/*================================================================
 *	Project Name: helmyOS
 * 	File Name: LED.h
 * 	Created on: Sep 12, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 *
 */
#ifndef LED_H_
#define LED_H_
#include "../../MCAL/GPIO/GPIO.h"

#define LED_PORT    PORTC_ID
#define RED_PORT    PORTA_ID

#define LED_GREEN    PIN15
#define LED_BLUE     PIN14
#define LED_YELLOW   PIN13

#define LED_RED1     PIN2
#define LED_RED2     PIN1

/**
 * @brief Initialize all LEDs by configuring their GPIO pins.
 */
void LEDs_Init(void);

/**
 * @brief Turn on a specific LED by color.
 *
 * @param ledColor The color of the LED to turn on (e.g., LED_BLUE, LED_GREEN, etc.).
 */
void LED_On(uint8 ledColor);

/**
 * @brief Turn off a specific LED by color.
 *
 * @param ledColor The color of the LED to turn off (e.g., LED_BLUE, LED_GREEN, etc.).
 */
void LED_Off(uint8 ledColor);

/**
 * @brief Toggle the state of a specific LED by color.
 *
 * @param ledColor The color of the LED to toggle (e.g., LED_BLUE, LED_GREEN, etc.).
 */
void LED_Toggle(uint8 ledColor);



#endif /* LED_H_ */
