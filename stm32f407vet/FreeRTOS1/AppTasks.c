/*
 * AppTasks.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

// File: FreeRTOS/AppTasks.c
#include "cmsis_os2.h"
#include "AppTasks.h"
#include "AppSensor.h"
#include "AppCAN.h"
#include "AppCloud.h"
#include "AppControl.h"
#include "AppDisplay.h"  // nếu bạn dùng LCD

void MX_FREERTOS_Init(void) {
    osKernelInitialize();

    // Tạo các task
    osThreadNew(StartSensorTask, NULL, NULL);
    osThreadNew(StartCANTask, NULL, NULL);
    osThreadNew(StartCloudTask, NULL, NULL);
    osThreadNew(StartControlTask, NULL, NULL);
    osThreadNew(StartDisplayTask, NULL, NULL);  // nếu dùng LCD

    osKernelStart();
}

void StartSensorTask(void *argument) {
    Sensor_Init();
    for (;;) {
        Sensor_Read();
        osDelay(1000);
    }
}

void StartCANTask(void *argument) {
    CanIf_Init();
    for (;;) {
        CanIf_SendSensorData();
        osDelay(1000);
    }
}

void StartCloudTask(void *argument) {
    FirebaseService_Init();
    for (;;) {
        FirebaseService_Send();
        osDelay(2000);
    }
}

void StartControlTask(void *argument) {
    ActuatorManager_Init();
    for (;;) {
        ActuatorManager_HandleControl();
        osDelay(100);
    }
}

void StartDisplayTask(void *argument) {
    DisplayManager_Init();
    for (;;) {
        DisplayManager_Update();
        osDelay(1000);
    }
}
