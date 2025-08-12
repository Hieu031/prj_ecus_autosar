/*
 * SWC_Comm.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "Rte.h"
#include "Com.h"
#include "UartIf.h"

void R_Comm_Publish_1Hz(void){
  Rte_EnvData_t d; Rte_Read_EnvData(&d);
  Com_Env_t e = {
    .t10 = (int16_t)(d.tempC*10.0f),
    .h10 = (uint16_t)(d.humi*10.0f),
    .st  = d.status
  };
  Com_SendEnv(&e);                       // CAN → F1
  UartIf_SendJSON(d.tempC, d.humi, d.status); // UART → ESP32
}

