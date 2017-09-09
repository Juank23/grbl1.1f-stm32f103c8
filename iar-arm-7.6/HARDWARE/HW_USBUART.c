/**
  ******************************************************************************
  * @file    usbuart.c
  * $Author: tuoqiang
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   USB���⴮�ڽӿں���.
  ******************************************************************************
  */
#include "stm32f10x.h"
#include "usb_desc.h"
#include "usb_lib.h"
#include "hw_config.h"


#include "Hardware.h"


/* Private functions ---------------------------------------------------------*/
/* ��ʼ��USB���⴮�� */
void HW_USB_Init(void){
    Set_System();//ϵͳʱ�ӳ�ʼ��
    USB_Interrupts_Config();
    Set_USBClock();
    USB_Init();
}  


