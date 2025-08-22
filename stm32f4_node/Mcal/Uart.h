#ifndef UART_H_
#define UART_H_

#include "Rte_Type.h"
#include <stdint.h>

Rte_StatusType Uart_Transmit(uint8_t* data, uint16_t len);

#endif /* UART_H_ */
