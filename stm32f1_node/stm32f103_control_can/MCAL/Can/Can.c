/*
 * Can.c
 *
 *  Created on: Jul 17, 2025
 *      Author: hieu.nguyentri
 */

#include "Can.h"
#include "stm32f1xx_hal.h"

extern CAN_HandleTypeDef hcan;

static void (*CanRxCallback)(uint32_t, uint8_t*, uint8_t) = 0;

void Can_Init(void)
{
    HAL_CAN_Start(&hcan);
    HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void Can_SetRxCallback(void (*cb)(uint32_t id, uint8_t* data, uint8_t len))
{
    CanRxCallback = cb;
}

void Can_Send(uint32_t id, uint8_t* data, uint8_t len)
{
    CAN_TxHeaderTypeDef txHeader;
    uint32_t txMailbox;

    txHeader.StdId = id;
    txHeader.ExtId = 0;
    txHeader.RTR = CAN_RTR_DATA;
    txHeader.IDE = CAN_ID_STD;
    txHeader.DLC = len;
    txHeader.TransmitGlobalTime = DISABLE;

    HAL_CAN_AddTxMessage(&hcan, &txHeader, data, &txMailbox);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t rxData[8];

    if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, rxData) == HAL_OK)
    {
        if (CanRxCallback != 0 && rxHeader.IDE == CAN_ID_STD)
        {
            CanRxCallback(rxHeader.StdId, rxData, rxHeader.DLC);
        }
    }
}

