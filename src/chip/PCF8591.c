#include "PCF8591.h"

unsigned char Convert_To_Voltage(unsigned char original)
{
    return (unsigned char)(original * 5 / 256.0 + 0.0005);
}

// Photosensitive sensor: 0x40
// Temperature sensor: 0x41
// Potential sensor: 0x43
unsigned char ADC_Read(unsigned char com)
{
    unsigned char i = 0, com_data = 0;

begin:
    // Establish communication with PCF8591 chip (ADC Mode)
    IIC_Controller_Start();
    IIC_Controller_Write(WRITE_MODE);
    if (IIC_Controller_Read_ACK()) {
        if (++i == 255) {
            return i;
        }
        IIC_Controller_Stop();
        goto begin;
    }

    // Set communication port
    IIC_Controller_Write(com);
    if (IIC_Controller_Read_ACK()) {
        IIC_Controller_Stop();
        goto begin;
    }

    // Set the 89C52RC chip to slave mode (receive data)
    IIC_Controller_Start();
    IIC_Controller_Write(READ_MODE);
    if (IIC_Controller_Read_ACK()) {
        IIC_Controller_Stop();
        goto begin;
    }

    com_data = IIC_Controller_Read();
    // Do not reply the ACK singal
    IIC_Controller_Write_ACK(1);
    IIC_Controller_Stop();

    return com_data;
}
