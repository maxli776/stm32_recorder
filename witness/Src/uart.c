#include "global.h"

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;


/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart->Instance == USART1)
  {
    if(uart1_fifo.bufferInUseFlag == BUFFER_A_IN_USEING)
    {
      uart1_fifo.rxBuf_A[uart1_fifo.BufferIndex] = uart1_fifo.rec;
      uart1_fifo.BufferIndex ++;

      if(uart1_fifo.BufferIndex >= FIFO_RX_MAX_SIZE)
      {
        if(uart1_fifo.bufferFullFlag != BUFFER_A_FULL)
        {
          uart1_fifo.errorCode = FIFO_RES_ERROR_BUFA_OVERRUN;
        }    
        else
        {
          uart1_fifo.bufferFullFlag = BUFFER_A_FULL;
          uart1_fifo.bufferInUseFlag = BUFFER_B_IN_USEING;
          uart1_fifo.BufferIndex = 0;
        }
      }
    }
    else if(uart1_fifo.bufferInUseFlag == BUFFER_A_IN_USEING)
    {
      uart1_fifo.rxBuf_B[uart1_fifo.BufferIndex] = uart1_fifo.rec;
      uart1_fifo.BufferIndex ++;

      if(uart1_fifo.BufferIndex >= FIFO_RX_MAX_SIZE)
      {
        if(uart1_fifo.bufferFullFlag != BUFFER_B_FULL)
        {
          uart1_fifo.errorCode = FIFO_RES_ERROR_BUFB_OVERRUN;
        }    
        else
        {
          uart1_fifo.bufferFullFlag = BUFFER_B_FULL;
          uart1_fifo.bufferInUseFlag = BUFFER_A_IN_USEING;
          uart1_fifo.BufferIndex = 0;
        }
      }
    }
  }
}





