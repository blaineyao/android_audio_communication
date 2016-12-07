#ifndef _MYTYPEDEF_H
#define _MYTYPEDEF_H
#define Open_IRQ			IEN0|=(1<<EA)
#define	Close_IRQ			IEN0&=~(1<<EA)
#define	Open_Timer2_IRQ		IEN0|=(1<<ET2)
#define	Close_Timer2_IRQ	IEN0&=~(1<<ET2)
#define	Open_INT4_IRQ		IEN1|=(1<<EX4)
#define	Close_INT4_IRQ		IEN1&=~(1<<EX4)
#define	Open_INT4_7_IRQ		IENC|=(1<<EXS47)

#define	Close_INT4_7_IRQ	IENC&=~(1<<EXS47)
#define	Open_INT4_6_IRQ		IENC|=(1<<EXS46)
#define	Close_INT4_6_IRQ	IENC&=~(1<<EXS46)
#define	Open_INT4_5_IRQ		IENC|=(1<<EXS45)
#define	Close_INT4_5_IRQ	IENC&=~(1<<EXS45)
#define	Open_INT4_4_IRQ		IENC|=(1<<EXS44)
#define	Close_INT4_4_IRQ	IENC&=~(1<<EXS44)
#define	Open_INT4_3_IRQ		IENC|=(1<<EXS43)
#define	Close_INT4_3_IRQ	IENC&=~(1<<EXS43)
#define	Open_INT4_2_IRQ		IENC|=(1<<EXS42)
#define	Close_INT4_2_IRQ	IENC&=~(1<<EXS42)
#define	Open_INT4_1_IRQ		IENC|=(1<<EXS41)
#define	Close_INT4_1_IRQ	IENC&=~(1<<EXS41)
#define	Open_INT4_0_IRQ		IENC|=(1<<EXS40)
#define	Close_INT4_0_IRQ	IENC&=~(1<<EXS40)
	
#define	Start_Timer2		T2CON|=(1<<TR2)
#define	Close_Timer2		T2CON&=~(1<<TR2)
/*-CLKCON-0xB2-*/
#define _32K_SPDUP 	7
#define CLKS1		6
#define CLKS0		5
#define SCMIF		4	
#define HFON		3
#define FS			2
/*-P0CR-*/
#define P0CR7		7
#define P0CR6		6
#define P0CR5		5
#define P0CR4		4
#define P0CR3		3
#define P0CR2		2
#define P0CR1		1
#define P0CR0		0
/*-P1CR-*/
#define P1CR7		7
#define P1CR6		6
#define P1CR5		5
#define P1CR4		4
#define P1CR3		3
#define P1CR2		2
#define P1CR1		1
#define P1CR0		0
/*-P2CR-*/
#define P2CR7		7
#define P2CR6		6
#define P2CR5		5
#define P2CR4		4
#define P2CR3		3
#define P2CR2		2
#define P2CR1		1
#define P2CR0		0
/*-P3CR-*/
#define P3CR7		7
#define P3CR6		6
#define P3CR5		5
#define P3CR4		4
#define P3CR3		3
#define P3CR2		2
#define P3CR1		1
#define P3CR0		0	
/*-P4CR-*/
#define P4CR7		7
#define P4CR6		6
#define P4CR5		5
#define P4CR4		4
#define P4CR3		3
#define P4CR2		2
#define P4CR1		1
#define P4CR0		0
/*-P5CR-*/
#define P5CR5		5
#define P5CR4		4
#define P5CR3		3
#define P5CR2		2
#define P5CR1		1
#define P5CR0		0
/*-P0PCR-*/
#define P0PCR7		7
#define P0PCR6		6
#define P0PCR5		5
#define P0PCR4		4
#define P0PCR3		3
#define P0PCR2		2
#define P0PCR1		1
#define P0PCR0		0
/*-P1PCR-*/
#define P1PCR7		7
#define P1PCR6		6
#define P1PCR5		5
#define P1PCR4		4
#define P1PCR3		3
#define P1PCR2		2
#define P1PCR1		1
#define P1PCR0		0
/*-P2PCR-*/
#define P2PCR7		7
#define P2PCR6		6
#define P2PCR5		5
#define P2PCR4		4
#define P2PCR3		3
#define P2PCR2		2
#define P2PCR1		1
#define P2PCR0		0
/*-P3PCR-*/
#define P3PCR7		7
#define P3PCR6		6
#define P3PCR5		5
#define P3PCR4		4
#define P3PCR3		3
#define P3PCR2		2
#define P3PCR1		1
#define P3PCR0		0
/*-P4PCR-*/
#define P4PCR7		7
#define P4PCR6		6
#define P4PCR5		5
#define P4PCR4		4
#define P4PCR3		3
#define P4PCR2		2
#define P4PCR1		1
#define P4PCR0		0
/*-P5PCR-*/
#define P5PCR5		5
#define P5PCR4		4
#define P5PCR3		3
#define P5PCR2		2
#define P5PCR1		1
#define P5PCR0		0
/*-LCDON-0xABH-*/
#define LCDON		7
#define	PUMPON		6
#define	DUTY		4
#define	TYPESEL		3
#define	VOL2		2
#define	VOL1		1
#define	VOL0		0
/*-LCDON-0xAAH-*/
#define	FCCTL1		5
#define	FCCTL0		4
#define RLCD		2
#define	MOD1		1
#define	MOD0		0
/*-IEN0-*/
#define EA			7
#define EADC		6
#define	ET2			5
#define	ES			4
/*-IEN1-*/
#define ESCM		7
#define EPMW1		6
#define	ET3			4
#define EX4			3
#define	EREM		1
/*-IENC-*/
#define EXS47		7
#define EXS46		6
#define EXS45		5
#define EXS44		4
#define EXS43		3
#define EXS42		2
#define EXS41		1
#define EXS40		0
/*-EXF0-*/
#define	IT41		7
#define	IT40		6
/*-EXF1-*/
#define	IF47		7
#define	IF46		6
#define	IF45		5
#define	IF44		4
#define	IF43		3
#define	IF42		2
#define	IF41		1
#define	IF40		0
/*-T3CON-*/
#define	TF3			7
#define	T3PS1		5
#define	T3PS0		4
#define	TR3			2
#define	T3CLKS1		1
#define	T3CLKS0		0
/*-T2CON-*/
#define	TF2			7
#define	EXF2		6
#define	EXEN2		3
#define	TR2			2
#define	C/T2		1
#define	CP/RL2		0
/*-T2MOD-*/
#define	TLCKP2		7
#define T2OE		1
#define	DCEN		0
#endif