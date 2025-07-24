/*
 * SHT31.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "SHT31.h"
#include "i2c.h"
#include "stm32f4xx_hal.h"
#include <math.h>
#define SHT31_ADDR 0x44 << 1

void SHT31_Init(void) {
    uint8_t cmd[2] = {0x2C, 0x06};
    HAL_I2C_Master_Transmit(&hi2c1, SHT31_ADDR, cmd, 2, 100);
}

float SHT31_ReadTemperature(void) {
    uint8_t cmd[2] = {0xE0, 0x00};
    HAL_I2C_Master_Transmit(&hi2c1, SHT31_ADDR, cmd, 2, 100);

    HAL_Delay(20);
    uint8_t data[6];
    HAL_I2C_Master_Receive(&hi2c1, SHT31_ADDR, data, 6, 100);

    uint16_t rawTemp = (data[0] << 8) | data[1];
    return -45 + 175 * ((float)rawTemp / 65535.0);
}

float SHT31_ReadHumidity(void) {
    uint8_t data[6];
    HAL_I2C_Master_Receive(&hi2c1, SHT31_ADDR, data, 6, 100);

    uint16_t rawHum = (data[3] << 8) | data[4];
    return 100 * ((float)rawHum / 65535.0);
}

