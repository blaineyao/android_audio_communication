#include "timer.h"
#include "Mytypedef.h"
#include "user.h"
//F05F 100ms   ����
//0x0FEB0 10ms  ����
//FFD7 1ms		����
//2.5ms->0x0FFB0   ����
//2ms->	0x0FFC0  ����
#define	value_2ms		0x0FFC0
#define	value_2_5ms		0x0FFB0
#define	value_10ms		0x0FEB0
#define	value_100ms		0x0F05F

#define	timer2_value	time_unit	
#define	TH2_value		(timer2_value>>8)&0xff
#define	TL2_value		timer2_value&0xff
unsigned int timecount2=0;
void init_timer2(void)
{
	T2CON=0;
	T2MOD|=(1<<TLCKP2);//ϵͳʱ����Ϊ��ʱ��2��ʱ��Դ
}
void init_timer3(void)//
{
	//T3CON=(1<<T3CLKS1);
	//T3CON=(1<<TR3);//������ʱ��3
}
void Timer2_Start(void)
{
	TL2=TL2_value;
	TH2=TH2_value;
	RCAP2L=TL2;
	RCAP2H=TH2;
	Open_Timer2_IRQ;
	Start_Timer2;
}
void Timer2_Stop(void)
{
	Close_Timer2_IRQ;
	Close_Timer2;
}
void time2_interrupt(void)interrupt 5
{
	T2CON&=~(1<<TF2);//�����ʱ��2�жϱ�־λ
	timecount2++;	
}