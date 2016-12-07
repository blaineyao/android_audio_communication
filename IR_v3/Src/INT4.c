#include "INT4.h"
#include "Mytypedef.h"
#include <intrins.h>
unsigned char int4_status=0;
void init_INT4(void)
{
	P1CR&=~(1<<P1CR0);//P1-0输入模式 Add New 2015/3/3	P1PCR改为P1CR
	P1PCR|=(1<<P1PCR0);//P1-0上拉电阻
	EXF0|=(1<<IT41);//上升沿触发
	//EXF0|=(1<<IT40);//下降沿触发
	_nop_();
	_nop_();
	_nop_();
}

void INT4_Start(void)
{
	Open_INT4_IRQ;//允许外部中断4中断
	Open_INT4_0_IRQ;//允许外部中断4-0中断
}
void INT4_Stop(void)
{
	Close_INT4_IRQ;
	Close_INT4_0_IRQ;
}

void INT4_interrupt(void)interrupt  10
{
	
	if(EXF1&0x01)//确认是否是外部中断4-0发生中断
	{
		EXF1&=~(1<<IF40);//清除外部中断4-0中断标志位
		int4_status=1;
	}
}