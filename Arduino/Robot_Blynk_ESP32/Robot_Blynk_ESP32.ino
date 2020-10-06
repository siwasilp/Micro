#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <analogWrite.h>

//pins to drive motors
#define IN1  13
#define IN2  12
#define IN3  14
#define IN4  27
#define ENA  26
#define ENB  25

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Ee_btcxBL68a8roSSvM1vzLSfe2shzBz";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Puwanat";
char pass[] = "11111111";


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //Serial.print("*Explore Robo Mode Computer: Controlled*\n\r");
  //Serial.println("Commands:\n W->Forward \n S->Backwards \n A->Left \n D->Right");
}

void loop()
{

  Blynk.run();

}

//Robot Driving Functions
void Robot_Forward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 195);
  analogWrite(ENB, 200);
}
void Robot_Backward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 195);
  analogWrite(ENB, 200);
}
void Robot_Left()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}
void Robot_Right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 195);
}

void Robot_Stop()
{
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
}



BLYNK_WRITE(V1)
{
  int value = param.asInt(); // Get value as integer
  Serial.println("Going Forward");
  if (value)
  {
    Robot_Forward();

  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt(); // Get value as integer
  Serial.println("Moving Left");
  if (value)
  {

    Robot_Left();
    delay(200);
    Robot_Stop();
  }
}


BLYNK_WRITE(V3)
{
  int value = param.asInt(); // Get value as integer
  Serial.println("Going back");
  if (value)
  {
    Robot_Backward();

  }
}


BLYNK_WRITE(V4)
{
  int value = param.asInt(); // Get value as integer
  Serial.println("Moving Right");
  if (value)
  {
    Robot_Right();
    delay(200);
    Robot_Stop();

  }
}
BLYNK_WRITE(V5)
{
  int value = param.asInt(); // Get value as integer
  Serial.println("Braking!!");
  if (value)
  {
    Robot_Stop();
  }
}
