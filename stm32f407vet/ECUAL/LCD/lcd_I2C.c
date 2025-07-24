/*
 * lcd_I2C.c
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#include "../../ECUAL/LCD/lcd_I2C.h"

#include "i2c.h"
#include "string.h"
#define LCD_ADDR 0x27 << 1

void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_WriteNibble(uint8_t nibble, uint8_t mode);

void LCD_Init(void) {
    HAL_Delay(50);
    LCD_SendCommand(0x33);
    LCD_SendCommand(0x32);
    LCD_SendCommand(0x28);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x06);
    LCD_SendCommand(0x01);
    HAL_Delay(5);
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t pos = (row == 0) ? (0x80 + col) : (0xC0 + col);
    LCD_SendCommand(pos);
}

void LCD_Print(char* str) {
    while (*str) {
        LCD_SendData((uint8_t)(*str++));
    }
}

void LCD_SendCommand(uint8_t cmd) {
    LCD_WriteNibble(cmd & 0xF0, 0);
    LCD_WriteNibble((cmd << 4) & 0xF0, 0);
}

void LCD_SendData(uint8_t data) {
    LCD_WriteNibble(data & 0xF0, 1);
    LCD_WriteNibble((data << 4) & 0xF0, 1);
}

void LCD_WriteNibble(uint8_t nibble, uint8_t mode) {
    uint8_t data = nibble | 0x08 | (mode ? 0x01 : 0x00);
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, 10);
    data |= 0x04;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, 10);
    data &= ~0x04;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, 10);
    HAL_Delay(1);
}
