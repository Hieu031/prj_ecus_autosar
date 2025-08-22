#ifndef COM_TYPES_H_
#define COM_TYPES_H_

#pragma once
#include <stdint.h>

typedef int16_t Com_SignalType;

typedef enum {
	COM_SIG_Temp_x10 = 0,
	COM_SIG_Humi_x10 = 1,
	COM_SIGNAL_NUM
} Com_SignalIdType;

typedef enum {
	COM_RXPDU_SENSOR = 0,
	COM_PDU_NUM
} Com_PduIdType;

#endif /* COM_TYPES_H_ */
