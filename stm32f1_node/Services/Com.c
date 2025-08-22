#include "Com.h"

static volatile Com_SignalType s_sigBuf[COM_SIGNAL_NUM];

void Com_Init(void) {
    for (int i=0;i<COM_SIGNAL_NUM;i++)
    	s_sigBuf[i]=0;
}

void Com_RxIndication(Com_PduIdType pduId, const uint8_t *data, uint8_t dlc) {
    if (pduId != COM_RXPDU_SENSOR || dlc < 4) return;
    int16_t T = (int16_t)(data[0] | (data[1]<<8));
    int16_t H = (int16_t)(data[2] | (data[3]<<8));
    s_sigBuf[COM_SIG_Temp_x10] = T;
    s_sigBuf[COM_SIG_Humi_x10] = H;
}

Com_SignalType Com_ReadSignal(Com_SignalIdType sigId) {
    return s_sigBuf[sigId];
}
