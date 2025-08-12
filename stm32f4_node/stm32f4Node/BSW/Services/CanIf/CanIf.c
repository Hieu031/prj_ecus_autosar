/*
 * CanIf.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "CanIf.h"
#include "Mcal_Can.h"

#define CAN_ID_ENV 0x100

void CanIf_Init(void){ Mcal_Can_Start(); }

void CanIf_Tx_Env(int16_t t10, uint16_t h10, uint8_t st){
	uint8_t d[8] = {
			(uint8_t)(t10 & 0xFF), (uint8_t)((t10>>8) & 0xFF),
			(uint8_t)(h10 & 0xFF), (uint8_t)((t10>>8) & 0xFF),
			st, 0, 0, 0
	};
	(void)Mcal_Can_SendStd(CAN_ID_ENV, d, 8);
}
