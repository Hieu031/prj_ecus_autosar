/*
 * Com.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef SERVICES_COMM_COM_H_
#define SERVICES_COMM_COM_H_

#pragma once
#include <stdint.h>

typedef struct {
	int16_t t10;
	uint16_t h10;
	uint8_t st;
}Com_Env_t;

void Com_Init(void);
void Com_SendEnv(const Com_Env_t* e);

#endif /* SERVICES_COMM_COM_H_ */
