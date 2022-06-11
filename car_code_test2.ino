/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.7 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.10.2 or later version;
     - for iOS 1.8.2 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,5,0,0,0,53,0,15,152,0,
  1,0,17,14,16,16,40,31,0,1,
  0,30,25,16,16,40,31,0,1,0,
  5,25,16,16,40,31,0,1,0,17,
  37,16,16,54,31,0,2,0,58,21,
  30,20,54,53,31,31,76,0,66,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t button_3; // =1 if button pressed, else =0 
  uint8_t button_4; // =1 if button pressed, else =0 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#define in1 3
#define in2 4
#define in3 5
#define in4 6
#define sensorR 7
#define sensorL 8
#define trig 12
#define echo 11
int sr = 0;
int sl = 0;
char readin;
long duration,distance;



void setup() 
{
  RemoteXY_Init (); 
 pinMode(in1,OUTPUT); 
 pinMode(in2,OUTPUT); 
 pinMode(in3,OUTPUT); 
 pinMode(in4,OUTPUT); 
 pinMode(trig,OUTPUT); 
 pinMode(sensorR,INPUT); 
 pinMode(sensorL,INPUT);
 pinMode(echo,INPUT);  

  
  
  // TODO you setup code
  
}

void loop() 
{ if (RemoteXY.switch_1 == 0){


  Ultrasonic();
sr=digitalRead(sensorR);
sl=digitalRead(sensorL);
  if(sl==0&&sr==0&&distance>20){
  forword();

  }
   else if(sl==0&&sr==0&&distance<20){
  stoop();

  }
  else if(sl==0&&sr==1&&distance>20){
  left();
   
  }
    else if(sl==0&&sr==1&&distance<20){
  stoop();
 
  }
  else if(sl==1&&sr==0&&distance>20){
  right();

  }
    else if(sl==1&&sr==0&&distance<20){
 stoop();
  }
  else if(sl==1&&sr==1){
  stoop();
  }


}
else if (RemoteXY.switch_1 == 1){
  if (RemoteXY.button_1 == 1){
 forword(); 
}
 else if (RemoteXY.button_2 == 1){
 right(); }
 else if (RemoteXY.button_3 == 1){
 left(); }
  else if (RemoteXY.button_4 == 1){
 backword(); }
   else{
   stoop();
}
}
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}  void  Ultrasonic()
{digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
duration =pulseIn (echo, HIGH);
distance = (duration/2 )* 0.0343 ;
}
 void forword()
  {
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
    }
   void backword()
  {
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
    }  
    
   void left()
  {
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
    }
   void right()
  {
 digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
    }  
   void stoop()
  {
 digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
    } 
