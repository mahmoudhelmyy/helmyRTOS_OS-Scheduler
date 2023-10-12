/*========================================================================================================================
 *	Project Name: helmyOS
 * 	File Name: STM32F103C8T6.h
 * 	Created on: Sep 9, 2023
 * 	Author: HELMY-PC
   _____   _______   __  __   ____    ___    ______   __    ___    ____     _____    ___    _______     __        _
  / ____| |__   __| |  \/  | |___ \  |__ \  |  ____| /_ |  / _ \  |___ \   / ____|  / _ \  |__   __|   / /       | |
 | (___      | |    | \  / |   __) |    ) | | |__     | | | | | |   __) | | |      | (_) |    | |     / /_       | |__
  \___ \     | |    | |\/| |  |__ <    / /  |  __|    | | | | | |  |__ <  | |       > _ <     | |    | '_ \      | '_ \
  ____) |    | |    | |  | |  ___) |  / /_  | |       | | | |_| |  ___) | | |____  | (_) |    | |    | (_) |  _  | | | |
 |_____/     |_|    |_|  |_| |____/  |____| |_|       |_|  \___/  |____/   \_____|  \___/     |_|     \___/  (_) |_| |_|
========================================================================================================================
 */
/*================ APB2 Peripherals ===================|
/* 0x4001 5800 - 0x4001 7FFF   |   Reserved            |
 * 0x4001 5400 - 0x4001 57FF   |  TIM11 timer          |
 * 0x4001 5000 - 0x4001 53FF   |  TIM10 timer          |
 * 0x4001 4C00 - 0x4001 4FFF   |   TIM9 timer          |
 * 0x4001 4000 - 0x4001 4BFF   |    Reserved           |
 * 0x4001 3C00 - 0x4001 3FFF   |      ADC3             |
 * 0x4001 3800 - 0x4001 3BFF   |     USART1            |
 * 0x4001 3400 - 0x4001 37FF   |   TIM8 timer          |
 * 0x4001 3000 - 0x4001 33FF   |      SPI1             |
 * 0x4001 2C00 - 0x4001 2FFF   |   TIM1 timer          |
 * 0x4001 2800 - 0x4001 2BFF   |      ADC2             |
 * 0x4001 2400 - 0x4001 27FF   |      ADC1             |
 * 0x4001 2000 - 0x4001 23FF   |   GPIO Port G         |
 * 0x4001 1C00 - 0x4001 1FFF   |   GPIO Port F         |
 * 0x4001 1800 - 0x4001 1BFF   |   GPIO Port E         |
 * 0x4001 1400 - 0x4001 17FF   |   GPIO Port D         |
 * =====================================================
 * 0x4001 1000 - 0x4001 13FF   |   GPIO Port C         |<< C13 - C14 - C15
 * 0x4001 0C00 - 0x4001 0FFF   |   GPIO Port B         |<< B0 => B15
 * 0x4001 0800 - 0x4001 0BFF   |   GPIO Port A         |<< A0 => A15
 * =====================================================
 * 0x4001 0400 - 0x4001 07FF   |      EXTI             |
 * 0x4001 0000 - 0x4001 03FF   |      AFIO             |
 * ====================================================*/
/*============ AHB Peripherals ==========================
 * Boundary address            |   Peripheral          |
 *======================================================
 * 0xA000 0000 - 0xA000 0FFF   |       FSMC            |
 * 0x5000 0000 - 0x5003 FFFF   |    USB OTG FS         |
 * 0x4003 0000 - 0x4FFF FFFF   |     Reserved          |
 * 0x4002 8000 - 0x4002 9FFF   |     Ethernet          |
 * 0x4002 3400 - 0x4002 7FFF   |      Reserved         |
 * 0x4002 3000 - 0x4002 33FF   |        CRC            |
 * 0x4002 2000 - 0x4002 23FF   |Flash memory interface |
 * 0x4002 1400 - 0x4002 1FFF   |     Reserved          |
 * 0x4002 1000 - 0x4002 13FF   |       RCC             |<<<
 * 0x4002 0800 - 0x4002 0FFF   |    Reserved           |
 * 0x4002 0400 - 0x4002 07FF   |      DMA2             |
 * 0x4002 0000 - 0x4002 03FF   |      DMA1             |
 * 0x4001 8400 - 0x4001 FFFF   |    Reserved           |
 * 0x4001 8000 - 0x4001 83FF   |      SDIO             |
 *======================================================
 */

#ifndef STM32F103C8T6_H_
#define STM32F103C8T6_H_

/*===========================================================================================================*/
/* 											FILE GUARD
/*===========================================================================================================*/
#include "Std_Types.h"
#include "Macros.h"

/* Define the base address of the Flash memory
 * Flash memory is where the program code is stored.
 */
#define FLASH_MEMORY_BASE        (0x08000000)UL

/* Define the base address of the system memory
 * The system memory is a special region of memory that can be used for bootloader code
 * The or system configuration data.
 */
#define SYSTEM_MEMORY_BASE       (0x1FFFF000)UL

/* Define the base address of the SRAM
 * SRAM is used for storing data and variables that can be read from and written to during program execution.
 */
#define SRAM_BASE                (0x20000000)UL


#define PERIPHERALS_BASE 					0x40000000UL
#define CORE_PERIPHERALS_BASE               0xE0000000UL

/*===========================================================================================================*/
/*                                    RCC (Reset and Clock Control)
/*===========================================================================================================*/
/* Register boundary address for RCC */
#define RCC_BASE              ((volatile uint32*)(PERIPHERALS_BASE + 0x00021000UL))
/* Structure to represent RCC (Reset and Clock Control) */
typedef struct
{
    volatile uint32 CR;      /* Clock Control Register (CR) */
    volatile uint32 CFGR; 	 /* Clock Configuration Register (CFGR) */
    volatile uint32 CIR;  	 /* Clock Interrupt Register (CIR) */
    volatile uint32 APB2RSTR;/* APB2 Peripheral Reset Register (APB2RSTR) */
    volatile uint32 APB1RSTR;/* APB1 Peripheral Reset Register (APB1RSTR) */
    volatile uint32 AHBENR;  /* AHB Peripheral Clock Enable Register (AHBENR) */
    volatile uint32 APB2ENR; /* APB2 Peripheral Clock Enable Register (APB2ENR) */
    volatile uint32 APB1ENR; /* APB1 Peripheral Clock Enable Register (APB1ENR) */
    volatile uint32 BDCR;    /* Backup Domain Control Register (BDCR) */
    volatile uint32 CSR;     /* Clock Control & Status Register (CSR) */
    volatile uint32 AHBSTR;  /* AHB Peripheral Clock Reset Register (AHBSTR) */
    volatile uint32 CFGR2;   /* Clock Configuration Register 2 (CFGR2) */
}RCC_TypeDef;
/* Create a pointer to the RCC structure. */
#define RCC                 ((RCC_TypeDef *)RCC_BASE)

/*===========================================================================================================*/
/*                                    			 GPIO
/*===========================================================================================================*/
/* Define the base addresses for GPIO ports A, B, and C. */
#define GPIOA_BASE            ((volatile uint32*)(PERIPHERALS_BASE + 0x00010800UL))
#define GPIOB_BASE            ((volatile uint32*)(PERIPHERALS_BASE + 0x00010C00UL))
#define GPIOC_BASE            ((volatile uint32*)(PERIPHERALS_BASE + 0x00011000UL))

/* Structure to represent a GPIO port */
typedef struct
{
    volatile uint32 CRL;  /* Configuration Register Low */
    volatile uint32 CRH;  /* Configuration Register High */
    volatile uint32 IDR;  /* Input Data Register */
    volatile uint32 ODR;  /* Output Data Register */
    volatile uint32 BSRR; /* Bit Set/Reset Register */
    volatile uint32 BRR;  /* Bit Reset Register */
    volatile uint32 LCKR; /* Lock Register */
} GPIO_TypeDef;

/* Create pointers to GPIO port structures for each port. */
#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
/*===========================================================================================================*/
/*                                        External Interrupt                                  */
/*===========================================================================================================*/
typedef struct{

	volatile uint32 IMR; /*Interrupt mask register (EXTI_IMR)*/
	volatile uint32 EMR; /*Event mask register (EXTI_EMR)*/
	volatile uint32 RTSR;/*Rising trigger selection register (EXTI_RTSR)*/
	volatile uint32 FTSR;/*Falling trigger selection register (EXTI_FTSR)*/
	volatile uint32 SWIER;/*Software interrupt event register (EXTI_SWIER)*/
	volatile uint32 PR; /*Pending register (EXTI_PR)*/

}EXTI_Type;
#define EXTI_BASE  ((volatile uint32*)(PERIPHERALS_BASE + 0x00010400UL))
#define EXTI ((EXTI_Type *) EXTI_BASE)

/*===========================================================================================================*/
/*                                        SYSTICK - System Timer Controller                                  */
/*===========================================================================================================*/

/**
 * @struct SYSTICK
 * @brief  Structure representing the System Timer Controller (SYSTICK) registers.
 *
 * The System Timer Controller (SYSTICK) is a system timer in ARM Cortex-M microcontrollers.
 * It is used for various timekeeping and timing-related tasks.
 * This structure provides access to the SYSTICK registers for configuration and control.
 */
typedef struct {
    volatile uint32 CTRL;  /**< Control and Status Register: Used to configure and control the SYSTICK timer. */
    volatile uint32 LOAD;  /**< Reload Value Register: Used to set the value at which the timer reloads. */
    volatile uint32 VAL;   /**< Current Value Register: Contains the current value of the timer. */
    volatile uint32 CALIB; /**< Calibration Value Register: Contains information about the timer's calibration. */
} SYSTICK;
#define SYSTICK_BASE  ((volatile uint32*)(CORE_PERIPHERALS_BASE+ 0x0000E010))

/** Base address of the SYSTICK peripheral. */
#define STK ((SYSTICK*)SYSTICK_BASE)








#endif /* STM32F103C8T6_H_ */
