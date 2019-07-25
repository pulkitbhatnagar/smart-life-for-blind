#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#include <SPI.h>
#include <ThingerWifi.h>
#define USERNAME "pulkitbhatnagar1"
#define DEVICE_ID "node"
#define DEVICE_CREDENTIAL "123456"

#define SSID "Hamarawifi"
#define SSID_PASSWORD "doomsday12"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
int pushPin = 12; //  Pin 6 on Node MCU   //the digital pin connected to the PIR sensor's output
int ledPin = 4;  // Pin 2 on NodeMCU
int val = 0;     // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pushPin, INPUT_PULLUP);

  int pushPin = 12; //  Pin 6 on Node MCU   //the digital pin connected to the PIR sensor's output
int ledPin = 4;  // Pin 2 on NodeMCU
int val = 0;     // variable for reading the pin status
Serial.begin(9600);

  thing.add_wifi(SSID, SSID_PASSWORD);

  
}

void loop() {
   val = digitalRead(pushPin);
  Serial.println(val);// read input value
  if (val == LOW) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, HIGH);  // turn LED OFF
    delay(1000);
        digitalWrite(ledPin, LOW);
  thing.handle();
   thing.call_endpoint("email");
           delay(5000);
   // digitalWrite(inPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW); 
}
}
