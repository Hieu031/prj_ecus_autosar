/*
 * AppCloud.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "AppCloud.h"
#include "FirebaseService.h"
#include "AppSensor.h"

void FirebaseService_Init(void) {
    Firebase_HAL_Init();
}

void FirebaseService_Send(void) {
    Firebase_SendSensorData(&g_sensorData);
}

