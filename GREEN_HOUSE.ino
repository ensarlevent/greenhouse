#include <LCD5110_Basic.h>

LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup() {
  myGLCD.InitLCD();
  
  pinMode(7, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(3, OUTPUT);  //pompa
  pinMode(4, OUTPUT);  //pompa

  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);

  myGLCD.setFont(SmallFont);
  myGLCD.print("e.levent", CENTER, 5);
  myGLCD.print("LOADING..", CENTER, 30);
  delay(2000);
}

void loop() {
 int sensorValue = analogRead(A0);
 int last = ((1024 - sensorValue) / 10);

 int sensorValue1 = analogRead(A1);
 int mid = ((1024 - sensorValue1) / 10);
 
  myGLCD.clrScr();

  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(2200);
  digitalWrite(3, LOW);
  
  myGLCD.setFont(MediumNumbers);
  myGLCD.printNumI(last, RIGHT, 0);

  myGLCD.setFont(MediumNumbers);
  myGLCD.printNumI(mid, RIGHT, 20);

  myGLCD.setFont(SmallFont);
  myGLCD.print("AIR QUA.:", 0, 6);
  myGLCD.print("MOISTURE:", 0, 24);
  
  digitalWrite(7, HIGH);
  myGLCD.setFont(SmallFont);
  myGLCD.print("LIGHT ON", CENTER, 40);
  delay(1800000);
  
  digitalWrite(7, LOW);
  myGLCD.setFont(SmallFont);
  myGLCD.print("LIGHT OFF", CENTER, 40);
  delay(1800000);
}
