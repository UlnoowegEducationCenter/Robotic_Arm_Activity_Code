/*
 * Matthew Paul, Digital Mi'kmaq, Oct 15, 2021
 */

#include <VarSpeedServo.h>

VarSpeedServo clawPin; 
VarSpeedServo basePin; 
VarSpeedServo leftPin; 
VarSpeedServo rightPin; 

// Global Variables
int armSpeed = 20; // 1-255, higher values are faster, 0 for fullspeed
int baseSpeed = 20; 
int clawSpeed = 30;

void setup(){
  clawPin.attach(6);     // Assign Servo pins (Use PWM pins)
  leftPin.attach(9);
  rightPin.attach(10);
  basePin.attach(11);
}


// Define Functions
void claw(int angle){
  angle = map(angle, 0, 100, 70, 180);
  clawPin.write(angle, clawSpeed);
}

void reach(int angle){
  angle = map(angle, 0, 100, 20, 170);
  rightPin.write(angle, armSpeed);
}

void height(int angle){
  angle = map(angle, 0, 100, 10, 160);
  leftPin.write(angle, armSpeed);
}


void base(int angle){
  angle = map(angle, 0, 100, 10, 170);
  basePin.write(angle, baseSpeed);
}

void endRoutine(){
  delay(1500); //These 7 lines of code return the arm to its neutral position and end the routine.
  clawPin.write(90, clawSpeed); 
  leftPin.write(90, armSpeed);
  rightPin.write(90, armSpeed);
  basePin.write(90, baseSpeed);
  delay(2000);
  exit(0);
}

  /*
   * Commands:
   * All functions take a range from 0 to 100 inside the brackets
   * claw(); closed = 0, fully open = 100
   * reach(); furthest back = 0, furthest forward = 100
   * height(); lowest = 0, highest = 100
   * base(); furthest left = 0, furthest right = 100
   */

void loop(){
  //You can erase the 10 lines below after seeing how the code works, or reuse and modify them!
  base(25);
  delay(1000);
  base(75);
  delay(2000);
  height(25);
  delay(1000);
  reach(90);
  delay(1000);
  claw(100);
  delay(1500);
  claw(0);
  delay(1000);
  reach(25);
  delay(1000);
  height(90);
  delay(1500);
  claw(100);
  delay(1500);
  claw(0);
  endRoutine();
}
