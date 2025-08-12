/*
 * Rte_Type.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef RTE_TYPE_H_
#define RTE_TYPE_H_

#pragma once
#include <stdint.h>

typedef struct {
	float tempC;
	float humi;
	uint8_t status;
}Rte_EnvData_t;


#endif /* RTE_TYPE_H_ */
