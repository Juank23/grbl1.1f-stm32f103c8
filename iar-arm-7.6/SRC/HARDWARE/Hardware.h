#ifndef __HARDWARE_H
#define __HARDWARE_H


#include "stm32f10x.h"


//#####################����׼�⡿#####################
#include <string.h>	
//#####################���ײ㡿#####################
#include "HW_GPIO.h"	//GPIO
#include "HW_INT.h"	//GPIO
#include "HW_TIM.h"		//��ʱ��
#include "HW_EXTI.h"	//�ⲿ�ж�
#include "HW_PWM.h"		//PWM
#include "HW_EEPROM.h"	//STM32��Flash��EEPROM
#include "HW_USBUART.h"
#include "HW_Delay.h"
#include "stepper_four-phase.h"


#define F_CPU 72000000
#define M_PI  3.14159265358979323846


void Hardware_Init(void);


#endif
