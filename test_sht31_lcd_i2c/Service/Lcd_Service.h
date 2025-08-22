/*
 * Lcd_Service.h
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#ifndef LCD_SERVICE_H_
#define LCD_SERVICE_H_

void LcdService_Init(void);
void LcdService_DisplayTempHumi(float temp, float humi);
void LcdService_DisplayError(void);

#endif /* LCD_SERVICE_H_ */
