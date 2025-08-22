/*
 * App_TempHum.c
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#include "App_TempHum.h"
#include "Rte_TempHum.h"

void Application_Init(void){
	Rte_TempHum_Init();
}

void Application_Run(void){
	Rte_TempHum_Cyclic();
}
