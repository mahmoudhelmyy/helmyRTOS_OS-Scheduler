/*================================================================
 *	Project Name: helmyOS
 * 	File Name: GPIO.h
 * 	Created on: Sep 10, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 *
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "STM32F103C8T6.h"

#define LOGIC_HIGH    0x01          /* Define the HIGH state as 0x01 */
#define LOGIC_LOW     0x00          /* Define the LOW state as 0x00 */

#define HIGH_PORTL 0x00FF     /* Define a mask for setting the lower 8 bits of a port to HIGH */
#define HIGH_PORTH 0xFF00     /* Define a mask for setting the higher 8 bits of a port to HIGH */

#define PORTA_ID   0
#define PORTB_ID   1
#define PORTC_ID   2

#define PIN0    0x00          /* Define pin 0 as 0x00 */
#define PIN1    0x01          /* Define pin 1 as 0x01 */
#define PIN2    0x02          /* Define pin 2 as 0x02 */
#define PIN3    0x03          /* Define pin 3 as 0x03 */
#define PIN4    0x04          /* Define pin 4 as 0x04 */
#define PIN5    0x05          /* Define pin 5 as 0x05 */
#define PIN6    0x06          /* Define pin 6 as 0x06 */
#define PIN7    0x07          /* Define pin 7 as 0x07 */
#define PIN8    0x08          /* Define pin 8 as 0x08 */
#define PIN9    0x09          /* Define pin 9 as 0x09 */
#define PIN10   0x0A          /* Define pin 10 as 0x0A */
#define PIN11   0x0B          /* Define pin 11 as 0x0B */
#define PIN12   0x0C          /* Define pin 12 as 0x0C */
#define PIN13   0x0D          /* Define pin 13 as 0x0D */
#define PIN14   0x0E          /* Define pin 14 as 0x0E */
#define PIN15   0x0F          /* Define pin 15 as 0x0F */

#define INPUT_ANLOG               0x00          /* Define input mode as analog (0x00) */
#define INPUT_FLOATING            0x04          /* Define input mode as floating (0x04) */
#define INPUT_PULLUP_PULLDOWN     0x08          /* Define input mode as pull-up/pull-down (0x08) */

/*Speed 10*/
#define OUTPUT_SPEED_10MHZ_PP     0x01          /* Define output mode with 10MHz speed in push-pull configuration (0x01) */
#define OUTPUT_SPEED_10MHZ_OD     0x05          /* Define output mode with 10MHz speed in open-drain configuration (0x05) */
#define OUTPUT_SPEED_10MHZ_AFPP   0x09          /* Define alternate function output mode with 10MHz speed in push-pull configuration (0x09) */
#define OUTPUT_SPEED_10MHZ_AFOD   0x0D          /* Define alternate function output mode with 10MHz speed in open-drain configuration (0x0D) */

/*Speed 2*/
#define OUTPUT_SPEED_2MHZ_PP      0x02          /* Define output mode with 2MHz speed in push-pull configuration (0x02) */
#define OUTPUT_SPEED_2MHZ_OD      0x06          /* Define output mode with 2MHz speed in open-drain configuration (0x06) */
#define OUTPUT_SPEED_2MHZ_AFPP    0x0A          /* Define alternate function output mode with 2MHz speed in push-pull configuration (0x0A) */
#define OUTPUT_SPEED_2MHZ_AFOD    0x0E          /* Define alternate function output mode with 2MHz speed in open-drain configuration (0x0E) */

/*Speed 50*/
#define OUTPUT_SPEED_50MHZ_PP     0x03          /* Define output mode with 50MHz speed in push-pull configuration (0x03) */
#define OUTPUT_SPEED_50MHZ_OD     0x07          /* Define output mode with 50MHz speed in open-drain configuration (0x07) */
#define OUTPUT_SPEED_50MHZ_AFPP   0x0B          /* Define alternate function output mode with 50MHz speed in push-pull configuration (0x0B) */
#define OUTPUT_SPEED_50MHZ_AFOD   0x0F          /* Define alternate function output mode with 50MHz speed in open-drain configuration (0x0F) */



/**
 * @brief Configure the direction and mode of a specific GPIO pin.
 *
 * This function configures the direction (input or output) and mode of a specified GPIO pin
 * in a given GPIO port.
 *
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pin is located.
 * @param pin: The pin number (0 to 15) to configure.
 * @param mode: The desired mode for the pin (e.g., GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP).
 * @note For STM32F103C6, the MCU has GPIO A, B, and part of C/D exported as external pins.
 * @retval None
 */
void MCAL_GPIO_setupPinDirection(uint8 port, uint8 pin, uint8 mode);

/**
 * @brief Write a digital value to a specific GPIO pin.
 *
 * This function sets or clears a specified GPIO pin in a given GPIO port to a digital value.
 *
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pin is located.
 * @param pin: The pin number (0 to 15) to write to.
 * @param value: The digital value to write (HIGH or LOW).
 * @retval None
 */
void MCAL_GPIO_WritePin(uint8 port, uint8 pin, uint8 value);

/**
 * @brief Read the digital value of a specific GPIO pin.
 *
 * This function reads the digital value of a specified GPIO pin in a given GPIO port.
 *
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pin is located.
 * @param pin: The pin number (0 to 15) to read from.
 * @retval The digital value of the specified pin (HIGH or LOW).
 */
uint8 MCAL_GPIO_ReadPin(uint8 port, uint8 pin);

/**
 * @brief Configure the direction (input or output) of a group of GPIO pins in a specific port.
 *
 * This function configures the direction (input or output) of a group of GPIO pins in a specified
 * GPIO port. It allows configuring both the low and high 8 bits of the port separately.
 *
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pins are located.
 * @param position: The position (LOW or HIGH) of the pins in the port (e.g., low or high 8 bits).
 * @param mode: The mode (GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP, GPIO_MODE_OUTPUT_OD, etc.) to set for the pins.
 */
void MCAL_GPIO_SetupPortDirection(uint8 port, uint8 position, uint8 mode);

/**
 * @brief Write a 16-bit value to a group of GPIO pins in a specific port.
 *
 * This function writes a 16-bit value to a group of GPIO pins in a specified GPIO port.
 * It allows writing to both the low and high 8 bits of the port separately.
 *
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pins are located.
 * @param position: The position (LOW or HIGH) of the pins in the port (e.g., low or high 8 bits).
 * @param value: The 16-bit value to write to the pins.
 */
void MCAL_GPIO_WritePort(uint8 port, uint8 position, uint16 value);

/**
 * @brief Read the input value of a group of GPIO pins in a specific port.
 *
 * This function reads the input value of a group of GPIO pins in a specified GPIO port.
 * It allows reading both the low and high 8 bits of the port separately.
 *
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pins are located.
 * @param position: The position (LOW or HIGH) of the pins in the port (e.g., low or high 8 bits).
 * @return The 16-bit input value of the specified pins in the port.
 */
uint16 MCAL_GPIO_ReadPort(uint8 port, uint8 position);


void MCAL_GPIO_TogglePin(uint8 Port, uint8 Pin);

#endif /* GPIO_H_ */
