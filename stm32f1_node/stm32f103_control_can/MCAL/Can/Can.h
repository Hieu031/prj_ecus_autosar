/*
 * Can.h
 *
 *  Created on: Jul 17, 2025
 *      Author: hieu.nguyentri
 */

#ifndef CAN_CAN_H_
#define CAN_CAN_H_

#include <stdint.h>

void Can_Init(void);
void Can_Send(uint32_t id, uint8_t* data, uint8_t len);
void Can_SetRxCallback(void (*cb)(uint32_t id, uint8_t* data, uint8_t len));

#endif /* CAN_CAN_H_ */
