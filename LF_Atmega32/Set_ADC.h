/*
 * Set_ADC.h
 *
 *
 * Author : Konrad
 */ 


#ifndef SET_ADC_H_
#define SET_ADC_H_

#define F_CPU 16000000

extern int sensors[8];
extern volatile int point;

void read_ADC();
void calibration();
void leds_ADC();
void leds_effect();

#endif /* SET_ADC_H_ */