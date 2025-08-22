#include "CanIf.h"
#include "Com_Cfg.h"
#include "PduR_Cfg.h"

void PduR_CanIfRxIndication(uint8_t RxPduId, const uint8_t *data, uint8_t dlc);

void CanIf_Init(void) {}

void CanIf_RxIndication(uint16_t canId, const uint8_t *data, uint8_t dlc) {
    if (canId == COM_RXPDU_CAN_ID) {
        PduR_CanIfRxIndication(PDUR_CANIF_RX_PDU_SENSOR, data, dlc);
    }
}
