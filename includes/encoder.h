
#ifndef		__H_FIRMATA_ENCODER__
#define		__H_FIRMATA_ENCODER__

#include	"firmata.h"

#define FIRMATA_ENCODER 0x61

int initialize_encoder(t_firmata *firmata, int encno, int pin1, int pin2);
void get_encoderPos(t_firmata *firmata, int encno);
void getCounter(t_firmata *firmata);

#endif
