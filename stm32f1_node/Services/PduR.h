
#ifndef PDUR_H_
#define PDUR_H_

#pragma once
#include <stdint.h>

void PduR_CanIfRxIndication(uint8_t RxPduId, const uint8_t *data, uint8_t dlc);


#endif /* PDUR_H_ */
