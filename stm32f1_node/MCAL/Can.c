#include "Can.h"

static CAN_HandleTypeDef *s_hcan;

void Can_Init(CAN_HandleTypeDef *hcan) {
    s_hcan = hcan;
}

void Can_ConfigFilter(uint16_t stdid) {
    CAN_FilterTypeDef f = {0};
    f.FilterBank = 0;
    f.FilterMode = CAN_FILTERMODE_IDMASK;
    f.FilterScale = CAN_FILTERSCALE_32BIT;
    f.FilterIdHigh     = (stdid << 5);
    f.FilterIdLow      = 0;
    f.FilterMaskIdHigh = (0x7FF << 5);
    f.FilterMaskIdLow  = 0;
    f.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    f.FilterActivation = ENABLE;
    f.SlaveStartFilterBank = 14;
    HAL_CAN_ConfigFilter(s_hcan, &f);
}

void Can_Start(void) {
    HAL_CAN_Start(s_hcan);
    HAL_CAN_ActivateNotification(s_hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void Can_RxIrqHandler(void) {
    CAN_RxHeaderTypeDef hdr;
    uint8_t data[8];
    if (HAL_CAN_GetRxMessage(s_hcan, CAN_RX_FIFO0, &hdr, data) == HAL_OK) {
        if (hdr.IDE == CAN_ID_STD) {
            extern void CanIf_RxIndication(uint16_t canId, const uint8_t *data, uint8_t dlc);
            CanIf_RxIndication(hdr.StdId, data, hdr.DLC);
        }
    }
}
