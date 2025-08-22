/*
 * LCD_Driver.h
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include <stdint.h>

void LCD_I2C_Init(void);
void LCD_I2C_Clear(void);
void LCD_I2C_SetCursor(uint8_t row, uint8_t col);
void LCD_I2C_Print(char *str);
void LCD_SendCmd(uint8_t cmd);
void LCD_SendData(uint8_t data);

#endif /* LCD_DRIVER_H_ */
