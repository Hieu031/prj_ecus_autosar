/*
 * AppControl.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "AppControl.h"
#include "ActuatorManager.h"

void ActuatorManager_Init(void) {
    Buzzer_Init();
}

void ActuatorManager_HandleControl(void) {
    ActuatorManager_HandleCANCommand();
}

