/*
 * Set_ADC.c
 *
 * Created: 29.03.2020 17:13:35
 *  Author: lunqe
 */ 

#include "Set_ADC.h"
#include <avr/io.h>
#include <avr/delay.h>

int sensors[8];
int tab_sensors[8]={7,6,5,4,3,2,1,0};
volatile int point=150;

void read_ADC()
{
	
	for (uint8_t i=0; i<8; i++)
	{
		ADMUX &= 0b11100000; //zero mask
		ADMUX |= tab_sensors[i]; //input channel
		ADCSRA |= (1<<ADSC); //start conversion
		while (ADCSRA & (1<<ADSC)){}; //wait for stop conversion
		if (ADCH>point) sensors[i]=1;
		else sensors[i]=0;
	}
}

void calibration()
{
	int firstCH; //ADC value of 0 channel
	int secondCH;
	
	ADMUX |= 0 & 0b11100000;	//0 channel ADC
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC)){};
	firstCH=ADCH;
	
	ADMUX |= 1 & 0b11100000;	//1 channel ADC
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC)){};
	secondCH=ADCH;
	
	point = (firstCH+secondCH)/2.0;
}

void leds_ADC()
{
	PORTB &= 0xF0;
	PORTC &= 0x0F;
	for (int i=0; i<8; i++)
	{
		if(i<4)
		{
			PORTC |= (sensors[i] << (i+4));
		}
		else
		{
			PORTB |= (sensors[i] << (i-4));
		}
	}
}

void leds_effect()
{
	PORTB &= 0xF0;
	PORTC &= 0x0F;
	for(int i=0; i<3; i++)
	{
		PORTB |= 0x0F;
		PORTC |= 0xF0;
		_delay_ms(200);
		PORTB &= 0xF0;
		PORTC &= 0x0F;
		_delay_ms(200);
		}
}