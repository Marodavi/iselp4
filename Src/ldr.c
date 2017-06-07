/*
 * ldr.c
 *
 *  Created on: 6 de jun. de 2017
 *      Author: Mario
 */
#include "ldr.h"
#include "FreeRTOSConfig.h"
#include <projdefs.h>
#include "cmsis_os.h"
#include "stm32f0xx_hal.h"


#define VREFINT_CAL_ADDR ((uint16_t*)((uint32_t) 0x1FFFF7BA))
int adecerrao0,adecerrao1;
 int ADC_raw[2];
 float Vdd;
 unsigned char i=0;
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {

	if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOC)) {
		ADC_raw[i] = HAL_ADC_GetValue(hadc);
		i++;
	}
	if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOS)) { //Interrupcion que aparece cuando se llenan los valores
		i = 0;
		Vdd = 3300 * (*VREFINT_CAL_ADDR) / ADC_raw[1];
		adecerrao1=ADC_raw[1];
		adecerrao0=ADC_raw[0];
	}
}



void vLdrCode(void * pvParameters) {
	for (;;) {
		/* Task code goes here. */
		HAL_ADC_ConvCpltCallback(&hadc);
		vTaskDelay(pdMS_TO_TICKS(250));
	}
}

/* Function that creates a task. */
 void vLdr(void) {
	/* Create the task, storing the handle. */
	xTaskCreate(
			vLdrCode, /* Function that implements the task. */
			"Ldr", /* Text name for the task. */
			configMINIMAL_STACK_SIZE, /* Stack size in words, not bytes. */
			( void * ) 1, /* Parameter passed into the task. */
			osPriorityHigh,/* Priority at which the task is created. */
			NULL); /* Used to pass out the created task's handle. */
}

