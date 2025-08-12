/*
 * Mcal_Time.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef MCAL_MCAL_TIME_H_
#define MCAL_MCAL_TIME_H_

#pragma once
#include "stm32f4xx_hal.h"
static inline uint32_t Mcal_TimeNow(void){ return HAL_GetTick(); }


#endif /* MCAL_MCAL_TIME_H_ */
