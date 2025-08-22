/*
 * I2C_Driver.c
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#include "I2C_Driver.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t I2C_Master_Transmit(uint16_t devAddr, uint8_t *data, uint16_t size){
	return HAL_I2C_Master_Transmit(&hi2c1, devAddr, data, size, HAL_MAX_DELAY);
}

uint8_t I2C_Master_Receive(uint16_t devAddr, uint8_t *data, uint16_t size){
	return HAL_I2C_Master_Receive(&hi2c1, devAddr, data, size, HAL_MAX_DELAY);
}
