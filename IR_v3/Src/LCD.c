#include "LCD.h"
#include "Mytypedef.h"
pdata unsigned char addr[30] _at_ 0x00;		  //LCDdisplay ram
unsigned char Code_Num[11]={0x5f,0x50,0x3d,0x79,0x72,0x6b,0x6f,0x51,0x7f,0x7b,0x00};//0,1,2,3,4,5,6,7,8,9,_
void init_LCD(void)
{
	LCDCON		=	0xCf;  // 允许LCD驱动器; 允许LCD PUMP ;	1/4占空比，1/3偏置，P4.5作为Segment或者I/O ; 选择内建电压稳定器型LCD驱动方式;VLCD=1.000 VDD
	LCDCON1		=	0x06;  //  1/4 LCD com周期;	LCD偏置电阻总和为990k; 快速充电模式，偏置电阻总和自动在60k和450k/990k之间切换 
	P3SS		|=	0xE0;  // P3.7-P3.5作为Segment（SEG24 – SEG22）
	P4SS		|=	0xFF;  // P4.7-P4.6作为Common（COM3 – COM4）,P4.5-P4.0作为Segment（SEG30 –SEG25）
	P5SS		|=	0x03;  // P5.1-P5.0作为Common（COM1 – COM2）	
}

void LCD_Display_Num(unsigned char position,unsigned char Data)
{
	XPAGE=1;
	if(position==0||position==1)
	{
		addr[21+2*position]=Code_Num[Data]&0x0f;
		addr[22+2*position]=(Code_Num[Data]>>4)&0x0f;
	}
	else if(position==2||position==3)
	{
		addr[21+2*position+1]=Code_Num[Data]&0x0f;
		addr[22+2*position+1]=(Code_Num[Data]>>4)&0x0f;		
	}
	XPAGE=0;
}