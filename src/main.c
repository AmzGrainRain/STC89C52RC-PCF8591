#include <STDIO.H>
#include <STDLIB.H>
#include <INTRINS.H>
#include "REG52.H"

#include "include/uart_controller.h"
#include "include/iic_controller.h"
#include "include/PCF8591.h"

void Delay1000ms()		//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
    // Initialize UART serial port
    UART_Controller_Init();
    while (1) {
        unsigned char rd_data;
        rd_data = Convert_To_Voltage(ADC_Read(0x40));
        if (rd_data == 1) {
            UART_Controller_Send('O');
            UART_Controller_Send('N');
            Delay1000ms();
        }
    }
}
