#include "Dio.h"

void Dio_WritePin(GPIO_TypeDef *port, uint16_t pin, GPIO_PinState state) {
    HAL_GPIO_WritePin(port, pin, state);
}
