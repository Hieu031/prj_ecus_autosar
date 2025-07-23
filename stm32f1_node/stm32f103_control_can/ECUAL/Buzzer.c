/*
 * Buzzer.c
 *
 *  Created on: Jul 17, 2025
 *      Author: hieu.nguyentri
 */

#include "Buzzer.h"
#include "Dio.h"

#define BUZZER_PORT GPIOB
#define BUZZER_PIN  GPIO_PIN_0

void Buzzer_On(void)
{
    Dio_Write(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);
}

void Buzzer_Off(void)
{
    Dio_Write(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
}
