#include <Servo.h>

Servo finger1;
Servo finger2;
Servo finger3;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0; 

int finger_switch1=2 ;
int finger_switch2=3 ;
int finger_switch3=4 ;


void setup() {
  // put your setup code here, to run once:
finger1.attach(6);
finger2.attach(7);
finger3.attach(8);

pinMode(finger_switch1,INPUT);
pinMode(finger_switch2,INPUT);
pinMode(finger_switch3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 finger1.write(pos1); 
 finger2.write(pos2);
 finger3.write(pos3);

if(digitalRead(finger_switch1)==HIGH){

pos1=180;

finger1.write(pos1);
  }
else {
  pos1 = 0 ;
  finger1.write(pos1);
  
  }


if(digitalRead(finger_switch2)==HIGH){

pos2=180;

finger2.write(pos2);
  }
else {
  pos2 = 0 ;
  finger2.write(pos2);
  
  }


if(digitalRead(finger_switch3)==HIGH){

pos3=180;

finger3.write(pos3);
  }
else {
  pos3 = 0 ;
  finger3.write(pos3);
  
  }

}
