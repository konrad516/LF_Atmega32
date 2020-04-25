/*
 * usart.c
 *
 * Created: 07.04.2020 12:25:19
 *  Author: lunqe
 */ 

#include "usart.h"
#include "IO_cfg.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void USART_init()
{
	UCSRB |= (1<<RXEN) | (1<<TXEN) | (1<<RXCIE); //receiver, transmitter, rx interrupt enable
	UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); //data 8bit
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE>>8);
}

void usar_put_char(unsigned char c)
{
	while(!(UCSRA &= (1<<UDRE))){}; //wait for empty buffer
	UDR=c;
}

void usart_put_string(char *pointer)
{
	while (*pointer != 0x00)
	{
		usar_put_char(*pointer);
		pointer++;
	}
}

void usart_send_value(int value)
{
	char buffor[10];
	itoa(value,buffor,10);
	usar_put_char(buffor);
	strcpy(buffor,' ');
}