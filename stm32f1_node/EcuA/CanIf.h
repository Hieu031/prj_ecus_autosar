#ifndef CANIF_H_
#define CANIF_H_

#pragma once
#include <stdint.h>

void CanIf_Init(void);
void CanIf_RxIndication(uint16_t canId, const uint8_t *data, uint8_t dlc);


#endif /* CANIF_H_ */
