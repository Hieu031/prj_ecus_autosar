/*
 * SHT31_Driver.h
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#ifndef SHT31_DRIVER_H_
#define SHT31_DRIVER_H_

#include <stdint.h>

uint8_t SHT31_Init(void);
uint8_t SHT31_Read(float *temp, float *humi);

#endif /* SHT31_DRIVER_H_ */
