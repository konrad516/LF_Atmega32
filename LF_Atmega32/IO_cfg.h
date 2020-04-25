/*
 * IO_cfg.h
 *
 * Created: 29.03.2020 12:01:04
 *  Author: lunqe
 */ 


#ifndef IO_CFG_H_
#define IO_CFG_H_
#define F_CPU 16000000UL


typedef struct
{
	unsigned int bit0:1;
	unsigned int bit1:1;
	unsigned int bit2:1;
	unsigned int bit3:1;
	unsigned int bit4:1;
	unsigned int bit5:1;
	unsigned int bit6:1;
	unsigned int bit7:1;
} _io_reg;

#define REGISTER_BIT(rg,bt) ((volatile _io_reg*)&rg)->bit##bt

//H BRIDGE

#define E1_AIN		REGISTER_BIT(PORTD,3)
#define E1_BIN		REGISTER_BIT(PORTD,2)
#define E2_AIN		REGISTER_BIT(PORTD,6)
#define E2_BIN		REGISTER_BIT(PORTD,7)

#define PWM1		REGISTER_BIT(PORTD,4)
#define PWM2		REGISTER_BIT(PORTD,5)




#endif /* IO_CFG_H_ */