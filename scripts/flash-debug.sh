#!/usr/bin/env bash

set -x

ELF=build/stm32/test1-f33.elf

openocd -f ./openocd.cfg -c "program ${ELF} verify reset" -c "halt"
