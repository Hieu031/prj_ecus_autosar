#include "UartIf.h"
#include "Uart.h"
#include <stdio.h>
#include <string.h>
Rte_StatusType UartIf_Transmit(const SensorDataType* data)
{
    char buf[64];
    sprintf(buf, "{\"temp\"=%.2f,  \"hum\"=%.2f}\n", data->temperature, data->humidity);
    return Uart_Transmit((uint8_t*)buf, strlen(buf));
}
