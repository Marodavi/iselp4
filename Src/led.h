/*
 * led.h
 *
 *  Created on: 6 de jun. de 2017
 *      Author: Mario
 */

#ifndef LED_H_
#define LED_H_
#include "stm32f0xx_hal.h"
TIM_HandleTypeDef htim3;
void vLedCode(void * pvParameters);
void vLed(void) ;
#endif /* LED_H_ */
