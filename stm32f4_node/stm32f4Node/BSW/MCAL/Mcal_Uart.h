/*
 * Mcal_Uart.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef MCAL_MCAL_UART_H_
#define MCAL_MCAL_UART_H_

#pragma once
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal.h"
#ifdef __cplusplus
extern "C" {
#endif

extern UART_HandleTypeDef huart2;

static inline void Mcal_Uart_Write(const uint8_t* d, uint16_t n){
  HAL_UART_Transmit(&huart2,(uint8_t*)d,n,100);
}

#ifdef __cplusplus
}
#endif

#endif /* MCAL_MCAL_UART_H_ */
