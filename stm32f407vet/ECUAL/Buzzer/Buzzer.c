/*
 * Buzzer.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */
#include "../../ECUAL/Buzzer/Buzzer.h"

#include "stm32f4xx_hal.h"

void Buzzer_Init(void) {
    // Đảm bảo chân PA6 đã được cấu hình là output trong CubeMX
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}

void Buzzer_On(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
}

void Buzzer_Off(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}
