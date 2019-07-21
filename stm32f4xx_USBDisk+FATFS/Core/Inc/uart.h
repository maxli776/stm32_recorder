#ifndef UART_H
#define UART_H


#include "stm32f4xx_hal.h"

typedef struct
{
  unsigned int UsbDetectFlag;
}UartProcessHandle_TypeDef;


extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef  hdma_usart1_rx;
extern DMA_HandleTypeDef  hdma_usart1_tx;
extern UartProcessHandle_TypeDef UartHandle;

extern void MX_USART1_UART_Init(void);
extern void MX_DMA_Init(void);


#endif
