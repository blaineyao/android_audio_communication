#include "INT4.h"
#include "Mytypedef.h"
#include <intrins.h>
unsigned char int4_status=0;
void init_INT4(void)
{
	P1CR&=~(1<<P1CR0);//P1-0����ģʽ Add New 2015/3/3	P1PCR��ΪP1CR
	P1PCR|=(1<<P1PCR0);//P1-0��������
	EXF0|=(1<<IT41);//�����ش���
	//EXF0|=(1<<IT40);//�½��ش���
	_nop_();
	_nop_();
	_nop_();
}

void INT4_Start(void)
{
	Open_INT4_IRQ;//�����ⲿ�ж�4�ж�
	Open_INT4_0_IRQ;//�����ⲿ�ж�4-0�ж�
}
void INT4_Stop(void)
{
	Close_INT4_IRQ;
	Close_INT4_0_IRQ;
}

void INT4_interrupt(void)interrupt  10
{
	
	if(EXF1&0x01)//ȷ���Ƿ����ⲿ�ж�4-0�����ж�
	{
		EXF1&=~(1<<IF40);//����ⲿ�ж�4-0�жϱ�־λ
		int4_status=1;
	}
}