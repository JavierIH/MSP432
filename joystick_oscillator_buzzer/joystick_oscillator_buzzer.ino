#include "octosnake.h"


const int joystickX = 2;       // the number of the joystick X-axis analog
const int joystickY =  26;     // the number of the joystick Y-axis analog
const int buzzerPin = 40;

int joystickXState, joystickYState ; 

Oscillator oscillator; //Oscillator from OctoSnake


void setup() {
  pinMode(buzzerPin,OUTPUT);
  oscillator.setAmplitude(200);
}

void loop(){
  joystickXState = analogRead(joystickX);
  joystickXState = map(joystickXState, 0, 4096, 400, 3000);
  joystickYState = analogRead(joystickY);
  joystickYState = map(joystickYState, 0, 4096, 100, 3000);
  
  oscillator.setOffset(joystickXState); //Offset proportional to X axis
  oscillator.setPeriod(joystickYState); //Period proportional to Y axis
  
  tone(buzzerPin, oscillator.refresh());
  delay(20);
}
