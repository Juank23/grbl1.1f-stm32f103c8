#ifndef __HW_TIM_H
#define __HW_TIM_H


//##############################��API��##############################
void HW_TIM_Init(void);				//��ʱ����ʼ����Ҫ������stepper.c�е�st_init()
//Driver Interrupt
void HW_TIM_DriverInterrupt_Enable(void); 		//������ʱ��
void HW_TIM_DriverInterrupt_Disable(void);		//�رն�ʱ��
void HW_TIM_DriverInterrupt_ValueConfig(uint16_t Prescaler,uint16_t Autoreload);		//���ö�ʱ����װֵ
//Port Reset Interrupt
void HW_TIM_PortResetInterrupt_Enable(void);  	//������ʱ��
void HW_TIM_PortResetInterrupt_Disable(void);	//�رն�ʱ��
void HW_TIM_PortResetInterrupt_ValueConfig(uint16_t Prescaler,uint16_t Autoreload); 	//���ö�ʱ����װֵ
//Debounce
void HW_Debounce_Init(void);		//ȥ����ʱ��
void HW_Debounce_Enable(void);		//ʹ��ȥ����ʱ��
void HW_Debounce_Disable(void);		//����ȥ����ʱ��


#endif
