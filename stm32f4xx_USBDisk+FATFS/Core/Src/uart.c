#include "uart.h"

UartHandle_TypeDef UartHandle;

void UartInit(UartHandle_TypeDef *uHandle)
{
  uHandle->UsbDetectFlag = 0;
}


