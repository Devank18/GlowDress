// circuit as in http://www.instructables.com/file/F9LKDFGGU7FXUMH
#include <UltraSonicRanging.h>


#define ECHO_PIN 2 // White
#define TRIG_PIN 3 // Brown
#define LED_OUT  5

const int space = 125;

void setup()
{
   Serial.begin (9600);
   pinMode(TRIG_PIN, OUTPUT); // trigger pin of US range finder
   pinMode(ECHO_PIN, INPUT);  // Echo pin of US range finder
   pinMode(LED_OUT, OUTPUT);  // base of TIP120 to drive LED

   analogWrite(LED_OUT, 0); 
}

void GlowLed()
{  
  // Slowly get from LED strip off to full bright (glow-in)
  for (int brightness = 0; brightness < 255; brightness++) 
  {
    analogWrite(LED_OUT, brightness);
    delay(3);
  }

  // Slowly get from LED strip on to full off (glow-out)
  for (int brightness = 255; brightness >= 0; brightness--) 
  {
    analogWrite(LED_OUT, brightness);
    delay(3);
  }
}

void loop() 
{
  int distance = GetDistanceInCm(TRIG_PIN, ECHO_PIN);
  Serial.println(distance);

  if (distance <= 0 || distance > space)
  {
    analogWrite(LED_OUT, 0);
    delay(500);
    return;
  }  
  
  if (distance <= space)
  {
    GlowLed();
  }
}
