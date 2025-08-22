#ifndef RTE_BUFFER_H_
#define RTE_BUFFER_H_

#include "Rte_Type.h"

Rte_StatusType Rte_Write_SensorData(const SensorDataType* data);
Rte_StatusType Rte_Read_SensorData(SensorDataType* data);

#endif /* RTE_BUFFER_H_ */
