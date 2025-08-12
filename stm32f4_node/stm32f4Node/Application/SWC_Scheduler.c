/*
 * SWC_Scheduler.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "Rte.h"
#include "Mcal_Time.h"
#include "Com.h"

// Runnable declarations
void R_Sensor_Read_1Hz(void);
void R_Display_Update_1Hz(void);
void R_Comm_Publish_1Hz(void);

void App_Init(void){
  Rte_Buffer_Init();
  Com_Init();      // init CAN/filters
}

void App_MainLoop(void){
  static uint32_t t1s=0;
  if (t1s==0) t1s = Mcal_TimeNow();
  uint32_t now = Mcal_TimeNow();
  if (now - t1s >= 1000){
    t1s += 1000;
    R_Sensor_Read_1Hz();
    R_Display_Update_1Hz();
    R_Comm_Publish_1Hz();
  }
}

