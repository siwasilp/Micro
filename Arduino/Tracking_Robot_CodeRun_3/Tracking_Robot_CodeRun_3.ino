// Motor A pins (enableA = enable motor, pinA1 = forward, pinA2 = backward)
int enableA = 11;
int pinA1 = 9;
int pinA2 = 8;

//Motor B pins (enabledB = enable motor, pinB2 = forward, pinB2 = backward)
int enableB = 10;
int pinB1 = 7;
int pinB2 = 6;

int count = 0 ;

int sensor[5] = {0, 0, 0, 0, 0};

void setup()
{
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);

  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
}

void loop()
{

  enableMotors();
  analogWrite(enableA, 130);  // ปรับค่าความเร็วของหุ่นยนต์
  analogWrite(enableB, 135);  // ปรับค่าความเร็วของหุ่นยนต์

  sensor[0] = digitalRead(A1);
  sensor[1] = digitalRead(A2);
  sensor[2] = digitalRead(A3);
  sensor[3] = digitalRead(A4);
  sensor[4] = digitalRead(A5);

  if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    forward(1);//11011 ให้หุ่นยนต์เดินหน้า
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    turnRight(1);//11101 ให้หุ่นยนต์เลี้ยวขวา
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    forward(1);//11001 ให้หุ่นยนต์เลี้ยวขวา
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    turnLeft(1);//10111 ให้หุ่นยนต์เลี้ยวซ้าย
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    forward(1);//10011 ให้หุ่นยนต์เลี้ยวซ้าย
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    forward(1);//11001 ให้หุ่นยนต์เลี้ยวขวา
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    forward(1);//11001 ให้หุ่นยนต์เลี้ยวขวา
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    forward(1);//11001 ให้หุ่นยนต์เลี้ยวขวา
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    turnRight(1);//11100 ให้หุ่นยนต์เลี้ยวขวา 90 องศา
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))
    turnRight(1);//11101 ให้หุ่นยนต์เลี้ยวขวา
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    turnLeft(1);//11101 ให้หุ่นยนต์เลี้ยวขวา
  else if (((sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0)) ||
           ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))) {
    if (count == 1) {
      turnRight(400);
      count++;
    }
    else if (count == 2) {
      turnRight(400);
      count++;
    }
    else if (count == 3) {
      turnRight(400);
      count++;
    }
    else if (count >= 4) {
      disableMotors();
    }
    else {
      delay(250);
      count++;
    }
  }
  else
    forward(1);//เคสอื่นๆ ให้หุ่นยนต์เดินหน้า
}

//Define high-level H-bridge commands

void enableMotors()
{
  motorAOn();
  motorBOn();
}

void disableMotors()
{
  motorAOff();
  motorBOff();
}

void forward(int time)
{
  motorAForward();
  motorBForward();
  delay(time);
}

void backward(int time)
{
  motorABackward();
  motorBBackward();
  delay(time);
}

void turnLeft(int time)
{
  motorABackward();
  motorBForward();
  delay(time);
}

void turnRight(int time)
{
  motorAForward();
  motorBBackward();
  delay(time);
}

void coast(int time)
{
  motorACoast();
  motorBCoast();
  delay(time);
}

void brake(int time)
{
  motorABrake();
  motorBBrake();
  delay(time);
}
//Define low-level H-bridge commands

//enable motors
void motorAOn()
{
  digitalWrite(enableA, HIGH);
}

void motorBOn()
{
  digitalWrite(enableB, HIGH);
}

//disable motors
void motorAOff()
{
  digitalWrite(enableB, LOW);
}

void motorBOff()
{
  digitalWrite(enableA, LOW);
}

//motor A controls
void motorABackward()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
}

void motorAForward()
{
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
}

//motor B controls
void motorBBackward()
{
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
}

void motorBForward()
{
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
}

//coasting and braking
void motorACoast()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
}

void motorABrake()
{
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, HIGH);
}

void motorBCoast()
{
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
}

void motorBBrake()
{
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, HIGH);
}
