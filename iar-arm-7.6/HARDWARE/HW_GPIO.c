#include "Hardware.h"

void HW_GPIO_Init_CLK(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	 			//ʹ�ܶ˿�ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
    // �ı�ָ���ܽŵ�ӳ�� GPIO_Remap_SWJ_Disable SWJ ��ȫ���ã�JTAG+SW-DP��
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
    // �ı�ָ���ܽŵ�ӳ�� GPIO_Remap_SWJ_JTAGDisable ��JTAG-DP ���� + SW-DP ʹ��
    
}

//�˴����뽫ʵ��GPIO�Ĺ��ܿ��ƣ�������ʼ�����������ŵ�ƽ�Ͷ�ȡ���ŵ�ƽ��
void HW_GPIO_Init_Out(GPIO_TypeDef * gpio,u16 gpio_pin)			
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = gpio_pin;						//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 	//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		 	//IO���ٶ�Ϊ50MHz
	GPIO_Init(gpio, &GPIO_InitStructure);					//�����趨������ʼ��
}

void HW_GPIO_Init_In(GPIO_TypeDef * gpio,u16 gpio_pin)			
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = gpio_pin;						//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 		//��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;		 	//IO���ٶ�Ϊ50MHz
	GPIO_Init(gpio, &GPIO_InitStructure);					//�����趨������ʼ��
}

void HW_GPIO_Write(GPIO_TypeDef* gpio, uint16_t gpio_pin, u8 val)
{
  if(val==0) gpio->BRR = gpio_pin;else gpio->BSRR = gpio_pin;
}

