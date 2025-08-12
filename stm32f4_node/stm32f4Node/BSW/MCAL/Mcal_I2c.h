/*
 * Mcal_I2c.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef MCAL_MCAL_I2C_H_
#define MCAL_MCAL_I2C_H_

#pragma once
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal.h"
#ifdef __cplusplus
extern "C" {
#endif

extern I2C_HandleTypeDef hi2c1;

static inline I2C_HandleTypeDef* Mcal_I2c_Get(void){ return &hi2c1; }
static inline HAL_StatusTypeDef Mcal_I2c_Tx(uint16_t addr, uint8_t* d, uint16_t n, uint32_t to){
  return HAL_I2C_Master_Transmit(&hi2c1, addr<<1, d, n, to);
}
static inline HAL_StatusTypeDef Mcal_I2c_Rx(uint16_t addr, uint8_t* d, uint16_t n, uint32_t to){
  return HAL_I2C_Master_Receive(&hi2c1, addr<<1, d, n, to);
}

#ifdef __cplusplus
}
#endif

#endif /* MCAL_MCAL_I2C_H_ */
