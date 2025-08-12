/*
 * SWC_Sensor.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "Rte.h"
#include "DHT22.h"

void R_Sensor_Read_1Hz(void){
	static uint8_t inited = 0;
	if(!inited){
		DHT22_Init();
		inited = 1;
	}
	Rte_EnvData_t d = {0};
	float t = 0, h = 0;
	DHT22_Status st = DHT22_Read(&t, &h);
	d.tempC = t;
	d.humi = h;
	d.status = (st == DHT22_OK) ? 0 : (uint8_t)st;
	Rte_Write_EnvData(&d);
}
