#pragma once

#include "stdbool.h"
#include "stdint.h"

static uint32_t LED_port;
static uint32_t LED_pin;


void pin_init(uint32_t port, uint32_t pin, uint32_t dir,
              uint32_t pull);

void port_clock_init(uint32_t port);

void heartbeat_init(uint32_t port, uint32_t pin);
void GPIO_toggle_heartbeat(void);
void GPIO_set_heartbeat(bool state);
