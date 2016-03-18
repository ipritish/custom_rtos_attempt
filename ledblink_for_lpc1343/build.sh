#!/bin/sh

arm-none-eabi-gcc lpcstartup.c -nostartfiles -mcpu=cortex-m3 -mthumb -T linkerscript.ld -o lpcstartup.elf
arm-none-eabi-objcopy --strip-unneeded -O binary lpcstartup.elf lpcstartup.bin
lpc-crc lpcstartip.bin
