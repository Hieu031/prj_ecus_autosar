/*
 * Lcd_I2c.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#ifndef ECUAL_LCD_I2C_LCD_I2C_H_
#define ECUAL_LCD_I2C_LCD_I2C_H_

#pragma once
#include "Mcal_I2c.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

void LCD_Init(I2C_HandleTypeDef *hi2c, uint8_t addr, uint8_t cols, uint8_t rows);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t col, uint8_t row);
void LCD_Print(const char *s);
void LCD_PrintPad(const char *s, uint8_t width);


#endif /* ECUAL_LCD_I2C_LCD_I2C_H_ */
