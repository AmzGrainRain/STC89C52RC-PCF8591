#include "UART.h"

void UART_Controller_Init()
{
    PCON &= 0x7F; // �����ʲ�����
    SCON = 0x40;  // 8λ����,�ɱ䲨����
    TMOD &= 0x0F; // �����ʱ��1ģʽλ
    TMOD |= 0x20; // �趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
    TL1 = 0xFD;   // �趨��ʱ��ֵ
    TH1 = 0xFD;   // �趨��ʱ����װֵ
    TR1 = 1;      // ������ʱ��1
    ET1 = 0;      // ��ֹ��ʱ��1�ж�
}

void UART_Controller_Send(unsigned char com_data)
{
    SBUF = com_data;
    while (TI == 0)
        ;
    TI = 0;
}
