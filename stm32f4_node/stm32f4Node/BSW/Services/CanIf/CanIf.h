/*
 * CanIf.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef SERVICES_CANIF_CANIF_H_
#define SERVICES_CANIF_CANIF_H_

#pragma once
#include <stdint.h>

void canIf_Init(void);
void canIf_Tx_Env(int16_t temp_x10);

#endif /* SERVICES_CANIF_CANIF_H_ */
