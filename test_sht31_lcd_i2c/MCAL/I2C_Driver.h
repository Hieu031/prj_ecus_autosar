/*
 * I2C_Driver.h
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include <stdint.h>

uint8_t I2C_Master_Transmit(uint16_t devAddr, uint8_t *data, uint16_t size);
uint8_t I2C_Master_Receive(uint16_t devAddr, uint8_t *data, uint16_t size);

#endif /* I2C_DRIVER_H_ */
