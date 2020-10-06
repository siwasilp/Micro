#define ENA 9
#define IN1 8
#define IN2 7

#define IN3 13
#define IN4 12
#define ENB 11
void setup() {
  Robot_Stop(150);
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  if (Serial.available()) {
    int c = Serial.read();
    if (c == 'S') Robot_Stop(1);
    else if (c == 'L') Robot_GoLeft(255, 50);
    else if (c == 'R') Robot_GoRight(255, 50);
    else if (c == 'G') Robot_Go(255, 50);
    else if (c == 'B') Robot_Back(255, 50);
    else Robot_Stop(1);
  }
}

}
void Robot_Stop(int xDelay)
{ digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  delay(xDelay);
}
void Robot_Go(int xSpeed, int xDelay)
{ digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, xSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, xSpeed);
  delay(xDelay);
}
void Robot_Back(int xSpeed, int xDelay)
{ digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, xSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, xSpeed);
  delay(xDelay);
}
void Robot_GoLeft(int xSpeed, int xDelay)
{ digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENA, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, xSpeed);
  delay(xDelay);
}
void Robot_GoRight(int xSpeed, int xDelay)
{ digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, xSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENB, LOW);
  delay(xDelay);
}
}
