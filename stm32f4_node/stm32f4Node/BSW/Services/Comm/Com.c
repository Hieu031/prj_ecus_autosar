/*
 * Com.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "Com.h"
#include "CanIf.h"

void Com_Init(void) {
	CanIf_Init();
}

void Com_SendEnv(const Com_Env_t* e){
	CanIf_Tx_Env(e->t10, e->t10, e->st);
}
