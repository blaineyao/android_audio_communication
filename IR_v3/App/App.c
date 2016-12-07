#include "App.h"
#include "timer.h"
#include "MyTypedef.h"
#include "LCD.h"
#include "sh77p1651.h"
#include "INT4.h"
#include "Coder.h"
#include "user.h"
#include <intrins.h>

#define	delay_500us_bit			_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_()
#define	delay_1ms_bit			for(i=0;i<1;i++)_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
#define	delay_2ms_bit			for(i=0;i<3;i++)_nop_();_nop_();_nop_();_nop_();_nop_();_nop_()

sbit mic_pin=P1^1;// Add new 2015/3/3

extern unsigned char int4_status;
unsigned char audio_data=0;

void init_sysclock(void);//ʱ�ӳ�ʼ��
void time2_interrupt(void);
void INT4_interrupt(void);
void send_data(unsigned char byte_data);

void system_init(void)
{
	init_sysclock();
	init_timer2();
	init_timer3();
	init_LCD();
	init_INT4();

	P1CR|=(1<<P1CR1);//P1-1���ģʽ

	Open_IRQ;//����ȫ���ж�
	INT4_Start();//�������ⲿ�ж�
}

void init_sysclock(void)//ʱ�ӳ�ʼ��
{
	CLKCON  = (1<<_32K_SPDUP)|(1<<HFON)|(1<<FS)	;  //32.768kHz��������ģʽ�����������Ӳ����1;fSYS= fOSCS;���ڲ�4MHz RC����; ѡ���Ƶʱ��ΪOSCSCLK
	_nop_();
	_nop_();
}

void system_runing(void)//ϵͳ����
{
	unsigned char temp;
	send_data(0x55);
	audio_data=72;
	LCD_Display_Num(0,audio_data/1000);
	LCD_Display_Num(1,audio_data/100%10);
	LCD_Display_Num(2,audio_data/10%10);
	LCD_Display_Num(3,audio_data%10);
	while(1)
	{
		RSTSTAT=RSTSTAT	& (0x78);	
		if(int4_status==1)//�յ�����
		{
			int4_status=0;
			temp=Decoder();//����
			if(temp)//���������
			{
				LCD_Display_Num(0,audio_data/1000);
				LCD_Display_Num(1,audio_data/100%10);
				LCD_Display_Num(2,audio_data/10%10);
				LCD_Display_Num(3,audio_data%10);
				//send_data(audio_data);			
			}	
		}
	}
}

void send_data(unsigned char byte_data)
{
	unsigned char i=0;

	Close_IRQ;

	mic_pin=1;//��ʼλ
	delay_2ms_bit; //2ms	16������
	mic_pin=0;
	delay_500us_bit; //500us	4������
/*
	for(i=0;i<3;i++)
	{
		if(byte_data&0x80)//1
		{ 
			mic_pin=1;
			delay_1ms_bit; //1ms	8������
	   		mic_pin=0;
			delay_500us_bit;
		}
		else//0
		{
			mic_pin=1;
			delay_500us_bit;
			mic_pin=0;
			delay_1ms_bit;					
		}
		byte_data<<=1;
	}
*/ 
///*
	if(byte_data&0x80)//1								0
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1  									1
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1	   						2
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1			  				3
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1				 			4
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1							5
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1				 			6
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;

	if(byte_data&0x80)//1						 7
	{ 
		mic_pin=1;
		delay_1ms_bit; //1ms	8������
	   	mic_pin=0;
		delay_500us_bit;
	}
	else//0
	{
		mic_pin=1;
		delay_500us_bit;
		mic_pin=0;
		delay_1ms_bit;					
	}
	byte_data<<=1;
//*/
	Open_IRQ;
}






