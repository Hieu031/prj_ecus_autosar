#ifndef COM_H_
#define COM_H_

#include "Rte_Type.h"

typedef enum {
    COM_SIGNAL_CAN,
    COM_SIGNAL_UART
} Com_SignalIdType;

Rte_StatusType Com_SendSignal(Com_SignalIdType id, void* data);

#endif /* COM_H_ */
