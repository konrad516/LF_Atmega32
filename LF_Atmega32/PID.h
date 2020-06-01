/*
 * PID.h
 *
 *
 * Author : Konrad
 */ 


#ifndef PID_H_
#define PID_H_

extern int kp;
extern int kd;
extern int V;
extern int e_last, err;

int error();
int PID_calc();

#endif /* PID_H_ */