#ifndef _UART_H
#define _UART_H

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;



extern void MX_USART1_UART_Init(void);


#endif
