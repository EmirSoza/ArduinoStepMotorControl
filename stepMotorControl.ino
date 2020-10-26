
/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.



 */

#include <Stepper.h>

int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int sensor1;
int sensor2;
int counter1;
int counter2;
int delta;
int deltaAbs;
int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
  counter1 = 0;
  counter2 = 0;
}

void loop() {
  // read the sensor value:
  sensor1 = analogRead(A0);
  sensor2 = analogRead(A1);
  delta = sensor1-sensor2;
  deltaAbs = abs(delta); 
  
  // map it to a range from 0 to 100:
  int motorSpeed = map(deltaAbs, 0, 1023, 0, 100);
Serial.println(motorSpeed);
  // set the motor speed:
  if (motorSpeed > 0) {
     myStepper.setSpeed(motorSpeed);
     
    if(delta>0){
      // step 1/100 of a revolution:
      stepsPerRevolution = 200;
    myStepper.step(stepsPerRevolution / 100);
    counter1++;
    counter2 = counter2-1;
    }
    else if(delta<0){  
      stepsPerRevolution = -200;
      myStepper.step(stepsPerRevolution / 100);
      counter2++;
      counter1 = counter1-1;
      }
}
//Serial print corrupts the flow of programm
//Serial.print("Player 1: " );
//Serial.println( counter1);
//Serial.print("Player 2: " );
//Serial.println( counter2);

  
}
