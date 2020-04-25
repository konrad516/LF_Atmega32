/*
 * Set_ADC.h
 *
 * Created: 29.03.2020 17:59:54
 *  Author: lunqe
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