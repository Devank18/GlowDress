#include <UltraSonicRanging.h>

int GetDistanceInCm(int triggerPin, int echoPin)
{
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration/2) / 29.1;
    if (distance >= MAXRANGE || distance <= 0)
    {
        return -1;
    }

    return distance;
};


