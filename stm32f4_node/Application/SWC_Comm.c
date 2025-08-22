#include "SWC_Comm.h"
#include "Rte.h"

void SWC_Comm_Send(void)
{
    SensorDataType data;
    if(Rte_Read_SensorData(&data) == RTE_E_OK)
    {
        // gửi qua CAN
        Rte_Send_CanMsg(&data);
        // gửi qua UART
        Rte_Send_UartMsg(&data);
    }
}
