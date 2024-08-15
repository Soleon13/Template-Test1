#include "main.h"

#include <stdbool.h>

#include "can.h"
#include "clock.h"
#include "gpio.h"
#include "i2c.h"
#include "interrupts.h"
#include "error_handler.h"

#include "FreeRTOS.h"
#include "task.h"

#include <stm32g4xx_hal.h>

void heartbeat_task(void *pvParameters) {
	(void) pvParameters;
	while(true)
	{
		// CAN_send(0, 8, 0x0123456789abcdef);
		GPIO_toggle_heartbeat();
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}

int main(void)
{
	// Drivers
	if (!clock_init()) error_handler();
	if (!I2C_init()) error_handler();
	if (!CAN_init()) error_handler();

    heartbeat_init(GPIOA, GPIO_PIN_5);
	interrupts_init();

	int err = xTaskCreate(heartbeat_task,
        "heartbeat",
        1000,
        NULL,
        4,
        NULL);
    if (err != pdPASS) {
        error_handler();
    }


    // hand control over to FreeRTOS
    vTaskStartScheduler();

    // we should not get here ever
    error_handler();
}

// Called when stack overflows from rtos
// Not needed in header, since included in FreeRTOS-Kernel/include/task.h
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName)
{
	(void) xTask;
	(void) pcTaskName;

    error_handler();
}