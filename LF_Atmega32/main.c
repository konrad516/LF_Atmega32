/*
 * LF_Atmega32.c
 *
 * Created: 29.03.2020 10:47:34
 * Author : lunqe
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include "IO_cfg.h"
#include "init.h"
#include "Set_ADC.h"
#include "PWM.h"
#include "PID.h"
#include "LF_loop.h"
#include "usart.h"

volatile int synch_timer = 0, start=0;

int main(void)
{
		init_all();
		USART_init();
		
		while(1)
		{
			if(synch_timer)
			{
				synch_timer=0;
				LF_loop(start);
			}
		}
}


ISR(TIMER0_COMP_vect)
{
	synch_timer=1;
}

ISR(USART_RXC_vect)
{
	char data;
	data = UDR;
	UDR = data;
	
	switch(data)
	{
		case '1':
		start ^=1;
		break;
		
		case '2':
		calibration();
		usart_put_string("\nSensors point: ");
		usart_send_value(point);
		leds_effect();
		break;
		
		case '3':
		kp+=1;
		usart_put_string("\nKp: ");
		usart_send_value(kp);
		break;
		
		case '4':
		kp-=1;
		usart_put_string("\nKp: ");
		usart_send_value(kp);
		break;
		
		case '5':
		kd+=1;
		usart_put_string("\nKd: ");
		usart_send_value(kd);
		break;
		
		case '6':
		kd-=1;
		usart_put_string("\nKd: ");
		usart_send_value(kd);
		break;
		
		case '7':
		V+=5;
		usart_put_string("\nV: ");
		usart_send_value(V);
		break;
		
		case '8':
		V-=5;
		usart_put_string("\nV: ");
		usart_send_value(V);
		break;
		
		
	}
	
}
