#ifndef RTE_H_
#define RTE_H_

#include "Rte_Type.h"

Rte_StatusType Rte_Write_SensorData(const SensorDataType* data);
Rte_StatusType Rte_Read_SensorData(SensorDataType* data);

Rte_StatusType Rte_Send_CanMsg(const SensorDataType* data);
Rte_StatusType Rte_Send_UartMsg(const SensorDataType* data);

#endif /* RTE_H_ */
