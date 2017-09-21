#ifndef __HW_Delay_h
#define __HW_Delay_h 			   

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//ʹ��SysTick����ͨ����ģʽ���ӳٽ��й���
//����delay_us,delay_ms
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.5
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//********************************************************************************	 
void HW_Delay_Init(void);
void HW_Delay_ms(u16 nms);
void HW_Delay_us(u32 nus);


#define _delay_ms HW_Delay_ms
#define _delay_us HW_Delay_us

#endif





























