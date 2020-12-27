cmake_minimum_required(VERSION 3.8.2)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME MyLedLighting)

set(${PROJECT_NAME}_BOARD nano)
set(${PROJECT_NAME}_PORT COM5)

set(nano.upload.maximum_size 30720)
set(nano.upload.maximum_data_size 2048)
set(nano.upload.speed 57600)
set(nano.bootloader.low_fuses 0xFF)
set(nano.bootloader.high_fuses 0xDA)
set(nano.bootloader.extended_fuses 0x05)
set(nano.bootloader.file atmega/ATmegaBOOT_168_atmega328.hex)
set(nano.build.mcu atmega328p)

# set(ARDUINO_CPU)
project(${PROJECT_NAME})

# Define additional source and header files or default arduino sketch files
set(${PROJECT_NAME}_SRCS
        MyLedLighting.cpp
        libraries/Controller.cpp
        libraries/EffectStrategy.cpp
        libraries/Slicer.cpp
        libraries/Effects/WhiteLampEffect.cpp
        libraries/Effects/Rainbow.cpp
        libraries/Effects/FadeInOut.cpp
        libraries/Effects/Strobe.cpp
        libraries/Effects/Meteor.cpp
        libraries/Effects/RunningLights.cpp
        libraries/Effects/Fire.cpp
        )
set(${PROJECT_NAME}_HDRS
        libraries/Controller.h
        libraries/EffectStrategy.h
        libraries/Slicer.h
        libraries/Effects/WhiteLampEffect.h
        libraries/Effects/Rainbow.h
        libraries/Effects/FadeInOut.h
        libraries/Effects/Strobe.h
        libraries/Effects/Meteor.h
        libraries/Effects/RunningLights.h
        libraries/Effects/Fire.h
        )

### Additional static libraries to include in the target.
# set(${PROJECT_NAME}_LIBS)

### Main sketch file
#set(${PROJECT_NAME}_SKETCH MyLedLighting.ino)

### Add project directories into the build
# add_subdirectory()

### Additional settings to add non-standard or your own Arduino libraries.
# For this example (libs will contain additional arduino libraries)
# An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

# For nested library sources replace ${LIB_NAME} with library name for each library
#set(MicroLED_RECURSE true)
#set(FastLED_RECURSE true)

#### Additional settings for programmer. From programmers.txt
# set(${PROJECT_NAME}_PROGRAMMER avrispmkii)

#set(uno.upload.speed 9600)

## Verbose build process
# set(${PROJECT_NAME}_AFLAGS -v)

generate_arduino_firmware(${PROJECT_NAME})

print_board_list()
print_programmer_list()