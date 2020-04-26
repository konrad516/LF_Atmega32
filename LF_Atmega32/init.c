/*
 * init.c
 *
 *
 * Author : Konrad
 */ 

#include "init.h"
#include "IO_cfg.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void init()
{
	//H BRIDGE
	DDRD=0b00111111;
	
	E1_AIN=0; // PORTD &= ~(1<<PD3);
	E1_BIN=0;
	E2_AIN=0;
	E2_BIN=0;
	PWM1=0;
	PWM2=0;
	
	//LEDS
	DDRB=0xF0;
	DDRC=0x0F;
}

void ADC_init()
{
	ADMUX |= (1<<REFS0); //Vol reference: AVCC with external capacitor at AREF pin
	ADMUX |= (1<<ADLAR); //8bit ADCH
	ADCSRA |= (1<<ADEN); //ADC Enable
	ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); //prescaler 128, 16M/128=125k
}

void Timers_init()
{
	//timer 1 - PWM
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1); //fast PWM, non inverting mode
	TCCR1A |= (1<<WGM12) | (1<<WGM10); //fast PWM, 8-bit
	TCCR1B |= (1<<CS10); //no prescaler
	
	//timer 0 - main loop
	TCCR0 |= (1<<WGM01); //ctc mode
	TCCR0 |= (1<<CS02) | (1<<CS00); //preskaler 1024 16M/1024=15625
	OCR0=125; // 15625/125=125, main loop 125Hz
	TIMSK |= (1<<OCIE0); //timer0 compare match interrupt enable
}

void init_all()
{
	sei(); //enable global interrupt
	init();
	ADC_init();
	Timers_init();
}


