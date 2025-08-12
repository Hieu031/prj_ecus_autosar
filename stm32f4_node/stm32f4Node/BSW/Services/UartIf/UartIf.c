/*
 * UartIf.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "UartIf.h"
#include "Mcal_Uart.h"
#include "stdio.h"
#include "string.h"

void UartIf_SendJSON(float tC, float h, uint8_t st){
	char js[64];
	int n = snprintf(js,sizeof(js), "{\"t\":%.1f,\"h\":%.1f,\"st\":%u}\r\n", tC, h, st);
	 if (n>0) Mcal_Uart_Write((uint8_t*)js,(uint16_t)n);
}
