#!/bin/sh

arm-none-eabi-gcc -O0 -mfpu=vfp -mfloat-abi=soft -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -g -Wl,-T,rpi.x ledblink.c startup.c start.S -o kernel.elf
arm-none-eabi-objcopy kernel.elf -O binary kernel.img
