#include "Rte_Buffer.h"

static SensorDataType g_sensorData;

Rte_StatusType Rte_Write_SensorData(const SensorDataType* data)
{
    g_sensorData = *data;
    return RTE_E_OK;
}

Rte_StatusType Rte_Read_SensorData(SensorDataType* data)
{
    *data = g_sensorData;
    return RTE_E_OK;
}
