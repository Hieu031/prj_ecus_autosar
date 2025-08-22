#include "SWC_Scheduler.h"
#include "SWC_Sensor.h"
#include "SWC_Display.h"
#include "SWC_Comm.h"

void SWC_Scheduler_Run(void)
{
    SWC_Sensor_Read();
    SWC_Display_Update();
    SWC_Comm_Send();
}
