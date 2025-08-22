#include "PduR.h"
#include "CanIf.h"
#include "UartIf.h"

Rte_StatusType PduR_RouteSignal(Com_SignalIdType id, void* data)
{
    switch(id)
    {
        case COM_SIGNAL_CAN:
            return CanIf_Transmit((SensorDataType*)data);
        case COM_SIGNAL_UART:
            return UartIf_Transmit((SensorDataType*)data);
        default:
            return RTE_E_NOT_OK;
    }
}
