#ifndef UART_H
#define UART_H


#include "stm32f4xx_hal.h"

#define UART_RX_BUFFER_SIZE   1024


typedef struct
{
  unsigned int UsbDetectFlag;
  unsigned char UartRxData;
  unsigned char UartRxBuffer[UART_RX_BUFFER_SIZE];
  unsigned int UartRxBuffer_DockerIndex;
  unsigned int UartRxBuffer_ProcessorIndex;
  unsigned int UartRx_UnprocessedCount;
  unsigned int OverRunFlag;
  unsigned int OverRunCount;
}UartProcessHandle_TypeDef;


extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef  hdma_usart1_rx;
extern DMA_HandleTypeDef  hdma_usart1_tx;
extern UartProcessHandle_TypeDef UartHandle;

extern void MX_USART1_UART_Init(void);
extern void MX_DMA_Init(void);


#endif
