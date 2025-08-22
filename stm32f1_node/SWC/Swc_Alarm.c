#include "Swc_Alarm.h"
#include "Rte.h"
#include "Com_Cfg.h"

static uint8_t s_alarm=0;

void Swc_Alarm_Init(void) {
    s_alarm=0;
    Rte_Call_Buzzer_Set(0);
}

void Swc_Alarm_Runnable_100ms(void) {
    int16_t T = Rte_Read_Temp_x10();
    int16_t H = Rte_Read_Humi_x10();

    uint8_t need = s_alarm;
    if (!s_alarm) {
        if (T >= COM_TEMP_HIGH_X10 || H >= COM_HUMI_HIGH_X10)
        	need=1;
    } else {
        if (T <= (COM_TEMP_HIGH_X10-COM_TEMP_HYS_X10) &&
            H <= (COM_HUMI_HIGH_X10-COM_HUMI_HYS_X10))
        	need=0;
    }

    if (need != s_alarm) {
        s_alarm = need;
        Rte_Call_Buzzer_Set(s_alarm);
    }
}
