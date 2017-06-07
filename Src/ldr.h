/*
 * ldr.h
 *
 *  Created on: 6 de jun. de 2017
 *      Author: Mario
 */

#ifndef LDR_H_
#define LDR_H_
#include "stm32f0xx_hal.h"
ADC_HandleTypeDef hadc;

void vLdrCode(void * pvParameters);
void vLdr(void) ;

#endif /* LDR_H_ */
