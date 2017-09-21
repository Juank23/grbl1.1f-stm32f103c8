#include "Hardware.h"

void HW_EXTI_Init(u8 int_portsource,u8 int_pinsource,u32 int_line,EXTITrigger_TypeDef trig)
{
  EXTI_InitTypeDef EXTI_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

  //�ж����Լ��жϳ�ʼ������
  GPIO_EXTILineConfig(int_portsource,int_pinsource);

  EXTI_InitStructure.EXTI_Line = int_line;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = trig;			
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	 					//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
 	
}

void HW_EXTI_Enable(u8 int_channel,u8 preemption_priority,u8 sub_priority)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = int_channel;							//ʹ���ⲿ�ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = preemption_priority;	//��ռ���ȼ� 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = sub_priority;				//�����ȼ�
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);	
}

void HW_EXTI_Disable(u8 int_channel,u8 preemption_priority,u8 sub_priority)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = int_channel;							//ʹ���ⲿ�ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = preemption_priority;	//��ռ���ȼ� 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = sub_priority;				//�����ȼ�
  NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;							//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);		
}



