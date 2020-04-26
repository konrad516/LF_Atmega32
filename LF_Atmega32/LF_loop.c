/*
 * LF_loop.c
 *
 *
 * Author : Konrad
 */ 

#include "LF_loop.h"
#include "PWM.h"
#include "Set_ADC.h"
#include "init.h"
#include "IO_cfg.h"
#include "PID.h"


void LF_loop(int start)
{
	if(start)
	{
		read_ADC();
		leds_ADC();
		err=error();
		int value= PID_calc();
		PWM(V + value, V - value);
	}
	else
	{
		stop_engine();
	}
}