/*
 * Mcal_Can.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef MCAL_MCAL_CAN_H_
#define MCAL_MCAL_CAN_H_

#pragma once
#include "stm32f4xx_hal_can.h"
#include "stm32f4xx_hal.h"
#ifdef __cplusplus
extern "C" {
#endif

extern CAN_HandleTypeDef hcan1;

static inline void Mcal_Can_Start(void){
  HAL_CAN_Start(&hcan1);
  CAN_FilterTypeDef f={0};
  f.FilterActivation=ENABLE; f.FilterBank=0; f.FilterFIFOAssignment=CAN_FILTER_FIFO0;
  f.FilterIdHigh=0; f.FilterIdLow=0; f.FilterMaskIdHigh=0; f.FilterMaskIdLow=0;
  f.FilterMode=CAN_FILTERMODE_IDMASK; f.FilterScale=CAN_FILTERSCALE_32BIT;
  HAL_CAN_ConfigFilter(&hcan1,&f);
}

static inline HAL_StatusTypeDef Mcal_Can_SendStd(uint16_t id, uint8_t* d, uint8_t len){
  CAN_TxHeaderTypeDef th={.StdId=id,.IDE=CAN_ID_STD,.RTR=CAN_RTR_DATA,.DLC=len};
  uint32_t mb; return HAL_CAN_AddTxMessage(&hcan1,&th,d,&mb);
}

#ifdef __cplusplus
}
#endif

#endif /* MCAL_MCAL_CAN_H_ */
