/*
 * AppDisplay.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "AppDisplay.h"
#include "DisplayManager.h"

void DisplayManager_Init(void) {
    Display_HAL_Init();
}

void DisplayManager_Update(void) {
    Display_UpdateFromSensor();
}

