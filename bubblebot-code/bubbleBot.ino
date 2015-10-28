
//This sketch is based off the Stepper example sketch by Tom Igoe.

//stepper library--you should have it already
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
int fanPin = 11; // the TIP-120 base plugs in here

int sixthRev = stepsPerRevolution / 6; //how many steps go into each sixth?

// initialize the stepper library on pins 5 through 8:
Stepper myStepper(stepsPerRevolution, 5,6,7,8);            

int stepCount = 0;         // number of steps the motor has taken
//used only during calibration

void setup() {
  // initialize the serial port:
  Serial.begin(9600);

  Serial.println("Beginning calibration");

  //move the wand one step   
  for (int thisStep = 0; thisStep < stepsPerRevolution; thisStep++) { 

    myStepper.step(1);
    stepCount++;
    delay(500);

    int hallEffect = digitalRead(3); //listening for pin 3 to light up

    //when it does, the sketch breaks out of the FOR loop
    if hallEffect = HIGH (thisStep = stepsPerRevolution);

  }

  Serial.println("Calibration done");

// initializes this value
  int wandStep = 0;

}

void loop() {

  //the loop is the part where the bubble bot does its thing

  // first, it moves one sixth of its full rotation:
  myStepper.step(sixthRev);
  wandStep++;
  if wandStep = 7 (wandStep = 1); //resets wandStep for a new rotation
  delay(500);


  //next, it blows the fan a certain speed and duration 
  //depending on how you've programmed it

  switch (wandStep) {
  case 1:    
    analogWrite(fanPin, 100); //number is how fast the fan blows: 0=stopped, 255=max
    delay(2000); // milliseconds the fan blows
    analogWrite(fanPin, 0); //turn off that fan
    delay(500); //a half-second before it continues the loop
    break;

  case 2:    
    analogWrite(fanPin, 125);
    delay(2000); //
    analogWrite(fanPin, 0); 
    delay(500); 
    break;

  case 3:    
    analogWrite(fanPin, 150);
    delay(1750); //
    analogWrite(fanPin, 0); 
    delay(500); 
    break;

  case 4:    
    analogWrite(fanPin, 200);
    delay(1500); //
    analogWrite(fanPin, 0); 
    delay(500); 
    break;

  case 5:    
    analogWrite(fanPin, 225);
    delay(1250); //
    analogWrite(fanPin, 0); 
    delay(500); 
    break;

  case 6:    
    analogWrite(fanPin, 250);
    delay(1000); //
    analogWrite(fanPin, 0); 
    delay(500); 
    break;  
  }
  
  //the fan is done, and the loop resets
  
}

