#include "PduR.h"
#include "Com.h"
#include "Com_Types.h"

void PduR_CanIfRxIndication(uint8_t RxPduId, const uint8_t *data, uint8_t dlc) {
    Com_RxIndication(COM_RXPDU_SENSOR, data, dlc);
}
