/*
 * DHT22.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef ECUAL_DHT22_DHT22_H_
#define ECUAL_DHT22_DHT22_H_

#pragma once
#include "stm32f4xx_hal.h"

// Chân DATA DHT22:
#define DHT22_GPIO_Port   GPIOA
#define DHT22_Pin         GPIO_PIN_1

typedef enum { DHT22_OK=0, DHT22_TO_LOW, DHT22_TO_HIGH, DHT22_BAD_CRC } DHT22_Status;

void DHT22_Init(void);                              // enable DWT delay
DHT22_Status DHT22_Read(float *tempC, float *humi); // đo 1 lần

#endif /* ECUAL_DHT22_DHT22_H_ */
