#ifndef _TIMER_H
#define _TIMER_H
#include "sh77p1651.h"
void init_timer2(void);//初始化定时器2
void init_timer3(void);//初始化定时器3
void Timer2_Start(void);
void Timer2_Stop(void);
void time2_interrupt(void);
#endif