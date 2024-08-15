#include "interrupts.h"

#include "stm32g4xx_hal.h"

void interrupts_init()
{
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
}

void interrupts_disable()
{
	__disable_irq();
}