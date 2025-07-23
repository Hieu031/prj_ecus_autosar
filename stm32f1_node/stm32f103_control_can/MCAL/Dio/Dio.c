/*
 * Dio.c
 *
 *  Created on: Jul 17, 2025
 *      Author: hieu.nguyentri
 */


#include "Dio.h"

void Dio_Write(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState state)
{
    HAL_GPIO_WritePin(port, pin, state);
}

void Dio_Toggle(GPIO_TypeDef* port, uint16_t pin)
{
    HAL_GPIO_TogglePin(port, pin);
}

