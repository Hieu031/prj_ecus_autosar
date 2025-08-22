/*
 * SHT31_Driver.c
 *
 *  Created on: Jul 26, 2025
 *      Author: nth280102
 */

#include "SHT31_Driver.h"
#include "I2C_Driver.h"
#include "stm32f4xx_hal.h"

// Địa chỉ I2C của SHT31, đã dịch trái 1 bit để sử dụng với HAL
#define SHT31_ADDR (0x44 << 1)

// Lệnh khởi tạo đo lường chu kỳ, độ chính xác cao
#define SHT31_CMD_MEAS_HPM_PERI_START   0x2236
// Lệnh đọc dữ liệu
#define SHT31_CMD_FETCH_DATA            0xE000

// Hàm kiểm tra CRC
static uint8_t check_crc8(uint8_t *data, int len, uint8_t crc){
    uint8_t crc_calc = 0xFF;
    for (int i = 0; i < len; ++i) {
        crc_calc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            if (crc_calc & 0x80) {
                crc_calc = (crc_calc << 1) ^ 0x31;
            } else {
                crc_calc = (crc_calc << 1);
            }
        }
    }
    return (crc_calc == crc);
}

uint8_t SHT31_Init(void){
	// Gửi lệnh khởi tạo chế độ đo lường chu kỳ với độ chính xác cao
	uint8_t cmd_high_precision[] = {0x22, 0x36};

	// Kiểm tra trạng thái trả về để xác nhận gửi lệnh thành công
	    if (I2C_Master_Transmit(SHT31_ADDR, cmd_high_precision, 2) != 0) {
	        return 1; // error init
	    }
	    return 0;
}

uint8_t SHT31_Read(float *temp, float *humi){
	uint8_t data[6];
	uint8_t cmd_fetch[] = {0xE0, 0x00};
	if (I2C_Master_Transmit(SHT31_ADDR, cmd_fetch, 2) != 0) {
	        return 1; // error when send read command
	    }
	HAL_Delay(10);

	if (I2C_Master_Receive(SHT31_ADDR, data, 6) != 0) {
        return 1; // error when receive data
    }
    // Kiểm tra CRC cho nhiệt độ và độ ẩm
    if (!check_crc8(&data[0], 2, data[2])) return 2; // Lỗi CRC nhiệt độ
    if (!check_crc8(&data[3], 2, data[5])) return 3; // Lỗi CRC độ ẩm

	uint16_t rawT = (data[0] << 8) | data[1];
	uint16_t rawH = (data[3] << 8) | data[4];

	*temp = -45.0f + 175.0f * ((float)rawT / 65535.0f);
	*humi = 100.0f * ((float)rawH / 65535.0f);

	return 0;
}
