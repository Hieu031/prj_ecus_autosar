#include "Com.h"
#include "PduR.h"

Rte_StatusType Com_SendSignal(Com_SignalIdType id, void* data)
{
    return PduR_RouteSignal(id, data);
}
