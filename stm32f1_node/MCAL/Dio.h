
#ifndef DIO_H_
#define DIO_H_

#pragma once
#include "stm32f1xx_hal.h"

void Dio_WritePin(GPIO_TypeDef *port, uint16_t pin, GPIO_PinState state);


#endif /* DIO_H_ */
