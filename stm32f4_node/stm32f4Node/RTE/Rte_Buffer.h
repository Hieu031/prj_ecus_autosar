/*
 * Rte_Buffer.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef RTE_BUFFER_H_
#define RTE_BUFFER_H_

#pragma once
#include <Rte_Type.h>

void Rte_Buffer_Init(void);
void Rte_Write_EnvData(const Rte_EnvData_t* d);
void Rte_Read_EnvData(Rte_EnvData_t* d);

#endif /* RTE_BUFFER_H_ */
