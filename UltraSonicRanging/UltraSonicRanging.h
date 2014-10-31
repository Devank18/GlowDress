/*
 * UltraSonicRanging.h - Library for finding distanced in cm and inch from a
 * unltrasonic range finder like HC-SR04
 */

#ifndef _ULTRASONIC_RANGING_H_
#define _ULTRASONIC_RANGING_H_

#include "Arduino.h"

const int MAXRANGE = 500;
const int MINRANGE = 2;

int GetDistanceInCm(int triggerPin, int echoPin);

#endif // _ULTRASONIC_RANGING_H_

