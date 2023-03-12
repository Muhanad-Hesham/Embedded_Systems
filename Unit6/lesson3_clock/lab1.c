/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
//register address

#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIO_CRH     *(volatile uint32_t *) (PORTA_BASE + 0x04)
#define GPIO_ODR 	 *(volatile uint32_t *) (PORTA_BASE + 0x0C)
/*

#define RCC_CFGR     *(volatile uint32_t *) (RCC_BASE + 0x04)
#define RCC_CR		 *(volatile uint32_t *) (RCC_BASE)
*/
typedef union {

	vuint32_t  all_fields;
	struct{
		vuint32_t reserved:13;
		vuint32_t p_13:1;
	}pin;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0C);

int main(void)
{
	/*RCC_CFGR |= 0b10<<0; //PLL selector clock source

	RCC_CFGR |= (0b101<<11); //APB1 prescaler
	RCC_CFGR |= (0b100<<8); //APB2 prescaler

	RCC_CFGR |= 0b0110<<18; //PLL MUX prescaler

	RCC_CR |= (1<<24); //PLL ENABLE*/

	RCC_APB2ENR |= 1<<2; //set bit2 (only bit 2)
	GPIO_CRH &= 0xff0fffff; //clear bits from 20 to 24
	GPIO_CRH |= 0x00200000; // put value 2 (0010) to bits from 20 to 24
	while(1)
	{
		//GPIO_ODR |= 1<<13; //set bit 13
		R_ODR->pin.p_13=1;
		for(int i=0;i<5000;i++); //delay
		//GPIO_ODR &= ~1<<13; //clear bit 13
		R_ODR->pin.p_13=0;
		for(int i=0;i<5000;i++); // delay
	}


	return 0;
}
