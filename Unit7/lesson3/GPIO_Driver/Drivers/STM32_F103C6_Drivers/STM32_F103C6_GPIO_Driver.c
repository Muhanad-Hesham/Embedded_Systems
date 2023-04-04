/*
 * STM32_F103C6_GPIO_Driver.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Muhand
 */

#include "STM32_F103C6_GPIO_Driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}


/**================================================================
 * @Fn				-MCAL_GPIO_INIT
 * @brief 			-Initialize the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinConfig:pointer to the GPIO_PinConfig_t structure that contains config info for specified GPIO PIN
 * @retval 			-none
 * Note				-stm32F103C6 MCU has GPIO A,B,C,D,E Modules but LQFP48 Pckage has only A,B, part of C,D exported as Pins from MCU
 */

void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx, GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) from pin 0>>>7
	//Port configuration register high (GPIOx_CRL) from pin 8>>15
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config = 0;

	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL:&GPIOx->CRH;
	//clear CNF[1:0] MODE[1:0]
	(*configregister) &= ~(0xf<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if pin is output
	if((PinConfig->GPIO_MODE == GPIO_Mode_Output_PP) || (PinConfig->GPIO_MODE == GPIO_Mode_Output_OD) || (PinConfig->GPIO_MODE == GPIO_Mode_Output_AF_PP) || (PinConfig->GPIO_MODE == GPIO_Mode_Output_AF_OD))
	{
		//set CNF[1:0] MODE[1:0]
		PIN_Config = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f );
		//(*configregister) |= ((PIN_Config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	}
	//if pin is input
	else
	{
		//00: Input mode (reset state)
		if((PinConfig->GPIO_MODE == GPIO_Mode_Analog )||(PinConfig->GPIO_MODE == GPIO_Mode_Input_Flo))
		{
			//set CNF[1:0] MODE[1:0]00
			PIN_Config = (((PinConfig->GPIO_MODE) << 2) & 0x0f);
			//(*configregister) |= ((PIN_Config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		}
		else if((PinConfig->GPIO_MODE == GPIO_Mode_Input_PU )||(PinConfig->GPIO_MODE == GPIO_Mode_Input_PD))
		{
			PIN_Config = (((GPIO_Mode_Input_PU) << 2) & 0x0f);
			//(*configregister) |= ((PIN_Config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));
			if(PinConfig->GPIO_MODE == GPIO_Mode_Input_PU)
			{
				//PxODR = 1 Input pull up table 20 port bit configuration table
				GPIOx ->ODR |= PinConfig->GPIO_PinNumber ;
			}
			else
			{
				//PxODR = 0 Input pull down table 20 port bit configuration table
				GPIOx ->ODR &= ~(PinConfig->GPIO_PinNumber) ;
			}


		}
		else //AF input (consider it as input floating)
		{
			//set CNF[1:0] MODE[1:0]00
			PIN_Config = (((GPIO_Mode_Input_Flo) << 2) & 0x0f);
			//(*configregister) |= ((PIN_Config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		}
	}
	//write on CRL or CRH
	(*configregister) |= ((PIN_Config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));

}

/**================================================================
 * @Fn				-MCAL_GPIO_DeINIT
 * @brief 			-reset all the gpio registers
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @retval 			-none
 * Note				-none
 */

void MCAL_GPIO_DeINIT(GPIO_Typedef* GPIOx)
{
	//with no reset controller (reset manually)
	/*GPIOx->CRL =  0x44444444;
	GPIOx->CRH =  0x44444444;
	GPIOx->BRR =  0x00000000;
	GPIOx->BSRR = 0x00000000;
	//GPIOx->IDR = (read only)
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR =  0x00000000;*/

	//or by using reset controller
	//APB2 peripheral reset register (RCC_APB2RSTR)
	//Set and cleared by software

	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2); //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}
	if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3); //Bit 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}
	if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4); //Bit 4 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}
	if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5); //Bit 5 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-read specific pin
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinNumber:set specific pinnumber according to @ref GPIO_PINS_define
 * @retval 			-the input pin value (two values (1/0) based on @ref GPIO_PIN_state)
 * Note				-none
 */

uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef* GPIOx,uint16_t PinNumber)
{
	uint8_t bitstatus;
	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESet)
	{
		bitstatus = GPIO_PIN_Set;
	}
	else
	{
		bitstatus = GPIO_PIN_RESet;
	}
	return bitstatus;
}

/**================================================================
 * @Fn				-MCAL_GPIO_ReadPORT
 * @brief 			-read input port value
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @retval 			-the input port value
 * Note				-none
 */

uint16_t MCAL_GPIO_ReadPORT(GPIO_Typedef* GPIOx)
{
	uint16_t portstatus;
	portstatus = (uint16_t)(GPIOx->IDR);
	return portstatus;
}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-write on specific pin
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinNumber:set specific pinnumber according to @ref GPIO_PINS_define
 * @param [in] 		-value: value will be written on the pin
 * @retval 			-none
 * Note				-none
 */

void MCAL_GPIO_WritePin(GPIO_Typedef* GPIOx,uint16_t PinNumber, uint8_t value)
{
	if(value != GPIO_PIN_RESet)
	{
		//GPIOx->ODR |= PinNumber;
		//or
		/* BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit*/
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		/*Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit*/
		GPIOx->BRR = (uint32_t)PinNumber;
	}

}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePORT
 * @brief 			-write on specific port
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @param [in] 		-value: value will be written on the port
 * @retval 			-none
 * Note				-none
 */

void MCAL_GPIO_WritePORT(GPIO_Typedef* GPIOx, uint16_t value)
{
	GPIOx->ODR = (uint32_t) value;

}

/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-toggle specific pin "the locking mechanism allows the IO config to be frozen"
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinNumber:set specific pinnumber according to @ref GPIO_PINS_define
 * @retval 			-none
 * Note				-none
 */

void MCAL_GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}

/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-lock specific pin
 * @param [in] 		-GPIOx: where x can be (A...D depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinNumber:set specific pinnumber according to @ref GPIO_PINS_define
 * @retval 			-lock succedded or not "ok if pin is locked or error if pin not locked" based on @ref GPIO_PinLock_state
 * Note				-none
 */

uint8_t MCAL_GPIO_LockPin(GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	/*Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
			0: Port configuration lock key not active
			1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
			LOCK key writing sequence:
			Write 1
			Write 0
			Write 1
			Read 0
			Read 1 (this read is optional but confirms that the lock is active)
			Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
			Any error in the lock sequence will abort the lock.
			Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
			These bits are read write but can only be written when the LCKK bit is 0.
			0: Port configuration not locked
			1: Port configuration locked.*/
	volatile uint32_t temp = (1<<16); //set LCKK[16]
	//set LCKy
	temp |= PinNumber;
	//Write 1
	GPIOx->LCKR =temp;
	//Write 0
	GPIOx->LCKR =PinNumber;
	//Write 1
	GPIOx->LCKR =temp;
	//Read 0
	temp = GPIOx->LCKR;
	//Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_PinLock_Enabled;
	}
	else
	{
		return GPIO_PinLock_ERROR;
	}
}
