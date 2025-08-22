#include "CanIf.h"
#include "Can.h"

Rte_StatusType CanIf_Transmit(const SensorDataType* data)
{
    return Can_Transmit(data);
}
