/*
 * Lcd_Service.c
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#include "Lcd_Service.h"
#include "LCD_Driver.h"
#include <stdio.h>

void LcdService_Init(void){
	LCD_I2C_Init();
	LCD_I2C_Clear();
}

void LcdService_DisplayTempHumi(float temp, float humi){
	char line[17];

	LCD_I2C_Clear();

	LCD_I2C_SetCursor(0, 0);
	snprintf(line, 17, "Temp: %-.7fC", temp); // @suppress("Float formatting support")
	LCD_I2C_Print(line);

	LCD_I2C_SetCursor(1, 0);
	snprintf(line, 17, "Humi: %-.7f%%", humi); // @suppress("Float formatting support")
	LCD_I2C_Print(line);
}

void LcdService_DisplayError(void){
	LCD_I2C_Clear();

	LCD_I2C_SetCursor(0, 0);
	LCD_I2C_Print("Sensor Error    ");

	LCD_I2C_SetCursor(1, 0);
	LCD_I2C_Print("                ");
}

