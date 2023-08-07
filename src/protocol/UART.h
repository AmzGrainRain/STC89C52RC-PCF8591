#ifndef _UART_CONTROLLER_H_
#define _UART_CONTROLLER_H_

#include "REG52.H"

void UART_Controller_Init();

void UART_Controller_Send(unsigned char com_data);

#endif
