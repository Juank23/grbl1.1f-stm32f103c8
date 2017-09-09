#include "Hardware.h"


void HW_PWM_Init(u32 gpio_clk,GPIO_TypeDef * gpio,u16 gpio_pin,u32 pwm_clk,TIM_TypeDef * pwm_timer,float pwm_max_value)		  
{
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;

  RCC_APB1PeriphClockCmd(pwm_clk, ENABLE);					//ʹ�ܶ�ʱ��ʱ��
  RCC_APB2PeriphClockCmd(gpio_clk|RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
 
  GPIO_InitStructure.GPIO_Pin = gpio_pin; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(gpio, &GPIO_InitStructure);//��ʼ��GPIO
 
  //��ʼ��TIM3
  TIM_TimeBaseStructure.TIM_Period = (u32)pwm_max_value; 	
  TIM_TimeBaseStructure.TIM_Prescaler =8;			//�Ķ�Դ�ļ�spindle_control.c��֪��Ƶ��Ϊ8 
  TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
  TIM_TimeBaseInit(pwm_timer, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
  //��ʼ��Channel 1 PWMģʽ	 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
  TIM_OC1Init(pwm_timer, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIMx OC1

  TIM_OC1PreloadConfig(pwm_timer, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
}

void HW_PWM_Write(TIM_TypeDef * pwm_timer,u32 val)
{
  TIM_SetCompare1(pwm_timer,val);
}

void HW_PWM_Disable(TIM_TypeDef * pwm_timer)
{
  TIM_Cmd(pwm_timer, DISABLE); 
}

void HW_PWM_Enable(TIM_TypeDef * pwm_timer)
{
  TIM_Cmd(pwm_timer, ENABLE); 
}

