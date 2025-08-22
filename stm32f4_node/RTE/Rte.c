#include "Rte.h"
#include "Com.h"
#include "IoHwAb.h"

Rte_StatusType Rte_Send_CanMsg(const SensorDataType* data)
{
    return Com_SendSignal(COM_SIGNAL_CAN, (void*)data);
}

Rte_StatusType Rte_Send_UartMsg(const SensorDataType* data)
{
    return Com_SendSignal(COM_SIGNAL_UART, (void*)data);
}
