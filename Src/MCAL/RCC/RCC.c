/*================================================================
 *	Project Name: helmyOS
 * 	File Name: RCC.c
 * 	Created on: Sep 9, 2023
 * 	Author: HELMY-PC
 * 	============================================================
			 _____     _____    _____
			|  __ \   / ____|  / ____|
			| |__) | | |      | |            ___
			|  _  /  | |      | |           / __|
			| | \ \  | |____  | |____   _  | (__
			|_|  \_\  \_____|  \_____| (_)  \___|
=================================================================
 *
 */


#include "RCC.h"
#include "RCC_Cfg.h"

void MCAL_RCC_Init(void){

	uint32 TimeOut = 0;

	#if   CLOCK_TYPE == HSI

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSI Selected As A System Clock */
		CLEAR_BIT( RCC->CFGR , 0  );
		CLEAR_BIT( RCC->CFGR , 1  );
		/* Bit 0 -> Enable The HSI Clock */
		SET_BIT( RCC->CR   , 0  );
		/* Bit 1 -> Checking While The HSI Clock Is Stable */
		while( ( ( GET_BIT( RCC->CR , 1 ) ) == 0 ) && ( TimeOut < 100000 ) ){ TimeOut++; }
		if( TimeOut >= 100000 ){ /*TimeOut*/ }

	#elif CLOCK_TYPE == HSE

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		SET_BIT( RCC->CFGR , 0  );
		CLEAR_BIT( RCC->CFGR , 1  );
		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT( RCC->CR   , 16 );
		/* Bit 17 -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( RCC->CR , 17 ) ) == 0 ) && ( TimeOut < 100000 ) ){ TimeOut++; }
		if( TimeOut >= 100000 ){ /*TimeOut*/ }

	#elif CLOCK_TYPE == PLL

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* PLL Selected As A System Clock */
		CLEAR_BIT( RCC->CFGR , 0  );
		SET_BIT( RCC->CFGR , 1  );

		/*The Start Of Nested #IF*/
		/* Choosing The Multiplication Factor For PLL */
		#if ( CLOCK_FACTOR >= NO_CLOCK_FACTOR ) && ( CLOCK_FACTOR <= PLL_CLOCK_MULTIPLE_BY_16)

		RCC->CFGR &= ~( ( 0b1111 )     << 18 ) ;
		RCC->CFGR |=  ( CLOCK_FACTOR ) << 18   ;

		#elif ( CLOCK_FACTOR > PLL_CLOCK_MULTIPLE_BY_16 ) || ( CLOCK_FACTOR < NO_CLOCK_FACTOR )
			#warning "Wrong Multiplication Factor"
		/*The End OF Nested #IF */
		#endif

		/*The Start Of Nested #IF*/
		#if PLL_SOURCE == PLL_HSI_DIVIDED_BY_2

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSI Divided By 2 */
			CLEAR_BIT( RCC->CFGR , 16 );

		#elif PLL_SOURCE == PLL_HSE

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( RCC->CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( RCC->CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Not Divided */
			CLEAR_BIT( RCC->CFGR , 17 );

		#elif PLL_SOURCE == PLL_HSE_DIVIDED_BY_2

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( RCC->CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( RCC->CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Divided By Two */
			SET_BIT( RCC->CFGR , 17 );

			/*The End Of Nested IF*/
		#endif

		/* PLL Clock Enable */
		SET_BIT( RCC->CR , 24 );

		/* Wait Until PLL Ready Flag Set */
		while( ( ( GET_BIT( RCC->CR , 25 ) ) == 0 ) && ( TimeOut < 100000 ) ){ TimeOut++; }
		if( TimeOut >= 100000 ){ /*TimeOut*/ }

	#elif CLOCK_TYPE == HSE_BYPASS

		/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
		/* HSE Clock Disabled */
		CLEAR_BIT( RCC->CR   , 16 );

		/* BIT 18 -> To Select HSE BYPASS */
		/* HSEBYPASS Clock Enable */
		SET_BIT( RCC->CR , 18 );

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		SET_BIT( RCC->CFGR , 0  );
		CLEAR_BIT( RCC->CFGR , 1  );

		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT( RCC->CR   , 16 );

		/* Bit 17 -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( RCC->CR , 17 ) ) == 0 ) && ( TimeOut < 100000 ) ){ TimeOut++; }
		if( TimeOut >= 100000 ){ /*TimeOut*/ }

	#else

		#error " Wrong Clock System Type Configuration"

	/* The Close Of Big If */
	#endif

	/* For Clock Security System */
	#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM

		SET_BIT( RCC->CR , 19 );

	#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM

		CLEAR_BIT( RCC->CR , 19 );

	#else

		#warning " Wrong Clock Security System Configuration Choice "

	#endif

}

void MCAL_RCC_EnablePeripheralClock(uint8 PeripheralBus , uint8 Peripheral ){
		switch(PeripheralBus){

			case AHB_BUS  :
				SET_BIT( RCC->AHBENR  , Peripheral );
				break;
			case APB1_BUS :
				SET_BIT( RCC->APB1ENR , Peripheral );
			    break;
			case APB2_BUS :
				SET_BIT( RCC->APB2ENR , Peripheral );
				break;
		}
}

void MCAL_RCC_DisablePeripheralClock(uint8 PeripheralBus , uint8 Peripheral ){

		switch(PeripheralBus){

			case AHB_BUS  : CLEAR_BIT( RCC->AHBENR  , Peripheral ); break;
			case APB1_BUS :	CLEAR_BIT( RCC->APB1ENR , Peripheral ); break;
			case APB2_BUS : CLEAR_BIT( RCC->APB2ENR , Peripheral ); break;

		}
}

