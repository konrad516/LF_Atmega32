/*
 * usart.h
 *
 * Created: 07.04.2020 12:25:29
 *  Author: lunqe
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000
void USART_init();
void usart_put_char(unsigned char c);
void usart_put_string(char *pointer);
void usart_send_value(int value);


#endif /* USART_H_ */