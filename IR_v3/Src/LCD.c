#include "LCD.h"
#include "Mytypedef.h"
pdata unsigned char addr[30] _at_ 0x00;		  //LCDdisplay ram
unsigned char Code_Num[11]={0x5f,0x50,0x3d,0x79,0x72,0x6b,0x6f,0x51,0x7f,0x7b,0x00};//0,1,2,3,4,5,6,7,8,9,_
void init_LCD(void)
{
	LCDCON		=	0xCf;  // ����LCD������; ����LCD PUMP ;	1/4ռ�ձȣ�1/3ƫ�ã�P4.5��ΪSegment����I/O ; ѡ���ڽ���ѹ�ȶ�����LCD������ʽ;VLCD=1.000 VDD
	LCDCON1		=	0x06;  //  1/4 LCD com����;	LCDƫ�õ����ܺ�Ϊ990k; ���ٳ��ģʽ��ƫ�õ����ܺ��Զ���60k��450k/990k֮���л� 
	P3SS		|=	0xE0;  // P3.7-P3.5��ΪSegment��SEG24 �C SEG22��
	P4SS		|=	0xFF;  // P4.7-P4.6��ΪCommon��COM3 �C COM4��,P4.5-P4.0��ΪSegment��SEG30 �CSEG25��
	P5SS		|=	0x03;  // P5.1-P5.0��ΪCommon��COM1 �C COM2��	
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