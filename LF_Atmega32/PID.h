/*
 * PID.h
 *
 * Created: 02.04.2020 18:05:46
 *  Author: lunqe
 */ 


#ifndef PID_H_
#define PID_H_

extern volatile int kp;
extern volatile int kd;
extern volatile int V;
extern int e_last, err;

int error();
int PID_calc();

#endif /* PID_H_ */