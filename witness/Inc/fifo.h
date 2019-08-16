#ifndef _FIFO_H
#define _FIFO_H


#define FIFO_RX_MAX_SIZE  4096

enum
{
  BUFFER_A_IN_USEING,
  BUFFER_B_IN_USEING
};

enum
{
  BUFFER_NONE_FULL,
  BUFFER_A_FULL,
  BUFFER_B_FULL
};

enum
{
  FIFO_RES_OK,
  FIFO_RES_ERROR_BUFA_OVERRUN,
  FIFO_RES_ERROR_BUFB_OVERRUN,
  FIFO_RES_ERROR_HARDWARE_FAULT
};


typedef struct
{
  unsigned char rec;
  unsigned char rxBuf_A[FIFO_RX_MAX_SIZE];
  unsigned char rxBuf_B[FIFO_RX_MAX_SIZE];
  unsigned char bufferInUseFlag;
  unsigned char bufferFullFlag;
  unsigned int BufferIndex;
  unsigned int errorCode;
}FIFO_Handle_TypeDef;



extern FIFO_Handle_TypeDef uart1_fifo;

#endif
