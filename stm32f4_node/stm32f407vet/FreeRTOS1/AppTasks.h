/*
 * AppTasks.h
 *
 *  Created on: Jul 17, 2025
 *      Author: nth280102
 */

#ifndef APPTASKS_H_
#define APPTASKS_H_

void MX_FREERTOS_Init(void);

void StartSensorTask(void *argument);
void StartCANTask(void *argument);
void StartCloudTask(void *argument);
void StartControlTask(void *argument);
void StartDisplayTask(void *argument); // LCD

#endif /* APPTASKS_H_ */
