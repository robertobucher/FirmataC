
#include	"encoder.h"
#include "serial.h"

#include	<stdlib.h>
#include	<stdio.h>
#include <unistd.h>

#define VERB

static unsigned char attach_msg[] = {0xF0, 0x61, 0x00, 0x00, 0x00, 0x00, 0xF7};
static unsigned char enaReport_msg[] = {0xF0, 0x61, 0x04, 0x01, 0xF7};
static unsigned char reset_msg[] = {0xF0, 0x61, 0x03, 0x00, 0xF7};
static unsigned char getpos_msg[] = {0xF0, 0x61, 0x01, 0x00, 0xF7};

int initialize_encoder(t_firmata *firmata, int encno, int pin1, int pin2)
{
  int res, r;
  
  attach_msg[3] = (unsigned char) encno;
  attach_msg[4] = (unsigned char) pin1;
  attach_msg[5] = (unsigned char) pin2;

  reset_msg[3] = (unsigned char) encno;
  res = serial_write(firmata->serial, attach_msg, 7);
  firmata_pull(firmata);
  res = serial_write(firmata->serial, enaReport_msg, 5);
  firmata_pull(firmata);
  res = serial_write(firmata->serial, reset_msg, 5);
  firmata_pull(firmata);
   return 0;
}

void get_encoderPos(t_firmata *firmata, int encno)
{
  int res, r;
  unsigned char buf[8];
  int counter;
  
  getpos_msg[3] = (unsigned char) encno;
  res = serial_write(firmata->serial, getpos_msg, 5);
  r = serial_waitInput(firmata->serial, 1);
  if(r>0) {
    r = serial_read(firmata->serial, buf, 8);
    firmata_parse(firmata, buf, 8);
  }
}

void getCounter(t_firmata *firmata)
{
int counter;

      counter =  (firmata->parse_buff[3] & 0x7f) +
	((firmata->parse_buff[4] & 0x7F) <<7) +
	((firmata->parse_buff[5] & 0x7F) <<14) +
	((firmata->parse_buff[6] & 0x7F) <<21);
      if(firmata->parse_buff[2]==0) counter = -counter;
      firmata->encoder_counter = counter;
  
/* #ifdef VERB */
/*     for(int i=0;i<8;i++) printf("0x%02x  ",buf[i]); */
/*     printf("\n");     */
/* #endif */
/*     if(buf[1] == 0x61){  */
/*       counter =  (buf[3] & 0x7f) + */
/* 	((buf[4] & 0x7F) <<7) + */
/* 	((buf[5] & 0x7F) <<14) + */
/* 	((buf[6] & 0x7F) <<21); */
/*       if(buf[2]==0) counter = -counter; */
/*       return counter; */
/*     } */
/*   } */
}


  

  
  
