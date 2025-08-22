
#ifndef RTE_H_
#define RTE_H_

#pragma once
#include <stdint.h>

void Rte_Init(void);

int16_t Rte_Read_Temp_x10(void);
int16_t Rte_Read_Humi_x10(void);

void Rte_Call_Buzzer_Set(uint8_t on);


#endif /* RTE_H_ */
