/*
 * PID.c
 *
 *
 * Author : Konrad
 */ 

#include "PID.h"
#include "Set_ADC.h"

volatile int kp=5;
volatile int kd=0;
volatile int V=100;

int e_last=0, err=0;

int error()
{
	int e=0;
	int e_last=0;
	int counter=0;
	int sensors_value[8]={-12,-8,-4,-1,1,4,8,12};
		
	for (int i=0; i<8; i++)
	{
		e+=sensors[i]*sensors_value[i];		
		counter += sensors_value[i];		//how many sensors read line
	}
	
	if(counter>0) 
	{
		e=e/counter;	//average error
		e_last = e;	
	}
	else //no sensors on line found
	{
		if(e_last>9) e=20;
		else if (e_last<-9) e=-20;
		else e_last=e;
	}
	return e;
}

int PID_calc()
{
	int u;
	int err_d;
	err_d=err-e_last;
	e_last = err;
	u = kp*err + kd*err_d;
	return u;
}