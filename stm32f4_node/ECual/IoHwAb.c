#include "IoHwAb.h"

#include "../Mcal/I2c.h"
#include "Dio.h"

void IoHwAb_ReadDHT22(float* temp, float* hum)
{
    Dio_ReadDHT22(temp, hum);
}

void IoHwAb_DisplayLCD(float temp, float hum)
{
    I2c_DisplayLCD(temp, hum);
}
