#ifndef __HW_GPIO_H
#define __HW_GPIO_H

#include "hardware.h"
//�˴����뽫ʵ��GPIO�Ĺ��ܿ��ƣ��������������ʼ�����������ŵ�ƽ�Ͷ�ȡ���ŵ�ƽ��

//##############################��API��##############################
void HW_GPIO_Init_CLK(void);
void HW_GPIO_Init_Out(GPIO_TypeDef * gpio,u16 gpio_pin);	
void HW_GPIO_Init_In(GPIO_TypeDef * gpio,u16 gpio_pin);
void HW_GPIO_Write(GPIO_TypeDef * gpio,u16 gpio_pin,u8 val);

#define HW_GPIO_ReadIDR(gpio,gpio_pin) (gpio->IDR & gpio_pin)

#define HW_GPIO_ReadODR(gpio,gpio_pin) (gpio->ODR & gpio_pin)

#endif
