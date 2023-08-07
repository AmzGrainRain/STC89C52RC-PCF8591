#ifndef _PCF8591_H_
#define _PCF8591_H_

#include "../protocol/IIC.h"

unsigned char Convert_To_Voltage(unsigned char original);

unsigned char ADC_Read(unsigned char com);

#endif
