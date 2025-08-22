
#ifndef COM_H_
#define COM_H_

#pragma once
#include "Com_Types.h"

void Com_Init(void);
void Com_RxIndication(Com_PduIdType pduId, const uint8_t *data, uint8_t dlc);
Com_SignalType Com_ReadSignal(Com_SignalIdType sigId);


#endif /* COM_H_ */
