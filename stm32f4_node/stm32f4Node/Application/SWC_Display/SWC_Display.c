/*
 * SWC_Display.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "Rte.h"
#include "lcd_I2C.h"
#include "Mcal_I2c.h"
#include "stdio.h"

#define LCD_ADDR 0x27

void R_Display_Update_1Hz(void){
  static uint8_t inited=0;
  if(!inited){
    LCD_Init(Mcal_I2c_Get(), LCD_ADDR, 16, 2);
    LCD_Clear();
    inited=1;
  }
  Rte_EnvData_t d; Rte_Read_EnvData(&d);
  char ln[17];
  snprintf(ln,sizeof(ln),"T:%5.1fC", d.tempC);
  LCD_SetCursor(0,0); LCD_PrintPad(ln,16);
  snprintf(ln,sizeof(ln),"H:%5.1f%% St:%u", d.humi, d.status);
  LCD_SetCursor(0,1); LCD_PrintPad(ln,16);
}

