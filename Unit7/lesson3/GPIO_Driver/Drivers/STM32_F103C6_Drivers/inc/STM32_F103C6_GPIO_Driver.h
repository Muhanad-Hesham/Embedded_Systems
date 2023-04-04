/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Muhand
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//Includes
#include "stm32f103x6.h"

//------------------------------

//Config Structure
typedef struct{
	uint16_t GPIO_PinNumber  ; //Specifies the GPIO pinS to be configured
							  //This parameter must be a value of @ref GPIO_PINS_define
	uint8_t GPIO_MODE        ; //Specifies the operating mode for the selected pins
							  //This parameter can be a value of @ref GPIO_Mode_define
	uint8_t GPIO_Output_Speed; //Specifies the speed for the selected pins
							  //This parameter can be a value of @ref GPIO_Output_Speed_define
}GPIO_PinConfig_t;

//===================================
//Macros Configuration References
//===================================

//@ref GPIO_PIN_state
#define GPIO_PIN_Set			1
#define GPIO_PIN_RESet			0

//@ref GPIO_PinLock_state
#define GPIO_PinLock_Enabled 	1
#define GPIO_PinLock_ERROR 		0

//@ref GPIO_PINS_define
							//Replacing or Alternative for shifting to th pin
#define GPIO_PIN_0			((uint16_t)0x0001) /* Pin 0 Selected */
#define GPIO_PIN_1			((uint16_t)0x0002) /* Pin 1 Selected */
#define GPIO_PIN_2			((uint16_t)0x0004) /* Pin 2 Selected */
#define GPIO_PIN_3			((uint16_t)0x0008) /* Pin 3 Selected */
#define GPIO_PIN_4			((uint16_t)0x0010) /* Pin 4 Selected */
#define GPIO_PIN_5			((uint16_t)0x0020) /* Pin 5 Selected */
#define GPIO_PIN_6			((uint16_t)0x0040) /* Pin 6 Selected */
#define GPIO_PIN_7			((uint16_t)0x0080) /* Pin 7 Selected */
#define GPIO_PIN_8			((uint16_t)0x0100) /* Pin 8 Selected */
#define GPIO_PIN_9			((uint16_t)0x0200) /* Pin 9 Selected */
#define GPIO_PIN_10			((uint16_t)0x0400) /* Pin 10 Selected */
#define GPIO_PIN_11			((uint16_t)0x0800) /* Pin 11 Selected */
#define GPIO_PIN_12			((uint16_t)0x1000) /* Pin 12 Selected */
#define GPIO_PIN_13			((uint16_t)0x2000) /* Pin 13 Selected */
#define GPIO_PIN_14			((uint16_t)0x4000) /* Pin 14 Selected */
#define GPIO_PIN_15			((uint16_t)0x8000) /* Pin 15 Selected */
#define GPIO_PIN_All		((uint16_t)0xFFFF) /* All Pins Selected */

#define GPIO_PIN_MASK		0x0000FFFFUL /*PIN mask fo assert test*/

//@ref GPIO_Mode_define

/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input*/

#define GPIO_Mode_Analog			0x00000000u //Analog mode
#define GPIO_Mode_Input_Flo			0x00000001u //Floating input mode
#define GPIO_Mode_Input_PU			0x00000002u //Input with pull-up mode
#define GPIO_Mode_Input_PD			0x00000003u //Input with pull-down mode
#define GPIO_Mode_Output_PP			0x00000004u //General purpose output push-pull mode
#define GPIO_Mode_Output_OD			0x00000005u //General purpose output Open-drain mode
#define GPIO_Mode_Output_AF_PP		0x00000006u //Alternate function output Push-pull mode
#define GPIO_Mode_Output_AF_OD		0x00000007u //Alternate function output Open-drain mode
#define GPIO_Mode_Input_AF			0x00000008u //Alternate function input mode

//@ref GPIO_Output_Speed_define

/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz*/

#define Output_Speed_10M			0x00000001u //Output mode, max speed 10 MHz
#define Output_Speed_2M				0x00000002u //Output mode, max speed 2 MHz
#define Output_Speed_50M			0x00000003u //Output mode, max speed 50 MHz

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeINIT(GPIO_Typedef* GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef* GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPORT(GPIO_Typedef* GPIOx);
void MCAL_GPIO_WritePin(GPIO_Typedef* GPIOx, uint16_t PinNumber, uint8_t value);
void MCAL_GPIO_WritePORT(GPIO_Typedef* GPIOx, uint16_t value);
void MCAL_GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_Typedef* GPIOx, uint16_t PinNumber);


#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
