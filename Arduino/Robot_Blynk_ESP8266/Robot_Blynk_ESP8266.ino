/**************************************************************
   This example runs directly on NodeMCU chip
   using the Blynk platform and mobile application.
   Change WiFi ssid, password, and Blynk auth token to run :)
 **************************************************************/

#define BLYNK_PRINT Serial // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 9 // D1 <-> IN1
#define RightMotorDir 8  // D3 <-> IN2
#define LeftMotorSpeed 7  // D2 <-> IN3
#define LeftMotorDir 6  // D4 <-> IN4

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "IzN8yWFrLPseVv5CFDlv0PQq3YLKpNyZ";
char ssid[] = "Puwanat";
char pass[] = "11111111";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

void halt()
{
  digitalWrite(RightMotorSpeed, LOW);
  digitalWrite(LeftMotorSpeed, LOW);
}

void forward()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, LOW);
  digitalWrite(LeftMotorSpeed, LOW);
}

void reverse()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void right()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void left()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

BLYNK_WRITE(V0)
{
  if (param[0])
    forward();
  else
    halt();
}

BLYNK_WRITE(V1)
{
  if (param[0])
    reverse();
  else
    halt();
}

BLYNK_WRITE(V2)
{
  if (param[0])
    right();
  else
    halt();
}

BLYNK_WRITE(V3)
{
  if (param[0])
    left();
  else
    halt();
}
