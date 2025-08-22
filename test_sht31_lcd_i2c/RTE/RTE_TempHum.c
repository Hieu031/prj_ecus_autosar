/*
 * RTE_TempHum.c
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */
#include "stm32f4xx_hal.h"
#include "RTE_TempHum.h"
#include "SHT31_Driver.h"
#include "Lcd_Service.h"

void Rte_TempHum_Init(void){
	LcdService_Init();
	if(SHT31_Init() != 0){
		LcdService_DisplayError();
		while(1){
			HAL_Delay(100);
		}
	}
	LcdService_Init();
	LcdService_DisplayTempHumi(0.0f, 0.0f);

}

void Rte_TempHum_Cyclic(void){
	float temp = 0.0f, humi = 0.0f;
	if (SHT31_Read(&temp, &humi) == 0){
		LcdService_DisplayTempHumi(temp, humi);
	}
	else
	{
		LcdService_DisplayError();
	}
}
