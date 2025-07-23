/*
 * Dio.h
 *
 *  Created on: Jul 17, 2025
 *      Author: hieu.nguyentri
 */

#ifndef DIO_DIO_H_
#define DIO_DIO_H_

#include "stm32f1xx_hal.h"

void Dio_Write(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState state);
void Dio_Toggle(GPIO_TypeDef* port, uint16_t pin);

#endif /* DIO_DIO_H_ */
