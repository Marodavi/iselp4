/*
 * led.c
 *
 *  Created on: 6 de jun. de 2017
 *      Author: Mario
 */
#include "led.h"
#include "FreeRTOSConfig.h"
#include <projdefs.h>
#include "cmsis_os.h"

//Nivel de brillo [0-200]
#define LOW 20
#define MEDIUM 100
#define HIGH 200

int pwm=0;
void pwm_led(){
	pwm= LOW;
  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_3, pwm); //update pwm value

}

void vLedCode(void * pvParameters) {
	for (;;) {
		/* Task code goes here. */
    	pwm_led();
		vTaskDelay(pdMS_TO_TICKS(250));
	}
}

/* Function that creates a task. */
 void vLed(void) {
	/* Create the task, storing the handle. */
	xTaskCreate(
			vLedCode, /* Function that implements the task. */
			"Led", /* Text name for the task. */
			configMINIMAL_STACK_SIZE, /* Stack size in words, not bytes. */
			( void * ) 1, /* Parameter passed into the task. */
			osPriorityAboveNormal,/* Priority at which the task is created. */
			NULL); /* Used to pass out the created task's handle. */
}
