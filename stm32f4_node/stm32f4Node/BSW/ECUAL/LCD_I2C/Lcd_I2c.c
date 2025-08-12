/*
 * Lcd_I2c.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "lcd_I2C.h"
#include <stdio.h>

#define LCD_BACKLIGHT 0x08
static I2C_HandleTypeDef *lcd_i2c;
static uint8_t lcd_addr, lcd_cols, lcd_rows;

static void expanderWrite(uint8_t data){
  HAL_I2C_Master_Transmit(lcd_i2c, lcd_addr<<1, &data, 1, 10);
}
static void pulseEnable(uint8_t data){
  expanderWrite(data | 0x04);
  HAL_Delay(1);
  expanderWrite(data & ~0x04);
  HAL_Delay(1);
}
static void write4bits(uint8_t value){
  expanderWrite(value | LCD_BACKLIGHT);
  pulseEnable(value | LCD_BACKLIGHT);
}
static void send(uint8_t value, uint8_t mode){
  uint8_t high = value & 0xF0;
  uint8_t low  = (value<<4) & 0xF0;
  write4bits(high | mode);
  write4bits(low  | mode);
}

void LCD_Init(I2C_HandleTypeDef *hi2c, uint8_t addr, uint8_t cols, uint8_t rows){
  lcd_i2c = hi2c; lcd_addr = addr; lcd_cols = cols; lcd_rows = rows;
  HAL_Delay(50);
  write4bits(0x30); HAL_Delay(5);
  write4bits(0x30); HAL_Delay(5);
  write4bits(0x20); HAL_Delay(5); // 4-bit
  send(0x28, 0); // 2 lines
  send(0x0C, 0); // display on
  send(0x06, 0); // entry mode
  send(0x01, 0); HAL_Delay(2);
}
void LCD_Clear(void){ send(0x01,0); HAL_Delay(2); }
void LCD_SetCursor(uint8_t col, uint8_t row){
  static const uint8_t offsets[] = {0x00,0x40,0x14,0x54};
  if(row>=lcd_rows) row=0;
  send(0x80 | (col + offsets[row]), 0);
}
void LCD_Print(const char *s){ while(*s) { send(*s++, 1); } }
void LCD_PrintPad(const char *s, uint8_t width){
  char buf[32]; snprintf(buf,sizeof(buf), "%-*s", width, s); LCD_Print(buf);
}

