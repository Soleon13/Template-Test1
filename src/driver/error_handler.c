#include "error_handler.h"

#include <stdbool.h>
#include "interrupts.h"

void error_handler()
{
    interrupts_disable();
    while (true) {};
}