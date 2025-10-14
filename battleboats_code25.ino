#include "motors.h"
#include "ultrasonic.h"
bool rwall = true;
bool lwall = true;
bool old_rwall;
bool old_lwall;
void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

bool CheckRWall(int dist1){
  if(dist1 >= 39.2){
    old_rwall = rwall;
    rwall = false;
    return false;
  }
  else{
    return true;
  }
}
bool CheckLWall(int dist2){
  if(dist2 >= 39.2){
    old_lwall = lwall;
    lwall = false;
    return false;
  }
  else{
    return true;
  }
}
void loop() {
  bool old_wall;
  float dist1 = readDistanceCM(TRIG_PIN1, ECHO_PIN1);
  float dist2 = readDistanceCM(TRIG_PIN2, ECHO_PIN2);
  Serial.print("Distance 1: ");
  Serial.print(dist1);
  Serial.println(" cm \n");
  Serial.print("Distance 2: ");
  Serial.print(dist2);
  Serial.println(" cm \n");

  
  while(!CheckRWall() ){
    turnRight(100);
    delay(3000);
  }
  while(!CheckLWall()){
    turnLeft(100);
    delay(3000);
  }
  while(CheckLWall() && CheckRWall()){
    driveForward(150);
    delay(3000);
  }
  if(!CheckLWall() || !CheckRWall()){
    driveBackward(50);
    delay(2000)
  }
  delay(100);
}
