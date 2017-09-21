/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different
   processor types or alternative pin layouts. This version of Grbl officially supports
   only the Arduino Mega328p. */


#ifndef cpu_map_h
#define cpu_map_h

/****************************************************************************/
  // Define step pulse output pins. NOTE: All step bit pins must be on the same port.
  //���岽������������š�ע�����еĲ����������ű��붨����ͬһ���˿��ϡ�
  #define STEP_GPIO				GPIOB					//�˿�
  #define X_STEP_GPIO_PIN			GPIO_Pin_0				//����
  #define Y_STEP_GPIO_PIN			GPIO_Pin_1			   	//����
  #define Z_STEP_GPIO_PIN			GPIO_Pin_2				//����

//ԭƽ̨���䣬�ɲ����޸ġ�
  #define X_STEP_BIT      			2  
  #define Y_STEP_BIT      			3  
  #define Z_STEP_BIT      			4  
  #define STEP_MASK       			((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) 

  // Define step direction output pins. NOTE: All direction pins must be on the same port.
//���巽���ƽ������š�ע�����еķ������ű��붨����ͬһ���˿��ϡ�
  #define DIRECTION_GPIO			GPIOB					//�˿�
  #define X_DIRECTION_GPIO_PIN			GPIO_Pin_3				//����
  #define Y_DIRECTION_GPIO_PIN			GPIO_Pin_4			   	//����
  #define Z_DIRECTION_GPIO_PIN			GPIO_Pin_5				//����

//ԭƽ̨���䣬�ɲ����޸ġ�
  #define X_DIRECTION_BIT   			5  
  #define Y_DIRECTION_BIT   			6  
  #define Z_DIRECTION_BIT   			7  
  #define DIRECTION_MASK    			((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT))

  // Define stepper driver enable/disable output pin.
  //���岽�����������ʹ������
  #define STEPPERS_DISABLE_GPIO   		GPIOA					//�˿�
  #define STEPPERS_DISABLE_GPIO_PIN		GPIO_Pin_3				//����
//ԭƽ̨���䣬�ɲ����޸ġ�
  #define STEPPERS_DISABLE_BIT    		0  
  #define STEPPERS_DISABLE_MASK   		(1<<STEPPERS_DISABLE_BIT)
/****************************************************************************/
  // Define homing/hard limit switch input pins and limit interrupt vectors.
  // NOTE: All limit bit pins must be on the same port, but not on a port with other input pins (CONTROL).
  //����ԭ��/Ӳ��λ�����������ź���λ�ж�����
//ע�⣺���е���λ���ű���ʹ��ͬһ���жϴ�������
  #define LIMIT_GPIO				GPIOA					//�˿�
  #define X_LIMIT_GPIO_PIN			GPIO_Pin_10				//����
  #define Y_LIMIT_GPIO_PIN			GPIO_Pin_13			   	//����
  #define Z_LIMIT_GPIO_PIN			GPIO_Pin_14				//����

  #define LIMIT_INT_PORTSOURCE 		        GPIO_PortSourceGPIOA 	//�ж�Դ�˿�
  #define X_LIMIT_INT_PINSOURCE		        GPIO_PinSource10	   	//�ж�Դ����
  #define Y_LIMIT_INT_PINSOURCE		        GPIO_PinSource13		//�ж�Դ����
  #define Z_LIMIT_INT_PINSOURCE		        GPIO_PinSource14		//�ж�Դ����
  #define X_LIMIT_INT_LINE			EXTI_Line10				//�ж���
  #define Y_LIMIT_INT_LINE			EXTI_Line13				//�ж���
  #define Z_LIMIT_INT_LINE			EXTI_Line14				//�ж���

  #define LIMIT_INT_CHANNEL			EXTI15_10_IRQn			//�ж�����ͨ��
//ע�⣺�жϴ��������ڴ������޸�
//ԭƽ̨���䣬�ɲ����޸ġ�
  #define X_LIMIT_BIT                           1
  #define Y_LIMIT_BIT                           2
  #define Z_LIMIT_BIT    	                3
  #define LIMIT_MASK                            ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits
/****************************************************************************/
  // Define spindle enable and spindle direction output pins.
  //��������ʹ���������
  #define SPINDLE_ENABLE_GPIO   		GPIOA					//�˿�
  #define SPINDLE_ENABLE_GPIO_PIN		GPIO_Pin_1				//����
//�������᷽���������
  #define SPINDLE_DIRECTION_GPIO   		GPIOA					//�˿�
  #define SPINDLE_DIRECTION_GPIO_PIN		GPIO_Pin_2				//����// Z Limit pin and spindle PWM/enable pin swapped to access hardware PWM on Pin 11.

//����PWM��������
  #ifdef VARIABLE_SPINDLE 
    #define SPINDLE_PWM_GPIO   		        GPIOA					//�˿�
    #define SPINDLE_PWM_GPIO_PIN		GPIO_Pin_0				//����
  
    #define PWM_MAX_VALUE       		65535.0					//PWM�������ֵ
//�Ķ�Դ�ļ�spindle_control.c��֪PWM���ֵΪ0xffff��65535��

    #define PWM_TIMER				TIM2					//PWM����ʱ��
    #define PWM_CLK 				RCC_APB1Periph_TIM2		//����ʱ��
  //ע�⣺OC1Init()��TIM_OC1PreloadConfig()���ض�ͨ���������ڴ������޸�

  #endif // End of VARIABLE_SPINDLE

/****************************************************************************/
  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_GPIO   		        GPIOB					//�˿�
  #define COOLANT_FLOOD_GPIO_PIN	        GPIO_Pin_6				//����
  #define COOLANT_MIST_GPIO   		        GPIOB					//�˿�
  #define COOLANT_MIST_GPIO_PIN		        GPIO_Pin_7				//����
/****************************************************************************/
  // Define user-control controls (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
//�����û����ƣ�ѭ����ʼ����λ���������֣���������
//ע�⣺���е���λ���ű���ʹ��ͬһ���жϴ�������
  #define CONTROL_GPIO			        GPIOA					//�˿�
  #define RESET_GPIO_PIN			GPIO_Pin_5				//����
  #define FEED_HOLD_GPIO_PIN			GPIO_Pin_6			   	//����
  #define CYCLE_START_GPIO_PIN		        GPIO_Pin_7				//����
  #define SAFETY_DOOR_GPIO_PIN		        GPIO_Pin_8				//����

  #define CONTROL_INT_PORTSOURCE 		GPIO_PortSourceGPIOA 	//�ж�Դ�˿�
  #define RESET_INT_PINSOURCE		        GPIO_PinSource5			//�ж�Դ���ţ���λ
  #define FEED_HOLD_INT_PINSOURCE		GPIO_PinSource6			//�ж�Դ���ţ���������
  #define CYCLE_START_INT_PINSOURCE	        GPIO_PinSource7			//�ж�Դ���ţ�ѭ����ʼ
  #define SAFETY_DOOR_INT_PINSOURCE	        GPIO_PinSource8			//�ж�Դ���ţ�����ͣ��
  #define RESET_INT_LINE			EXTI_Line5				//�ж��ߣ���λ
  #define FEED_HOLD_INT_LINE		        EXTI_Line6				//�ж��ߣ���������
  #define CYCLE_START_INT_LINE		        EXTI_Line7				//�ж��ߣ�ѭ����ʼ
  #define SAFETY_DOOR_INT_LINE		        EXTI_Line8				//�ж��ߣ�����ͣ��

  #define CONTROL_INT_CHANNEL		        EXTI9_5_IRQn			//�ж�����ͨ��
//ע�⣺�жϴ��������ڴ������޸�

//ԭƽ̨���䣬�ɲ����޸ġ�
  #define CONTROL_RESET_BIT                     0  // Uno Analog Pin 0
  #define CONTROL_FEED_HOLD_BIT                 1  // Uno Analog Pin 1
  #define CONTROL_CYCLE_START_BIT               2  // Uno Analog Pin 2
  #define CONTROL_SAFETY_DOOR_BIT               3  //tq2017  Uno Analog Pin 1 NOTE: Safety door is shared with feed hold. Enabled by config define.
  #define CONTROL_MASK                          ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))
  #define CONTROL_INVERT_MASK                   CONTROL_MASK // May be re-defined to only invert certain control pins.
/****************************************************************************/
  // Define probe switch input pin.
  //����̽�⿪����������
  #define PROBE_GPIO   		                GPIOA					//�˿�
  #define PROBE_GPIO_PIN		        GPIO_Pin_4				//����

/****************************************************************************/
  // Variable spindle configuration below. Do not change unless you know what you are doing.
  // NOTE: Only used when variable spindle is enabled.
  #define SPINDLE_PWM_MAX_VALUE                 255 // Don't change. 328p fast PWM mode fixes top value as 255.
  #ifndef SPINDLE_PWM_MIN_VALUE
    #define SPINDLE_PWM_MIN_VALUE               1   // Must be greater than zero.
  #endif
  #define SPINDLE_PWM_OFF_VALUE                 0
  #define SPINDLE_PWM_RANGE                     (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

#endif
