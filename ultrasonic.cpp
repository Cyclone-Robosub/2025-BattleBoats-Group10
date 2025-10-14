#include "ultrasonic.h"

void ultrasonicInit(int TRIG_PIN, int ECHO_PIN) {
  // configure ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float readDistanceCM(int TRIG_PIN, int ECHO_PIN) {
  // Set TRIG low 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PIN, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}
