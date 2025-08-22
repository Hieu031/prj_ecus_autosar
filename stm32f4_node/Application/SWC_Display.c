#include "SWC_Display.h"
#include "Rte.h"
#include "IoHwAb.h"
void SWC_Display_Update(void)
{
    SensorDataType data;
    if(Rte_Read_SensorData(&data) == RTE_E_OK)
    {
        IoHwAb_DisplayLCD(data.temperature, data.humidity);
    }
}
