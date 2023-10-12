/*================================================================
 *	Project Name: helmyOS
 * 	File Name: GPIO.c
 * 	Created on: Sep 10, 2023
 * 	Author: HELMY-PC
 *
   _____   _____    _____    ____
  / ____| |  __ \  |_   _|  / __ \
 | |  __  | |__) |   | |   | |  | |       ___
 | | |_ | |  ___/    | |   | |  | |      / __|
 | |__| | | |       _| |_  | |__| |  _  | (__
  \_____| |_|      |_____|  \____/  (_)  \___|


 */

#include "GPIO.h"
/**
 * @brief Configure the direction and mode of a specific GPIO pin.
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pin is located.
 * @param pin: The pin number (0 to 15) to configure.
 * @param mode: The desired mode for the pin (e.g., GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP).
 * @note For STM32F103C6, the MCU has GPIO A, B, and part of C/D exported as external pins.
 * @retval None
 */
void MCAL_GPIO_setupPinDirection(uint8 port, uint8 pin, uint8 mode) {
    switch (port) {
        case PORTA_ID:
            if (pin <= 7) { /* Low pins (0-7) */
                GPIOA->CRL &= ~(0b1111 << (pin * 4)); /* Clear the configuration bits */
                GPIOA->CRL |= (mode << (pin * 4));  /* Set the desired mode */
            }
            else if (pin <= 15) { /* High pins (8-15) */
                pin =pin - 8; /* Adjust the pin number */
                GPIOA->CRH &= ~(0b1111 << (pin * 4)); /* Clear the configuration bits */
                GPIOA->CRH |= (mode << (pin * 4));  /* Set the desired mode */
            }
            break;

        case PORTB_ID:
            if (pin <= 7) { /* Low pins (0-7) */
                GPIOB->CRL &= ~(0b1111 << (pin * 4)); /* Clear the configuration bits */
                GPIOB->CRL |= (mode << (pin * 4));  /* Set the desired mode */
            }
            else if (pin <= 15) { /* High pins (8-15) */
                pin -= 8; /* Adjust the pin number */
                GPIOB->CRH &= ~(0b1111 << (pin * 4)); /* Clear the configuration bits */
                GPIOB->CRH |= (mode << (pin * 4));  /* Set the desired mode */
            }
            break;

        case PORTC_ID:
            if (pin <= 7) { /* Low pins (0-7) */
                GPIOC->CRL &= ~(0b1111 << (pin * 4)); /* Clear the configuration bits */
                GPIOC->CRL |= (mode << (pin * 4));  /* Set the desired mode */
            }
            else if (pin <= 15) { /* High pins (8-15) */
                pin -= 8; /* Adjust the pin number */
                GPIOC->CRH &= ~(0b1111 << (pin * 4)); /* Clear the configuration bits */
                GPIOC->CRH |= (mode << (pin * 4));  /* Set the desired mode */
            }
            break;

        default:
            break;
    }
}


/**
 * @brief Write a digital value to a specific GPIO pin.
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pin is located.
 * @param pin: The pin number (0 to 15) to write to.
 * @param value: The digital value to write (HIGH or LOW).
 * @retval None
 */
void MCAL_GPIO_WritePin(uint8 port, uint8 pin, uint8 value) {
    switch (port) {
        case PORTA_ID:
            if (value == LOGIC_HIGH) {
                SET_BIT(GPIOA->ODR, pin); /* Set the pin to HIGH */
            } else if (value == LOGIC_LOW) {
                CLEAR_BIT(GPIOA->ODR, pin); /* Clear the pin to LOW */
            }
            break;

        case PORTB_ID:
            if (value == LOGIC_HIGH) {
                SET_BIT(GPIOB->ODR, pin); /* Set the pin to HIGH */
            } else if (value == LOGIC_LOW) {
                CLEAR_BIT(GPIOB->ODR, pin); /* Clear the pin to LOW */
            }
            break;

        case PORTC_ID:
            if (value == LOGIC_HIGH) {
                SET_BIT(GPIOC->ODR, pin); /* Set the pin to HIGH */
            } else if (value == LOGIC_LOW) {
            	CLEAR_BIT(GPIOC->ODR, pin); /* Clear the pin to LOW */
            }
            break;

        default:
            break;
    }
}


/**
 * @brief Read the digital value of a specific GPIO pin.
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pin is located.
 * @param pin: The pin number (0 to 15) to read from.
 * @retval The digital value of the specified pin (HIGH or LOW).
 */
uint8 MCAL_GPIO_ReadPin(uint8 port, uint8 pin) {
    uint8 result = 0;

    switch (port) {
        case PORTA_ID:
            result = GET_BIT(GPIOA->IDR, pin); /* Read the pin value from GPIOA */
            break;

        case PORTB_ID:
            result = GET_BIT(GPIOB->IDR, pin); /* Read the pin value from GPIOB */
            break;

        case PORTC_ID:
            result = GET_BIT(GPIOC->IDR, pin); /* Read the pin value from GPIOC */
            break;

        default:
            break;
    }
    return result;
}

/**
 * @brief Configure the direction (input or output) of a group of GPIO pins in a specific port.
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pins are located.
 * @param position: The position (LOW or HIGH) of the pins in the port (e.g., low or high 8 bits).
 * @param mode: The mode (GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP, GPIO_MODE_OUTPUT_OD, etc.) to set for the pins.
 */
void MCAL_GPIO_SetupPortDirection(uint8 port, uint8 position, uint8 mode) {

    switch (port) {
        case PORTA_ID:
            if (position == LOGIC_LOW) {
                GPIOA->CRL = (0xFF * mode); /* Configure low 8 bits of GPIOA */
            } else if (position == LOGIC_HIGH) {
                GPIOA->CRH = (0xFF * mode); /* Configure high 8 bits of GPIOA */
            }
            break;
        case PORTB_ID:
            if (position == LOGIC_LOW) {
                GPIOB->CRL = (0xFF * mode); /* Configure low 8 bits of GPIOB */
            } else if (position == LOGIC_HIGH) {
                GPIOB->CRH = (0xFF * mode); /* Configure high 8 bits of GPIOB */
            }
            break;

        case PORTC_ID:
            if (position == LOGIC_LOW) {
                GPIOC->CRL = (0xFF * mode); /* Configure low 8 bits of GPIOC */
            } else if (position == LOGIC_HIGH) {
                GPIOC->CRH = (0xFF * mode); /* Configure high 8 bits of GPIOC */
            }
            break;

        default:
            break;
    }
}

/**
 * @brief Write a 16-bit value to a group of GPIO pins in a specific port.
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pins are located.
 * @param position: The position (LOW or HIGH) of the pins in the port (e.g., low or high 8 bits).
 * @param value: The 16-bit value to write to the pins.
 */
void MCAL_GPIO_WritePort(uint8 port, uint8 position, uint16 value) {

    switch (port) {
        case PORTA_ID:
            if (position == LOGIC_LOW) {
                GPIOA->ODR = (GPIOA->ODR & 0xFF00) | ((uint8)value); /* Write value to low 8 bits of GPIOA */
            } else if (position == LOGIC_HIGH) {
                GPIOA->ODR = (GPIOA->ODR & 0x00FF) | value; /* Write value to high 8 bits of GPIOA */
            }
            break;

        case PORTB_ID:
            if (position == LOGIC_LOW) {
                GPIOB->ODR = (GPIOB->ODR & 0xFF00) | ((uint8)value); /* Write value to low 8 bits of GPIOB */
            } else if (position == LOGIC_HIGH) {
                GPIOB->ODR = (GPIOB->ODR & 0x00FF) | value; /* Write value to high 8 bits of GPIOB */
            }
            break;

        case PORTC_ID:
            if (position == LOGIC_LOW) {
                GPIOC->ODR = (GPIOC->ODR & 0xFF00) | ((uint8)value); /* Write value to low 8 bits of GPIOC */
            } else if (position == LOGIC_HIGH) {
                GPIOC->ODR = (GPIOC->ODR & 0x00FF) | value; /* Write value to high 8 bits of GPIOC */
            }
            break;

        default:
            break;
    }
}


/**
 * @brief Read the input value of a group of GPIO pins in a specific port.
 * @param port: The GPIO port (e.g., GPIOA, GPIOB, GPIOC) where the pins are located.
 * @param position: The position (LOW or HIGH) of the pins in the port (e.g., low or high 8 bits).
 * @return The 16-bit input value of the specified pins in the port.
 */
uint16 MCAL_GPIO_ReadPort(uint8 port, uint8 position) {
    uint16 result = 0;
    switch (port) {
        case PORTA_ID:
            result = GPIOA->IDR;
            if (position == LOGIC_LOW) {
                result &= 0x00FF; /* Mask high 8 bits to zero */
            } else if (position == LOGIC_HIGH) {
                result &= 0xFF00; /* Mask low 8 bits to zero */
            }
            break;

        case PORTB_ID:
            result = GPIOB->IDR;
            if (position == LOGIC_LOW) {
                result &= 0x00FF; /* Mask high 8 bits to zero */
            } else if (position == LOGIC_HIGH) {
                result &= 0xFF00; /* Mask low 8 bits to zero */
            }
            break;

        case PORTC_ID:
            result = GPIOC->IDR;
            if (position == LOGIC_LOW) {
                result &= 0x00FF; /* Mask high 8 bits to zero */
            } else if (position == LOGIC_HIGH) {
                result &= 0xFF00; /* Mask low 8 bits to zero */
            }
            break;

        default:
            break;
    }

    return result;
}

void MCAL_GPIO_TogglePin(uint8 Port, uint8 Pin) {
    switch (Port) {
        case PORTA_ID:
            if (Pin < 16) {
                TOGGLE_BIT(GPIOA->ODR, Pin);
            } else {
                /* Handle invalid pin number for GPIOA */
                /* You can add error handling code here, such as logging or returning an error code. */
            }
            break;

        case PORTB_ID:
            if (Pin < 16) {
                TOGGLE_BIT(GPIOB->ODR, Pin);
            } else {
                /* Handle invalid pin number for GPIOB */
                /* You can add error handling code here, such as logging or returning an error code. */
            }
            break;

        case PORTC_ID:
            if (Pin < 16) {
                TOGGLE_BIT(GPIOC->ODR, Pin);
            } else {
                /* Handle invalid pin number for GPIOC */
                /* You can add error handling code here, such as logging or returning an error code. */
            }
            break;

        default:
            /* Handle invalid GPIO port */
            /* You can add error handling code here, such as logging or returning an error code. */
            break;
    }
}

