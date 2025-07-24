/*
 * AppSensor.h
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#ifndef INC_APPSENSOR_H_
#define INC_APPSENSOR_H_

typedef struct {
    float temperature;
    float humidity;
} SensorData_t;

extern SensorData_t g_sensorData;

void Sensor_Init(void);
void Sensor_Read(void);

#endif /* INC_APPSENSOR_H_ */

