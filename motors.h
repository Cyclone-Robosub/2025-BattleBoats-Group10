#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define IN1_PIN 2
#define IN2_PIN 3
#define IN3_PIN 4
#define IN4_PIN 5
#define ENA_PIN 10   // Pin must support PWM!
#define ENB_PIN 9  // Pin must support PWM!

// ==============================
//         Motor Control
// ==============================
void motorInit();
void driveForward(int speed);
void driveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void driveStop();

#endif
