#ifndef __HW_EXTI_H
#define __HW_EXTI_H

//##########################��API��##########################
void HW_EXTI_Init(u8 int_portsource,u8 int_pinsource,u32 int_line,EXTITrigger_TypeDef trig); //��ʼ���ⲿ�ж�
void HW_EXTI_Enable(u8 int_channel,u8 preemption_priority,u8 sub_priority);	//ʹ���ж�
void HW_EXTI_Disable(u8 int_channel,u8 preemption_priority,u8 sub_priority);	//�����ж�

#endif
