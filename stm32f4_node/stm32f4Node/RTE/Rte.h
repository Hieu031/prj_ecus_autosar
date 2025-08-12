/*
 * Rte.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef RTE_H_
#define RTE_H_

#pragma once
#include "Rte_Type.h"
#include "Rte_Buffer.h"

void R_Sensor_Read_1Hz(void);
void R_Display_Update_1Hz(void);
void R_Comm_Publish_1Hz(void);

#endif /* RTE_H_ */
