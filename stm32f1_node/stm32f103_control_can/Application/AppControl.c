/*
 * AppControl.c
 *
 *  Created on: Jul 17, 2025
 *      Author: hieu.nguyentri
 */

#include "AppControl.h"
#include "Can.h"
#include "Buzzer.h"

#define CAN_MSG_ID_CMD 0x321
#define CAN_MSG_ID_RESP 0x322
#define CMD_BUZZER_ON  0x01
#define CMD_BUZZER_OFF 0x00

void CanMessageHandler(uint32_t id, uint8_t* data, uint8_t len)
{
    uint8_t resp[1];
    if (id == CAN_MSG_ID_CMD && len >= 1)
    {
        if (data[0] == CMD_BUZZER_ON) {
            Buzzer_On();
            resp[0] = 0xA1;
        }
        else if (data[0] == CMD_BUZZER_OFF) {
            Buzzer_Off();
            resp[0] = 0xA0;
        }
        Can_Send(CAN_MSG_ID_RESP, resp, 1);
    }
}

void App_Init(void)
{
    Can_Init();
    Can_SetRxCallback(CanMessageHandler);
}

void App_Loop(void)
{
    // Nothing needed here for now
}

