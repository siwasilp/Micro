#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHTesp.h"
BlynkTimer timer; // Announcing the timer
DHTesp dht;
char auth[] = "kkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
char ssid[] = "SUT_IoTs";
char pass[] = "MaiMeeJingJing";
const int pinDHT_22 = 15; // D15
void myTimerEvent()
{ float temperature = dht.getTemperature();
  float humidity = dht.getHumidity();
  Blynk.virtualWrite(V10, temperature);
  Blynk.virtualWrite(V11, humidity);
  Serial.print(" Temp('C) >> "); Serial.print(temperature, 1);
  Serial.print(", Humidity(%) >> "); Serial.println(humidity, 1);
}
void setup()
{ Serial.begin(115200);
  dht.setup(pinDHT_22);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}
void loop()
{ Blynk.run();
  timer.run(); // running timer every 250ms
}
