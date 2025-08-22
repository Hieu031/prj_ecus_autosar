/*
 * LCD_I2C_Driver.c
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#include "LCD_Driver.h"
#include "I2C_Driver.h"
#include "stm32f4xx_hal.h"
#include <string.h>

#define LCD_ADDR (0x27 << 1)

//static I2C_HandleTypeDef *lcd_i2c = NULL;
//static void LCD_SendCmd(uint8_t cmd);
//static void LCD_SendData(uint8_t data);
static void LCD_Send(uint8_t data, uint8_t mode);

void LCD_I2C_Init(void){
	HAL_Delay(50);
	LCD_SendCmd(0x33);
	LCD_SendCmd(0x32);
	LCD_SendCmd(0x28);
	LCD_SendCmd(0x0C);
	LCD_SendCmd(0x06);
	LCD_SendCmd(0x01);
}

void LCD_I2C_SetCursor(uint8_t row, uint8_t col){
	uint8_t pos = (row == 0) ? 0x80 + col : 0xC0 + col;
	LCD_SendCmd(pos);
}

void LCD_SendCmd(uint8_t cmd){
	LCD_Send(cmd & 0xF0, 0);
	LCD_Send((cmd << 4) & 0xF0, 0);
}

void LCD_I2C_Print(char *str){
	while(*str){
		LCD_SendData(*str++);
	}
}

void LCD_I2C_Clear(void){
	LCD_SendCmd(0x01);
}

void LCD_SendData(uint8_t data){
	LCD_Send(data & 0xF0, 1);
	LCD_Send((data << 4) & 0xF0, 1);
}

static void LCD_Send(uint8_t data, uint8_t mode){
	uint8_t control = data | 0x08 | (mode ? 0x01 : 0x00); // Backlight + RS
	uint8_t en_high = control | 0x04; // EN = 1
	I2C_Master_Transmit(LCD_ADDR, &en_high, 1);
	HAL_Delay(1);
	uint8_t en_low = control & ~0x04; // EN = 0
	I2C_Master_Transmit(LCD_ADDR, &en_low, 1);
	HAL_Delay(1);
}
