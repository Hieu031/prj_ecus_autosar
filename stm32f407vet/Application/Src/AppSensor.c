/*
 * AppSensor.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "AppSensor.h"
#include "SensorManager.h"

SensorData_t g_sensorData;

void Sensor_Init(void) {
    SensorManager_Init();
}

void Sensor_Read(void) {
    SensorManager_ReadSensor(&g_sensorData);
}
