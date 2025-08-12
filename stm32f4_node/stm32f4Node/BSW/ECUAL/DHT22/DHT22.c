/*
 * DHT22.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nth280102
 */

#include "DHT22.h"

static inline void DWT_Delay_Init(void){
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}
static inline void DWT_Delay_us(uint32_t us){
  uint32_t start = DWT->CYCCNT;
  uint32_t ticks = us * (SystemCoreClock/1000000);
  while ((DWT->CYCCNT - start) < ticks) {}
}
static void gpio_out(void){
  GPIO_InitTypeDef g={0}; g.Pin=DHT22_Pin; g.Mode=GPIO_MODE_OUTPUT_PP;
  g.Pull=GPIO_NOPULL; g.Speed=GPIO_SPEED_FREQ_LOW; HAL_GPIO_Init(DHT22_GPIO_Port,&g);
}
static void gpio_in(void){
  GPIO_InitTypeDef g={0}; g.Pin=DHT22_Pin; g.Mode=GPIO_MODE_INPUT;
  g.Pull=GPIO_NOPULL; HAL_GPIO_Init(DHT22_GPIO_Port,&g);
}

void DHT22_Init(void){ DWT_Delay_Init(); }

DHT22_Status DHT22_Read(float *tC, float *h)
{
  uint8_t data[5]={0};
  // start
  gpio_out();
  HAL_GPIO_WritePin(DHT22_GPIO_Port, DHT22_Pin, GPIO_PIN_RESET);
  DWT_Delay_us(1200);      // ≥1ms
  HAL_GPIO_WritePin(DHT22_GPIO_Port, DHT22_Pin, GPIO_PIN_SET);
  DWT_Delay_us(30);
  gpio_in();

  uint32_t t=0;
  while(HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin)==GPIO_PIN_SET){ if(++t>200) return DHT22_TO_LOW;  DWT_Delay_us(1); }
  t=0; while(HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin)==GPIO_PIN_RESET){ if(++t>200) return DHT22_TO_HIGH; DWT_Delay_us(1); }
  t=0; while(HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin)==GPIO_PIN_SET){ if(++t>200) return DHT22_TO_LOW;  DWT_Delay_us(1); }

  for (int i=0;i<40;i++){
    t=0; while(HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin)==GPIO_PIN_RESET){ if(++t>200) return DHT22_TO_HIGH; DWT_Delay_us(1); }
    uint32_t cnt=0;
    while(HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin)==GPIO_PIN_SET){ if(++cnt>200) return DHT22_TO_LOW; DWT_Delay_us(1); }
    uint8_t bit = (cnt > 40) ? 1 : 0;  // ~70us -> '1', ~26-28us -> '0'
    data[i/8] <<= 1; data[i/8] |= bit;
  }

  if (((uint8_t)(data[0]+data[1]+data[2]+data[3])) != data[4]) return DHT22_BAD_CRC;

  uint16_t rh = (data[0]<<8) | data[1];
  int16_t  tc = (int16_t)((data[2]<<8) | data[3]);

  *h  = rh / 10.0f;
  *tC = (tc & 0x8000) ? -((tc & 0x7FFF)/10.0f) : (tc/10.0f);
  return DHT22_OK;
}

