/*================================================================
 *	Project Name: helmyOS
 * 	File Name: RCC_Cfg.h
 * 	Created on: Sep 10, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 *
 */

#ifndef RCC_RCC_CFG_H_
#define RCC_RCC_CFG_H_

#define CLOCK_TYPE       HSE
#define PLL_SOURCE       PLL_HSE_DIVIDED_BY_2

/*ClockFactor For PLL  Maybe :
0-NO_CLOCK_FACTOR
1-PLL_Clock_MULTIPLE_BY_2
2-PLL_Clock_MULTIPLE_BY_3
3-PLL_Clock_MULTIPLE_BY_4
4-PLL_Clock_MULTIPLE_BY_5
5-PLL_Clock_MULTIPLE_BY_6
6-PLL_Clock_MULTIPLE_BY_7
7-PLL_Clock_MULTIPLE_BY_8
8-PLL_Clock_MULTIPLE_BY_9
9-PLL_Clock_MULTIPLE_BY_10
10-PLL_Clock_MULTIPLE_BY_11
11-PLL_Clock_MULTIPLE_BY_12
12-PLL_Clock_MULTIPLE_BY_13
13-PLL_Clock_MULTIPLE_BY_14
14-PLL_Clock_MULTIPLE_BY_15
15-PLL_Clock_MULTIPLE_BY_16  */

#define CLOCK_FACTOR     PLL_CLOCK_MULTIPLE_BY_16
#define CLOCK_SECURITY_SYSTEM     DISABLE_CLOCK_SECURITY_SYSTEM

#endif /* RCC_RCC_CFG_H_ */
