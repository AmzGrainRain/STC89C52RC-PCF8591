#include "UART.h"

void UART_Controller_Init()
{
    EA  = 1; // 开总中断
    ES  = 1; // 允许串口中断
    ET1 = 0; // 禁止定时器1中断

    TMOD &= 0x0F; // 清除定时器1模式位
    TMOD |= 0x20; // 设定定时器1为8位自动重装方式

    PCON &= 0x7F; // 波特率不倍速
    SCON = 0x40;  // 8位数据,可变波特率

    TL1 = 0xFD; // 设定定时初值
    TH1 = 0xFD; // 设定定时器重装值
    TR1 = 1;    // 启动定时器1
}

void UART_Controller_Send(unsigned char com_data)
{
    SBUF = com_data;
    while (TI == 0)
        ;
    TI = 0;
}
