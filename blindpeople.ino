#include <Servo.h>
Servo myservo;

  const int pingTrigPin = 12; //Trigger connected to PIN 7   
  const int pingEchoPin = 10; //Echo connected yo PIN 8   
  int buz=7; //Buzzer to PIN 4   
  void setup() {
  myservo.attach(9);   
  Serial.begin(9600);   
  pinMode(buz, OUTPUT);  
  digitalWrite(buz, HIGH); 
  }   
  void loop()   
  { 
  long duration, cm;   
  pinMode(pingTrigPin, OUTPUT);   
  digitalWrite(pingTrigPin, LOW);   
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);   
  pinMode(pingEchoPin, INPUT);   
  duration = pulseIn(pingEchoPin, HIGH);   
  cm = microsecondsToCentimeters(duration);   
  if(cm<=15 && cm>0)   
  {   
  int d= map(cm, 1, 100, 20, 2000);   
  digitalWrite(buz, LOW);
  delay(500);
  digitalWrite(buz,HIGH);
  //digitalWrite(buz, HIGH);
  }  
  
  Serial.print(cm);    
  Serial.print("cm");   
  Serial.println();   
  delay(100);   
  }   
  long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  }   
   
