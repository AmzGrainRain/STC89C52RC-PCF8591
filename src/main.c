#include <STDIO.H>
#include <STDLIB.H>
#include <STRING.H>
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
        // unsigned char voltage = Convert_To_Voltage(ADC_Read(0x41));
        unsigned char voltage = ADC_Read(0x41);

        if (voltage <= 0xE2) {
		    UART_Controller_Send('M');
		    UART_Controller_Send('o');
		    UART_Controller_Send('v');
		    UART_Controller_Send('e');
		    UART_Controller_Send(' ');
		    UART_Controller_Send('o');
		    UART_Controller_Send('u');
		    UART_Controller_Send('t');
		    UART_Controller_Send(' ');
		    UART_Controller_Send('y');
		    UART_Controller_Send('o');
		    UART_Controller_Send('u');
		    UART_Controller_Send('r');
		    UART_Controller_Send(' ');
		    UART_Controller_Send('h');
		    UART_Controller_Send('a');
		    UART_Controller_Send('n');
		    UART_Controller_Send('d');
		    UART_Controller_Send('s');
		    UART_Controller_Send('.');
            Delay1000ms();
        }

		P02 = voltage > 0xE2 ? 1 : 0;
    }
}
