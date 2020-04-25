/*
 * PWM.c
 *
 * Created: 29.03.2020 17:04:11
 *  Author: lunqe
 */ 

#include "PWM.h"
#include "IO_cfg.h"
#include <avr/io.h>


void stop_engine()
{
	E1_AIN=0;
	E1_BIN=0;
	E2_AIN=0;
	E2_BIN=0;
}

void PWM(int left, int right)
{
	if (left>=0)
	{
		if(left>255)left=255;
		E1_AIN=1;
		E1_BIN=0;
	}
	else
	{
		if(left>-255)left=-255;
		E1_AIN=0;
		E1_BIN=1;
	}
	if (right>=0)
	{
		if(right>255)right=255;
		E2_AIN=1;
		E2_BIN=0;
	}
	else
	{
		if(right>-255)right=-255;
		E2_AIN=0;
		E2_BIN=1;
	}
	OCR1A=abs(left);
	OCR1B=abs(right);
}

