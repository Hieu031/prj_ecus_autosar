#include "Uart.h"
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart2;

Rte_StatusType Uart_Transmit(uint8_t* data, uint16_t len)
{
    if(HAL_UART_Transmit(&huart2, data, len, 100) == HAL_OK)
        return RTE_E_OK;
    else
        return RTE_E_NOT_OK;
}
