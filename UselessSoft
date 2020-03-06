#include <Servo.h>
  Servo servo;
  int angle = 10;
  const int on{50};
  const int off{153};
  const int half{100};
  int min{1};
  int max{5};
  int temp{2137};
  int ledPin = 3;  
  int inPin = 2;   
  int val = 0;      


void servoOn(int del){  
  delay(del);                     
    servo.write(on);        
    delay(100);                        
}


void servoOff(int del){
  for(int angle = servo.read(); angle<off; angle++)    
  { 
    delay(del);                               
    servo.write(angle);                                    
  } 
}

void servo_1(){                       
  servoOn(500);
  servoOff(50);                       
}
void servo_2(){                       
  servoOn(100);
  delay(1000);
  servoOff(50);                       
}
void servo_3(){                       
  servoOn(50);
  servoOff(5);                       
}
void servo_4(){                       
  servoOn(5000);
  servoOff(5);                       
}

void setup() {
  servo.attach(9) ;
  servo.write(off);
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);

  
}

void loop() {

 int val = digitalRead(inPin);

  
  //Serial.print(val);
  if(val == HIGH){
    temp = random(min, max);
    Serial.print(temp);
  switch (temp) {
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
  }
  }
}
