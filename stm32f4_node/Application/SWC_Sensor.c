#include "SWC_Sensor.h"
#include "Rte.h"
#include "IoHwAb.h"
void SWC_Sensor_Read(void)
{
    SensorDataType data;
    IoHwAb_ReadDHT22(&data.temperature, &data.humidity);
    Rte_Write_SensorData(&data);
}


