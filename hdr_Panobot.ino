#include <Arduino.h>

/*
  Turns on an LED on for one second, then off for one second, repeatedly.
*/

int photoPin = 10;
int shutterPin = 11;
int contador = 0;

void setup()
{
	Serial.begin(9600);

	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
	pinMode(photoPin,OUTPUT);
	pinMode(shutterPin,OUTPUT);
}

void exposureTime(int time){

digitalWrite(shutterPin,HIGH);
delay(time);
digitalWrite(shutterPin,LOW);
Serial.println("Foto");

}

void singleShoot(){

digitalWrite(photoPin,HIGH);
delay(50);
digitalWrite(photoPin,LOW);
delay(20);
}

///////////////////////////////////////

void hdrShoot(int fstop){

    for(int x =0;x <fstop;++x){

      exposureTime(200*x);
      singleShoot();
      Serial.println("loop");
    }
}

////////////////////////////////////////////////

void loop(){


    while (contador < 5 ) {
        //singleShoot();
        hdrShoot(5);
        delay(100);
        ++contador;
      }

}






