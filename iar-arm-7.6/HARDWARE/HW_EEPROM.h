#ifndef __HW_EEPROM_h
#define __HW_EEPROM_h

//##############################��API��##############################
void HW_EEPROM_Init(void);			//EEPROM��ʼ��

unsigned char HW_EEPROM_getChar(unsigned int addr);				   //EEPROM��ȡһ��u8����
void HW_EEPROM_putChar(unsigned int addr,unsigned char new_value); //EEPROMд��һ��u8����

#endif
