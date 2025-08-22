
#ifndef CAN_H_
#define CAN_H_

#pragma once
#include "stm32f1xx_hal.h"

void Can_Init(CAN_HandleTypeDef *hcan);
void Can_ConfigFilter(uint16_t stdid);
void Can_Start(void);
void Can_RxIrqHandler(void);


#endif /* CAN_H_ */
