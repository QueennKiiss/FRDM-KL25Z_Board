/*
 * app_GPIO.c
 *
 *  Created on: 19 oct. 2020
 *      Author: applemac
 */

#include "stdio.h"
#include "MKL25Z4.h"
#include "app_GPIO.h"
#include "stdtypedef.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

void app_GPIO_Init(void){

	//Habilitar los relojes de los módulos
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortB);

	//Configurar la funcionalidad del Pin
	port_pin_config_t ls_PinConfig;
	ls_PinConfig.mux = 0b001U;						//0b indica que el num es binario, 0x para hex
	PORT_SetPinConfig(PORTC, 9U, &ls_PinConfig); 	//Salida digital
	PORT_SetPinConfig(PORTB, 19U, &ls_PinConfig);	// LED

	//Indicar al modulo GPIO qué ha de hacer
	gpio_pin_config_t ls_GPIOConfig;
	ls_GPIOConfig.pinDirection = kGPIO_DigitalInput; //kGPIO_DigitalInput es un 0
	ls_GPIOConfig.outputLogic = FALSE;

	GPIO_PinInit(GPIOC, 9U, &ls_GPIOConfig);

	ls_GPIOConfig.pinDirection = kGPIO_DigitalOutput;
	ls_GPIOConfig.outputLogic = TRUE;

	GPIO_PinInit(GPIOB, 19U, &ls_GPIOConfig);
}

//Funcion para saber el estado del puerto
T_UBYTE app_GPIO_GetPinValue(GPIO_Type *lps_BaseAddress, T_UBYTE lub_PinNumber){

	T_UBYTE lub_PinValue;

	lub_PinValue = (T_UBYTE)GPIO_ReadPinInput(lps_BaseAddress, lub_PinNumber);

	if (lub_PinValue == TRUE)
	{
		printf("True");
		GPIO_ClearPinsOutput(GPIOB, 1U << 19U); // Para limpiar los pines
	}
	else
	{
		printf("False");
		GPIO_SetPinsOutput(GPIOB, 1U << 19U); // Para poner a 1 el pin y activar el LED
	}

	return lub_PinValue;
}
