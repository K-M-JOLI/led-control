#include "Arduino.h"

int numLEDs = 20;
int ledPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int onPercentage = 100;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < numLEDs; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  if (Serial.available() > 0)
  {
    onPercentage = Serial.parseInt();
    onPercentage = constrain(onPercentage, 0, 100);
    Serial.println(onPercentage);
  }

  int numLEDon = (numLEDs * onPercentage) / 100;

  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], (i <= numLEDon));
  }
}
