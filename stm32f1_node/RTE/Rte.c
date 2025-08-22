#include "Rte.h"
#include "Com.h"
#include "Com_Types.h"
#include "Buzzer.h"

void Rte_Init(void) {
    Com_Init();
    Buzzer_Init();
}

int16_t Rte_Read_Temp_x10(void) {
	return Com_ReadSignal(COM_SIG_Temp_x10);
}

int16_t Rte_Read_Humi_x10(void) {
	return Com_ReadSignal(COM_SIG_Humi_x10);
}

void Rte_Call_Buzzer_Set(uint8_t on) {
	Buzzer_Set(on);
}
