/*
 * lcd_I2C.h
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#ifndef LCD_LCD_I2C_H_
#define LCD_LCD_I2C_H_

#include <stdint.h>

void LCD_Init(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char* str);

#endif /* LCD_LCD_I2C_H_ */
