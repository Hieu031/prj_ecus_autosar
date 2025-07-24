/*
 * AppCAN.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "AppCAN.h"
#include "can.h"
#include "AppSensor.h"

void CanIf_Init(void) {
    HAL_CAN_Start(&hcan1);
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void CanIf_SendSensorData(void) {
    CAN_TxHeaderTypeDef txHeader;
    uint8_t txData[4];
    uint32_t txMailbox;

    txHeader.DLC = 4;
    txHeader.IDE = CAN_ID_STD;
    txHeader.RTR = CAN_RTR_DATA;
    txHeader.StdId = 0x100;

    txData[0] = (uint8_t)(g_sensorData.temperature * 10);
    txData[1] = (uint8_t)(g_sensorData.humidity * 10);
    txData[2] = 0;
    txData[3] = 0;

    HAL_CAN_AddTxMessage(&hcan1, &txHeader, txData, &txMailbox);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t rxData[8];

    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, rxData);

    if (rxHeader.StdId == 0x200 && rxHeader.DLC == 1) {
        if (rxData[0] == 1) {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        }
    }
}
