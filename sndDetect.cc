/*
From https://create.arduino.cc/projecthub/electropeak/how-to-use-ky-037-sound-detection-sensor-with-arduino-a757a7
KY-037 Sound Detection Sensor + Arduino
modified on 16 Apr 2019
by Mohammadreza Akbari @ Electropeak
https://electropeak.com/learn/
*/
int sensor_value = 0;
int threshold = 540; //Enter Your threshold value here
int abs_value = 0;
int ledCount = 10;                               //number of Bargraph LEDs
int bargraph[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Bargraph pins
void setup()
{
  Serial.begin(9600);                 // setup serial
  for (int i = 0; i <= ledCount; i++) // Define bargraph pins OUTPUT
  {
    pinMode(bargraph[i], OUTPUT);
  }
  for (int i = 0; i <= 9; i++)
  {
    digitalWrite(i, LOW);
  }
}
void loop()
{
  sensor_value = analogRead(A0);
  abs_value = abs(sensor_value - threshold);
  int ledLevel = map(abs_value, 0, (1024 - threshold), 0, ledCount);
  for (int i = 0; i < ledCount; i++)
  {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (i < ledLevel)
    {
      digitalWrite(bargraph[i], HIGH);
      Serial.println(i);
    }
    // turn off all pins higher than the ledLevel:
    else
    {
      digitalWrite(bargraph[i], LOW);
    }
  }
}
