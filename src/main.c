#include <STDIO.H>
#include <STDLIB.H>
#include <INTRINS.H>
#include "REG52.H"

#include "protocol/UART.h"
#include "protocol/IIC.h"
#include "chip/PCF8591.h"

sbit P02 = P0 ^ 2;

void Delay1000ms() //@11.0592MHz
{
    unsigned char data i, j, k;

    _nop_();
    i = 8;
    j = 1;
    k = 243;
    do {
        do {
            while (--k)
                ;
        } while (--j);
    } while (--i);
}

void main()
{
    // Initialize UART serial port
    UART_Controller_Init();
    while (1) {
        unsigned char voltage = Convert_To_Voltage(ADC_Read(0x40));
		UART_Controller_Send(voltage);

		P02 = voltage <= 2 ? 1 : 0;
    }
}
