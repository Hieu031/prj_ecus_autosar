/*
 * Rte_Buffer.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "Rte_Buffer.h"

static Rte_EnvData_t g_env;

void Rte_Buffer_Init(void){
	g_env.tempC  = 0;
	g_env.humi   = 0;
	g_env.status = 1;
}

void Rte_Write_EnvData(const Rte_EnvData_t* d){
	g_env = *d;
}

void Rte_Read_EnvData(Rte_EnvData_t* d){
	*d = g_env;
}
