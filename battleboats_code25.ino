#include "motors.h"
#include "ultrasonic.h"
bool rwall, lwall, old_rwall, old_lwall;
void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit(TRIG_PIN1, ECHO_PIN1);
  ultrasonicInit(TRIG_PIN2, ECHO_PIN2)
}

void loop() {
  bool turning;
  setup()
  float distR = readDistanceCM(TRIG_PIN1, ECHO_PIN1);
  float distL = readDistanceCM(TRIG_PIN2, ECHO_PIN2);

//wall presence
rwall = distR < 39.2;
lwall = distL < 39.2;


//detect wall changes
  bool rightDisappeared = (old_rwall == true && rwall == false);
  bool leftDisappeared  = (old_lwall  == true && lwall  == false);
  bool rightReappeared  = (old_rwall == false && rwall == true);
  bool leftReappeared   = (old_lwall  == false && lwall  == true);

  old_rwall = rwall;
  old_lwall = lwall;
  Serial.print("Distance 1: ");
  Serial.print(dist1);
  Serial.println(" cm \n");
  Serial.print("Distance 2: ");
  Serial.print(dist2);
  Serial.println(" cm \n");

  
if (turning) {
  //if we’re in a turning phase, just turn for a short time
  if (rwall || lwall) {          //wall reappeared
    driveStop();
    turning = false;
  } else {
    //keep turning a bit
    delay(100);
  }
} 
else {
  if (rightDisappeared && !leftDisappeared){
    turnRight(120);
    turning = true;
    delay(2000);                 //turn duration adjst this fr
  } 
  else if (leftDisappeared && !rightDisappeared){
    turnLeft(120);
    turning = true;
    delay(2000);                 //turn duration adjst this fr
  }
  else if(!rwall && !lwall){
    driveBackward(100);
    delay(800);
    driveStop();
  } 
  else {
    driveForward(150);
    delay(100);                  //small delay
  }
}
}