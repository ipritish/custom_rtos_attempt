cmake_minimum_required( VERSION 2.8 )

# Set the tutorial number so it's easier to re-use the CMakeLists.txt
#set( TUT 013 )

# Mark the language as C so that CMake doesn't try to test the C++
# cross-compiler's ability to compile a simple program because that will fail
project( interrupt C ASM )

# Add any C compiler flags here. The C flags concerned with processor tuning
# are in the toolchain files toolchain-arm-none-eabi-bcm2835.cmake, etc.
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O1" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles" )

# Set the linker flags so that we use our "custom" linker script
set( CMAKE_EXE_LINKER_FLAGS "-Wl,-T,${PROJECT_SOURCE_DIR}/rpi.x" )

add_executable( kernel.elf
    ledblink.c
    startup.c
    cstubs.c
    start.S
    rpi-armtimer.c
    rpi-armtimer.h
    rpi-base.h
    rpi-gpio.c
    rpi-gpio.h
    rpi-interrupts.c
    rpi-interrupts.h
    rpi-systimer.c
    rpi-systimer.h )

add_custom_command(
    TARGET kernel.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ./kernel.elf -O binary ./kernel.img
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Convert the ELF output file to a binary image" )
