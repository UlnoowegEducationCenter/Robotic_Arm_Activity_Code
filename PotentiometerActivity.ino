/*
 * This code controls the 4DOF robot manipulator arm with variable potentiometers.  Use analog pins for pot read-out and PWM 
 * VarSpeedServo pinout
 * Holly Griffiths, Digital Mi'kmaq 23/10/2020
 */
//The first line is where we tell the Arduino to use the VarSpeedServo.h Library
//A library is a premade set of instructions to make the process of coding easier 
//The library we are using has instructions to identify the motors and communicate with them 

#include <VarSpeedServo.h>


//We start off by giving the servo names.
//VarSpeedServo is used to tell the Arduino that what we are naming is a servo motor 

VarSpeedServo claw;  
VarSpeedServo baseL;
VarSpeedServo baseR;
VarSpeedServo baseRotation;

// Next up we create names for the dials and tell the Arduino which dial is connected to which pin 
int clawDial = ;            //type in the number of the pin in which you have connected to the claw dial after the "=" sign
int baseLDial = ;           //type in the number of the pin in which you have connected to the left base dial after the "=" sign
int baseRDial = ;           //type in the number of the pin in which you have connected to the right base dial after the "=" sign
int baseRotationDial = ;    //type in the number of the pin in which you have connected to the base rotation dial after the "=" sign

// here we are creating a place to keep hold of the values which the dial sends to the Arduino to then send them to the servo motor
int val1;
int val2;
int val3;
int val4;

// setting up the speed of the servo motors 
int motorSpeed = 20;

void setup() {
  // Here we are assigning the servo motor names to their respective servo motors 
  
  claw.attach();            //type in the number of the pin in which you have connected to the claw motor in between the brackets  
  baseL.attach();           //type in the number of the pin in which you have connected to the left base motor in between the brackets  
  baseR.attach();           //type in the number of the pin in which you have connected to the right base motor in between the brackets  
  baseRotation.attach();    //type in the number of the pin in which you have connected to the base rotation motor in between the brackets  
}

void loop() {
  //The following section of coding is where we take information from the dial to then send it to the servo motor to make it move 
  
  val1 = analogRead(clawDial);            // The Arduino reads the value of the claw dial and keeps hold of this value inside val1
  val1 = map(val1, 0, 1023, 70, 180);     // This line adjusts the value from the claw dial so that we can use it to control the claw motor 
  claw.write(val1, motorSpeed, true );   // Here we tell the claw motor to move in accordance with the position of the claw dial

//The process is then repeated for each set of dials and servo motors 

  val2 = analogRead(baseLDial);            
  val2 = map(val2, 0, 1023, 10, 170);     
  baseL.write(val2, motorSpeed, true);

  val3 = analogRead(baseRDial);            
  val3 = map(val3, 0, 1023, 10, 160);     
  baseR.write(val3, motorSpeed, true);        

  val4 = analogRead(baseRotationDial);            
  val4 = map(val4, 0, 1023, 10, 170);     
  baseRotation.write(val4, motorSpeed, true);  
}
