#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/i2c.h"

#include "DS2485.h"

static int addr = 0x40;

// read 1-wire port config 
void DS2485_Port_Config() {
    uint8_t data[2];
    uint8_t config[3];

    data[0] = 0x52;
    data[1] = 0x01;
    printf("hello\n");

    i2c_write_blocking(I2C_PORT, addr, data, 2, true);
    sleep_ms(100);
    i2c_read_blocking(I2C_PORT, addr, config, 3, false);

    // print to serial
    for ( int i = 0; i < 2; i++) {
        printf("%02x\n", config[i]);
    }


}


void main() {
    stdio_init_all();
    sleep_ms(12000);

    DS2485_Port_Config();

}

