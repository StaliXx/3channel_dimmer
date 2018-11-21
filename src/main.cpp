#include <Arduino.h>

#define dim1pin 4   // D2
#define dim1pin 12  // D6
#define dim1pin 14  // D5
#define zeroPin 5   // D1

volatile int tic, Dimmer;


volatile byte interruptCounter = 0;
int numberOfInterrupts = 0;

void handleInterrupt() {
  interruptCounter++;
}

void setup() {
 
  Serial.begin(115200);
  pinMode(zeroPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(zeroPin), handleInterrupt, FALLING);
 
}
 

 
void loop() {
 
  if(interruptCounter>0){
 
      interruptCounter--;
      numberOfInterrupts++;
 
      Serial.print("An interrupt has occurred. Total: ");
      Serial.println(numberOfInterrupts);
  }
 
}