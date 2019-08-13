/**
  ******************************************************************************
  * @file   fatfs.c
  * @brief  Code for fatfs applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include "fatfs.h"

SD_HandleTypeDef hsd;
DMA_HandleTypeDef hdma_sdio_rx;
DMA_HandleTypeDef hdma_sdio_tx;

uint8_t retSD;    /* Return value for SD */
char SDPath[4];   /* SD logical drive path */
FATFS SDFatFS;    /* File system object for SD logical drive */
FIL SDFile;       /* File object for SD */
static uint8_t buffer[_MAX_SS]; /* a work buffer for the f_mkfs() */

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */    

void MX_FATFS_Init(void) 
{
  FRESULT res;
  uint32_t byteswritten, bytesread;                     /* File write/read counts */
  uint8_t wtext[] = "This is STM32 working with FatFs";
  
  /*## FatFS: Link the SD driver ###########################*/
  if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
  {
    if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) != FR_OK)
    {
      /* FatFs Initialization Error */
      Error_Handler();
    }
    else
    {
      /*##-3- Create a FAT file system (format) on the logical drive #########*/
      /* WARNING: Formatting the uSD card will delete all content on the device */
      if((res = f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, buffer, sizeof(buffer))) != FR_OK)
      {
        /* FatFs Format Error */
        Error_Handler();
      }
      else
      { 
#if 0
        /*##-4- Create and Open a new text file object with write access #####*/
        if(f_open(&SDFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
        {
          /* 'STM32.TXT' file Open for write Error */
          Error_Handler();
        }
        else
        {
          /*##-5- Write data to the text file ################################*/
          res = f_write(&SDFile, wtext, sizeof(wtext), (void *)&byteswritten);
          
          if((byteswritten == 0) || (res != FR_OK))
          {
            /* 'STM32.TXT' file Write or EOF Error */
            Error_Handler();
          }
          else
          {
            /*##-6- Close the open text file #################################*/
            f_close(&SDFile);
          }
        }
#endif
      }
    }
  }
  
  /*##-11- Unlink the RAM disk I/O driver ####################################*/
  //FATFS_UnLinkDriver(SDPath);

  /* USER CODE BEGIN Init */
  /* additional user code for init */     
  /* USER CODE END Init */
}

/**
  * @brief  Gets Time from RTC 
  * @param  None
  * @retval Time in DWORD
  */
DWORD get_fattime(void)
{
  /* USER CODE BEGIN get_fattime */
  return 0;
  /* USER CODE END get_fattime */  
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
