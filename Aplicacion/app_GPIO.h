/*
 * app_GPIO.h
 *
 *  Created on: 19 oct. 2020
 *      Author: applemac
 */

#ifndef APLICACION_APP_GPIO_H_
#define APLICACION_APP_GPIO_H_

#include "stdtypedef.h"

extern void app_GPIO_Init(void);
extern T_UBYTE app_GPIO_GetPinValue(GPIO_Type *lps_BaseAddress, T_UBYTE lub_PinNumber);


#endif /* APLICACION_APP_GPIO_H_ */
