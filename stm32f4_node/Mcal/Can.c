#include "Can.h"
#include "stm32f4xx_hal.h"
#include <string.h>
extern CAN_HandleTypeDef hcan1;

Rte_StatusType Can_Transmit(const SensorDataType* data)
{
    CAN_TxHeaderTypeDef txHeader;
    uint32_t txMailbox;
    uint8_t payload[8];

    memcpy(payload, data, sizeof(SensorDataType));

    txHeader.StdId = 0x123U;
    txHeader.IDE   = CAN_ID_STD;
    txHeader.RTR   = CAN_RTR_DATA;
    txHeader.DLC   = sizeof(SensorDataType);

    if (HAL_CAN_AddTxMessage(&hcan1, &txHeader, payload, &txMailbox) == HAL_OK)
        return RTE_E_OK;
    else
        return RTE_E_NOT_OK;
}
