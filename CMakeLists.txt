cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(MAX31820)
add_library( sensor_lib INTERFACE)

pico_sdk_init()

target_sources(sensor_lib INTERFACE
${CMAKE_CURRENT_LIST_DIR}/DS2485.c
${CMAKE_CURRENT_LIST_DIR}/Temp_Sensor.c
)

target_link_libraries(sensor_lib INTERFACE
    pico_stdlib
    hardware_i2c
)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} sensor_lib)
target_compile_definitions(${PROJECT_NAME} PRIVATE SENSOR_LIB)

pico_enable_stdio_usb(${PROJECT_NAME} 1) # from video
pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_add_extra_outputs(${PROJECT_NAME})
