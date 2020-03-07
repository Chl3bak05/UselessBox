#include <Servo.h>
Servo servo;
int angle = 10; //Does nothing
const int on{50}; //Angle when on
const int off{153}; //Angle when hidden
const int half{110}; //Angle between
int min{1}; //Amount of programs
int max{7};
int caseFunction{1}; //number of program
int inPin = 2;   //InputPin
int val = 0;      //val delaration
int startup{5}; //amount of startup program 3 runs
unsigned long startTime;
unsigned long stopTime;
long idleTime{120000}; //czas bezczynnosci w ms



void servoOn(int del) {
  delay(del);
  servo.write(on);
  delay(250);
}


void servoOff(int del) {
  for (int angle = servo.read(); angle < off; angle++)
  {
    delay(del);
    if (digitalRead(inPin) == HIGH) break;
    servo.write(angle);
  }
}

void servo_1() { //Delay and slow return
  servoOn(500);
  servoOff(35);
}
void servo_2() { //Stop and slow return
  servoOn(110);
  delay(1000);
  servoOff(35);
}
void servo_3() { //Fast On/off
  servoOn(50);
  servoOff(5);
}
void servo_4() { //big Delay and fast return
  servoOn(5000);
  servoOff(5);
}
void servo_5() {//Go to half then turn on
  servo.write(half);
  servoOn(800);
  servoOff(5);
}
void servo_6() {//Go to half, hide, turn on, hide
  servo.write(half);
  delay(400);
  servo.write(off);
  servoOn(3000);
  servoOff(5);
}


void setup() {
  servo.attach(9) ;
  servo.write(off);
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(inPin, INPUT);

  startTime=millis();

}

void loop() {
  
  stopTime=millis();
  Serial.print(stopTime-startTime);
  Serial.print('\n');
  if(stopTime-startTime > idleTime)startup=5;
  int val = digitalRead(inPin);

  //Serial.print(val);
  
  if (startup > 0) {
    if (val == HIGH){
      startTime=millis();
      servo_3();
      --startup;
    }
  }
  else {
     if (val == HIGH) {
      startTime=millis();
      caseFunction = random(min, max);
      Serial.print(caseFunction);
      switch (caseFunction) {
        case 1:
          servo_1();
          break;
        case 2:
          servo_2();
          break;
        case 3:
          servo_3();
          break;
        case 4:
          servo_4();
          break;
        case 5:
          servo_5();
          break;
        case 6:
          servo_6();
          break;
      }
    }
  }
}
