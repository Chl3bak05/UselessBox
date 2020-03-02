#include <Servo.h>
  Servo servo;
  int angle = 10;
  const int on{50};
  const int off{153};

  int ledPin = 3;  // LED connected to digital pin 13
  int inPin = 2;    // pushbutton connected to digital pin 7
  int val = 0;      // variable to store the read value


void gotoservo(int ang1, int ang2, int del){
  for(int angle = ang2; angle<ang1; angle++)     // 
  {                                
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(del);                       
  } 
}

void setup() {
  servo.attach(9) ;
  servo.write(off);
  Serial.begin(9600);


  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);

  
}

void loop() {

 
  int val = digitalRead(inPin);
  
  Serial.print(val);
  if(val == HIGH){
     int rand = random(0, 10);
    if(rand <=5){
    servo.write(on);
    delay(1000);
    Serial.print("servo");
    gotoservo(off,on,14);
  }
  else{
    servo.write(on);
    Serial.print("servo");
    gotoservo(off,on,14);
  }
    
  }
 
}
