#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PIN1 11
#define ECHO_PIN1 12
#define TRIG_PIN2 6
#define ECHO_PIN2 7

void ultrasonicInit(int a, int b);
float readDistanceCM(int a, int b);

#endif
