// A cube of 4*4*4 RGB leds
// By Linuxsmurfen 2019-08-02


// Download https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/tlc5940arduino/Tlc5940_r014_2.zip
// Tools -> 
//    Board: Aurdino/Genuino Uno
//    Port:  /dev/ttyUSB0
//    Programmer: AVRISP mkII




#include "Tlc5940.h"

#define LayerOne 4     //PD4 => D4
#define LayerTwo 5     //PD5 => D5
#define LayerThree 6   //PD6 => D6
#define LayerFour 7    //PD7 => D7


float CubeBrig = 0.10;
float CubeSat = 1.00;
int CubeRes = 2047;

int RedCal = 2048;
int GreenCal = -512;
int BlueCal = 768;

int LayerDuration = 4167;
int layer = 0;
unsigned long oldMicros = 0;

float hueAAone = 0.00;
float hueADone = 0.00;
float hueDAone = 0.00;
float hueDDone = 0.00;

float hueAAfour = 0.00;
float hueADfour = 0.00;
float hueDAfour = 0.00;
float hueDDfour = 0.00;


void setup()
{
  /* Call Tlc.init() to setup the tlc.
     You can optionally pass an initial PWM value (0 - 4095) for all channels.*/
  pinMode(LayerOne, OUTPUT);
  pinMode(LayerTwo, OUTPUT);
  pinMode(LayerThree, OUTPUT);
  pinMode(LayerFour, OUTPUT);
  
  Tlc.init(0);   //sets the inital output level
  
  // LOW enables the layer, use one at the time
  // HIGH disables the layer
  digitalWrite(LayerOne, HIGH);
  digitalWrite(LayerTwo, LOW);
  digitalWrite(LayerThree, HIGH);
  digitalWrite(LayerFour, HIGH);

  Serial.begin(9600);     //setup serial
}

// With three TLC5490, adjust ../Tlc5940/tlc_config.h ==> #define NUM_TLCS    3
// Green 1-4
// Blue 17-20
// Red 33-36

 
void loop(){

  //Tlc.set(1, 0); Tlc.set(2, 500); Tlc.set(3, 1500); Tlc.set(4, 2000);
  //Tlc.set(17, 20); Tlc.set(18, 20); Tlc.set(19, 20); Tlc.set(20, 20);
  //Tlc.set(33, 20); Tlc.set(34, 20); Tlc.set(35, 20); Tlc.set(36, 20);


  
  Tlc.set(1, 0); Tlc.set(2, 500); Tlc.set(3, 0); Tlc.set(4, 500);
  Tlc.update();
  
  for(int i = 1; i <=4; i++){
     //Tlc.set(i, 100);

     //Tlc.update();
     //delay(50);
     
     String SendData = "4,";
     //delay(10);
     //Serial.print (analogRead(1));
     //Serial.print (",");
     //delay(10);
     //Serial.print (analogRead(2));
     //Serial.print (",");
     //delay(10);
     //Serial.print (analogRead(3));
     //Serial.print (",");
     //delay(10);
     //Serial.println (analogRead(4));
   
     SendData = SendData + analogRead(1) + "," + analogRead(2) + "," + analogRead(3) + "," + analogRead(4);   //Layer;A1;A2;A3;A4
     Serial.println(SendData);               // debug value
     
     //Tlc.set(i, 0);
  }
}
