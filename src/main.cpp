#include <Arduino.h>

#define dimpin1 4   // D2
#define dimpin2 12  // D6
#define dimpin3 14  // D5
#define zeroPin 5   // D1

volatile int tic, Dimmer;


volatile byte interruptCounter = 0;
int numberOfInterrupts = 0;

void handleInterrupt() {
  interruptCounter++;
}

void setup() {
 
  Serial.begin(115200);
  
  pinMode(dimpin1, OUTPUT);
  pinMode(dimpin2, OUTPUT);
  pinMode(dimpin3, OUTPUT);
  digitalWrite(dimpin1, LOW);
  digitalWrite(dimpin2, LOW);
  digitalWrite(dimpin3, LOW);

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