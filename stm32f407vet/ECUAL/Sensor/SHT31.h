/*
 * SHT31.h
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#ifndef SENSOR_SHT31_H_
#define SENSOR_SHT31_H_

void SHT31_Init(void);
float SHT31_ReadTemperature(void);
float SHT31_ReadHumidity(void);


#endif /* SENSOR_SHT31_H_ */
