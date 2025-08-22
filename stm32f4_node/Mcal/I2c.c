#include "I2c.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

void I2c_DisplayLCD(float temp, float hum)
{
    char buf[32];
    sprintf(buf, "T=%.1f H=%.1f", temp, hum);
    // TODO: gọi LCD_I2C driver (HD44780 hoặc PCF8574) viết sẵn
}
